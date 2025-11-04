// Materia: Programación I, Paralelo 4
// Autor: Carlos Adrian Guachalla Quispe
// Carnet: 9918131 L.P.
// Carrera del estudiante: Ingeniería Mecatrónica
// Fecha creación: 4/11/2025
// Número de ejercicio: 9
#include <iostream>
#include <vector>
#include <string>
using namespace std;
struct Alumno {
    string nombre;
    double T1, T2, T3, T4, EF;
    double NP;
    double NF;
};
void registrar_notas(Alumno& a, int indice) {
    cout << "\n--- Datos del Alumno #" << indice << " ---" << endl;
    cout << "Nombre del alumno: ";
    getline(cin, a.nombre);
    cout << "Nota T1: ";
    while (!(cin >> a.T1) || a.T1 < 0) {
        cerr << "Nota inválida. Intente de nuevo: ";
        cin.clear();
        cin.ignore(256, '\n');
    }
    cout << "Nota T2: ";
    while (!(cin >> a.T2) || a.T2 < 0) {
        cerr << "Nota inválida. Intente de nuevo: ";
        cin.clear();
        cin.ignore(256, '\n');
    }
    cout << "Nota T3: ";
    while (!(cin >> a.T3) || a.T3 < 0) {
        cerr << "Nota inválida. Intente de nuevo: ";
        cin.clear();
        cin.ignore(256, '\n');
    }
    cout << "Nota T4: ";
    while (!(cin >> a.T4) || a.T4 < 0) {
        cerr << "Nota inválida. Intente de nuevo: ";
        cin.clear();
        cin.ignore(256, '\n');
    }
    cout << "Nota EF (Examen Final): ";
    while (!(cin >> a.EF) || a.EF < 0) {
        cerr << "Nota inválida. Intente de nuevo: ";
        cin.clear();
        cin.ignore(256, '\n');
    }
    cin.ignore(256, '\n');
}
void calcular_notas_finales(vector<Alumno>& alumnos) {
    for (auto& a : alumnos) {
        // NP = (T1+T2+T3+T4)/4
        a.NP = (a.T1 + a.T2 + a.T3 + a.T4) / 4.0;
        // NF = 0.7*NP + 0.3*EF
        a.NF = 0.7 * a.NP + 0.3 * a.EF;
    }
}
void mostrar_resumen_curso(const vector<Alumno>& alumnos) {
    if (alumnos.empty()) {
        cout << "\nNo hay alumnos registrados." << endl;
        return;
    }
    double sumaNF = 0.0;
    double minNF = alumnos[0].NF;
    double maxNF = alumnos[0].NF;
    for (const auto& a : alumnos) {
        sumaNF += a.NF;
        if (a.NF < minNF) minNF = a.NF;
        if (a.NF > maxNF) maxNF = a.NF;
    }
    double promedioNF = sumaNF / alumnos.size();
    cout << "\n=============================================" << endl;
    cout << "       RESUMEN DE CALIFICACIONES DEL CURSO" << endl;
    cout << "=============================================" << endl;
    cout << "Total de alumnos: " << alumnos.size() << endl;
    cout << "Promedio del curso (NF): " << promedioNF << endl;
    cout << "Nota Final Mínima (NF): " << minNF << endl;
    cout << "Nota Final Máxima (NF): " << maxNF << endl;
    cout << "\n--- Notas Finales Individuales ---" << endl;
    for (const auto& a : alumnos) {
        cout << a.nombre << " | NP: " << a.NP << " | NF: " << a.NF << endl;
    }
    cout << "=============================================" << endl;
}
int main() {
    int N;
    cout << "--- Sistema de Calificaciones ---" << endl;
    cout << "Ingrese el número de alumnos (N): ";
    if (!(cin >> N) || N <= 0) {
        cerr << "Número de alumnos inválido." << endl;
        return 1;
    }
    cin.ignore(256, '\n');
    vector<Alumno> listaAlumnos;
    for (int i = 0; i < N; ++i) {
        Alumno nuevoAlumno;
        registrar_notas(nuevoAlumno, i + 1);
        listaAlumnos.push_back(nuevoAlumno);
    }
    calcular_notas_finales(listaAlumnos);
    mostrar_resumen_curso(listaAlumnos);
    return 0;
}