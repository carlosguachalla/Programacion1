// Materia: Programación I, Paralelo 4
// Autor: Carlos Adrian Guachalla Quispe
// Carnet: 9918131 L.P.
// Carrera del estudiante: Ingeniería Mecatrónica
// Fecha creación: 04/09/2025
// Número de ejercicio: 19
#include<iostream>
using namespace std;
int main(){
    int num=0, tabla=0, numtabla=0;
    cout<<"Introduce un numero: ";
    cin>>num;
    for(tabla=1;tabla<=10;tabla++){//con este for hacemos la tabla de una sola vez y no se hace uno por uno la multiplicacion
        cout<<tabla<<"x"<<num<<"="<<tabla*num<<endl;
    }
}