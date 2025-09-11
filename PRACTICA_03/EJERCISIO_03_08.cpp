//Materia:Programación I, Paralelo 4
//Autor:Carlos Adrian Guachalla Quispe
//Fecha creación:07/09/2025
//Número de ejercicio:8
#include<iostream>
using namespace std;
int calcular(int &monto,int valor){//con &monto nos aseguramos que el valor vaya bajando despues de cada prueba
    int cantidad=monto/valor;
    monto-=cantidad*valor;
    return cantidad;
}
int main(){
    int monto=0, c1=0,c2=0,c5=0,c10=0,c20=0,c50=0,c100=0,c200=0;
    cout<<"Ingrese un monto:";
    cin>>monto;
    c200=calcular(monto,200);
    c100=calcular(monto,100);
    c50=calcular(monto,50);
    c20=calcular(monto,20);
    c10=calcular(monto,10);
    c5=calcular(monto,5);
    c2=calcular(monto,2);
    c1=calcular(monto,1);
    cout<<"Desglose del monto:\n";
    cout<<"Billetes de 200:"<<c200<<endl;
    cout<<"Billetes de 100:"<<c100<<endl;
    cout<<"Billetes de 50:"<<c50<<endl;
    cout<<"BIllete de 20:"<<c20<<endl;
    cout<<"Billetes de 10:"<<c10<<endl;
    cout<<"Monedas de 5:"<<c5<<endl;
    cout<<"Monedas de 2:"<<c2<<endl;
    cout<<"Monedas de 11:"<<c1<<endl;
    return 0;
}
