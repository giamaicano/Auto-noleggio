#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;



struct auton{

    string categoria,marca,modello,colore;
    //string giorni[7];
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
      getline(fin,an[cont].marca,',');
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
void ricerca(auton an[])
{
    ifstream fin("Auto.csv");

    string c;
    int v = 1,b = 0,g[10],i = 1,k;
    bool contr;

    cout<<"Inserire il categoria di auto che si vuole noleggiare: ";
    cin>>c;
    cout<<"Inserire i giorni in cui la si vuole noleggiare(1,2,3,4,5,6,7)(8 per uscire): "<<endl;

    do
    {
       cin>>g[i];
       if(g[i]<8 && g[i]>-1)
       i++;
       else if(g[i]==8)
        cout<<"Ricerca in corso..."<<endl;
       else
        cout<<"Numero sbagliato"<<endl;
    }while(g[i]!=8 && i!=8);


    cout<<"Auto disponibili: ";
    while(an[v].categoria != "0")
    {   k = 1; contr = false;

        //cout<<an[v].categoria;
        if(an[v].categoria == c)
        {

            while(g[k]!=8)
            {
                switch(g[k])
                {
                case 1:
                    if(an[v].l == "L")
                    contr = true;

                    else{
                    contr = false;
                    k = 7;
                    }
                break;

                case 2:
                    if(an[v].ma == "L")
                    contr = true;

                    else{
                    contr = false;
                    k = 7;
                    }
                break;

                 case 3:
                    if(an[v].me == "L")
                    contr = true;

                    else{
                    contr = false;
                    k = 7;
                    }
                break;

                case 4:
                    if(an[v].g == "L")
                    contr = true;

                    else{
                    contr = false;
                    k = 7;
                    }
                break;
                case 5:
                    if(an[v].v == "L")
                    contr = true;

                    else{
                    contr = false;
                    k = 7;
                    }
                break;

                case 6:
                    if(an[v].s == "L")
                    contr = true;

                    else{
                    contr = false;
                    k = 7;
                    }
                break;
                case 7:
                    if(an[v].d == "L")
                    contr = true;

                    else{
                    contr = false;
                    k = 7;
                    }
                break;

                }
             k++;
            }
                if(contr == true)
                //b++;
                cout<<b<<")"<<an[v+1].categoria<<setw(3);

        }
     v++;
    }

    fin.close();
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
                ricerca(an);
                    break;


            }




    }while(sc!=4);



}
int main()
{

    menu();


    return 0;
}

