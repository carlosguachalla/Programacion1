// Materia: Programación I, Paralelo 4
// Autor: Carlos Adrian Guachalla Quispe
// Carnet: 9918131 L.P.
// Carrera del estudiante: Ingeniería Mecatrónica
// Fecha creación: 4/11/2025
// Número de ejercicio: 1
#include <iostream>
#include <string>
#include <vector>
using namespace std;
struct Libro {
    string titulo;
    string autor;
    int anio_publicacion;
    bool disponible;
};
int main() {
    Libro nuevoLibro;
    string disponible_str;
    vector<Libro> biblioteca;
    cout << "Registro de un Libro" << endl;
    cout << "Ingrese el título del libro: ";
    getline(cin, nuevoLibro.titulo);
    cout << "Ingrese el autor del libro: ";
    getline(cin, nuevoLibro.autor);
    cout << "Ingrese el año de publicación: ";
    if (!(cin >> nuevoLibro.anio_publicacion)) {
        return 1;
    }
    cin.ignore(256, '\n');
    do {
        cout << "¿Está disponible el libro? (si/no): ";
        getline(cin, disponible_str);
        if (disponible_str == "si" || disponible_str == "no" || disponible_str == "Si" || disponible_str == "No") {
            break;
        }
        cout << "Entrada no válida. Por favor, ingrese 'si' o 'no'." << endl;
    } while (true);
    nuevoLibro.disponible = (disponible_str == "si" || disponible_str == "Si");
    biblioteca.push_back(nuevoLibro);
    cout << "\nDatos del Libro Registrado" << endl;
    for (const auto& libro : biblioteca) {
        cout << "Título: " << libro.titulo << endl;
        cout << "Autor: " << libro.autor << endl;
        cout << "Año de Publicación: " << libro.anio_publicacion << endl;
        cout << "Estado: ";
        if (libro.disponible) {
            cout << "DISPONIBLE" << endl;
        } else {
            cout << "NO DISPONIBLE" << endl;
        }
    }
    return 0;
}