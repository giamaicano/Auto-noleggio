#include <iostream>
#include <fstream>

using namespace std;

struct g_s
{
    char l,ma,me,g,v,s,d;
};

struct auton{

    string categoria,marca,modello,colore;
    struct g_s gds;
};

void ricerca()
{



}

void stampa()
{



}


void menu()
{
    auton an[20];
    int sc;

    do
    {
        cout << endl<<"MENU'" << endl;
        cout << "1) Inserimento della categoria e dei giorni in cui si vuole utilizzare l'autovettura" << endl
             << "2) Stampa del file aggiornato " << endl
             << "3) Esci.. " << endl<<endl
             << ">> ";
            cin>>sc;

            switch(sc)
            {
                case 1:

                    break;

                case 2:

                    break;

                case 3:
                    return 0;
                    break;

            }




    }while(true);



}
int main()
{

    menu();


    return 0;
}

