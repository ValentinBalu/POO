#include<iostream>
#include "Nod.h"
#pragma once
class Nod_dublu:public  Nod
{
protected:
    Nod*ante;
public:
    Nod_dublu();
    Nod_dublu(char*,Nod*,Nod*);
    Nod_dublu(const Nod_dublu&);
    virtual~Nod_dublu();
    Nod_dublu operator=(const Nod_dublu&);
    Nod* getAnte();
    void setAnte(Nod* ante);
    friend std::ostream &operator <<(std::ostream &out,const Nod_dublu&node);
    friend std::istream &operator >>(std::istream &in,Nod_dublu&node);
};

