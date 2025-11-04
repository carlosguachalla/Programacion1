// Materia: Programación I, Paralelo 4
// Autor: Carlos Adrian Guachalla Quispe
// Carnet: 9918131 L.P.
// Carrera del estudiante: Ingeniería Mecatrónica
// Fecha creación: 4/11/2025
// Número de ejercicio: 5
#include <iostream>
#include <string>
#include <vector>
using namespace std;
struct Pelicula {
    string titulo;
    string director;
    int duracion;
    int anio_estreno;
    string genero;
};
void mostrarPeliculas(const vector<Pelicula>& peliculas) {
    if (peliculas.empty()) {
        cout << "No se encontraron películas." << endl;
        return;
    }
    for (size_t i = 0; i < peliculas.size(); ++i) {
        const Pelicula& p = peliculas[i];
        cout << "\n--- Película #" << i + 1 << " ---" << endl;
        cout << "Título: " << p.titulo << endl;
        cout << "Director: " << p.director << endl;
        cout << "Duración (minutos): " << p.duracion << endl;
        cout << "Año de Estreno: " << p.anio_estreno << endl;
        cout << "Género: " << p.genero << endl;
    }
}
int main() {
    int N;
    cout << "--- Sistema de Gestión de Películas ---" << endl;
    cout << "Ingrese el número de películas (N) a registrar: ";
    if (!(cin >> N) || N <= 0) {
        cerr << "Número de películas inválido." << endl;
        return 1;
    }
    cin.ignore(256, '\n');
    vector<Pelicula> listaPeliculas;
    for (int i = 0; i < N; ++i) {
        Pelicula nuevaPelicula;
        cout << "\n--- Datos de la Película #" << i + 1 << " ---" << endl;
        cout << "Título: ";
        getline(cin, nuevaPelicula.titulo);
        cout << "Director: ";
        getline(cin, nuevaPelicula.director);
        cout << "Duración (minutos): ";
        while (!(cin >> nuevaPelicula.duracion) || nuevaPelicula.duracion <= 0) {
            cerr << "Duración inválida. Intente de nuevo: ";
            cin.clear();
            cin.ignore(256, '\n');
        }
        cout << "Año de Estreno: ";
        while (!(cin >> nuevaPelicula.anio_estreno) || nuevaPelicula.anio_estreno <= 0) {
            cerr << "Año inválido. Intente de nuevo: ";
            cin.clear();
            cin.ignore(256, '\n');
        }
        cin.ignore(256, '\n');
        cout << "Género: ";
        getline(cin, nuevaPelicula.genero);
        listaPeliculas.push_back(nuevaPelicula);
    }
    if (listaPeliculas.empty()) {
        cout << "\nNo se registraron películas." << endl;
        return 0;
    }
    cout << "\n========================================" << endl;
    cout << "      OPCIONES DE BÚSQUEDA" << endl;
    cout << "========================================" << endl;
    string busquedaGenero;
    cout << "Ingrese el GÉNERO específico a buscar: ";
    getline(cin, busquedaGenero);
    vector<Pelicula> peliculasPorGenero;
    for (const auto& p : listaPeliculas) {
        if (p.genero == busquedaGenero) {
            peliculasPorGenero.push_back(p);
        }
    }
    cout << "\n--- Resultados por GÉNERO: (" << busquedaGenero << ") ---" << endl;
    mostrarPeliculas(peliculasPorGenero);
    cout << "\n========================================" << endl;
    string busquedaDirector;
    cout << "Ingrese el DIRECTOR específico a buscar: ";
    getline(cin, busquedaDirector);
    vector<Pelicula> peliculasPorDirector;
    for (const auto& p : listaPeliculas) {
        if (p.director == busquedaDirector) {
            peliculasPorDirector.push_back(p);
        }
    }
    cout << "\n--- Resultados por DIRECTOR: (" << busquedaDirector << ") ---" << endl;
    mostrarPeliculas(peliculasPorDirector);
    cout << "========================================" << endl;
    return 0;
}