#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <string.h>
#include "tokens.h"
#include "automatas.h"
using namespace std;
bool vectorContains(vector<char> vec, char c){
    for (char currentChar : vec)
        if (c == currentChar) return true;
    return false;
}
int automatas(string palabra){
    //evaluamos si es una cadena de texto
    if(palabra.front() == '"' && palabra.back() == '"')
        return 1;
    else if(palabra.front() == '"' || palabra.back() == '"')
        return 4;
    // evaluamos si es una variable
    if (evaluarVariable(palabra))
        return 2;
    // evaluamos si es una constante
    if (evaluarConstante(palabra))
        return 3;        
    return 0;
}
vector<string> splitString(string str) {
    vector<string> palabras;
    vector<char> caracteresEspeciales = {'*', '+', '-', '/', '%', '=', '#', '"', '&', '(', ')', '[', ']', '{', '}', '!', ';', ',', '<', '>', '^',' ', '.'};
    string palabra;
    bool dentroDeComillas = false;
    bool makingNumber = false;

    for (char c : str) {
        if (c == '"') {
            // Cambio de estado al encontrar comillas
            dentroDeComillas = !dentroDeComillas;
            palabra.push_back(c);
            continue;
        }
        if (isdigit(c)) {
            makingNumber = true;
        }
        if (makingNumber){
            palabra.push_back(c);
            continue;
        }
        if (!dentroDeComillas && vectorContains(caracteresEspeciales, c)) {
            // Si no estamos dentro de comillas y encontramos un carácter especial
            if (!palabra.empty()) {
                palabras.push_back(palabra);
                palabra.clear();
            }
            caracteresEspeciales.push_back('.');
            makingNumber = false;
            if(c!=' ')
            // Agregar el carácter especial como una cadena solo si no es un epacio en blanco
                palabras.push_back(string(1, c)); 
        } else {
            palabra += c;
        }
    }
    if (!palabra.empty()) {
        palabras.push_back(palabra);
    }

    return palabras;
}
void tokenizarLinea(string str, ListaTokens tokens, int linea){
    bool isToken;
    vector<string> vec = splitString(str);
    for (string palabra : vec){
        isToken = false;
        for (int i = 0; i < tokens.nToken(); i++){
            if (palabra == tokens.list.at(i).getSymbol()){
                cout << tokens.list.at(i).toString() << endl;
                isToken = true;
                continue;
            }
        }
        if (!isToken){
            switch (automatas(palabra)){
            case 1:
                cout << Token(0, "STRING", palabra).toString() << endl;
                break;
            case 2:
                cout << Token(0, "ID", palabra).toString() << endl;
                break;
            case 3:
                cout << Token(0, "CONSTANT", palabra).toString() << endl;
                break;
            case 4:
                cout<< "\033[1;31mError en la linea "<<linea<<" missing character "<<"["<<palabra<<"]\033[0m"<<endl;
                break;
            default:
                cout<< "\033[1;31mError en la linea "<<linea<<" token no definido para "<<"["<<palabra<<"]\033[0m"<<endl;
                break;
            }
        }
    }
}
void tokenizar(string ruta){
    ListaTokens tokens;
    tokens.llenarTokens();
    int numeroLinea = 1;
    try{
        fstream file(ruta);      
        while (!file.eof()){
            string linea;
            getline(file, linea);
            tokenizarLinea(linea, tokens, numeroLinea++);
        }
    }catch (const exception &e){
        cout << e.what() << '\n';
    }
}
int main(){
    string archivo = "archivo1.c";
    cout << "Archivo: " << archivo << endl;
    tokenizar(archivo);

    return 0;
}