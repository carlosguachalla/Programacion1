// Materia: Programación I, Paralelo 4
// Autor: Carlos Adrian Guachalla Quispe
// Carnet: 9918131 L.P.
// Carrera del estudiante: Ingeniería Mecatrónica
// Fecha creación: 22/10/2025
// Número de ejercicio: 6
#include <iostream>
#include <vector>
using namespace std;
bool IgualdadVectores(const vector<int> &vec1, const vector<int> &vec2, int n){
    if (n == 0){ // Caso base
        return true;
    } else {
        if (vec1[n - 1] != vec2[n - 1]){
            return false;//si los elementos no son iguales retorna false y acabaa la recursion
        } else {
            return IgualdadVectores(vec1, vec2, n - 1);//en caso contrario llama recursivamente con n-1
        }
    }
}
int main(){
    vector<int> vec1, vec2;
    int n;
    bool sonIguales=false;
    cout<<"Ingrese el tamaño de los vectores: ";
    cin>>n;
    vec1.resize(n);
    vec2.resize(n);
    for (int i = 0; i < n; i++){
        cout<<"Ingrese el elemento "<<i+1<<" del primer vector: ";
        cin>>vec1[i];
    }
    for (int j = 0; j < n; j++){
        cout<<"Ingrese el elemento "<<j+1<<" del segundo vector: ";
        cin>>vec2[j];
    }
    sonIguales = IgualdadVectores(vec1, vec2, n);
    if (sonIguales==true){
        cout<<"Los vectores son iguales.";
    } else {
        cout<<"Los vectores no son iguales.";
    }
    
}