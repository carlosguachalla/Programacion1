//Materia:Programación I, Paralelo 4
//Autor:Carlos Adrian Guachalla Quispe
//Fecha creación:07/09/2025
//Número de ejercicio:10
#include<iostream>
using namespace std;
double calcularTarifa(double km){
    double total=10+2*km; //tarifa base 10 Bs + 2 Bs por km
    if(km>10) 
        total=total*0.9; //descuento 10% si km>10
    return total;
}
int main(){
    double km=0;
    cout<<"Ingrese km recorridos:";
    cin>>km; 
    cout<<"Precio del viaje:"<<calcularTarifa(km)<<" Bs"<<endl;
    return 0;
}
