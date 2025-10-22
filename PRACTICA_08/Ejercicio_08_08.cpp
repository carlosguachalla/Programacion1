// Materia: Programación I, Paralelo 4
// Autor: Carlos Adrian Guachalla Quispe
// Carnet: 9918131 L.P.
// Carrera del estudiante: Ingeniería Mecatrónica
// Fecha creación: 22/10/2025
// Número de ejercicio: 7
#include <iostream>
#include <vector>
using namespace std;
int llevarauno(int n){
    if (n == 1){ // Caso base
        return 0;
    } else if (n%2==0){ // Si n es par
        cout<<n/2<<"     ";
        return llevarauno(n/2);//de ser par llama recursivamente con n/2
    }
    else{
        cout<<(n*3)+1<<"     ";
        return llevarauno(n*3+1);//de ser impar llama recursivamente con n*3+1
    }
}
int main(){
    int numero, resultado;
    cout<<"Ingrese un número entero: ";
    cin>>numero;
    cout<<numero<<"     ";
    resultado=llevarauno(numero);
    return 0;
}