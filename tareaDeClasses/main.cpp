#include <iostream>
#include <cstring>
#include "Persona.h"
#include "Libro.h"
#include "Prestamo.h"
using namespace std;

Persona registrarUsuario(){
    /*Autor*/
    char nombres[100]; char apellidos[100]; char nacionalidad[100];
    /*Autor*/
    cout << "Ingrese nombre del usuario:"<<endl;
    cin >> nombres;
    cout << "Ingrese apellido del usuario:"<<endl;
    cin >> apellidos;
    cout << "Ingrese la nacionalidad:"<<endl;
    cin >> nacionalidad;
    Persona usuario = Persona(nombres,apellidos,nacionalidad);
    return usuario;
}
Libro registrarLibro(){
    /*Autor*/
    char nombres[100]; char apellidos[100]; char nacionalidad[100];
    /*Autor*/
    /*Libro*/
    char titulo[100]; int annio; char genero[100]; char editorial[100]; char isbn[100];
    /*Libro*/

    cout << "Ingrese el titulo del libro:"<<endl;
    cin >> titulo;
    cout << "Ingrese nombre del autor:"<<endl;
    cin >> nombres;
    cout << "Ingrese apellido del autor:"<<endl;
    cin >> apellidos;
    cout << "Ingrese la nacionalidad:"<<endl;
    cin >> nacionalidad;

    cout << "Ingrese el annio de publicacion:"<<endl;
    cin >> annio;
    cout << "Ingrese el genero del libro:"<<endl;
    cin >> genero;
    cout << "Ingrese la editorial:"<<endl;
    cin >> editorial;
    cout << "Ingrese la Isbn"<<endl;
    cin >> isbn;

    return Libro(titulo,Persona(nombres,apellidos,nacionalidad),annio,genero,editorial,isbn);
}
Prestamo registrarPrestamo(int libro){
    int usuario;
    char fechaInicial[100];

    cout << "Ingrese el numero de usuario"<<endl;
    cin >> usuario;
    cout << "Ingrese la fecha inicial"<<endl;
    cin >> fechaInicial;

    Prestamo nuevoPrestamo = Prestamo(usuario,libro,fechaInicial);
    return nuevoPrestamo;
}
void mostrarLibros(Libro libros[10],int librosC){
    for (int i=0; i<librosC;i++){
        cout << "Libro "<<i<<endl;
        libros[i].toString();
    }
}
void menu(){
    cout <<endl<<"---MENU---" <<endl;
    cout <<"Opcion 1: Registrar libro." <<endl;
    cout <<"Opcion 2: Editar datos del libro." <<endl;
    cout <<"Opcion 3: Consultar autor." <<endl;
    cout <<"Opcion 4: Consultar datos." <<endl;
    cout <<"Opcion 5: Eliminar." <<endl;
}
void menuPrestamos(){
    cout << "---Menu de prestamos---"<<endl;
    cout << "1.-Realizar prestamo."<<endl;
    cout << "2.-Devolver libro."<<endl;
    cout << "3.-Consultar prestamo."<<endl;
    cout << "4.-Regresar"<<endl;
}
void menuUsuarios(){
    cout << "---Menu de Usuarios---"<<endl<<endl;
    cout << "1.-Registrar Usuario."<<endl;
    cout << "2.-Editar datos de usuario."<<endl;
    cout << "3.-Eliminar usuario."<<endl;
    cout << "4.-Consultar datos de usuario"<<endl;
}
void menuLibros(){
    cout <<endl<<"---Menu libros---" <<endl<<endl;
    cout <<"Opcion 1: Registrar libro." <<endl;
    cout <<"Opcion 2: Editar datos del libro." <<endl;
    cout <<"Opcion 3: Consultar autor." <<endl;
    cout <<"Opcion 4: Consultar datos." <<endl;
    cout <<"Opcion 5: Eliminar." <<endl;
}
int main()
{
    Libro libros[10];
    Persona usuarios[10];
    Prestamo prestamos[100];
    bool power=true,t=true;
    int opc = 0, librosC=0, num=0,imc=0, usuariosC=0, prestamosC=0,tB;
    char fechaFinal[100];
    while (power){
        menu();
        cin >>opc;
        switch(opc){
            case 1:
                menuUsuarios();
                cin >>opc;
                switch(opc){
                    case 1:
                        usuarios[usuariosC] = registrarUsuario();
                        usuariosC++;
                        break;
                    case 2:
                        cout << "Ingrese el numero del usuario"<<endl;
                        cin >> num;
                        usuarios[num].toString();
                        usuarios[num] = registrarUsuario();
                        break;
                    case 3:
                        cout << "Ingrese el numero del usuario"<<endl;
                        cin >> num;
                        usuarios[num].toString();
                        usuarios[num] = Persona();
                        cout<<"Data erased"<<endl;
                        break;
                    case 4:
                        cout << "Ingrese el numero del usuario"<<endl;
                        cin >> num;
                        usuarios[num].toString();
                        break;
                }
                break;
            case 2:
                menuLibros();
                cin >>opc;
                switch(opc){
                    case 1:
                        cout << "---Registo de libros---"<<endl<<endl;
                        libros[librosC] = registrarLibro();
                        librosC++;
                        cout << "Ingrese el numero de libro que desea editar:"<<endl;
                        cin >>num;
                        libros[num].toString();
                        libros[num]= registrarLibro();
                        break;
                    case 2:
                        cout << "Ingrese el numero de Libro cuyo autor desea consultar"<<endl;
                        cin >>num;
                        libros[num].consultarAutor();
                        break;
                    case 3:
                        cout << "Ingrese el numero de Libro"<<endl;
                        cin >>num;
                        libros[num].toString();
                        break;
                    case 4:
                        cout << "Ingrese el numero del Libro"<<endl;
                        cin >>num;
                        libros[num] = Libro();
                        cout <<endl<< "---Libro Eliminado---"<<endl;
                        break;
                }
            case 3:
                menuPrestamos();
                cin >>opc;
                switch(opc){
                    case 1:
                        mostrarLibros(libros,librosC);
                        cout << "Ingrese el numero del libro"<<endl;
                        cin >>num;
                        t=true;
                        for(int i=0;i<prestamosC;i++){
                            if(num==prestamos[i].getLibro() && prestamos[i].getEstatus()==1){
                                t=false;
                            }
                        }
                        if(t == true){
                            prestamos[prestamosC]=registrarPrestamo(num);
                            prestamosC++;
                        }else{
                            cout << "El libro ya está prestado"<<endl;
                        }
                        break;
                    case 2:
                        cout << "Ingresa el numero del prestamo"<<endl;
                        cin >>num;
                        usuarios[prestamos[num].getUsuario()].toString();
                        tB = prestamos[num].getLibro();
                        libros[tB].toString();
                        prestamos[num].toString();
                        if (prestamos[num].getEstatus()==1){
                            cout << "Ingresa la fecha de devolucion"<<endl;
                            cin >> fechaFinal;
                            prestamos[num].devolucion(fechaFinal);
                            cout << "Libro devuelto"<<endl;
                        }else{
                            cout << "El prestamo ha sido finalizado anteriormente"<<endl;
                        }
                        break;
                    case 3:
                        cout << "Ingresa el numero del prestamo"<<endl;
                        cin >>num;
                        usuarios[prestamos[num].getUsuario()].toString();
                        libros[prestamos[num].getLibro()].toString();
                        prestamos[num].toString();
                        break;

                }
        }
    }
    return 0;
}
