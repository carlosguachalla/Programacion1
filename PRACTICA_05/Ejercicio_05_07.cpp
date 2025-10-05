// Materia: Programación I, Paralelo 4
// Autor: Carlos Adrian Guachalla Quispe
// Carnet: 9918131 L.P.
// Carrera del estudiante: Ingeniería Mecatrónica
// Fecha creación: 2/10/2025
// Número de ejercicio: 7
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int i,num,contador=0;
    vector<int>v(10);
    cout<<"Ingrese hasta 10 numeros (negativo para detener):"<<endl;
    for(i=0;i<10;i++){
        cin>>num;
        if(num>=0){//con este if de ser negativo hace que directamente el bucle acabe ya que el contador sube a 10
            v[i]=num;
            contador++;
        }else{
            i=10;
        }
    }
    cout<<"Elementos ingresados:"<<endl;
    for(i=0;i<contador;i++){//muestra los valores del vector del 1 al 10, si hubo negativp no muestra nada
        cout<<v[i]<<" ";
    }
    return 0;
}
