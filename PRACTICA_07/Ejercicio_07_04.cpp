// Materia: Programación I, Paralelo 4
// Autor: Carlos Adrian Guachalla Quispe
// Carnet: 9918131 L.P.
// Carrera del estudiante: Ingeniería Mecatrónica
// Fecha creación: 15/10/2025
// Número de ejercicio: 4
#include <iostream>
#include <vector>
using namespace std;
void GenerarMatriz(int matriz[100][100], int orden){//esta funcion genera la matriz sumando 2 despues de cada columna
    int num=1, num2=0;
    cout<<"Matriz generada:"<<endl;
    for(int i=0;i<orden;i++){
        for(int j=0;j<orden;j++){
            matriz[i][j]=num+num2;
            cout<<matriz[i][j]<<" ";
            num++;
        }
        cout<<endl;
        num2+=2;
        num=1;
    }
}
int main(){
    int matriz[100][100];
    int orden;
    cout<<"Ingrese el orden de la matriz cuadrada: ";
    cin>>orden;
    GenerarMatriz(matriz,orden);
}