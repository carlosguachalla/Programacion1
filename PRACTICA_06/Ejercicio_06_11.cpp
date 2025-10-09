// Materia: Programación I, Paralelo 4
// Autor: Carlos Adrian Guachalla Quispe
// Carnet: 9918131 L.P.
// Carrera del estudiante: Ingeniería Mecatrónica
// Fecha creación: 8/10/2025
// Número de ejercicio: 11
#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main() {
    string cadena, token;
    vector<string> tokens;
    int i;
    cout<<"Ingrese la cadena: ";
    getline(cin, cadena);//usamos getline para ingresar el valor de la cadena
    token = "";
    for(i=0;i<cadena.size();i++){
        if(cadena[i] != ' '){
            token += cadena[i];
        } else {
            if(token != ""){
                tokens.push_back(token);
                token = "";
            }
        }
    }
    if(token != ""){tokens.push_back(token);}
    cout<<"Tokens encontrados:"<<endl;
    for(i=0;i<tokens.size();i++){
        cout<<tokens[i]<<endl;
    }
    return 0;
}
