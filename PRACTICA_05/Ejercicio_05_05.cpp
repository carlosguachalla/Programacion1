// Materia: Programación I, Paralelo 4
// Autor: Carlos Adrian Guachalla Quispe
// Carnet: 9918131 L.P.
// Carrera del estudiante: Ingeniería Mecatrónica
// Fecha creación: 2/10/2025
// Número de ejercicio: 5
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int N,i;
    vector<int>A,B,C;
    cout<<"Ingrese el tamaño de los vectores: ";
    cin>>N;
    A.resize(N);
    B.resize(N);
    cout<<"Ingrese los elementos del vector A:"<<endl;
    for(i=0;i<N;i++){
        cin>>A[i];
    }
    cout<<"Ingrese los elementos del vector B:"<<endl;
    for(i=0;i<N;i++){
        cin>>B[i];
    }
    C.resize(2*N);
    for(i=0;i<N;i++){//se coloca los valores del primer vector
        C[i]=A[i];
    }
    for(i=0;i<N;i++){//esto con el tamano de N + el valor de i para seguir colocando valores y no sobreescribir encima
        C[N+i]=B[i];
    }
    cout<<"El vector combinado C es:"<<endl;
    for(i=0;i<2*N;i++){
        cout<<C[i]<<" ";
    }
    return 0;
}
