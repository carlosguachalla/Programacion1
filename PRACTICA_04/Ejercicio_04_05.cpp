// Materia: Programación I, Paralelo 4
// Autor: Carlos Adrian Guachalla Quispe
// Carnet: 9918131 L.P.
// Carrera del estudiante: Ingeniería Mecatrónica
// Fecha creación: 13/09/2025
// Número de ejercicio: 5
#include <iostream>
using namespace std;
int Horas(int horas){//la tarifa por hora normal se pasa por esta funcion sumandola tantas veces como horas trabjadas
    int tarifaxhora=1000, dinero=0;
    for (int i=0;i<horas; i++){
        dinero+=tarifaxhora;
    }
    return dinero;
}
int Extra(int horas){//en caso de haber horas extra se llama a esta funcion para que encuentre la tarifa extra
    int tarifaxhora=200, dinero=0;
    for (int i=0;i<horas; i++){
        dinero+=tarifaxhora;
    }
    return dinero;
}
int main() {
    int horas=0, dinero=0, extra=0;
    cout<<"Cuantas horas (Hora:1000, extra pasada jornada laboral=200): ";
    cin>>horas;
    dinero=Horas(horas);
    cout<<"La paga de tarifa normal seria de: "<<dinero<<" Bs"<<endl;
    if(horas>8){
        extra=Extra(horas);
        cout<<"La paga por horas extra seria de: "<<extra<<" Bs"<<endl;
    }
}
