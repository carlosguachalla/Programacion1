// Materia: Programación I, Paralelo 4
// Autor: Carlos Adrian Guachalla Quispe
// Carnet: 9918131 L.P.
// Carrera del estudiante: Ingeniería Mecatrónica
// Fecha creación: 07/09/2025
// Número de ejercicio: 1
#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
int main(){
    int dado=0, contador=0, nrepeticiones=0, npares=0;
    srand(time(0)); // ponemos una semilla
    cout<<"Ingrese un numero de repeticiones a lanzar el dado: ";
    cin>>nrepeticiones;
    for(contador=0; contador<nrepeticiones; contador++){
        dado = rand() % 6 + 1; // Genera un número entre 1 y 6
        cout << dado <<", ";
        if(dado%2==0){
            npares++;
        }
    }
    cout<<endl<<"De "<<nrepeticiones<<" lanzamientos de dado, "<<npares<<" salieron pares"<<endl;
    cout<<npares<<"/"<<nrepeticiones<<" lanzamientos son pares";
    return 0;
}