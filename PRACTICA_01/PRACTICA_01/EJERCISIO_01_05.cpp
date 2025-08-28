// Materia: Programación I, Paralelo 4
// Autor: Carlos Adrian Guachalla Quispe
// Carnet: 9918131 L.P.
// Carrera del estudiante: Ingeniería Mecatronica
// Fecha creación: 27/08/2025
// Número de ejercicio: 5
#include <iostream>
using namespace std;
int main() {
    float gradoscentigrados=0, gradoskelvin=0, formuladekelvin=273.15;//declaramos formuladekelvin de una vez como un valor con decimal
    cout<<"Ingrese una temperatura en grados centigrados: ";
    cin>>gradoscentigrados;
    gradoskelvin=gradoscentigrados+formuladekelvin;//formula sencilla de centigrados a kelvin
    cout<<"La temperatura en grados kelvine es: "<<gradoskelvin<<endl;
    return 0;
}


