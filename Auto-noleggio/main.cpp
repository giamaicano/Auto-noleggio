#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;



struct auton{

    string categoria,marca,modello,colore;
    string l,ma,me,g,v,s,d;
};


void vis_lista(auton an[])
{
    ifstream fin("Auto.csv");
    string app;
    int cont = 0;
    while(getline(fin,app,','))
    {
      getline(fin,an[cont].categoria,',');
      getline(fin,an[cont].marca,' ');
      getline(fin,an[cont].modello,',');
      getline(fin,an[cont].colore,',');
      getline(fin,an[cont].l,',');
      getline(fin,an[cont].ma,',');
      getline(fin,an[cont].me,',');
      getline(fin,an[cont].g,',');
      getline(fin,an[cont].v,',');
      getline(fin,an[cont].s,',');
      getline(fin,an[cont].d);

      cout<<" "<<an[cont].categoria;
      cout<<" "<<an[cont].marca;
      cout<<" "<<an[cont].modello;
      cout<<"  "<<an[cont].colore;
      cout<<" "<<an[cont].l;
      cout<<" "<<an[cont].ma;
      cout<<" "<<an[cont].me;
      cout<<" "<<an[cont].g;
      cout<<" "<<an[cont].v;
      cout<<" "<<an[cont].s;
      cout<<" "<<an[cont].d;
      cout<<endl;


      cont++;
    }

    fin.close();
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
                    vis_lista(an);

                    break;

                case 2:

                    break;


            }




    }while(sc!=3);



}
int main()
{

    menu();


    return 0;
}

