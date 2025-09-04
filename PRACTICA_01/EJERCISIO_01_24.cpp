// Materia: Programación I, Paralelo 4
// Autor: Carlos Adrian Guachalla Quispe
// Carnet: 9918131 L.P.
// Carrera del estudiante: Ingeniería Mecatrónica
// Fecha creación: 04/09/2025
// Número de ejercicio: 24
#include<iostream>
using namespace std;
int main(){
    int num1=0, contador=0, resp=0;
    do{
        cout<<"1. Opcion1"<<endl;
        cout<<"2. Opcion2"<<endl;
        cout<<"3. Opcion3"<<endl;
        cout<<"0. Salir"<<endl;
        cin>>resp;//aqui hay que introducir algun numero entre el 0 y el 3 caso contrario no mostrara nada
        if(resp==1){
        cout<<"Seleccionaste Opcion1"<<endl;
        }
        if(resp==2){
        cout<<"Seleccionaste Opcion2"<<endl;
        }
        if(resp==3){
        cout<<"Seleccionaste Opcion3"<<endl;
        }
        
    } while (resp!=0);//se opto por un do while porque el numero sera pedido indefinidamente
    
}