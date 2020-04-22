#include<iostream>
#include"Nod_dublu.h"
#pragma once
class Nod_prioritate:public Nod_dublu
{
protected:
    int prio;
public:
    Nod_prioritate();
    Nod_prioritate(char*,Nod*,Nod*,int);
    Nod_prioritate(const Nod_prioritate&);
    virtual~Nod_prioritate();
    int getPrio();
    void setPrio(int);
    Nod_prioritate operator=(const Nod_prioritate&);
    friend std::ostream &operator <<(std::ostream &out,const Nod_prioritate&node);
    friend std::istream &operator >>(std::istream &in,Nod_prioritate&node);
    //Nod_prioritate* getNext();
    virtual void setNext(Nod_prioritate*);

};
