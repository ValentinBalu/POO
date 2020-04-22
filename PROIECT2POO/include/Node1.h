#include<iostream>
#pragma once
class Node1
{
protected:
    char* info;
    Node1* next;
public:
    Node1();
    Node1(char*,Node1*);
    Node1(const Node1&);
    ~Node1();
    void afisare();
    Node1 operator=(const Node1&);
    friend std::ostream &operator <<(std::ostream &out,const Node1&node);
    friend std::istream &operator >>(std::istream &in,Node1&node);
};

