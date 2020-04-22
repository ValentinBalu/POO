#include "Coada_prioritati.h"
#include<iostream>
using namespace std;
Coada_prioritati::Coada_prioritati()
{
    prim=ultim=0;
}
Coada_prioritati::Coada_prioritati(const Coada_prioritati&que)
{
    prim=que.prim;
    ultim=que.ultim;
    Nod_prioritate*p=que.prim;
    while(p!=0)
    {
        Nod_prioritate*q=new Nod_prioritate(p->getInfo(),p->getNext(),0,p->getPrio());
        p=dynamic_cast<Nod_prioritate*>(p->getNext());
    }
}
Coada_prioritati::~Coada_prioritati()
{
    Nod_prioritate*p=prim;
    Nod_prioritate*q;

    while(p!=0)
    {
        q=p;
        p=dynamic_cast<Nod_prioritate*>(p->getNext());
        delete p;
    }
    prim=ultim=0;
}
void Coada_prioritati::adauga(Nod_prioritate node)
{
    Nod_prioritate *p;
    p=new Nod_prioritate(node.getInfo(),0,0,node.getPrio());
    if(goala())
        prim=ultim=p;
    else
    {
        ultim->setNext(p);
        ultim=p;
    }
}
void Coada_prioritati::inserare(Nod_prioritate node,int poz)
{
    Nod_prioritate*q;
    q=new Nod_prioritate(node.getInfo(),0,0,node.getPrio());
    Nod_prioritate*p=prim;
    poz--;
    while (poz!=0)
    {
        p=dynamic_cast<Nod_prioritate*>(p->getNext());
        poz--;
    }
    q->setNext(dynamic_cast<Nod_prioritate*>(p->getNext()));
    p->setNext(q);
}
void Coada_prioritati::top()
{
    Nod_prioritate*p=prim;
    Nod_prioritate*q;
    int maxx=prim->getPrio();
    while(p!=0)
    {
        if(p->getPrio()>maxx)
        {
            maxx=p->getPrio();
            q=p;
        }
        p=dynamic_cast<Nod_prioritate*>(p->getNext());
    }
    cout<<"Elementul cu prioritatea maxima este : ";
    cout<<q->getInfo()<<"-"<<maxx<<'\n';
}
void Coada_prioritati::pop()
{
    Nod_prioritate*p=prim;
    prim=dynamic_cast<Nod_prioritate*>(prim->getNext());
    delete p;
}
void Coada_prioritati::empty()
{
    Nod_prioritate*p=prim;
    Nod_prioritate*q;
    while(p!=0)
    {
        q=p;
        p=dynamic_cast<Nod_prioritate*>(p->getNext());
        delete q;
    }
    prim=ultim=0;
}
int Coada_prioritati::goala()
{
    return prim==0;
}
Nod_prioritate* Coada_prioritati::getPrim()
{
    return prim;
}
Nod_prioritate* Coada_prioritati::getUltim()
{
    return ultim;
}
Coada_prioritati Coada_prioritati::operator=(const Coada_prioritati&que)
{
    prim=que.prim;
    ultim=que.ultim;
    Nod_prioritate*p=que.prim;
    while(p!=0)
    {
        Nod_prioritate*q=new Nod_prioritate(p->getInfo(),p->getNext(),0,p->getPrio());
        p=dynamic_cast<Nod_prioritate*>(p->getNext());
    }
}
ostream &operator<<(ostream & out,Coada_prioritati &que)
{
    Nod_prioritate*p=que.getPrim();
    cout<<"Coada de prioritati este : ";
    if(que.goala())
        cout<<"vida";
    else
        while(p)
        {

            cout<<p->getInfo()<<"-"<<p->getPrio()<<" ";
            p=dynamic_cast<Nod_prioritate*>(p->getNext());
        }
    cout<<endl;
    return out;
}
ostream &operator>>(istream & in,Coada_prioritati &que)
{
}
