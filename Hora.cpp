#include "Hora.h"
#include <string>
#include<iomanip>
#include<iostream>
using namespace std;
Hora::Hora() // constructor default
{
    hora = 0;
    mm = 0;
}

Hora::Hora(int h, int m) // constructor por parametros
{
    if(h==24)
        h=0;
    hora = h;
    mm = m;
}

void Hora::muestraHora()
{
	cout << setw(2) << setfill('0') << hora << ":"
	<< setw(2) << setfill('0') << mm;
}
