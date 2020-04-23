#include "Funcion.h"
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

Funcion::Funcion() // constructor default
{
    cveFuncion = "indef";
    numPeli = 001;
    sala= 0;
    hora=Hora();
}

Funcion::Funcion(string _cveFuncion,int _numPeli,int _sala, Hora _hora) // constructor por parametros
{
    cveFuncion = _cveFuncion;
    numPeli = _numPeli;
    sala= _sala;
    hora=_hora;
}

void Funcion::muestraFuncion()
{
    cout << "Clave de la funcion: "<< cveFuncion << endl;
    cout << "Numero de Pelicula: "<< numPeli << endl;
    cout << "Sala: " << sala << endl;
    hora.muestraHora();
}
