#include <iostream>
#include "Pelicula.h"
#include "Funcion.h"
#include <fstream>
#include <string>
#include <clocale>


using namespace std;
void mostrarMenu()
{
        cout << "\n\n------------Menú---------------" << endl << endl;
        cout << "a. Mostrar todos los actores de la lista." << endl;
        cout << "b. Mostrar todas las peliculas de la lista." << endl;
        cout << "c. Mostrar las funciones disponibles. " << endl;
        cout << "d. Consulta funciones por hora. " << endl;
        cout << "e. Consulta por clave de pelicula. " << endl;
        cout << "f. Consulta de peliculas en las que participa un actor." << endl;
        cout << "g. Terminar. " << endl;

}
int main()
{
    setlocale(LC_CTYPE,"Spanish");
    Actor arrListaActores[20];
    //Pelicula arrListaActPeli[10];
    Pelicula arrPeliculas[20];
    ifstream archivoActores;
    archivoActores.open("actores.txt");
    ifstream archivoPeliculas;
    archivoPeliculas.open("peliculas.txt");
    int iDD,numPeli,anio,duracion,cantidadAct=0,a=0,e=0, esp,k;
    string nombreActor,genero,nombrePeli,linea1;
    Actor temporal[10]; //arreglo que me sirve para agregar los actores correspondientes a cada pelicula. Como al principio no sé cuantos serán, hago un arreglo con los que se ocupen y luego los agrego al atributo de la clase pelicula.
    char opcionDeseada;

    int datosActores[10]; //arreglo que me sirve para saber qué ids guardar en mi objeto tipo pelicula
        while(getline(archivoActores,nombreActor))
            {
                iDD= stoi(nombreActor);
                arrListaActores[a].setiD(iDD);
                nombreActor.erase(0,3);
                arrListaActores[a].setNombre(nombreActor);
                a++;
            }

   // arrListaActores[6].muestraActor();
        while(getline(archivoPeliculas,linea1))
        {
            numPeli=stoi(linea1);           linea1=linea1.erase(0,4);
            anio=stoi(linea1);              linea1=linea1.erase(0,5);
            duracion=stoi(linea1);          linea1=linea1.erase(0,4);
            genero=linea1;                  esp=genero.find(" "); genero=genero.erase(esp); linea1=linea1.erase(0,esp);
            cantidadAct=stoi(linea1);       linea1=linea1.erase(0,3);
            arrPeliculas[e].setNumPeli(numPeli);
            arrPeliculas[e].setAnio(anio);
            arrPeliculas[e].setDuracion(duracion);
            arrPeliculas[e].setGenero(genero);
            for(int x=0; x<cantidadAct;x++)
            {
                datosActores[x]=stoi(linea1);
                linea1=linea1.erase(0,3);
            }

            for(int x=0; x<cantidadAct; x++)
                    {
                        for(int y=0; y<20;y++)
                            {
                                if(arrListaActores[y].getiD()==datosActores[x])
                                    {
                                        temporal[x].setiD(datosActores[x]);
                                        temporal[x].setNombre(arrListaActores[y].getNombre());
                                        arrPeliculas[e].agregarActor(temporal[x]);
                                    }
                            }
                    }
                                arrPeliculas[e].setTitulo(linea1);
                                e++;



        }
        archivoPeliculas.close();
        archivoActores.close();
        //cout << arrPeliculas[0].getlistaActores(1).getiD()<< "  ";
        //cout << arrPeliculas[0].getlistaActores(1).getNombre() << endl;
        Funcion arrFuncionesXDia[20];
        int numFuncionesXDia;
        cout << "\nTeclea los datos para cada una de las funciones disponibles del día" << endl;
        cout << "\n¿Cuántas serán?--> ";
        cin >> numFuncionesXDia;
        int numfuncion,hra, minu,sala;
        Hora hrafuncion;
        string cvefuncion;
        bool validar,terminar=false;

        for(int x=0; x<numFuncionesXDia;x++)
        {

            cout << "\n-----------Función " << x+1<<"----------------\n\n";

            do{
                validar=true;
                cout << "Ingresa la clave de la función: ";
                cin >> cvefuncion;
                for(int x=0; x<numFuncionesXDia;x++)
                {
                    if(arrFuncionesXDia[x].getCveFuncion()==cvefuncion)
                        {
                            cout << "No puede haber dos funciones con la misma clave. \n\n" ;
                            validar=false;
                        }
                }
            arrFuncionesXDia[x].setCveFuncion(cvefuncion);
            }while(validar==false);
            numfuncion=0;
            do{
                cout << "Ingresa el número de la Pelicula: ";
                cin >> numfuncion;
                for(int x=0; x<e;x++)
                {
                    if(arrPeliculas[x].getNumPeli()==numfuncion)
                    {
                        validar=true;
                        goto continua;
                    }else{
                        validar=false;

                    }
                }
                cout << "\nError: No ingresaste un código de película correcto. \n\n";
            }while(validar==false);
continua:
            arrFuncionesXDia[x].setNumPeli(numfuncion);
            do{
                validar=true;
                cout << "Ingresa la hora de la función: " ;
                cin >> hra;
                if(hra==24)
                    hra=0;
                (hra>=0 && hra<25)?hra:validar=false;
                if(validar==false)
                    cout<<"\nError: Ingrese una hora del 0 al 24\n";
            }while(validar==false);
         do{
                    validar=true;
                    cout << "¿Y los minutos?--> ";
                    cin >>minu;
                    (minu>=0 && minu<60)?minu:validar=false;
                    if(validar==false)
                    cout<<"\nError: Ingrese minutos del 0 al 59.\n";
                }while(validar==false);
            hrafuncion.setHora(hra);        hrafuncion.setMinutos(minu);
            arrFuncionesXDia[x].setHora(hrafuncion);


            do{
            validar=true;
            cout << "Ingresa la sala de la función: ";
            cin >> sala;
            for(int x=0; x<numFuncionesXDia;x++)
                {
                    if(arrFuncionesXDia[x].getHora().getHora()==hra)
                        if(arrFuncionesXDia[x].getHora().getMinutos()==minu)
                            if(arrFuncionesXDia[x].getSala()==sala)
                                {
                                    cout << "\nNo puede haber dos funciones a la misma hora en la misma sala. \n\n" ;
                                    validar=false;
                                }
                }
            }while(validar==false);
            arrFuncionesXDia[x].setSala(sala);
        }
    do
    {
        mostrarMenu();
        cout << "\nTu opción es:(A,B,C,D,E, F o G) --->  ";
        cin >> opcionDeseada;
        cout<< endl;
        opcionDeseada=toupper(opcionDeseada);
        k=0;
        int f=-1;
        switch(opcionDeseada)
        {
            case 'A':
                cout << "---------------------------|\n";
                cout << "  ID  |       Nombre       |\n";
                cout << "______|____________________|\n";
                cout << "      |                     \n";
                for(int x=0; x<a; x++)
                    arrListaActores[x].muestraActor();
                break;
            case 'B':
                cout << "---------------------------------Peliculas--------------------------------" << endl;
                for(int x=0; x<e; x++)
                    {
                        cout << "__________________\n";
                        cout << "                  |\n";
                        cout << "      Título      |    ";
                        cout << arrPeliculas[x].getTitulo() <<"."<< endl;
                        cout << "__________________|\n\n";
                        cout << "________________________________\n";
                        cout << "    |\t            |\t        |\n";
                        cout << "Año "<<"|\tDuración    " << "|\tGénero  |" << endl;
                        cout << "____|_______________|___________|\n\n";
                        cout << arrPeliculas[x].getAnio() <<"\t"<< arrPeliculas[x].getDuracion()<< " minutos.\t";
                        cout <<  arrPeliculas[x].getGenero() << "\n\n---------Actores----------\n" ;
                        arrPeliculas[x].getListaCompleta();
                        cout << endl << endl;
                    }
                break;
            case 'C':
                cout << "------------------------------Funciones del día----------------------------" << endl << endl;
                for(int x=0; x<numFuncionesXDia;x++)
                {
                    cout << "----------------->     Función " << x+1 <<"      <----------------\n\n";
                    cout << "Clave" << "\tNombre de la pelicula"<< "\t# de sala"  << "\tHora\n\n";
                    cout << "  "<<arrFuncionesXDia[x].getCveFuncion()<< "\t";
                    for (int y=0;y<e;y++)
                    {
                        if(arrFuncionesXDia[x].getNumPeli()==arrPeliculas[y].getNumPeli())
                        {
                            nombrePeli=arrPeliculas[y].getTitulo();
                        }
                    }
                    cout << nombrePeli << "\t";
                    cout <<"     "<< arrFuncionesXDia[x].getSala()<< "\t\t";
                    arrFuncionesXDia[x].getHora().muestraHora();
                    cout << "\n\n";
                }
                break;
            case 'D':
                int encontro;

            do{
                cout << "\n¿Qué hora deseas consultar? --> ";
                validar=true;
                cin >> hra;
                (hra>=0 && hra<25)?hra:validar=false;
                if(hra==24)
                    hra=0;
            }while(validar==false);
            cout << "¿Y los minutos?-->  ";
            do{
                validar=true;
                cin >>minu;
                (minu>=0 && minu<60)?minu:validar=false;
            }while(validar==false);
            for(int x=0; x<numFuncionesXDia;x++)
            {
                if(hra==arrFuncionesXDia[x].getHora().getHora())
                    if(minu==arrFuncionesXDia[x].getHora().getMinutos())
                    {
                        for(int y=0; y<e;y++)
                        {
                            if(arrFuncionesXDia[x].getNumPeli()==arrPeliculas[y].getNumPeli())
                            {
                                cout << "\n------------------Funciones a las: ";
                                arrFuncionesXDia[x].getHora().muestraHora();
                                cout <<" ------------------\n\n";
                                cout << "Pelicula: " << arrPeliculas[y].getTitulo()<<"." << "\t--> Sala : ";
                                cout << arrFuncionesXDia[x].getSala() << endl <<endl;
                                encontro=1;
                            }
                        }
                    }

            }
            if(encontro!=1)
                cout << "No hay funciones a esa hora.\n\n";


                break;
            case 'E':
                int variable,variable2;
                do{
                validar=false;
                cout <<"Ingresa la clave de la función que deseas revisar: ";
                cin >> cvefuncion;
                for(int x=0; x<numFuncionesXDia;x++)
                    if(arrFuncionesXDia[x].getCveFuncion()==cvefuncion) //Verificando que la clave de funcion exista y
                        {                                               //guardando la posicion de ese objeto en "variable"
                                                                        //dentro del arreglo de funciones por día.
                            variable=x;
                            validar=true;
                        }
                if(validar==false)
                    cout<< "Error: No ingresaste una clave correcta. Intenta de nuevo. \n\n" ;
                }while(validar==false);
                cout <<"\n\n------------------------------Clave: " << cvefuncion << " ----------------------------" << endl << endl;
                cout << "Se presenta en la sala número " << arrFuncionesXDia[variable].getSala() << " a las: ";
                arrFuncionesXDia[variable].getHora().muestraHora();

                for (int x=0; x<e;x++)
                    {
                        if(arrFuncionesXDia[variable].getNumPeli()==arrPeliculas[x].getNumPeli())
                            {
                                variable2=x;
                            }
                    }
                cout <<"\nTitulo: " << arrPeliculas[variable2].getTitulo()<< endl;
                cout <<"\nDuración : " <<arrPeliculas[variable2].getDuracion()<<" Minutos. " <<endl;
                cout <<"\nGénero: " << arrPeliculas[variable2].getGenero()<< endl;
                cout <<"\n-->Lista de actores\n\n";
                arrPeliculas[variable2].getListaCompleta();
                cout << endl;
                break;
            case 'F':
                do{
                    cout << "Ingresa el ID del actor: ";
                    validar=false;
                    cin >>iDD;
                    for(int x=0;x<a;x++)
                        {
                            if(arrListaActores[x].getiD()==iDD)
                                {
                                    variable=x;
                                    validar=true;
                                }
                        }
                    if(validar==true)
                            for(int x=0; x<e;x++)
                                for(int y=0; y<cantidadAct;y++)
                                {
                                    if(arrListaActores[variable].getiD()==arrPeliculas[x].getlistaActores(y).getiD())
                                        {
                                            cout <<"\n\n"<< arrPeliculas[x].getTitulo() << "   ||   Año: " << arrPeliculas[x].getAnio();
                                        }
                                }
                    if(validar==false)
                        cout << "Error. No ingresaste un ID válido, intenta de nuevo. \n\n";

                }while(validar==false);

                break;
            case 'G':
                cout << "Gracias, hasta luego" << endl;
                return 0;
            default:
                cout<< "\nNo es una opción correcta, ingresa A,B,C,D,E o F según desees.\n" << endl;


        }if(opcionDeseada=='G')
        {
            terminar=true;
        }

    }while(terminar==false);
}
