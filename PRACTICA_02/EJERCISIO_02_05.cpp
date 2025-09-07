// Materia: Programación I, Paralelo 4
// Autor: Carlos Adrian Guachalla Quispe
// Carnet: 9918131 L.P.
// Carrera del estudiante: Ingeniería Mecatrónica
// Fecha creación: 07/09/2025
// Número de ejercicio: 5
#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
int main(){
    float numero=0, contador=0, nrepeticiones=0, suma=0, max=1000, min=0;
    srand(time(0)); // ponemos una semilla
    cout<<"Ingrese un numero de repeticiones: ";
    cin>>nrepeticiones;
    for(contador=0; contador<nrepeticiones; contador++){
        numero = rand() % 1000 + 1; // Genera un número entre 1 y 1000
        cout<<numero<<", ";
        suma=suma+numero;
        if(max>=numero){
            max=numero;
        }
        if(min<=numero){
            min=numero;
        }     
    }
    cout<<endl<<"La suma de todos los numeros es: "<<suma<<endl;
    cout<<"El promedio de la suma de todos los numeros es: "<<suma/nrepeticiones<<endl;
    cout<<"El mayor numero aleatorio es: "<<min<<endl;
    cout<<"El menor numero aleatorio es: "<<max<<endl;
    return 0;
}