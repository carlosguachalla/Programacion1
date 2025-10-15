// Materia: Programación I, Paralelo 4
// Autor: Carlos Adrian Guachalla Quispe
// Carnet: 9918131 L.P.
// Carrera del estudiante: Ingeniería Mecatrónica
// Fecha creación: 15/10/2025
// Número de ejercicio: 6
#include <iostream>
#include <vector>
using namespace std;
void MatrizTranspuesta(int matriz[100][100], int matrizTranspuesta[100][100], int filas, int columnas){//esta funcion realiza la transposicion de la matriz
    cout<<"Matriz transpuesta:"<<endl;
    for(int i=0;i<filas;i++){    
        for(int j=0;j<columnas;j++){
            matrizTranspuesta[j][i]=matriz[i][j];//intercambiamos filas por columnas
        }
    }
    for(int i=0;i<columnas;i++){  
        for(int j=0;j<filas;j++){
            cout<<matrizTranspuesta[i][j]<<" ";//mostramos la matriz transpuesta
        }
        cout<<endl;
    }
}
int main(){
    int filas, columnas;
    int matriz[100][100], matrizTranspuesta[100][100];
    cout<<"Ingrese el numero de filas de la matriz: ";
    cin>>filas;
    cout<<"Ingrese el numero de columnas de la matriz: ";
    cin>>columnas;
    cout<<"Ingrese los elementos de la matriz:"<<endl;
    for(int i=0;i<filas;i++){    
        for(int j=0;j<columnas;j++){
            cin>>matriz[i][j];
        }
    }
    cout<<"Matriz original:"<<endl;
    for(int i=0;i<filas;i++){  
        for(int j=0;j<columnas;j++){
            cout<<matriz[i][j]<<" ";
        }
        cout<<endl;
    }
    MatrizTranspuesta(matriz, matrizTranspuesta, filas, columnas);
}