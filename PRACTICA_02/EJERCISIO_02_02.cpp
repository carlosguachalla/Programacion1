// Materia: Programación I, Paralelo 4
// Autor: Carlos Adrian Guachalla Quispe
// Carnet: 9918131 L.P.
// Carrera del estudiante: Ingeniería Mecatrónica
// Fecha creación: 07/09/2025
// Número de ejercicio: 2
#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
int main(){
    int moneda=0, contador=0;
    float cara=0, cruz=0, nrepeticiones=0;
    srand(time(0)); // ponemos una semilla
    cout<<"Ingrese un numero de repeticiones a lanzar una moneda: ";
    cin>>nrepeticiones;
    for(contador=0; contador<nrepeticiones; contador++){
        moneda = rand() % 2 + 1; // Genera un número entre 1 y 2
        if(moneda==2){
            cara++;
            cout<<"cara, ";
        }
        else if(moneda==1){
            cruz++;
            cout<<"cruz, ";
        }
    }
    cout<<endl<<"El "<<(cara/nrepeticiones)*100<<"% de las pruebas salio cara";
    cout<<endl<<"El "<<(cruz/nrepeticiones)*100<<"% de las pruebas salio cruz";
    return 0;
}