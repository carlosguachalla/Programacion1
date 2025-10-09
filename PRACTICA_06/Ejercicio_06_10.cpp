// Materia: Programación I, Paralelo 4
// Autor: Carlos Adrian Guachalla Quispe
// Carnet: 9918131 L.P.
// Carrera del estudiante: Ingeniería Mecatrónica
// Fecha creación: 8/10/2025
// Número de ejercicio: 10
#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main() {
    string cadena, resultado;
    int i;
    cout<<"Ingrese una cadena: ";
    cin>>cadena;
    resultado = "";
    for(i=0;i<cadena.size();i++){
        if(!(cadena[i] >= '0' && cadena[i] <= '9')){//en caso de hallar numeros los elimina de la cadena 
            resultado += cadena[i];
        }
    }
    cout<<"Cadena sin digitos: "<<resultado;
    return 0;
}
