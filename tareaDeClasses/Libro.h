#ifndef LIBRO_H
#define LIBRO_H
#include "Persona.h"

class Libro
{
    private:
        char titulo[100];
        Persona autor;
        int annio;
        char genero[100];
        char editorial[100];
        char isbn[100];
    public:
        Libro();
        Libro(char[],Persona,int, char[],char[],char[]);
        void consultarAutor();
        void toString();
};

#endif // LIBRO_H
