// Materia: Programación I, Paralelo 4
// Autor: Carlos Adrian Guachalla Quispe
// Carnet: 9918131 L.P.
// Carrera del estudiante: Ingeniería Mecatrónica
// Fecha creación: 15/10/2025
// Número de ejercicio: 1
#include <iostream>
using namespace std;

// Función para intercambiar la Fila 1 (índice 0) por la Fila n (índice filas-1)
// NOTA: Se realiza la modificación 'in-place' (sobre la matriz original)
// o se usa una matriz 'destino' si se quiere preservar la original.
// Siguiendo la lógica del código anterior, usaremos una matriz destino.
void IntercambiarFila1PorFilan(int matrizOrigen[100][100], int matrizDestino[100][100], int filas, int columnas) {
    int indiceUltimaFila = filas - 1;
    
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            if (i == 0) {// La Fila 1 (índice 0) recibe el contenido de la última fila
                matrizDestino[0][j] = matrizOrigen[indiceUltimaFila][j];
            } else if (i == indiceUltimaFila) {// La Última Fila (índice n-1) recibe el contenido de la Fila 1
                matrizDestino[indiceUltimaFila][j] = matrizOrigen[0][j];
            } else {// Las filas intermedias se copian sin cambios
                matrizDestino[i][j] = matrizOrigen[i][j];
            }
        }
    }
}

void MostrarMatriz(int matriz[100][100], int filas, int columnas) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            cout<<matriz[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main() {
    int n; //Usaremos 'n' como variable para filas y columnas ya que es una matriz n x n
    int matriz[100][100];
    int matrizcambiada[100][100];
    int filas,columnas;
    cout<<"Ingrese el orden de la matriz (n):";
    cin>>n;
    filas=n;
    columnas=n;
    cout<<"Ingrese los elementos de la matriz:"<<endl;
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            cin>>matriz[i][j];
        }
    }
    cout<<endl<<"Matriz original:"<<endl;
    MostrarMatriz(matriz, filas, columnas);
    IntercambiarFila1PorFilan(matriz, matrizcambiada, filas, columnas);
    cout<<"Matriz con Fila 1 y Fila "<<n<<" intercambiadas:"<<endl;
    MostrarMatriz(matrizcambiada, filas, columnas);   
    return 0;
}