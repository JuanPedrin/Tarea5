#ifndef PERSONA_H
#define PERSONA_H

class Persona{
    private:
        char nombres[100];
        char apellidos[100];
        char nacionalidad[100];

    public:
        Persona();
        Persona(char[],char[],char[]);
        void toString();
};

#endif // PERSONA_H
