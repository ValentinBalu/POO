#include "fractie.h"
#include<iostream>

Fractie::Fractie()=default;
Fractie::Fractie(int x,int y)
{
    numarator=x;
    numitor=y;
}
Fractie::Fractie(const Fractie &q)
{
   this->numarator=q.numarator;
   this->numitor=q.numitor;
}
Fractie::~Fractie()
{
    this->numarator=0;
    this->numitor=0;
}
void Fractie::simplificare()
{
    int c,a=numarator,b=numitor;
    while(b)
    {
        c=a%b;
        a=b;
        b=c;
    }
    if(a!=1)
        numarator/=a,numitor/=a;

}
void Fractie::afisare1()
{
        std::cout<<numarator<<"/"<<numitor<<'\n';
}
void Fractie::afisare()
{
    this->simplificare();
    if(numitor<0)
    {
        numarator=-numarator;
        numitor=-numitor;
    }
    if(numitor!=1)
        std::cout<<numarator<<"/"<<numitor<<'\n';
    else
        std::cout<<numarator<<'\n';
}

Fractie Fractie::operator+(const Fractie& q)
{
    Fractie rez;
    int a=this->numarator;
    int b=this->numitor;
    int c=q.numarator;
    int d=q.numitor;
    int cmmmc=b*d;
    int e;
    while(d)
    {
        e=b%d;
        b=d;
        d=e;
    }
    cmmmc/=b;
    rez.numarator=this->numarator*(cmmmc/this->numitor)+q.numarator*(cmmmc/q.numitor);
    rez.numitor=cmmmc;
    rez.simplificare();
    return rez;
}
Fractie Fractie::operator-(const Fractie& q)
{
    Fractie rez;
    int a=this->numarator;
    int b=this->numitor;
    int c=q.numarator;
    int d=q.numitor;
    int cmmmc=b*d;
    int e;
    while(d)
    {
        e=b%d;
        b=d;
        d=e;
    }
    cmmmc/=b;
    rez.numarator=this->numarator*(cmmmc/this->numitor)-q.numarator*(cmmmc/q.numitor);
    rez.numitor=cmmmc;
    rez.simplificare();
    return rez;
}
Fractie Fractie::operator*(const Fractie &q)
{
    Fractie rez;
    rez.numarator=numarator*q.numarator;
    rez.numitor=numitor*q.numitor;
    rez.simplificare();
    return rez;
}
Fractie Fractie::operator/(const Fractie& q)
{
    Fractie rez;
    rez.numarator=this->numarator*q.numitor;
    rez.numitor=this->numitor*q.numarator;
    rez.simplificare();
    return rez;
}
Fractie Fractie::operator*(int w)
{
    Fractie rez;
    rez.numitor=this->numitor;
    rez.numarator=this->numarator*=w;
    rez.simplificare();
    return rez;
}

void Fractie::setFractie(int numa,int numi)
{
    this->numarator=numa;
    this->numitor=numi;
}
int Fractie::getnumarator()
{
    return numarator;
}
int Fractie::getnumitor()
{
    return numitor;
}
