#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <string.h>
#include "tokens.h"
#include "automatas.h"

using namespace std;

bool vectorContains(vector<char> vec, char c) {
    for (char currentChar : vec)
        if (c == currentChar) return true;
    return false;
}
void addPalabra(string &palabra, vector<string> &palabras) {
    if(!palabra.empty()){
        palabras.push_back(palabra);
        palabra.clear();
    }
}
vector<string> splitString(string str) {
    vector<string> palabras;
    vector<char> caracteresEspeciales = {'*', '+', '-', '/', '%', '=', '#', '"', '&', '(', ')', '[', ']', '{', '}', '!', ';', ',', '<', '>', '^',' ', '|', '&'};
    string palabra;
    bool dentroDeComillas = false;
    for (char c : str) {
        if (c == '"') {
            // Cambio de estado al encontrar comillas
            dentroDeComillas = !dentroDeComillas;
            palabra.push_back(c);
            continue;
        }
        if (!dentroDeComillas && vectorContains(caracteresEspeciales, c)) {
            // Si no estamos dentro de comillas y encontramos un carácter especial
            addPalabra(palabra, palabras);
            if (c != ' ') {
            // Agregar el carácter especial como una cadena solo si no es un epacio en blanco
                palabras.push_back(string(1, c));
            }
        } else
            if (c == '.') {
                //aquí hay dos casos
                //primero se evuala si es una constante númerica con un punto
                //luego se evalua si es una variable llamando a un método 
                if (!evaluarConstante(palabra)) {
                    addPalabra(palabra, palabras);
                    palabras.push_back(string(1,c));
                } else {
                    palabra += c;
                }
            } else {
            palabra += c;
        }
    }
    addPalabra(palabra, palabras);
    return palabras;
}
void tokenizarLinea(string str, ListaTokens tokens, int linea) {
    bool isToken;
    vector<string> vec = splitString(str);
    for (string palabra : vec){
        isToken = false;
        for (int i = 0; i < tokens.nToken(); i++){
            if (palabra == tokens.list.at(i).getSymbol()) {
                cout << tokens.list.at(i).toString() << endl;
                isToken = true;
                continue;
            }
        }
        if (!isToken) {
            switch (evaluar(palabra)) {
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
            //casos de error para cuando se encuentra un comilla doble pero no encuentra su par
                cout << "\033[1;31mError en la linea " << linea << " missing character "<<"["<<palabra<<"]\033[0m" << endl;
                break;
            default:
                cout << "\033[1;31mError en la linea " << linea << " token no definido para "<<"["<<palabra<<"]\033[0m" << endl;
                break;
            }
        }
    }
}
void tokenizar(string ruta) {
    ListaTokens tokens;
    tokens.llenarTokens();
    int numeroLinea = 1;
    try {
        fstream file(ruta);      
        while (!file.eof()) {
            string linea;
            getline(file, linea);
            tokenizarLinea(linea, tokens, numeroLinea++);
        }
    } catch (const exception &e) {
        cout << e.what() << '\n';
    }
}
int main() {
    string archivo = "archivo1.c";
    cout << "Archivo: " << archivo << endl;
    tokenizar(archivo);
    return 0;
}