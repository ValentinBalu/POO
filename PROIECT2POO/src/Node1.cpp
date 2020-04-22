#include "Node1.h"
Node1::Node1()
{
    this->info="";
    this->next=0;
}
Node1::Node1(char* info,Node1*next)
{
    this->info=info;
    this->next=next;
}
Node1::Node1(const Node1&node)
{
    this->info=node.info;
    this->next=node.next;
}
Node1::~Node1()
{
    delete this;
    std::cout<<"deleted";
}
void Node1::afisare(){
    std::cout<<this->info<<std::endl;
}
Node1 Node1::operator=(const Node1& node)
{
    this->info=node.info;
    this->next=node.next;
}
std::ostream &operator <<(std::ostream &out,const Node1 &node)
{
    out<<node.info<<" "<<node.next<<'\n';
    return out;
}
std::istream &operator >>(std::istream &in, Node1 &node)
{
    in>>node.info;
    return in;
}





