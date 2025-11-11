// Materia: Programación I, Paralelo 4
// Autor: Carlos Adrian Guachalla Quispe
// Carnet: 9918131 L.P.
// Carrera del estudiante: Ingeniería Mecatrónica
// Fecha creación: 10/11/2025
// Número de ejercicio: 4
#include <iostream>
#include <fstream>
#include <string>
#include <limits>
using namespace std;
void prepararArchivo() {
    ofstream archivoSalida("datos.txt", ios::out);
    string textoCompleto;
    cout << "Escribe el texto completo que deseas guardar en datos.txt, presiona Enter dos veces para terminar: " << endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    string linea;
    while (getline(cin, linea) && !linea.empty()) {
        textoCompleto += linea + "\n";
    }
    if (archivoSalida.fail()) {
        cout << "Error al crear o limpiar el archivo datos.txt" << endl;
        return;
    }
    archivoSalida << textoCompleto;
    archivoSalida.close();
    cout << "Archivo datos.txt creado y actualizado con el nuevo texto." << endl;
}
void buscarTexto() {
    ifstream archivoEntrada("datos.txt");
    string fraseBuscar;
    string contenidoArchivo;
    size_t posicion = 0;
    int contador = 0;
    if (archivoEntrada.fail()) {
        cout << "Error, No se pudo abrir el archivo datos.txt." << endl;
        return;
    }
    archivoEntrada.seekg(0, ios::end);
    contenidoArchivo.reserve(archivoEntrada.tellg());
    archivoEntrada.seekg(0, ios::beg);
    contenidoArchivo.assign((istreambuf_iterator<char>(archivoEntrada)), istreambuf_iterator<char>());
    archivoEntrada.close();
    if (contenidoArchivo.empty()) {
        cout << "El archivo datos.txt esta vacio." << endl;
        return;
    }
    cout << "Ingrese la palabra o frase a buscar: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, fraseBuscar);
    if (fraseBuscar.empty()) {
        cout << "La frase de busqueda no puede estar vacia." << endl;
        return;
    }
    while ((posicion = contenidoArchivo.find(fraseBuscar, posicion)) != string::npos) {
        contador++;
        posicion += fraseBuscar.length();
    }
    cout << "La palabra o frase " << fraseBuscar << " aparece " << contador << " veces en el archivo." << endl;
}
void salirPrograma() {
    cout << "Saliendo del programa, Adios." << endl;
}
int main() {
    int opcion;
    bool salir = false;
    while (!salir) {
        cout << endl;
        cout << "--- Menu de Busqueda de Texto ---" << endl;
        cout << "1. Crear o limpiar y colocar nuevo texto en datos.txt" << endl;
        cout << "2. Buscar palabra o frase en datos.txt" << endl;
        cout << "3. Salir del programa" << endl;
        cout << "Seleccione una opcion: ";
        if (!(cin >> opcion)) {
            cout << "Entrada invalida, Ingrese un numero." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        switch (opcion) {
            case 1:
                prepararArchivo();
                break;
            case 2:
                buscarTexto();
                break;
            case 3:
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
La función prepararArchivo solicita al usuario un texto multilinea, limpia el archivo "datos.txt" y escribe el texto ingresado en él.
La función buscarTexto lee el contenido completo del archivo "datos.txt", pide al usuario una frase a buscar, y cuenta cuántas veces aparece dicha frase.
La función salirPrograma simplemente imprime un mensaje de despedida y se invoca al finalizar el programa.
El programa principal (main) presenta un menú de opciones que permite al usuario elegir entre escribir un nuevo texto, buscar una frase o salir de la aplicación.
*/