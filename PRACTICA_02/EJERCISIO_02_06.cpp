// Materia: Programación I, Paralelo 4
// Autor: Carlos Adrian Guachalla Quispe
// Carnet: 9918131 L.P.
// Carrera del estudiante: Ingeniería Mecatrónica
// Fecha creación: 07/09/2025
// Número de ejercicio: 6
#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
int main(){
    int numero=0, contador=0, nrepeticiones=0, primo=0, nprimo=0;
    srand(time(0)); // ponemos una semilla
    cout<<"Ingrese un numero de repeticiones: ";
    cin>>nrepeticiones;
    for(contador=0; contador<nrepeticiones; contador++){
        numero=rand() % 10000 + 1; // Genera un número entre 1 y 10000
        cout<<numero<<", ";
        for (int i=1; i<=numero; i++){
            if (numero%i==0){
                primo++;
            }
        }
        if (primo==2){//con esto si hay un numero primo se aumenta a la suma
            nprimo++;
        }
        primo=0;
    }
    cout<<endl<<"Hay "<<nprimo<<" numeros primos en los numeros aleatorios";
    return 0;
}