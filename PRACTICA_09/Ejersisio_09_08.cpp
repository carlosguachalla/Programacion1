// Materia: Programación I, Paralelo 4
// Autor: Carlos Adrian Guachalla Quispe
// Carnet: 9918131 L.P.
// Carrera del estudiante: Ingeniería Mecatrónica
// Fecha creación: 4/11/2025
// Número de ejercicio: 8
#include <iostream>
#include <string>
#include <vector>
using namespace std;
struct Atleta {
    string nombre;
    string departamento;
    string deporte;
    int medallas_oro;
    int medallas_plata;
    int medallas_bronce;
};
struct MedalleroDepto {
    string departamento;
    int oro = 0;
    int plata = 0;
    int bronce = 0;
    int total = 0;
};
void registrar_datos_atleta(Atleta& a, int indice) {
    cout << "\n--- Datos del Atleta #" << indice << " ---" << endl;
    cout << "Nombre: ";
    getline(cin, a.nombre);
    cout << "Departamento: ";
    getline(cin, a.departamento);
    cout << "Deporte (Tiro con arco, Atletismo, Boxeo, Ciclismo, Natación, Esgrima): ";
    getline(cin, a.deporte);
    cout << "Medallas de Oro ganadas: ";
    while (!(cin >> a.medallas_oro) || a.medallas_oro < 0) {
        cerr << "Cantidad inválida. Intente de nuevo: ";
        cin.clear();
        cin.ignore(256, '\n');
    }
    cout << "Medallas de Plata ganadas: ";
    while (!(cin >> a.medallas_plata) || a.medallas_plata < 0) {
        cerr << "Cantidad inválida. Intente de nuevo: ";
        cin.clear();
        cin.ignore(256, '\n');
    }
    cout << "Medallas de Bronce ganadas: ";
    while (!(cin >> a.medallas_bronce) || a.medallas_bronce < 0) {
        cerr << "Cantidad inválida. Intente de nuevo: ";
        cin.clear();
        cin.ignore(256, '\n');
    }
    cin.ignore(256, '\n');
}
vector<MedalleroDepto> calcular_medallero(const vector<Atleta>& atletas) {
    vector<MedalleroDepto> medallero;
    for (const auto& a : atletas) {
        bool encontrado = false;
        // Búsqueda lineal para encontrar el departamento en el vector
        for (size_t i = 0; i < medallero.size(); ++i) {
            if (medallero[i].departamento == a.departamento) {
                medallero[i].oro += a.medallas_oro;
                medallero[i].plata += a.medallas_plata;
                medallero[i].bronce += a.medallas_bronce;
                medallero[i].total += a.medallas_oro + a.medallas_plata + a.medallas_bronce;
                encontrado = true;
                break;
            }
        }
        // Si el departamento no se encontró, agrégalo al vector
        if (!encontrado) {
            MedalleroDepto nuevoDepto;
            nuevoDepto.departamento = a.departamento;
            nuevoDepto.oro = a.medallas_oro;
            nuevoDepto.plata = a.medallas_plata;
            nuevoDepto.bronce = a.medallas_bronce;
            nuevoDepto.total = a.medallas_oro + a.medallas_plata + a.medallas_bronce;
            medallero.push_back(nuevoDepto);
        }
    }
    return medallero;
}
void mostrar_medallero(vector<MedalleroDepto>& medallero) {
    // Implementación manual de un algoritmo de ordenamiento (Burbuja simplificado)
    // Ordena por Total (mayor a menor)
    size_t n = medallero.size();
    for (size_t i = 0; i < n - 1; ++i) {
        for (size_t j = 0; j < n - i - 1; ++j) {
            if (medallero[j].total < medallero[j+1].total) {
                // Intercambio
                MedalleroDepto temp = medallero[j];
                medallero[j] = medallero[j+1];
                medallero[j+1] = temp;
            }
            // Puedes agregar criterios de desempate (oro, plata, bronce) aquí si es necesario
        }
    }
    cout << "\n===========================================" << endl;
    cout << "         MEDALLERO NACIONAL FINAL" << endl;
    cout << "===========================================" << endl;
    cout << "Departamento\tOro\tPlata\tBronce\tTotal" << endl;
    cout << "-------------------------------------------" << endl;
    for (const auto& d : medallero) {
        cout << d.departamento << "\t\t" << d.oro << "\t" << d.plata << "\t" << d.bronce << "\t" << d.total << endl;
    }
    cout << "===========================================" << endl;
}
int main() {
    int N;
    cout << "--- Registro de Atletas Olímpicos ---" << endl;
    cout << "Ingrese el número de atletas (N) a registrar: ";
    if (!(cin >> N) || N <= 0) {
        cerr << "Número de atletas inválido." << endl;
        return 1;
    }
    cin.ignore(256, '\n');
    vector<Atleta> listaAtletas;
    for (int i = 0; i < N; ++i) {
        Atleta nuevoAtleta;
        registrar_datos_atleta(nuevoAtleta, i + 1);
        listaAtletas.push_back(nuevoAtleta);
    }
    if (listaAtletas.empty()) {
        cout << "\nNo hay atletas registrados." << endl;
        return 0;
    }
    vector<MedalleroDepto> medalleroFinal = calcular_medallero(listaAtletas);
    mostrar_medallero(medalleroFinal);
    return 0;
}