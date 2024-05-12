#include <iostream>
#include <cstring>
#include "automatas.h"
using namespace std;

int menu(){
    int op;
    cout<<"Menú"<<endl;
    cout<<"1 - Para validar una constante"<<endl;
    cout<<"2 - Para validar una variable"<<endl;
    cout<<"0 - salir del programa"<<endl;
    cout<<"Ingrese su opción: ";
    cin>>op;
    return op;
}

void pausa(){
    char x;
    cout<<"Ingrese un caracter para continuar: ";
    cin>>x;
}

int main(){
    cout<<"Autómatas capaces de reconocer las constantes y variables de C"<<endl;
    int op;
    string  expresion;

    
    do{
        op = menu();
        switch (op){
        case 1: 
            cout<<"Ingrese la constante a validar: ";
            cin>>expresion;    
            if(evaluarConstante(expresion)){
                cout<<"Valido, Es una constante acpetada por el lenguaje C"<<endl;
            }else{
                cout<<"Error, NO es una constante acpetada por el lenguaje C"<<endl;
            }
            break;
        
        case 2: 
            cout<<"Ingrese el nombre de variable a validar: ";
            cin>>expresion;
            if(evaluarVariable(expresion)){
                cout<<"Valido, Es un nombre de variable acpetado por el lenguaje C"<<endl;
            }else{
                cout<<"Error, NO es un nombre de variable acpetada por el lenguaje C"<<endl;
            }
            break;
        
        case 0:
            cout<<"Saliendo..."<<endl;
            break;
        
        default:
            cout<<"Opción invalida"<<endl;
            break;
        }

        //system("pause");
        pausa();
        system("clear");
        //system("cls");

    }while(op != 0);
}
