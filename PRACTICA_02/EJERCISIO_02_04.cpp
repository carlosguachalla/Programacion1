// Materia: Programación I, Paralelo 4
// Autor: Carlos Adrian Guachalla Quispe
// Carnet: 9918131 L.P.
// Carrera del estudiante: Ingeniería Mecatrónica
// Fecha creación: 07/09/2025
// Número de ejercicio: 4
#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
int main(){
    int naleatorio=0, contador=0, min=0, max=50, numero=100;
    srand(time(0)); // ponemos una semilla
    naleatorio = rand() % 51; // Genera un número entre 0 y 50
    for (contador = 0; contador<5; contador++){
        if (naleatorio!=numero){
            cout<<"El numero esta entre "<<min<<" y "<<max<<endl;
            cin>>numero;
            if(numero<naleatorio&&numero>min){//coloca el nuevo minimo de rango
                min=numero;
            }
            else if(numero>naleatorio&&numero<max){//coloca el nuevo maximo de rango
                max=numero;
            }
        }
        else if(numero==naleatorio){
            cout<<"Encontraste el numero aleatorio"<<endl;
            contador=5;
        }
    }
    if (numero!=naleatorio){
        cout<<"Se acabaron los intentos el numero era"<<endl;
        cout << naleatorio <<endl;
    }
    else if(numero==naleatorio&&contador==5){
        cout<<"Encontraste el numero aleatorio"<<endl;
    }
    return 0;
}