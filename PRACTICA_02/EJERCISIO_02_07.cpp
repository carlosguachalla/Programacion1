// Materia: Programación I, Paralelo 4
// Autor: Carlos Adrian Guachalla Quispe
// Carnet: 9918131 L.P.
// Carrera del estudiante: Ingeniería Mecatrónica
// Fecha creación: 07/09/2025
// Número de ejercicio: 7
#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
int main(){
    int numero=0, contador=0, nrepeticiones=0, n1=0, n2=0, n3=0;
    srand(time(0)); // ponemos una semilla
    cout<<"Ingrese un numero de repeticiones: ";
    cin>>nrepeticiones;
    nrepeticiones=rand() % nrepeticiones + 1; 
    for(contador=0; contador<nrepeticiones; contador++){
        numero=rand() % 3 + 1; // Genera un número entre 1 y 3
        cout<<numero<<", ";
        switch (numero){
        case (1):
            n1++;
        break;
        case (2):
            n2++;
        break;
        case (3):
            n3++;
        break;
        }
    }
    cout<<endl<<"Numero total de niños: "<<n1+n2+n3<<endl;
    cout<<"Niños de 1 año: "<<n1<<endl;
    cout<<"Niños de 2 años: "<<n2<<endl;
    cout<<"Niños de 3 años: "<<n3<<endl;
    cout<<"Numero total de pañales usados: "<<n1*6+n2*3+n3*2<<endl;
    return 0;
}