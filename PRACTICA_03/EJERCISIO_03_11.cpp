//Materia:Programación I, Paralelo 4
//Autor:Carlos Adrian Guachalla Quispe
//Fecha creación:07/09/2025
//Número de ejercicio:11
#include<iostream>
using namespace std;
double retirarDinero(double saldo,double cantidad){
    if(cantidad>saldo){ //verifica saldo suficiente
        cout<<"Saldo insuficiente"<<endl;
        return saldo;
    }
    if((int)cantidad%10!=0){ //verifica múltiplo de 10
        cout<<"Monto debe ser múltiplo de 10"<<endl;
        return saldo;
    }
    saldo-=cantidad; //retiro válido, actualiza saldo
    cout<<"Retiro exitoso:"<<cantidad<<" Bs"<<endl;
    return saldo; //devuelve nuevo saldo
}
int main(){
    double saldo=1000,cantidad=0;
    cout<<"Ingrese monto a retirar:";
    cin>>cantidad;
    saldo=retirarDinero(saldo,cantidad); 
    cout<<"Saldo actual:"<<saldo<<" Bs"<<endl; //muestra saldo actualizado
    return 0;
}
