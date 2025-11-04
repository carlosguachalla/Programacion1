// Materia: Programación I, Paralelo 4
// Autor: Carlos Adrian Guachalla Quispe
// Carnet: 9918131 L.P.
// Carrera del estudiante: Ingeniería Mecatrónica
// Fecha creación: 4/11/2025
// Número de ejercicio: 4
#include <iostream>
#include <string>
#include <vector>
using namespace std;
struct empleado {
    string nombre;
    string genero;
    double salario;
};
int main() {
    int N;
    cout << "--- Registro de Empleados UCB ---" << endl;
    cout << "Ingrese el número de trabajadores (N) a registrar: ";
    if (!(cin >> N) || N <= 0) {
        cerr << "Número de trabajadores inválido." << endl;
        return 1;
    }
    cin.ignore(256, '\n');
    vector<empleado> listaEmpleados;
    for (int i = 0; i < N; ++i) {
        empleado nuevoEmpleado;
        cout << "\n--- Datos del Empleado #" << i + 1 << " ---" << endl;
        cout << "Nombre: ";
        getline(cin, nuevoEmpleado.nombre);
        cout << "Género: ";
        getline(cin, nuevoEmpleado.genero);
        cout << "Salario (decimal): ";
        while (!(cin >> nuevoEmpleado.salario) || nuevoEmpleado.salario < 0) {
            cerr << "Salario inválido. Intente de nuevo: ";
            cin.clear();
            cin.ignore(256, '\n');
        }
        cin.ignore(256, '\n');
        listaEmpleados.push_back(nuevoEmpleado);
    }
    if (listaEmpleados.empty()) {
        cout << "\nNo se registraron empleados." << endl;
        return 0;
    }
    empleado empleadoMenorSalario = listaEmpleados[0];
    empleado empleadoMayorSalario = listaEmpleados[0];
    for (size_t i = 1; i < listaEmpleados.size(); ++i) {
        const empleado& e = listaEmpleados[i];
        if (e.salario < empleadoMenorSalario.salario) {
            empleadoMenorSalario = e;
        }
        if (e.salario > empleadoMayorSalario.salario) {
            empleadoMayorSalario = e;
        }
    }
    cout << "\n=======================================" << endl;
    cout << "   RESULTADOS DE ANÁLISIS SALARIAL" << endl;
    cout << "=======================================" << endl;
    cout << "\n EMPLEADO CON MAYOR SALARIO:" << endl;
    cout << "Nombre: " << empleadoMayorSalario.nombre << endl;
    cout << "Género: " << empleadoMayorSalario.genero << endl;
    cout << "Salario: " << empleadoMayorSalario.salario << endl;
    cout << "\nEMPLEADO CON MENOR SALARIO:" << endl;
    cout << "Nombre: " << empleadoMenorSalario.nombre << endl;
    cout << "Género: " << empleadoMenorSalario.genero << endl;
    cout << "Salario: " << empleadoMenorSalario.salario << endl;
    cout << "=======================================" << endl;
    return 0;
}