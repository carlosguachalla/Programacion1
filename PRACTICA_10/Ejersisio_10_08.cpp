// Materia: Programación I, Paralelo 4
// Autor: Carlos Adrian Guachalla Quispe
// Carnet: 9918131 L.P.
// Carrera del estudiante: Ingeniería Mecatrónica
// Fecha creación: 11/11/2025
// Número de ejercicio: 8
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <limits>
using namespace std;
void limpiarYCrearArchivo() {
    ofstream archivoSalida("documento.txt", ios::out | ios::trunc);
    if (archivoSalida.fail()) {
        cout << "Error critico al crear o limpiar documento.txt" << endl;
        return;
    }
    cout << "Archivo documento.txt limpiado y listo para usar." << endl;
    archivoSalida.close();
}
void agregarLinea() {
    ofstream archivoSalida("documento.txt", ios::app);
    string nuevaLinea;
    cout << "Ingrese la linea de texto a agregar: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, nuevaLinea);
    if (archivoSalida.fail()) {
        cout << "Error al abrir documento.txt para agregar texto." << endl;
        return;
    }
    archivoSalida << nuevaLinea << endl;
    archivoSalida.close();
    cout << "Linea agregada con exito." << endl;
}
void contarEstadisticas() {
    ifstream archivoEntrada("documento.txt");
    string linea;
    int contadorLineas = 0;
    int contadorPalabras = 0;
    int contadorCaracteres = 0;
    if (archivoEntrada.fail()) {
        cout << "Error, No se pudo abrir el archivo documento.txt." << endl;
        return;
    }
    while (getline(archivoEntrada, linea)) {
        contadorLineas++;
        contadorCaracteres += linea.length();
        stringstream ss(linea);
        string palabra;
        while (ss >> palabra) {
            contadorPalabras++;
        }
    }
    archivoEntrada.close();
    cout << endl;
    cout << "--- Estadisticas de documento.txt ---" << endl;
    cout << "Lineas totales: " << contadorLineas << endl;
    cout << "Palabras totales: " << contadorPalabras << endl;
    cout << "Caracteres totales: " << contadorCaracteres << " sin contar saltos de linea" << endl;
    cout << "-------------------------------------" << endl;
}
void borrarArchivo() {
    limpiarYCrearArchivo();
    cout << "Archivo documento.txt ha sido efectivamente borrado." << endl;
}
void salirPrograma() {
    cout << "Saliendo del programa, Adios." << endl;
}
int main() {
    int opcion;
    bool salir = false;
    while (!salir) {
        cout << endl;
        cout << "--- Menu de Analisis de Texto ---" << endl;
        cout << "1. Contar Lineas, Palabras y Caracteres" << endl;
        cout << "2. Crear o limpiar documento.txt" << endl;
        cout << "3. Agregar una nueva linea al archivo" << endl;
        cout << "4. Borrar todo el contenido del archivo" << endl;
        cout << "5. Salir del programa" << endl;
        cout << "Seleccione una opcion: ";
        if (!(cin >> opcion)) {
            cout << "Entrada invalida, Ingrese un numero." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        switch (opcion) {
            case 1:
                contarEstadisticas();
                break;
            case 2:
                limpiarYCrearArchivo();
                break;
            case 3:
                agregarLinea();
                break;
            case 4:
                borrarArchivo();
                break;
            case 5:
                salirPrograma();
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
La función limpiarYCrearArchivo limpia el contenido del archivo "documento.txt" o lo crea si no existe, preparándolo para nuevos datos.
La función agregarLinea solicita una línea de texto al usuario y la añade al final del archivo "documento.txt".
La función contarEstadisticas lee "documento.txt" línea por línea y calcula el número total de líneas, palabras y caracteres contenidos en él.
La función borrarArchivo invoca a limpiarYCrearArchivo para vaciar completamente el contenido de "documento.txt".
El programa principal (main) gestiona un menú que permite al usuario interactuar con el archivo de texto para agregar líneas, contar estadísticas, limpiar el archivo o salir.
*/