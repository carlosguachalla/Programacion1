// Materia: Programación I, Paralelo 4
// Autor: Carlos Adrian Guachalla Quispe
// Carnet: 9918131 L.P.
// Carrera del estudiante: Ingeniería Mecatrónica
// Fecha creación: 8/10/2025
// Número de ejercicio: 4
#include <iostream>
#include <vector>
#include <cmath>
#include <string>
using namespace std;
int main(){
    int valor, numrota, ultimo;
    vector<int> num;
    cout<<"Ingrese edades (para terminar coloque -1): "<<endl;
    do{
        cin>>valor;
        if(valor!=-1){
            num.push_back(valor);
        }
    }while(valor!=-1);
    cout<<"Menciona cuantas veces a la derecha rotaran los numeros: ";
    cin>>numrota;
    for(int i=0; i<numrota; i++){
        ultimo = num.back();//guarda el valor del ultimo
        num.pop_back(); //elimina el ultimo numero
        num.insert(num.begin(),ultimo);//inserta numero
    }
    cout<<"Vector rotado: ";
    for(int i=0; i<num.size(); i++){
        cout<<num[i]<<" ";
    }
    cout<<endl;
}
