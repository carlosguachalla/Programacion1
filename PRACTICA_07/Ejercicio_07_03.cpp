// Materia: Programación I, Paralelo 4
// Autor: Carlos Adrian Guachalla Quispe
// Carnet: 9918131 L.P.
// Carrera del estudiante: Ingeniería Mecatrónica
// Fecha creación: 15/10/2025
// Número de ejercicio: 3
#include <iostream>
#include <vector>
using namespace std;
void MostrarMatriz(char matriz[3][4],int filas,int columnas){//esta funcion muestra la matriz
    cout<<"a) Mostrar matriz"<<endl;
    for(int i=0;i<filas;i++){
        for(int j=0;j<columnas;j++){
            cout<<matriz[i][j]<<" ";
        }
        cout<<endl;
    }
}
void FilasColumnasLibres(char matriz[3][4],int filas,int columnas,int &filaslibres,int &columnaslibres){//esta funcion cuenta las filas y columnas libres
    filaslibres=0;
    columnaslibres=0;
    bool tieneX;
    for(int i=0;i<filas;i++){
        tieneX=false;
        for(int j=0;j<columnas;j++){
            if(matriz[i][j]=='x'){tieneX=true;}
        }
        if(!tieneX)filaslibres++;
    }
    for(int j=0;j<columnas;j++){
        tieneX=false;
        for(int i=0;i<filas;i++){
            if(matriz[i][j]=='x'){tieneX=true;}
        }
        if(!tieneX)
            columnaslibres++;
    }
    cout<<"b) Filas libres: "<<filaslibres<<endl;
    cout<<"   columnas libres: "<<columnaslibres<<endl;
}
void CoordenadasMuertos(char matriz[3][4],int filas,int columnas,vector<int> &filasMuertos,vector<int> &columnasMuertos){//esta funcion guarda las coordenadas de los muertos vivientes
    cout<<"c) Posiciones en la matriz:"<<endl;
    for(int i=0;i<filas;i++){
        for(int j=0;j<columnas;j++){
            if(matriz[i][j]=='x'){
                filasMuertos.push_back(i);
                columnasMuertos.push_back(j);
                cout<<i<<" - "<<j<<endl;
            }
        }
    }
}
int ContarMuertos(char matriz[3][4],int filas,int columnas){//esta funcion cuenta los muertos vivientes
    int total=0;
    for(int i=0;i<filas;i++){
        for(int j=0;j<columnas;j++){
            if(matriz[i][j]=='x')total++;
        }
    }
    cout<<"d) Total muertos vivientes: "<<total<<endl;
    return total;
}
void VerificarEntrada(char matriz[3][4], int filas, int columnas){//esta funcion verifica si es posible entrar al complejo
    int cont = 0;
    for(int j = 0; j < columnas; j++){
        if(matriz[0][j] == 'x')
            cont++;
    }
    if(cont >= 2)
        cout<<"e) No es posible entrar al complejo"<< endl;
    else
        cout<<"e) Es posible entrar al complejo"<< endl;
}
void EspacioLibre(char matriz[3][4],int filas,int columnas){//esta funcion cuenta los espacios libres
    int libres=0;
    for(int i=0;i<filas;i++){
        for(int j=0;j<columnas;j++){
            if(matriz[i][j]=='o')libres++;
        }
    }
    cout<<"f) Espacios libres: "<<libres<<endl;
}
int main(){
    int filas=3,columnas=4;
    char matriz[3][4]={{'x','o','x','o'},
                       {'o','o','o','o'},
                       {'o','o','x','o'}};
    vector<int> filasMuertos;
    vector<int> columnasMuertos;
    int filaslibres,columnaslibres;
    MostrarMatriz(matriz,filas,columnas);
    FilasColumnasLibres(matriz,filas,columnas,filaslibres,columnaslibres);
    CoordenadasMuertos(matriz,filas,columnas,filasMuertos,columnasMuertos);
    ContarMuertos(matriz,filas,columnas);
    VerificarEntrada(matriz, filas, columnas);
    EspacioLibre(matriz,filas,columnas);
}