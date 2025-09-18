// Materia: Programación I, Paralelo 4
// Autor: Carlos Adrian Guachalla Quispe
// Carnet: 9918131 L.P.
// Carrera del estudiante: Ingeniería Mecatrónica
// Fecha creación: 14/09/2025
// Número de ejercicio: 8
#include <iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
float IVA(int sumvalores){
    return (sumvalores*0.13);
}
int main() {
    int productosv=0, valor=0, sumvalor=0;
    srand(time(0)); // ponemos una semilla
    cout<<"Ingrese la cantidad de productos vendidos: ";
    cin>>productosv;
    for (int i=0; i<productosv; i++){
        valor=rand()%(50-20+1)+20; // Genera un número entre 20 y 50
        sumvalor+=valor;
    }
    cout<<"El total en valor de todo lo obtenido es: "<<sumvalor<<endl;
    if (sumvalor<=2500){
        cout<<"El RC IVA del 13% a pagar es: "<<IVA(sumvalor)<<endl;
        cout<<"El total del valor descontado el RC IVA del 13% es: "<<sumvalor-IVA(sumvalor)<<endl;
    }
    else{
        cout<<"El total en valor de todo lo obtenido es(Aplicado el descuento del 5% por exceder 2500): "<<sumvalor*0.95<<endl;
        cout<<"El RC IVA del 13% a pagar es(Aplicado el descuento del 5% por exceder 2500): "<<IVA(sumvalor)*0.95<<endl;
        cout<<"El total del valor descontado el RC IVA del 13% es(Aplicado el descuento del 5% por exceder 2500): "<<(sumvalor-IVA(sumvalor))*0.95<<endl;
    }
    
}