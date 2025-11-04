// Materia: Programación I, Paralelo 4
// Autor: Carlos Adrian Guachalla Quispe
// Carnet: 9918131 L.P.
// Carrera del estudiante: Ingeniería Mecatrónica
// Fecha creación: 4/11/2025
// Número de ejercicio: 6
#include <iostream>
#include <string>
#include <vector>
using namespace std;
struct Empleado {
    string nombre;
    int id;
    double sueldo;
    int antiguedad;
};
int contar_sueldos_mayores(const vector<Empleado>& empleados, double sueldo_limite) {
    int contador = 0;
    for (const auto& e : empleados) {
        if (e.sueldo > sueldo_limite) {
            contador++;
        }
    }
    return contador;
}
double calcular_promedio_antiguedad(const vector<Empleado>& empleados) {
    if (empleados.empty()) {
        return 0.0;
    }
    int suma_antiguedad = 0;
    for (const auto& e : empleados) {
        suma_antiguedad += e.antiguedad;
    }
    return (double)suma_antiguedad / empleados.size();
}
int main() {
    int N;
    cout << "--- Gestión de Empleados ---" << endl;
    cout << "Ingrese el número de empleados (N) a registrar: ";
    if (!(cin >> N) || N <= 0) {
        cerr << "Número de empleados inválido." << endl;
        return 1;
    }
    cin.ignore(256, '\n');
    vector<Empleado> listaEmpleados;
    for (int i = 0; i < N; ++i) {
        Empleado nuevoEmpleado;
        cout << "\n--- Datos del Empleado #" << i + 1 << " ---" << endl;
        cout << "Nombre: ";
        getline(cin, nuevoEmpleado.nombre);
        cout << "ID (entero): ";
        while (!(cin >> nuevoEmpleado.id) || nuevoEmpleado.id <= 0) {
            cerr << "ID inválido. Intente de nuevo: ";
            cin.clear();
            cin.ignore(256, '\n');
        }
        cout << "Sueldo (decimal): ";
        while (!(cin >> nuevoEmpleado.sueldo) || nuevoEmpleado.sueldo < 0) {
            cerr << "Sueldo inválido. Intente de nuevo: ";
            cin.clear();
            cin.ignore(256, '\n');
        }
        cout << "Antigüedad (años): ";
        while (!(cin >> nuevoEmpleado.antiguedad) || nuevoEmpleado.antiguedad < 0) {
            cerr << "Antigüedad inválida. Intente de nuevo: ";
            cin.clear();
            cin.ignore(256, '\n');
        }
        cin.ignore(256, '\n');
        listaEmpleados.push_back(nuevoEmpleado);
    }
    if (listaEmpleados.empty()) {
        cout << "\nNo hay empleados registrados para analizar." << endl;
        return 0;
    }
    double valor_sueldo_limite;
    cout << "\n--- Análisis de Sueldos ---" << endl;
    cout << "Ingrese el valor de sueldo límite para la comparación: ";
    while (!(cin >> valor_sueldo_limite) || valor_sueldo_limite < 0) {
        cerr << "Valor inválido. Intente de nuevo: ";
        cin.clear();
        cin.ignore(256, '\n');
    }
    int empleados_con_mayor_sueldo = contar_sueldos_mayores(listaEmpleados, valor_sueldo_limite);
    double promedio_antiguedad = calcular_promedio_antiguedad(listaEmpleados);
    cout << "\n=====================================" << endl;
    cout << "   RESULTADOS DEL ANÁLISIS" << endl;
    cout << "=====================================" << endl;
    cout << "Empleados con sueldo mayor a " << valor_sueldo_limite << ": " << empleados_con_mayor_sueldo << endl;
    cout << "Promedio de antigüedad: " << promedio_antiguedad << " años" << endl;
    cout << "=====================================" << endl;
    return 0;
}