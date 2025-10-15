// Materia: Programación I, Paralelo 4
// Autor: Carlos Adrian Guachalla Quispe
// Carnet: 9918131 L.P.
// Carrera del estudiante: Ingeniería Mecatrónica
// Fecha creación: 15/10/2025
// Número de ejercicio: 2
#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <cmath>
using namespace std;
void SumaUltimaColumna(int matriz[100][100], int filas, int columnas, int &suma){//funcion con la suma de la ultima columna
    for (int i = 0; i < filas; i++){
        suma+=matriz[i][columnas-1];
    }
}
void MultiplicacionUltimaFila(int matriz[100][100], int filas, int columnas, int &multiplicacion){//funcion con la multiplicacion de la ultima fila
    for (int j = 0; j < columnas; j++){
        multiplicacion*=matriz[filas-1][j];
    }
}
int main(){
    srand(time(0));
    int filas, columnas, suma = 0, multiplicacion = 1, mayorf, mayorc, mayor = 0, elementos = 0;
    float media, desviacionstandard=0.0, sumacuadrados=0.0;
    int matriz[100][100];
    cout<<"Ingrese el numero de filas de la matriz: ";
    cin>>filas;
    cout<<"Ingrese el numero de columnas de la matriz: ";
    cin>>columnas;
    for (int i = 0; i < filas; i++){
        for (int j = 0; j < columnas; j++){
            matriz[i][j]=rand()%100+1;// Números aleatorios entre 1 y 100
            if (matriz[i][j]>mayor){
                mayor=matriz[i][j];
                mayorf=i;
                mayorc=j;
            }
            elementos+=matriz[i][j];
        }
    }
    cout<<"Matriz generada aleatoriamente:"<<endl;
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            cout<<matriz[i][j]<<" ";
        }
        cout<<endl;
    }
    media=elementos/(filas*columnas);
    for (int i = 0; i < filas; i++){
        for (int j = 0; j < columnas; j++) {
            sumacuadrados+=pow(matriz[i][j]-media,2);
        }
    }
    desviacionstandard=sqrt(sumacuadrados/(filas * columnas));//usamos sqrt para elevar a la raiz cuadrada
    cout<<"La suma de los elementos de la ultima columna es: "<<suma<<endl;
    cout<<"La multiplicacion de los elementos de la ultima fila es: "<<multiplicacion<<endl;
    cout<<"El mayor elemento de la matriz es: "<<mayor<<" y se encuentra en la fila "<<mayorf+1<<" y columna "<<mayorc+1<<endl;
    cout<<"La media de todos los elementos de la matriz es: "<<media<<endl;
    cout<<"La desviacion estandar de todos los elementos de la matriz es: "<<desviacionstandard<<endl;
}