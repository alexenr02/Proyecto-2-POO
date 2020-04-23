#include <iostream>
#include <string>

using namespace std;

class Actor{
    public:
        //constructores
        Actor(); //constructor default
        Actor(int idd,string nom); // constructor por parametros

        //Metodos GET
        int getiD()                {return iD;};
        string getNombre()         {return Nombre;}; //metodo para verificar el nombre del objeto Actor

        //Metodos SET
        void setiD(int idd){iD=idd;}; //Metodo para sobreescribir el ID
        void setNombre(string nom){Nombre=nom;};

        //Metodo muestra
        void muestraActor(); //Método para mostrar nombre
    private:
        int iD;
        string Nombre;
        };








