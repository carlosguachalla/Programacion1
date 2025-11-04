// Materia: Programación I, Paralelo 4
// Autor: Carlos Adrian Guachalla Quispe
// Carnet: 9918131 L.P.
// Carrera del estudiante: Ingeniería Mecatrónica
// Fecha creación: 4/11/2025
// Número de ejercicio: 3
#include <iostream>
#include <string>
#include <vector>
using namespace std;
struct Estudiante {
    int cedula;
    string nombre;
    string apellido;
    int edad;
    string profesion;
    string lugar_nacimiento;
    string direccion;
    long long telefono;
};
int main() {
    int N;
    cout << "--- Registro de Estudiantes de Programación I ---" << endl;
    cout << "Ingrese el número de estudiantes (N) a registrar: ";
    if (!(cin >> N) || N <= 0) {
        cerr << "Número inválido." << endl;
        return 1;
    }
    cin.ignore(256, '\n');
    vector<Estudiante> listaEstudiantes;
    for (int i = 0; i < N; ++i) {
        Estudiante nuevoEstudiante;
        cout << "\n--- Datos del Estudiante #" << i + 1 << " ---" << endl;
        cout << "Cédula (entero): ";
        while (!(cin >> nuevoEstudiante.cedula) || nuevoEstudiante.cedula <= 0) {
            cerr << "Cédula inválida. Intente de nuevo: ";
            cin.clear();
            cin.ignore(256, '\n');
        }
        cin.ignore(256, '\n');
        cout << "Nombre: ";
        getline(cin, nuevoEstudiante.nombre);
        cout << "Apellido: ";
        getline(cin, nuevoEstudiante.apellido);
        cout << "Edad (entero): ";
        while (!(cin >> nuevoEstudiante.edad) || nuevoEstudiante.edad <= 0) {
            cerr << "Edad inválida. Intente de nuevo: ";
            cin.clear();
            cin.ignore(256, '\n');
        }
        cin.ignore(256, '\n');
        cout << "Profesión/Carrera: ";
        getline(cin, nuevoEstudiante.profesion);
        cout << "Lugar de Nacimiento: ";
        getline(cin, nuevoEstudiante.lugar_nacimiento);
        cout << "Dirección: ";
        getline(cin, nuevoEstudiante.direccion);
        cout << "Teléfono (entero): ";
        while (!(cin >> nuevoEstudiante.telefono) || nuevoEstudiante.telefono <= 0) {
            cerr << "Teléfono inválido. Intente de nuevo: ";
            cin.clear();
            cin.ignore(256, '\n');
        }
        cin.ignore(256, '\n');
        listaEstudiantes.push_back(nuevoEstudiante);
    }
    cout << "\n========================================================" << endl;
    cout << "      LISTADO DE ESTUDIANTES DE PROGRAMACIÓN I " << endl;
    cout << "========================================================" << endl;
    if (listaEstudiantes.empty()) {
        cout << "No hay estudiantes registrados para mostrar." << endl;
    } else {
        for (size_t i = 0; i < listaEstudiantes.size(); ++i) {
            const Estudiante& e = listaEstudiantes[i];
            cout << "\n--- ESTUDIANTE #" << i + 1 << " ---" << endl;
            cout << "Cédula: " << e.cedula << endl;
            cout << "Nombre: " << e.nombre << endl;
            cout << "Apellido: " << e.apellido << endl;
            cout << "Edad: " << e.edad << endl;
            cout << "Profesión/Carrera: " << e.profesion << endl;
            cout << "Lugar de Nacimiento: " << e.lugar_nacimiento << endl;
            cout << "Dirección: " << e.direccion << endl;
            cout << "Teléfono: " << e.telefono << endl;
        }
    }
    cout << "\n========================================================" << endl;
    return 0;
}