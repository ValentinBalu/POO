#include "Nod.h"
Nod::Nod()
{
    this->info=new char[0];
    this->next=0;
}
Nod::Nod(char* info,Nod*next)
{
    this->info=info;
    this->next=next;
}
Nod::Nod(const Nod&node)
{
    this->info=node.info;
    this->next=node.next;
}
Nod::~Nod()
{
    std::cout<<"nod"<<'\n';
}
void Nod::afisare()
{
    std::cout<<this->info<<std::endl;
}
/*Nod Nod::operator=(const Nod& node)
{
    this->info=node.info;
}*/
std::ostream &operator <<(std::ostream &out,const Nod &node)
{
    out<<node.info<<'\n';
    return out;
}
std::istream &operator >>(std::istream &in, Nod &node)
{
    in>>node.info;
    return in;
}
char* Nod::getInfo()
{
    return info;
}
Nod* Nod::getNext()
{
    return next;
}
void Nod::setNext(Nod* next)
{
    this->next=next;
}



