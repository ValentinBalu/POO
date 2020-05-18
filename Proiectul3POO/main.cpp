#include <iostream>
#include <string>
#include <vector>
#include <exception>
using namespace std;


class Exceptia: public exception {
    const char* what_arg;
public:
  Exceptia(const char* what_arg) throw() {
    this->what_arg = what_arg;
  };
  ~Exceptia() throw() {};

  const char* what() const throw() {
    return this->what_arg;
  }
};

class Masina{
protected:
    int cai_putere;
    int capacitate_rezervor;
    string marca;
public:
    Masina(int cai_putere=0, int capacitate_rezervor=0, string marca=""):cai_putere(cai_putere),capacitate_rezervor(capacitate_rezervor),marca(marca){}
    Masina(const Masina &other):cai_putere(other.cai_putere),capacitate_rezervor(other.capacitate_rezervor),marca(other.marca){}
    ~Masina()=default;
    virtual void afisare(){
    cout<<"Cai putere : "<<this->cai_putere<<" , "<<"Capacitate rezervor : "<<this->capacitate_rezervor<<" , "<<"Marca : "<<this->marca<<'\n';
    }
    friend istream& operator>> (istream&, Masina&);
    friend ostream& operator<< (ostream&, Masina&);
};

istream& operator>>(istream &in, Masina &masina){
    cout<<"Introduceti numarul de cai putere, capacitatea rezervorului in cm3, marca masinii"<<'\n';
    in>>masina.cai_putere;
    in>>masina.capacitate_rezervor;
    in>>masina.marca;
    return in;
}

ostream& operator<<(ostream &cout, Masina &masina)
{
    masina.afisare();
    return cout;
}

class Coupe : public Masina{
public:
    Coupe(int cai_putere=0,int capacitate_rezervor=0,string marca=""):Masina(cai_putere,capacitate_rezervor,marca){}
    Coupe(const Coupe &other):Masina(other){}
    ~Coupe()=default;
    void afisare(){
        cout<<"Tip : Coupe , ";
        cout<<"Cai putere : "<<this->cai_putere<<" , "<<"Capacitate rezervor : "<<this->capacitate_rezervor<<" , "<<"Marca : "<<this->marca<<'\n';
    }
    friend istream& operator>> (istream&, Coupe&);
    friend ostream& operator<< (ostream&, Coupe&);
};

istream& operator>>(istream &in,Coupe &masina){
    in>>dynamic_cast<Masina&>(masina);
    return in;
}

ostream& operator<<(ostream &cout,Coupe &masina)
{
    masina.afisare();
    return cout;
}

class Hot_hatch : public Masina{
    int tip_motor; ///0-benzina,1-diesel
public:
    Hot_hatch(int cai_putere=0,int capacitate_rezervor=0,string marca="",int tip_motor=-1):Masina(cai_putere,capacitate_rezervor,marca),tip_motor(tip_motor){}
    Hot_hatch(const Hot_hatch &other):Masina(other),tip_motor(other.tip_motor){}
    ~Hot_hatch()=default;
    void afisare(){
        cout<<"Tip : Hot-Hatch , ";
        cout<<"Cai putere : "<<this->cai_putere<<" , "<<"Capacitate rezervor : "<<this->capacitate_rezervor<<" , "<<"Marca : "<<this->marca<<" , "<<"Tip motor : ";
        if (this->tip_motor==0)
            cout<<"Benzina"<<'\n';
        else
            cout<<"Diesel"<<'\n';
    }
    friend istream& operator>> (istream&, Hot_hatch&);
    friend ostream& operator<< (ostream&, Hot_hatch&);
};

istream& operator>>(istream &in,Hot_hatch &masina){
    in>>dynamic_cast<Masina&>(masina);
    cout<<"Adaugati si tipul motorului : 0-benzina, 1-diesel"<<'\n';
    in>>masina.tip_motor;
    return in;
}

ostream& operator<<(ostream &cout,Hot_hatch &masina)
{
    masina.afisare();
    return cout;
}

class Cabrio : public Masina{
    int tip_acoperis;///0-metalic,1-textil
public:
    Cabrio(int cai_putere=0,int capacitate_rezervor=0,string marca="",int tip_acoperis=-1):Masina(cai_putere,capacitate_rezervor,marca),tip_acoperis(tip_acoperis){}
    Cabrio(const Cabrio &other):Masina(other),tip_acoperis(tip_acoperis){}
    ~Cabrio()=default;
    void afisare(){
        cout<<"Tip : Cabrio , ";
        cout<<"Cai putere : "<<this->cai_putere<<" , "<<"Capacitate rezervor : "<<this->capacitate_rezervor<<" , "<<"Marca : "<<this->marca<<" , "<<"Tip acoperis : ";
        if(this->tip_acoperis==0)
            cout<<"Metalic"<<'\n';
        else
            cout<<"Textil"<<'\n';
    }
    friend istream& operator>> (istream&, Cabrio&);
    friend ostream& operator<< (ostream&, Cabrio&);
};

istream& operator>>(istream &in,Cabrio &masina){
    in>>dynamic_cast<Masina&>(masina);
    cout<<"Adaugati si tipul acoperisului : 0-metalic, 1-textil"<<'\n';
    in>>masina.tip_acoperis;
    return in;
}

ostream& operator<<(ostream &cout,Cabrio &masina)
{
    masina.afisare();
    return cout;
}

class SuperSport : public Masina{
    int pret;
    static int nr_ss;
public:
    SuperSport(int cai_putere=0,int capacitate_rezervor=0,string marca="",int pret=-1):Masina(cai_putere,capacitate_rezervor,marca),pret(pret){nr_ss++;}
    SuperSport(const SuperSport &other):Masina(other),pret(pret){nr_ss++;}
    ~SuperSport(){
        nr_ss--;
        if(pret==-1)
            throw(Exceptia("Masina nu a fost vanduta"));
    }
    void setpret(int pret){
        this->pret=pret;
    }
    void afisare(){
        cout<<"Tip : SuperSport , ";
        cout<<"Cai putere : "<<this->cai_putere<<" , "<<"Capacitate rezervor : "<<this->capacitate_rezervor<<" , "<<"Marca : "<<this->marca<<" , "<<"Pret : "<<this->pret<<'\n';
    }
    friend istream& operator>> (istream&, SuperSport&);
    friend ostream& operator<< (ostream&, SuperSport&);
    SuperSport operator+=(int &pretul){
        setpret(pretul);
    };
};
int SuperSport::nr_ss=0;

istream& operator>>(istream &in,SuperSport &masina){
    in>>dynamic_cast<Masina&>(masina);
    return in;
}

ostream& operator<<(ostream &cout,SuperSport &masina)
{
    masina.afisare();
    return cout;
}

void afisare_meniu(){
    cout<<"MENIU"<<'\n';
    cout<<"1. Introduceti o noua masina in expozitie!"<<'\n';
    cout<<"2. Afisati numarul total de masini expuse dintr-o expozitie si care sunt acestea!"<<'\n';
    cout<<"3. Doriti sa cumparati o masina de tip SuperSport?"<<'\n';
    cout<<"4. Afisati numarul de masini de tip SuperSport din stoc si care sunt acestea!"<<'\n';
    cout<<"5. Afisati numarul de masini de tip SuperSport vandute si care sunt acestea!"<<'\n';
    cout<<"6. Exit"<<'\n'<<'\n';


}
template <class T>
class Expozitie{
    int nr_total_expuse=0;
    vector<T*> masini_exp;
public:
    ~Expozitie(){
        for(int i=0;i<masini_exp.size();i++)
            delete masini_exp[i];
    }
    void adaugacar(){
        T* m1=new T;
        cin>>*m1;
        masini_exp.push_back(m1);
        nr_total_expuse++;
    }
    void getnr(){
        cout<<nr_total_expuse;
    }
    void getcar(){
        for(int i=0;i<masini_exp.size();i++)
            cout<<*masini_exp[i];
    }
};

template<>
class Expozitie<SuperSport>{
    int nr_total_expuse=0;
    int nr_total_vandute=0;
    vector<SuperSport*> masini_exp;
    vector<SuperSport*> masini_vandute;
public:
    ~Expozitie(){
        for(int i=0;i<masini_exp.size();i++)
            delete masini_exp[i];
        for(int i=0;i<masini_vandute.size();i++)
            delete masini_vandute[i];
    }
    void adaugacar(){
        SuperSport* m1=new SuperSport;
        cin>>*m1;
        masini_exp.push_back(m1);
        nr_total_expuse++;
    }
    void getnr(){
        cout<<nr_total_expuse<<endl;
    }
    void getcar(){
        for(int i=0;i<masini_exp.size();i++)
            cout<<*masini_exp[i];
    }
    void vanzare(int i,int pretul){
        *masini_exp[i]+=pretul;
        masini_vandute.push_back(masini_exp[i]);
        for(int j=i;j<masini_exp.size();j++)
            masini_exp[j]=masini_exp[j+1];
        masini_exp.pop_back();
        nr_total_expuse--;
        nr_total_vandute++;
    }
     void getnrvand(){
        cout<<"Numarul de masini de tip SuperSport vandute este : "<<nr_total_vandute<<endl;
    }
    void getcarvand(){
        cout<<"Acestea sunt : "<<'\n';
        for(int i=0;i<masini_vandute.size();i++)
            cout<<*masini_vandute[i];
    }
    void operator-=(int i){
        int k;
        cin>>k;
        this->vanzare(i,k);
    }
};

int op,op1;
int main()
{
   try{
        SuperSport test;
        cin>>test;
        cout<<test;
    }
    catch(exception &exp){
        cout<<exp.what()<<'\n';
    }

    Expozitie<Cabrio> ECabrio;
    Expozitie<Coupe> ECoupe;
    Expozitie<Hot_hatch> EHot_hatch;
    Expozitie<SuperSport> ESuperSport;
    do{
        afisare_meniu();
        cin>>op;
        if(op==1){
            cout<<"Ce tip de masina doriti sa introduceti?"<<'\n'<<'\n';
            cout<<"1.Coupe"<<endl;
            cout<<"2.Hot_hatch"<<endl;
            cout<<"3.Cabrio"<<endl;
            cout<<"4.Supersport"<<endl<<endl;
            cin>>op1;
            if(op1==1)
                ECoupe.adaugacar();
            else if(op1==2)
                EHot_hatch.adaugacar();
            else if(op1==3)
                ECabrio.adaugacar();
            else if(op1==4)
                ESuperSport.adaugacar();
        }
        else if(op==2){
            cout<<endl;
            cout<<"Ce tip de masini doriti sa vizionati?"<<'\n';
            cout<<"1.Coupe"<<endl;
            cout<<"2.Hot_hatch"<<endl;
            cout<<"3.Cabrio"<<endl<<endl;
            int op2;
            cin>>op2;
            if(op2==1){
                cout<<"Numarul de masini de tip Coupe este de ";
                ECoupe.getnr();
                cout<<" masini."<<'\n';
                cout<<"Acestea sunt : "<<'\n';
                ECoupe.getcar();
            }
            else if(op2==2){
                cout<<"Numarul de masini de tip Hot_hatch este de ";
                EHot_hatch.getnr();
                cout<<" masini."<<'\n';
                cout<<"Acestea sunt : "<<'\n';
                EHot_hatch.getcar();
            }
            else if(op2==3){
                cout<<"Numarul de masini de tip Cabrio este de ";
                ECabrio.getnr();
                cout<<" masini."<<'\n';
                cout<<"Acestea sunt : "<<'\n';
                ECabrio.getcar();
            }
        }
        else if(op==3){
            cout<<"Pe a cata masina doriti sa o achizitionati?"<<'\n';
            int x;
            cin>>x;
            cout<<"Care este pretul? (in euro)"<<'\n';
            int y;
            cin>>y;
            ESuperSport.vanzare(x-1,y);
            cout<<"Felicitari pentru noua achizitie"<<'\n';
        }
        else if(op==4){
            cout<<"Numarul de masini de tip SuperSport din cadrul expozitiei este : ";
            ESuperSport.getnr();
            cout<<"Acestea sunt : "<<'\n';
            ESuperSport.getcar();
        }
        else if(op==5){
            ESuperSport.getnrvand();
            ESuperSport.getcarvand();
        }
        else if(op==6)
            break;
        else
            cout<<"Introduceti o optiune valida!\n\n";
    }while(true);

    return 0;
}
