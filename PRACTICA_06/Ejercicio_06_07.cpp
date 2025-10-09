// Materia: Programación I, Paralelo 4
// Autor: Carlos Adrian Guachalla Quispe
// Carnet: 9918131 L.P.
// Carrera del estudiante: Ingeniería Mecatrónica
// Fecha creación: 8/10/2025
// Número de ejercicio: 7
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;
int main(){
    srand(time(0));
    int n,i,valor,indice;
    vector<int> imagen;
    vector<int> conteo(26,0);
    vector<string> rangos;
    for(i=0;i<26;i++){
        rangos.push_back(to_string(i*10) + "-" + to_string(i*10+9));//con esto hago que los rangos sean de una vez creados(un problema que tiene es que el ultimo rango supera 255)
    }
    cout<<"Ingrese la cantidad de pixeles: ";
    cin>>n;
    for(i=0;i<n;i++){//genera aleatorios del 256
        valor=rand() % 256;
        imagen.push_back(valor);
        indice=valor/10;
        if(indice>25){indice=25;}
        conteo[indice]++;
    }
    cout<<"Valores generados:"<<endl;
    for(i=0;i<imagen.size();i++){
        cout<<imagen[i]<<" ";
    }
    cout<<"Cantidad de pixeles por rango:"<<endl;
    for(i=0;i<26;i++){
        cout<<rangos[i]<<": "<<conteo[i]<<endl;
    }
    return 0;
}