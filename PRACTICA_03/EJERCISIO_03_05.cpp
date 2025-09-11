// Materia: Programación I, Paralelo 4
// Autor: Carlos Adrian Guachalla Quispe
// Fecha creación: 07/09/2025
// Número de ejercicio: 5
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
float prompon(int num1, int num2, int num3, int num4) {
    float promponde;
    promponde=(num1*10+num2*20+num3*30+num4*40)/100.0; // denominador = 10+20+30+40
    return promponde;
}
int main(){
    int num1=0, num2=0, num3=0, num4=0;
    srand(time(0)); // semilla para aleatorios
    num1 = rand() % 100 + 1; 
    num2 = rand() % 100 + 1; 
    num3 = rand() % 100 + 1; 
    num4 = rand() % 100 + 1; 
    cout << "Calificacion 1: " << num1 << " (Ponderacion 10%)" << endl;
    cout << "Calificacion 2: " << num2 << " (Ponderacion 20%)" << endl;   
    cout << "Calificacion 3: " << num3 << " (Ponderacion 30%)" << endl; 
    cout << "Calificacion 4: " << num4 << " (Ponderacion 40%)" << endl;   
    cout << "Promedio ponderado: " << prompon(num1,num2,num3,num4) << endl; 
}
