#include<iostream>
#pragma once
class Nod
{
protected:
    char* info;
    Nod* next;
public:
    Nod();
    Nod(char*,Nod*);
    Nod(const Nod&);
    virtual ~Nod();
    void afisare();
    Nod operator=(const Nod&);
    friend std::ostream &operator <<(std::ostream &out,const Nod&node);
    friend std::istream &operator >>(std::istream &in,Nod&node);
    char* getInfo();
    virtual Nod* getNext();
    virtual void setNext(Nod* next);
};


