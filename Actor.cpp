#include "Actor.h"

using namespace std;

Actor::Actor() // constructor default
{
    iD = 0;
    Nombre = "unknown";
}

Actor::Actor(int idd, string nom) // constructor por parametros
{
    iD = idd;
    Nombre = nom;
}

void Actor::muestraActor() //Metodo muestra
{
    cout << "  "<< iD<< "  |  " << Nombre <<"  "<< endl;

}
