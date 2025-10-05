// Materia: Programación I, Paralelo 4
// Autor: Carlos Adrian Guachalla Quispe
// Carnet: 9918131 L.P.
// Carrera del estudiante: Ingeniería Mecatrónica
// Fecha creación: 2/10/2025
// Número de ejercicio: 6
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int i;
    vector<int>vector1(5),vector2(5),vector3(5);//declaramos los 3 vectores con espacio para 5 enteros
    cout<<"Ingrese los elementos de vector1:"<<endl;
    for(i=0;i<5;i++){
        cin>>vector1[i];
    }
    cout<<"Ingrese los elementos de vector2:"<<endl;
    for(i=0;i<5;i++){
        cin>>vector2[i];
    }
    for(i=0;i<5;i++){//sumamos los valores del vector en posicion i para vector 3
        vector3[i]=vector1[i]+vector2[i];
    }
    cout<<"El vector3 resultante es:"<<endl;
    for(i=0;i<5;i++){
        cout<<vector3[i]<<" ";
    }
    return 0;
}
