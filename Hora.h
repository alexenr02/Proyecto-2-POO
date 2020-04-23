class Hora
{
    public:
        Hora(); //constructor default
        Hora(int hora, int mm); // constructor por parametros
        int getHora()                {return hora;};
        int getMinutos()         {return mm;};
        void setHora(int h){hora = ((h>=0 && h<25)?h:0);}; //Metodo para sobreescribir la hora
        void setMinutos(int m){mm = ((m>=0 && m<60)?m:0);};
        void muestraHora(); //metodo para mostrar hora
    private:
        int hora, mm;
};
