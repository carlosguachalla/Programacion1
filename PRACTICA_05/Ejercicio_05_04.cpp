// Materia: Programación I, Paralelo 4
// Autor: Carlos Adrian Guachalla Quispe
// Carnet: 9918131 L.P.
// Carrera del estudiante: Ingeniería Mecatrónica
// Fecha creación: 2/10/2025
// Número de ejercicio: 4
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int N;
    vector<int> A,B,C;
    cout<<"Ingrese el tamaño de los vectores: ";
    cin>>N;
    A.resize(N);//con resize se puede definir nuevamente el tamano de los vectores
    B.resize(N);
    C.resize(N);
    cout<<"Ingrese los elementos del vector A:"<<endl;
    for(int i=0;i<N;i++){
        cin>>A[i];
    }
    cout<<"Ingrese los elementos del vector B:"<<endl;
    for(int j=0;j<N;j++){
        cin>>B[j];
    }
    for(int k=0;k<N;k++){//multiplica los valores de A Y B en k posicion y es el valor k de C
        C[k]=A[k]*B[k];
    }
    cout<<"El vector resultante C es:"<<endl;
    for(int l=0;l<N;l++){
        cout<<C[l]<<" ";
    }
    return 0;
}
