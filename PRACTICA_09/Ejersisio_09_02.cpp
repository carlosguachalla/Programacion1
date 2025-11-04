// Materia: Programación I, Paralelo 4
// Autor: Carlos Adrian Guachalla Quispe
// Carnet: 9918131 L.P.
// Carrera del estudiante: Ingeniería Mecatrónica
// Fecha creación: 4/11/2025
// Número de ejercicio: 2
#include <iostream>
#include <string>
#include <vector>
using namespace std;
struct Atleta {
    string nombre;
    string pais;
    int edad;
    int mejor_tiempo;
};
int main() {
    int N;
    cout << "--- Registro de Atletas ---" << endl;
    cout << "Ingrese el número de atletas (N) a registrar: ";
    if (!(cin >> N) || N <= 0) {
        cerr << "Número de atletas inválido." << endl;
        return 1;
    }
    cin.ignore(256, '\n');
    vector<Atleta> listaAtletas;
    for (int i = 0; i < N; ++i) {
        Atleta nuevoAtleta;
        cout << "\n--- Datos del Atleta #" << i + 1 << " ---" << endl;
        cout << "Nombre: ";
        getline(cin, nuevoAtleta.nombre);
        cout << "País: ";
        getline(cin, nuevoAtleta.pais);
        cout << "Edad: ";
        while (!(cin >> nuevoAtleta.edad)) {
            cerr << "Edad inválida. Intente de nuevo: ";
            cin.clear();
            cin.ignore(256, '\n');
        }
        cout << "Mejor Tiempo (segundos): ";
        while (!(cin >> nuevoAtleta.mejor_tiempo) || nuevoAtleta.mejor_tiempo <= 0) {
            cerr << "Tiempo inválido. Intente de nuevo: ";
            cin.clear();
            cin.ignore(256, '\n');
        }
        cin.ignore(256, '\n');
        listaAtletas.push_back(nuevoAtleta);
    }
    if (listaAtletas.empty()) {
        cout << "\nNo se registraron atletas." << endl;
        return 0;
    }
    Atleta mejorTiempoAtleta = listaAtletas[0];
    for (size_t i = 1; i < listaAtletas.size(); ++i) {
        if (listaAtletas[i].mejor_tiempo < mejorTiempoAtleta.mejor_tiempo) {
            mejorTiempoAtleta = listaAtletas[i];
        }
    }
    cout << "\n==================================" << endl;
    cout << "     ATLETA CON MEJOR TIEMPO " << endl;
    cout << "==================================" << endl;
    cout << "Nombre: " << mejorTiempoAtleta.nombre << endl;
    cout << "País: " << mejorTiempoAtleta.pais << endl;
    cout << "Mejor Tiempo (segundos): " << mejorTiempoAtleta.mejor_tiempo << endl;
    cout << "\n==================================" << endl;
    return 0;
}