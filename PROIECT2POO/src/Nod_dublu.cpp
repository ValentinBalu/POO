#include "Nod_dublu.h"

Nod_dublu::Nod_dublu():Nod(new char[0],NULL),ante(NULL){}
Nod_dublu::Nod_dublu(char* info,Nod*next,Nod*ante):Nod(info,NULL),ante(NULL){}
Nod_dublu::Nod_dublu(const Nod_dublu&node):Nod(node)
{
    this->ante=node.ante;
}
Nod_dublu::~Nod_dublu()
{
   std::cout<<"dublu"<<'\n';
}
Nod_dublu Nod_dublu::operator=(const Nod_dublu &node)
{
    this->next=node.next;
    this->info=node.info;
    this->ante=node.ante;
}
Nod* Nod_dublu::getAnte()
{
    return ante;
}
void Nod_dublu::setAnte(Nod* ante)
{
    this->ante=ante;
}
std::ostream &operator <<(std::ostream &out, const Nod_dublu&node)
{
    out<<node.info<<'\n';
    return out;
}
std::istream &operator >>(std::istream &in, Nod_dublu&node)
{
    in>>node.info;
    return in;
}

