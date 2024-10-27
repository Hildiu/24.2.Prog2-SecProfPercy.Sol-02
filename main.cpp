#include <iostream>
#include <vector>
#include <time.h>
using namespace std;

string generateID()
{
    int ale = rand()%900000+999999;
    return "COD" + to_string(ale);
}

string generatePlace()
{
    int valor;
    string p;

    for (int i=1; i<=6; i++)
    {
        if (i<4)
        {
            valor = rand()%25+65;
            p = p + (char)valor;
        }
        else
        {
            valor = rand()%8+1;
            p = p + to_string(valor);
        }
    }

    return p;
}

int registravelocidad()
{
    return rand()%60 + 21;
}


class CEvento
{
private:
    string idevento;
    string placa;

    int velocidad;
public:

    CEvento(){}

    CEvento (int flag)
    {
        idevento = generateID();
        placa = generatePlace();
        velocidad = registravelocidad();
    }

    string getPlaca()
    {
        return placa;
    }

    int getVelocidad()
    {
        return velocidad;
    }

};


int main() {

    srand(time(0));
    //CREAMOS VECTOR CON 100 ESPACIOS DEL TIPO CEvento
    vector <CEvento> listaEventos(100);

    //LLENAMOS EL VECTOR CON OBJECTOS CEvento
    for (auto it = listaEventos.begin(); it!=listaEventos.end(); it ++)
    {
        CEvento ev(1); // El constructor genera aleatorimente los datos
        *it = ev; // se asigna el objeto a la posicion del iterador del vvector
    }

    //RECORREMOS EL VECTOR
    float suma; // suma de deuda
    for (auto it = listaEventos.begin(); it!=listaEventos.end(); it ++)
    {

        CEvento ev = *it; // Se recupera un objeto
        if (ev.getVelocidad() > 40)
        {
            float deuda = (ev.getVelocidad()-40)*1.5; // se calcula deuda
            suma = suma+deuda; // se acumula la deuda

            //SE IMPRIME PLACA , VELOCIDAD Y DEUDA
            cout << ev.getPlaca()<< "\t" << ev.getVelocidad() << " KM/H\t" << deuda << endl;
        }
    }

    //SE IMPRIME DEUDA TOTAL
    cout << "Deuda Total : " << suma << endl;

}
