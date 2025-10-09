// Materia: Programación I, Paralelo 4
// Autor: Carlos Adrian Guachalla Quispe
// Carnet: 9918131 L.P.
// Carrera del estudiante: Ingeniería Mecatrónica
// Fecha creación: 8/10/2025
// Número de ejercicio: 6
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;
int main() {
    srand(time(0));
    int n,i,nota,contReprobado=0,contRegular=0,contBueno=0,contExcelente=0;
    double pReprobado,pRegular,pBueno,pExcelente;
    vector<int> calificaciones;
    vector<string> rangos = {"Reprobado", "Regular", "Bueno", "Excelente"};
    cout << "Ingrese la cantidad de estudiantes: ";
    cin >> n;
    for(i=0;i<n;i++){//crea n valores aleatorios
        nota=rand() % 101;
        calificaciones.push_back(nota);
    }
    for(i=0;i<calificaciones.size();i++){//hace tantas veces el tamano del vector
        if(calificaciones[i]<=59){contReprobado++;}//con estos if va sumando los if
        else if(calificaciones[i]<=79){contRegular++;}
        else if(calificaciones[i]<=89){contBueno++;}
        else{contExcelente++;}
    }
    pReprobado=((contReprobado*100.0)/n);
    pRegular=((contRegular*100.0)/n);
    pBueno=((contBueno*100.0)/n);
    pExcelente=((contExcelente*100.0)/n);
    cout<<"Calificaciones generadas:"<<endl;
    for(i=0;i<calificaciones.size();i++){
        cout<<calificaciones[i]<<" ";
    }
    cout<<endl<<"Porcentajes por rango:"<<endl;
    cout<<rangos[0]<<": "<<pReprobado<<"%"<< endl;
    cout<<rangos[1]<<": "<<pRegular<<"%"<<endl;
    cout<<rangos[2]<<": "<<pBueno<<"%"<<endl;
    cout<<rangos[3]<<": "<<pExcelente<<"%"<<endl;
    return 0;
}
