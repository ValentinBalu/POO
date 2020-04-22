#include "Nod_prioritate.h"
#include "Exceptia.h"
Nod_prioritate::Nod_prioritate():Nod_dublu(new char[0],NULL,NULL),prio(-1){}
Nod_prioritate::Nod_prioritate(char* info,Nod*next,Nod*ante,int prio):Nod_dublu(info,NULL,NULL),prio(prio){}
Nod_prioritate::Nod_prioritate(const Nod_prioritate&node1):Nod_dublu(node1)
{
    this->prio=node1.prio;
}
Nod_prioritate::~Nod_prioritate()
{
    std::cout<<"prio"<<'\n';
    if(prio==-1)
        throw(Exceptia("Neprioritar"));
}
int Nod_prioritate::getPrio()
{
    return prio;
}
void Nod_prioritate::setPrio(int prio)
{
    this->prio=prio;
}
Nod_prioritate Nod_prioritate::operator=(const Nod_prioritate&node)
{
    this->next=node.next;
    this->ante=node.ante;
    this->info=node.info;
    this->prio=node.prio;
}

std::ostream &operator <<(std::ostream &out,const Nod_prioritate&node)
{
    out<<node.info<<" "<<node.prio<<'\n';
    return out;
}
std::istream &operator >>(std::istream &in, Nod_prioritate&node)
{
    in>>node.info>>node.prio;
    return in;
}
void Nod_prioritate::setNext(Nod_prioritate* next)
{
    this->next=next;
}

