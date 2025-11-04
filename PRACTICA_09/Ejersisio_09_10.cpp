// Materia: Programación I, Paralelo 4
// Autor: Carlos Adrian Guachalla Quispe
// Carnet: 9918131 L.P.
// Carrera del estudiante: Ingeniería Mecatrónica
// Fecha creación: 4/11/2025
// Número de ejercicio: 10
#include <iostream>
using namespace std;
struct Fraccion {
    int numerador;
    int denominador;
};
struct FraccionSimplificada {
    int numerador_simplificado;
    int denominador_simplificado;
};
int calcular_mcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
FraccionSimplificada ReducirFraccion(Fraccion f) {
    FraccionSimplificada simplificada;
    int mcd = calcular_mcd(f.numerador, f.denominador);
    simplificada.numerador_simplificado = f.numerador / mcd;
    simplificada.denominador_simplificado = f.denominador / mcd;
    return simplificada;
}
int main() {
    Fraccion original;
    cout << "--- Simplificación de Fracciones ---" << endl;
    cout << "Ingrese el numerador: ";
    while (!(cin >> original.numerador)) {
        cerr << "Entrada inválida. Intente de nuevo: ";
        cin.clear();
        cin.ignore(256, '\n');
    }
    cout << "Ingrese el denominador (debe ser diferente de cero): ";
    while (!(cin >> original.denominador) || original.denominador == 0) {
        cerr << "Denominador inválido. Intente de nuevo: ";
        cin.clear();
        cin.ignore(256, '\n');
    }
    FraccionSimplificada resultado = ReducirFraccion(original);
    cout << "\nFracción Original: " << original.numerador << "/" << original.denominador << endl;
    cout << "Fracción Simplificada: " << resultado.numerador_simplificado << "/" << resultado.denominador_simplificado << endl;
    return 0;
}