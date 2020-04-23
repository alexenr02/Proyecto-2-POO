#include "Hora.h"
#include <string>

using namespace std;

class Funcion
{
    public:
        //constructores
        Funcion(); //constructor default
        Funcion(string _cveFuncion,int _numPeli, int _sala, Hora _hora); // constructor por parametros

        //metodos GET
        string getCveFuncion()      {return cveFuncion;};
        int getNumPeli()            {return numPeli;}; //metodo para verificar el numero de pelicula
        int getSala()               {return sala;};
        Hora getHora()              {return hora;};

        //Metodos SET
        void setCveFuncion(string _cveFuncion)      {cveFuncion=_cveFuncion;}; //Metodo para modificar la clave de la funcion
        void setNumPeli(int _numPeli)               {numPeli=_numPeli;};
        void setSala(int _sala)                     {sala=_sala;};
        void setHora(Hora _hora )                   {hora=_hora;};

        //metodo muestra
        void muestraFuncion(); //método para mostrar


    private:
        string cveFuncion;
        int numPeli;
        int sala;
        Hora hora;
};
