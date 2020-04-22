#include <iostream>
#include"Nod.h"
#include"Nod_dublu.h"
#include"Nod_prioritate.h"
#include "Coada_prioritati.h"
using namespace std;

int main()
{
    try{
        Nod_prioritate m;
    }
    catch(std::exception &exp){
        cout<<exp.what()<<'\n';
    }
    Nod a("ana",0);
    cout<<a;
    Nod aa("maria",0);
    cout<<aa;
    Nod_dublu b("are",0,0);
    cout<<b;
    Nod_dublu c("",0,0);
    cout<<c;
    Nod_prioritate d("mere",0,0,13);
    cout<<d;
    int x=d.getPrio();
    cout<<x<<endl;
    Nod_dublu w=b;
    cout<<w;
    Nod_prioritate t=d;
    cout<<t;
    x=t.getPrio();
    cout<<x<<endl;
    Coada_prioritati Coada;
    cout<<Coada;
    Coada.adauga(Nod_prioritate("avram",0,0,5));
    Coada.adauga(Nod_prioritate("ana",0,0,10));
    cout<<Coada;
    Coada.top();
    Coada.inserare(Nod_prioritate("place",0,0,30),1);
    cout<<Coada;
    Coada.pop();
    cout<<Coada;
    Coada.adauga(Nod_prioritate("a1",0,0,1));
    Coada.adauga(Nod_prioritate("a2",0,0,2));
    Coada.adauga(Nod_prioritate("a3",0,0,3));
    Coada.adauga(Nod_prioritate("a4",0,0,50));
    cout<<Coada;
    Coada.top();
    Coada.pop();
    cout<<Coada;
    Coada.pop();
    cout<<Coada;
    Coada_prioritati Coada1(Coada);
    cout<<Coada1;
    Coada1.pop();
    Coada_prioritati Coada2=Coada1;
    Coada2.adauga(Nod_prioritate("a5",0,0,61));
    cout<<Coada2;
    Coada2.empty();
    cout<<Coada2;
    Coada2.adauga(Nod_prioritate("a6",0,0,1));
    Coada2.adauga(Nod_prioritate("a7",0,0,11));
    Coada2.adauga(Nod_prioritate("a8",0,0,12));
    Coada2.adauga(Nod_prioritate("a9",0,0,13));
    cout<<Coada2;
    Coada2.pop();
    cout<<Coada2;
}
