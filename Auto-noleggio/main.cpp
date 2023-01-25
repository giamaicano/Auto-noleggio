#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;


struct auton{

    string categoria,marca,modello,colore;
    //string giorni[7];
    string l,ma,me,g,v,s,d;
};



void vis_lista(auton an[],int &cont)
{
    ifstream fin("Auto.csv");
    string app;

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
void ricerca(auton an[],int &cont)
{
    ifstream fin("Auto.csv");
    string c;
    int v = 1,b = 0,g[10],i = 1,k;
    bool contr,cc = false;

    //cout<<"Inserire la categoria di auto ed i giorni in cui la si vuole noleggiare(1,2,3,4,5,6,7)(suddivisi da uno spazio) : ";
    cout<<"Inserire la categoria di auto che si vuole noleggiare: ";

    do{
            cin>>c;
        for(int i=0;i<cont;i++)
        {
            if(c == an[i].categoria)
                cc = true;

        }
        if(cc == false)
            cout<<"La categoria inserita non esiste, riprovare: ";
    }while(cc == false);

    cout<<"Inserire i rispettivi giorni (1,2,3,4,5,6,7)(inserire 8 per uscire): "<<endl;


 /*    do
    {
        c[t] = cg[t];
        cout<<c[t]<<endl;
        cout<<"ciao";
        t++;

    }
     while(cg[t] != ' ');

    do
    {
        if(cg[t] != ' ')
        g[i] = cg[t];
        cout<<"lol";
        t++; i++;
    }
    while(cg[t] != ' '  &&  cg[t+1] != ' ');

    i = 0;
*/


    do
    {
       cin>>g[i];
       if(g[i]<8 && g[i]>-1)
       i++;
       else if(g[i]==8)
        cout<<"Ricerca in corso..."<<endl<<endl;
       else
        cout<<"Numero sbagliato"<<endl;
    }while(g[i]!=8 && i!=8);


    cout<<"Auto disponibili: ";
    while(v<=cont)
    {   k = 1; contr = false;

        if(an[v].categoria == c)
        {

            while(g[k]!=8)
            {
                switch(g[k])
                {
                     case 1:
                        if(an[v].l == " L")
                        contr = true;

                        else
                        contr = false;
                     break;

                     case 2:
                        if(an[v].ma == " L")
                        contr = true;

                        else
                        contr = false;
                     break;

                     case 3:
                        if(an[v].me == " L")
                        contr = true;

                        else
                        contr = false;
                     break;

                     case 4:
                        if(an[v].g == " L")
                        contr = true;

                        else
                        contr = false;
                     break;
                     case 5:
                        if(an[v].v == " L")
                        contr = true;

                        else
                        contr = false;
                     break;

                     case 6:
                        if(an[v].s == " L")
                        contr = true;

                        else
                        contr = false;
                     break;
                     case 7:
                        if(an[v].d == " L")
                        contr = true;

                        else
                        contr = false;
                     break;

                }
            if(contr == false){
                k = 10;
                g[k] = 8;
                }
                else
             k++;
            }

            if(contr == true){
                b++;
                cout<<endl<<b<<")"<<an[v].categoria<<"  "<<an[v].marca<<"  "<<an[v].modello<<"  "<<an[v].colore;
            }
        }
     v++;
    }


    if(b != 0)
    {

        int sc1;

        cout<<endl<<endl<<"Inserire il numero corrispondente all'auto che si vuole affittare: ";
        do{
        cin>>sc1;
        if(sc1>b || sc1<0)
            cout<<"Inserimento errato, riprovare: ";
        }while(sc1>b || sc1<0);

    }
    else
        cout<<endl<<"Non sono state trovate macchine disponibili con le seguenti caratteristiche";




    fin.close();
}

void stampa()
{







}


void menu()
{

    auton an[20];

    int sc,cont = 0;;

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
                    vis_lista(an,cont);

                    break;

                case 2:
                ricerca(an,cont);
                    break;

                case 3:

                    break;


            }


    }while(sc!=4);



}
int main()
{

    menu();


    return 0;
}

