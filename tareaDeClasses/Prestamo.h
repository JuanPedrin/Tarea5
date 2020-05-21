#ifndef PRESTAMO_H
#define PRESTAMO_H


class Prestamo
{
    private:
        int usuario;
        int libro;
        char fechaInicial[100];
        char fechaFinal[100];
        int estatus;
    public:
        Prestamo();
        Prestamo(int,int,char[]);
        void devolucion(char[]);
        int getUsuario();
        int getLibro();
        int getEstatus();
        void toString();
};

#endif // PRESTAMO_H
