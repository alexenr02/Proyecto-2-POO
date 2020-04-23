#include <iostream>
#include "Actor.h"


using namespace std;


class Pelicula{
    private:
        int numPeli;
        string titulo;
        int anio;
        int duracion;
        string genero;
        int cantActores; //cantidad de actores que hay en el arreglo listaActores
        Actor listaActores[10];

    public:
        //constructores
        Pelicula(); //constructor default

        //metodos GET (Acceso)
        int getNumPeli()             {return numPeli;};
        string getTitulo()           {return titulo;}; //metodo para verificar el numero de pelicula
        int getAnio()                {return anio;};
        int getDuracion()            {return duracion;};
        string getGenero()           {return genero;};
        int getCantActores()         {return cantActores;};

        //static int getCantActores()  {return cantActores; };

        Actor getlistaActores(int subind)      {return listaActores[subind] ;};

        void getListaCompleta() {

            //for (Actor a : listaActores){
            for(int x=0; x<cantActores;x++)
            {
                    //cout << listaActores[x].getiD()<< "  ";
                    cout<<"\n" <<x+1<<".- "<< listaActores[x].getNombre() << "\n";


            };};

        // declaracion de Metodos SET
        void setNumPeli(int _numPeli)          {numPeli=_numPeli;}; //Metodo para modificar el numero de la pelicula
        void setTitulo(string _titulo)         {titulo=_titulo;};
        void setAnio(int _anio)                {anio=_anio;};
        void setDuracion(int _duracion)        {duracion=_duracion;};
        void setGenero(string _genero)         {genero=_genero;};


        // declaracion de Metodos
        bool agregarActor(Actor _actor);
        //metodo para get de actor
        };






