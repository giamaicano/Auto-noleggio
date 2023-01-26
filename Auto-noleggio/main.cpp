/*
Categoria	 Marca	 Modello	 Colore	 Lunedì	 Martedì	 Mercoledì	 Giovedì	 Venerdi	 Sabato	 Domenica
utilitaria	 FIAT	 Panda	 rosso	 L	 L	 L	 A	 A	 A	 A
utilitaria	 KIA	 Pikanto	 bronzo	 A	 A	 L	 L	 L	 A	 A
lusso	 Mercedes	 Classe 5	 nero	 L	 L	 L	 L	 L	 A	 A
sportiva	 Lamborghini	 Huracan	 giallo	 L	 L	 L	 L	 L	 L	 L
furgone	 Ford	 Transit	 bianco	 A	 A	 A	 A	 A	 L	 L
lusso	 BMW	 Serie 5	 grigio metallizzato	 L	 L	 L	 L	 L	 A	 A
utilitaria	 Peugeot	108	 verde	 L	 A	 L	 L	 L	 A	 L
*/


#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;


struct auton{

    string categoria,marca,modello,colore;
    string l,ma,me,g,v,s,d;
};



void vis_lista(auton an[],int &cont)
{
    ifstream fin("Autotab.csv");
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
void ricerca(auton an[],int &cont,int g[],int sc1)
{

    string c;
    int v = 1,b = 0,i = 1,k,vi[10],ac = 1;
    bool contr,cc = false;

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
                vi[b] = v;
            }
        }
     v++;
    }


    if(b != 0)
    {

        cout<<endl<<endl<<"Inserire il numero corrispondente all'auto che si vuole affittare: ";
        do{
        cin>>sc1;
        if(sc1>b || sc1<0)
            cout<<"Inserimento errato, riprovare: ";
        }while(sc1>b || sc1<0);

    }
    else
        cout<<endl<<"Non sono state trovate macchine disponibili con le seguenti caratteristiche"<<endl;


        while(g[ac] != 8)
        {
            switch(g[ac])
            {

                 case 1:
                    an[vi[sc1]].l = " A";

                 break;

                 case 2:
                    an[vi[sc1]].ma = " A";

                 break;

                 case 3:
                    an[vi[sc1]].me = " A";

                 break;

                 case 4:
                    an[vi[sc1]].g = " A";

                 break;
                 case 5:
                    an[vi[sc1]].v = " A";

                 break;

                 case 6:
                    an[vi[sc1]].s = " A";

                 break;
                 case 7:
                    an[vi[sc1]].d = " A";

                 break;

            }
          ac++;
        }





}

void stampa(auto an[],int &cont)
{
    int sp = 0;
    string app1 = "";

    ofstream fout("Autotest.txt");

    while(sp != cont)
    {
        fout<<an[sp].categoria<<',';
        fout<<an[sp].marca<<',';
        fout<<an[sp].modello<<',';
        fout<<an[sp].colore<<',';
        fout<<an[sp].l<<',';
        fout<<an[sp].ma<<',';
        fout<<an[sp].me<<',';
        fout<<an[sp].g<<',';
        fout<<an[sp].v<<',';
        fout<<an[sp].s<<',';
        fout<<an[sp].d;
        fout<<endl;

        sp++;

    }

    fout.close();


    ifstream fin("Autotest.txt");

    while(getline(fin,app1,','))
    {
      cout<<app1<<"  ";
    }


    fin.close();


}


void menu()
{

    auton an[20];

    int sc,cont = 0,g[10],sc1;

    do
    {
        cout << endl<<"MENU'" << endl;
        cout << "1) Visualizzazione della lista delle automobili" << endl
             << "2) Inserimento della categoria e dei giorni di noleggio " << endl
             << "3) Stampa del file aggiornato " << endl
             << "4) Esci.. " << endl<<endl
             << ">> ";
            cin>>sc;

            switch(sc)
            {
                case 1:
                    vis_lista(an,cont);

                    break;

                case 2:
                ricerca(an,cont,g,sc1);
                    break;

                case 3:
                    stampa(an,cont);
                    break;


            }


    }while(sc!=4);



}
int main()
{

    menu();


    return 0;
}

