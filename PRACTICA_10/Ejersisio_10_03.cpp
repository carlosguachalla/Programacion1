// Materia: Programación I, Paralelo 4
// Autor: Carlos Adrian Guachalla Quispe
// Carnet: 9918131 L.P.
// Carrera del estudiante: Ingeniería Mecatrónica
// Fecha creación: 10/11/2025
// Número de ejercicio: 3
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <limits>
using namespace std;
struct Estudiante {
    string nombre;
    int edad;
    double promedio;
};
void borrarArchivoEstudiantes() {
    ofstream archivoSalida("estudiantes.txt", ios::out | ios::trunc);
    if (archivoSalida.fail()) {
        cout << "Error al intentar borrar el archivo estudiantes.txt" << endl;
        return;
    }
    archivoSalida.close();
    cout << "El contenido de estudiantes.txt ha sido borrado con exito." << endl;
}
void registrarEstudiantes() {
    vector<Estudiante> listaEstudiantes;
    int cantidad = 0;
    string nombreTemporal;
    int edadTemporal;
    double promedioTemporal;
    cout << "Ingrese la cantidad de estudiantes a registrar: ";
    if (!(cin >> cantidad) || cantidad <= 0) {
        cout << "Entrada invalida, la cantidad debe ser un numero positivo." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    for (int i = 0; i < cantidad; i++) {
        Estudiante nuevoEstudiante;
        cout << "--- Estudiante " << i + 1 << " ---" << endl;
        cout << "Nombre: ";
        getline(cin, nuevoEstudiante.nombre);
        cout << "Edad: ";
        while (!(cin >> nuevoEstudiante.edad)) {
            cout << "Edad invalida. Ingrese solo numeros: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        cout << "Promedio: ";
        while (!(cin >> nuevoEstudiante.promedio)) {
            cout << "Promedio invalido. Ingrese solo numeros: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        listaEstudiantes.push_back(nuevoEstudiante);
    }
    ofstream archivoSalida("estudiantes.txt", ios::app);
    if (archivoSalida.fail()) {
        cout << "Error al abrir el archivo estudiantes.txt para escritura." << endl;
        return;
    }
    for (const auto& est : listaEstudiantes) {
        archivoSalida << "Nombre: " << est.nombre << endl;
        archivoSalida << "Edad: " << est.edad << endl;
        archivoSalida << "Promedio: " << est.promedio << endl;
        archivoSalida << "---" << endl;
    }
    archivoSalida.close();
    cout << "Registros guardados con exito en estudiantes.txt, se han adjuntado a los existentes." << endl;
}
void mostrarEstudiantes() {
    vector<Estudiante> listaLeida;
    ifstream archivoEntrada("estudiantes.txt");
    string linea;
    Estudiante estTemporal;
    int estado = 0;
    if (archivoEntrada.fail()) {
        cout << "No se pudo abrir el archivo estudiantes.txt para lectura." << endl;
        return;
    }
    while (getline(archivoEntrada, linea)) {
        if (linea.rfind("Nombre: ", 0) == 0) {
            estTemporal.nombre = linea.substr(8);
            estado = 1;
        } else if (linea.rfind("Edad: ", 0) == 0 && estado == 1) {
            try {
                estTemporal.edad = stoi(linea.substr(6));
                estado = 2;
            } catch (const std::exception& e) {
                cout << "Error en formato de edad." << endl;
                estado = 0;
            }
        } else if (linea.rfind("Promedio: ", 0) == 0 && estado == 2) {
            try {
                estTemporal.promedio = stod(linea.substr(10));
                listaLeida.push_back(estTemporal);
                estado = 0;
            } catch (const std::exception& e) {
                cout << "Error en formato de promedio." << endl;
                estado = 0;
            }
        }
    }
    archivoEntrada.close();
    cout << endl;
    cout << "--- Informacion de Estudiantes ---" << endl;
    if (listaLeida.empty()) {
        cout << "El archivo esta vacio." << endl;
    } else {
        for (const auto& est : listaLeida) {
            cout << "Nombre: " << est.nombre << endl;
            cout << "Edad: " << est.edad << " anos" << endl;
            cout << "Promedio: " << est.promedio << endl;
            cout << "---" << endl;
        }
        cout << "Total de estudiantes leidos: " << listaLeida.size() << endl;
    }
}
int main() {
    int opcion;
    bool salir = false;
    while (!salir) {
        cout << endl;
        cout << "--- Menu de Estudiantes ---" << endl;
        cout << "1. Registrar nuevos estudiantes y guardar en archivo" << endl;
        cout << "2. Leer y mostrar todos los estudiantes del archivo" << endl;
        cout << "3. Borrar todo el contenido del archivo estudiantes.txt" << endl;
        cout << "4. Salir del programa" << endl;
        cout << "Seleccione una opcion: ";
        if (!(cin >> opcion)) {
            cout << "Entrada invalida, Ingrese un numero." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        switch (opcion) {
            case 1:
                registrarEstudiantes();
                break;
            case 2:
                mostrarEstudiantes();
                break;
            case 3:
                borrarArchivoEstudiantes();
                break;
            case 4:
                cout << "Saliendo del programa, Adios." << endl;
                salir = true;
                break;
            default:
                cout << "Opcion no valida, Intente de nuevo." << endl;
                break;
        }
    }
    return 0;
}
/*
La estructura Estudiante define los campos para almacenar la información de cada alumno (nombre, edad y promedio).
La función borrarArchivoEstudiantes elimina el contenido del archivo "estudiantes.txt" abriéndolo en modo de truncado.
La función registrarEstudiantes guía al usuario para ingresar datos de múltiples estudiantes, maneja la validación de entrada, y luego adjunta estos registros formateados al archivo "estudiantes.txt".
La función mostrarEstudiantes lee línea por línea el archivo "estudiantes.txt", extrae y reconstruye los objetos Estudiante y muestra la información en la consola.
El programa principal (main) presenta un menú de opciones iterativo que permite al usuario registrar nuevos estudiantes, ver los existentes o borrar el archivo.
*/