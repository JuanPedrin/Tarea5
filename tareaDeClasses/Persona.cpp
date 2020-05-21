#include <iostream>
#include <cstring>
#include "Persona.h"
using namespace std;

Persona::Persona(){

}

Persona::Persona(char nombres[100],char apellidos[100],char nacionalidad[100]){
    strcpy(this->nombres,nombres);
    strcpy(this->apellidos,apellidos);
    strcpy(this->nacionalidad,nacionalidad);

}

void Persona::toString(){
    cout <<endl<< "---Informacion del autor---"<<endl<<endl;
    cout << "Nombre: "<< this->nombres<<endl;
    cout << "Apellidos: "<< this->apellidos <<endl;
    cout << "Nacionalidad: "<< this-> nacionalidad <<endl;
    //cout << "IMC: "<< this->calcularIMC()<<endl<<endl;
}
