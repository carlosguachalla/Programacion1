// Materia: Programación I, Paralelo 4
// Autor: Carlos Adrian Guachalla Quispe
// Fecha creación: 07/09/2025
// Número de ejercicio: 6
#include <iostream>
using namespace std;
int diasMA(int month, int year) {
    int dias;
    if (year%4==0&&month==2)//verifica si el año es biciestro ya que los años biciestros son multiplos de 4
        dias=29;
    if (year%4!=0&&month==2)//en caso de que no sea ell caso
        dias=28;
    if (month==1||month==4||month==6||month==8||month==10||month==12)
        dias=31;
    if (month==3||month==5||month==7||month==9||month==11)
        dias=30;
    return dias;
}
int main(){
    int month=0, year=0;
    cout<<"Ingrese un mes: ";
    cin>>month;
    cout<<"Ingrese un año: ";
    cin>>year;
    cout<<"El mes tiene "<<diasMA(month,year)<<" dias";
}