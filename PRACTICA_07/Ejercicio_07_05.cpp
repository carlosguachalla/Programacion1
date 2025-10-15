// Materia: Programación I, Paralelo 4
// Autor: Carlos Adrian Guachalla Quispe
// Carnet: 9918131 L.P.
// Carrera del estudiante: Ingeniería Mecatrónica
// Fecha creación: 15/10/2025
// Número de ejercicio: 5
#include <iostream>
#include <vector>
using namespace std;
void Multiplicacion(int matriz1[100][100],int matriz2[100][100],int valor1,int valor2){//esta funcion realiza la multiplicacion de las matrices
    int resultado[100][100];
    cout<<"Matriz resultante de la multiplicacion:"<<endl;
    for(int i=0;i<valor1;i++){    
        for(int j=0;j<valor1;j++){
            resultado[i][j]=0;
            for(int k=0;k<valor2;k++){
                resultado[i][j]+=matriz1[i][k]*matriz2[k][j];
            }
            cout<<resultado[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main(){
    int valor1, valor2;
    int matriz1[100][100],matriz2[100][100];
    cout<<"Ingrese el numero de filas y del otro columnas de las matrices: ";
    cin>>valor1;//valor1 es filas de la primera matriz y columnas de la segunda
    cout<<"Ingrese el numero de columnas y del otro filas de las matrices: ";
    cin>>valor2;//valor2 es columnas de la primera matriz y filas de la segunda
    cout<<"Ingrese los elementos de la primera matriz:"<<endl;
    for(int i=0;i<valor1;i++){    
        for(int j=0;j<valor2;j++){
            cin>>matriz1[i][j];
        }
    }
    cout<<"Ingrese los elementos de la segunda matriz:"<<endl;
    for(int i=0;i<valor2;i++){    
        for(int j=0;j<valor1;j++){
            cin>>matriz2[i][j];
        }
    }
    cout<<"Primera matriz:"<<endl;
    for(int i=0;i<valor1;i++){  
        for(int j=0;j<valor2;j++){
            cout<<matriz1[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"Segunda matriz:"<<endl;
    for(int i=0;i<valor2;i++){  
        for(int j=0;j<valor1;j++){
            cout<<matriz2[i][j]<<" ";
        }
        cout<<endl;
    }
    Multiplicacion(matriz1,matriz2,valor1,valor2);
}