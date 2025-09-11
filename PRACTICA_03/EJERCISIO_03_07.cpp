//Materia:Programación I, Paralelo 4
//Autor:Carlos Adrian Guachalla Quispe
//Fecha creación:07/09/2025
//Número de ejercicio:7
#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
float promAltura(int sumaAlturas,int nalumnos){//promedio de altura
    return (float)sumaAlturas/nalumnos;
}
float promedad(int sumaedades,int nalumnos){//prmedio de edades
    return (float)sumaedades/nalumnos;
}
int maltura(int altura){ //encargado de ver si el alumno mide mas de 175 cm
    if (altura>175){
        return 1;
    }
    else{
        return 0;
    }
}
int medad(int edad){// encargado de medir si un estudiante tiene mas de 18
    if (edad>18){
        return 1;
    }
    else{
        return 0;
    }
}
int main(){
    int nalumnos=0,contador=0,altura=0,edad=0;
    int sumaAlturas=0, sumaedades=0, naltura=0, nedad=0;
    srand(time(0));
    cout<<"Ingrese un numero de alumnos:";
    cin>>nalumnos;
    for(contador=1;contador<=nalumnos;contador++){
        altura=rand()%(200-120+1)+120;
        edad=rand()%35+1;
        cout<<"Estudiante "<<contador<<"    Altura:"<<altura<<"     Edad:"<<edad<<endl;
        sumaAlturas+=altura;
        sumaedades+=edad;
        naltura+=maltura(altura);
        nedad+=medad(edad);
    }
    cout<<"Promedio de altura:"<<promAltura(sumaAlturas,nalumnos)<<endl;
    cout<<"Promedio de edades:"<<promedad(sumaedades,nalumnos)<<endl;
    cout<<"Alumnos que miden mas de 175cm: "<<naltura<<endl;
    cout<<"Alumnos que tienen mas de 18: "<<nedad<<endl;
    return 0;
}
