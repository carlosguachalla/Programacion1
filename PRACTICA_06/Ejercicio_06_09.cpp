// Materia: Programación I, Paralelo 4
// Autor: Carlos Adrian Guachalla Quispe
// Carnet: 9918131 L.P.
// Carrera del estudiante: Ingeniería Mecatrónica
// Fecha creación: 8/10/2025
// Número de ejercicio: 9
#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main(){
    string oracion,palabra;
    vector<string> palabras;
    int i;
    cout << "Ingrese una oracion: ";
    getline(cin, oracion);
    palabra = "";
    for(i=0;i<oracion.size();i++){
        if(oracion[i]!=' '){
            palabra+=oracion[i];
        } else {
            if(palabra!=""){
                palabras.push_back(palabra);
                palabra="";
            }
        }
    }
    if(palabra != ""){palabras.push_back(palabra);}
    cout << "Oracion invertida: ";//coloca la oracion invertida por palabra
    for(i=palabras.size()-1;i>=0;i--){
        cout << palabras[i];
        if(i>0){cout << " ";}
    }
    return 0;
}