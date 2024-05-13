#include <string.h>
using namespace std;
//autómata de constantes númericas de c
bool evaluarConstante(string numero){
    int matriz[10][4] = {
        {1, 2, 3, 9},//inicial
        {9, 2, 4, 9},
        {9, 2, 5, 6},
        {9, 5, 9, 9},
        {9, 5, 9, 9},
        {9, 5, 9, 6},
        {8, 7, 9, 9},
        {9, 7, 9, 9},
        {9, 7, 9, 9},
        {9, 9, 9, 9},
    };
    int estado = 0;
    for(char c: numero) {
        if(c == '+' || c == '-') {
            estado = matriz[estado][0];
        }else
            if(c>=48 && c<=57) {
                estado = matriz[estado][1];
            }else
                if(c=='.') {
                    estado = matriz[estado][2];
                }else
                    if(c=='e' || c=='E') {
                        estado = matriz[estado][3];
                    }else{
                        return 0;
                    }
    }
    return estado==5 || estado==2 || estado==7;
}
//autómata de variables de c
bool evaluarVariable(string palabra){
    int matriz[3][3] ={
        {1, 2, 1},
        {1, 1, 1},
        {2, 2, 2}
    };
    int estado = 0;
    for(char c: palabra){
        if((c >= 65 && c <= 90) || (c >=97 && c <= 122)) {
            estado = matriz[estado][0];
        }else
            if(c >= 48 && c <= 57) {
                estado = matriz[estado][1];
            }else
                if(c == 95 || c == '$') {
                    estado = matriz[estado][2];
                }else{
                    return 0;
                }
    } 
    return estado == 1;
}
int evaluar(string palabra){
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