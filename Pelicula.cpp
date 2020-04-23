#include "Pelicula.h"
#include "Funcion.h"
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

Pelicula::Pelicula() // constructor default
{
    numPeli=0;
    titulo="N/A";
    anio=1000;
    duracion=001;
    genero="N/A";
    cantActores=0; //cantidad de actores que hay en el arreglo listaActores
    listaActores[10];
}


bool Pelicula::agregarActor(Actor _actor)
{
    if(cantActores>10){
        return false;
        }
        else{
                for(int x=0; x<cantActores;x++)
                    {
                        if(_actor.getiD()==listaActores[x].getiD())
                            {
                                return false;
                            }
                    }
                    listaActores[cantActores]=_actor;
                    cantActores++;
                    return true;
            }

}
// pides al usuario
// cin >> a
// listaFunciones[i].setcve(a);
// cunado pidas la hora, validar que sea correcto
// h, m
// while (h < 0 && h >60...
// quieres agregar otra pelicula? no, te vas al menu

// arregloActores y validar que exista el id ingresado
// arreglo peliculas y buscar en las que ha participado ese actor
// cin >> idActor  ...52
// arregloActores, si no lo encuentras regresas mensaje de que no se econtro, vuelves a menu
// --- arreglopeliculas e ir verificando pelicula por pelicula....recorres arregloPeliculas[i].listaACtores ...
// -------si encuentras el id en tu listaActores de la arregloPeliculas[i], ya imprimes el titulo y anio de la pelicula i

