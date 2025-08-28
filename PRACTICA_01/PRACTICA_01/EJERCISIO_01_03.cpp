// Materia: Programación I, Paralelo 4
// Autor: Carlos Adrian Guachalla Quispe
// Carnet: 9918131 L.P.
// Carrera del estudiante: Ingeniería Mecatronica
// Fecha creación: 27/08/2025
// Número de ejercicio: 3
#include <iostream>
using namespace std;
int main() {
    float altura=0, base=0, area=0;
    cout<<"Ingrese la altura del triangulo: ";
    cin>>altura;
    cout<<"Ingrese la base del triangulo: ";
    cin>>base;
    area=0.5*altura*base;//formula del area del triangulo, con 0.5 para que no se confunda usando 1/2
    cout<<"el area del triangulo es: "<<area<<endl;
    return 0;
}
//En este programa declaramos la variable con float, esto para que el programa lo tome su valor con el decimal
//asi que en caso de querer colocar valores a la altura, base o el mismo resultado del area sea un numero con
//decimal este lo acepte como es y entregue un resultado con decimal si es ese el caso


