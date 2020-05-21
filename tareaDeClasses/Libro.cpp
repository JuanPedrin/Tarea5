#include "Libro.h"
#include "Persona.h"
#include <iostream>
#include <cstring>
using namespace std;
Libro::Libro()
{

}
Libro::Libro(char titulo[100],Persona autor,int annio,char genero[100],char editorial[100],char isbn[100])
{
    strcpy(this->titulo,titulo);
    this-> autor = autor;
    this->annio=annio;
    strcpy(this->genero,genero);
    strcpy(this->editorial,editorial);
    strcpy(this->isbn,isbn);
}
void Libro::consultarAutor(){
    this->autor.toString();
}
void Libro::toString(){
    cout <<endl<< "---Datos del libro---"<<endl<<endl;
    cout << "Titulo "<< this->titulo <<endl;
    cout << "annio: "<< this->annio <<endl;
    cout << "Genero: "<< this-> genero <<endl;
    cout << "Editorial: "<< this-> editorial <<endl;
    this->autor.toString();
    //cout << "IMC: "<< this->calcularIMC()<<endl<<endl;
}
