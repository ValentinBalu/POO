#include <iostream>
#include "Fractie.h"
using namespace std;
void sistem(Fractie &x, Fractie &y,Fractie a1,Fractie b1,Fractie c1,Fractie a2,Fractie b2,Fractie c2)
{
    Fractie aux1=a1;
    Fractie aux2=b1;
    Fractie aux3=c1;
    a1=a1*a2;
    b1=b1*a2;
    c1=c1*a2;
    a2=a2*aux1;
    b2=b2*aux1;
    c2=c2*aux1;
    a1=a1-a2;
    b1=b1-b2;
    c1=c1-c2;
    c1=c1/b1;
    y=c1;
    aux2=aux2*y;
    aux3=aux3-aux2;
    aux3=aux3/aux1;
    x=aux3;
}
int n,t;
int main()
{
    Fractie x,y;
    Fractie z(36,-15);
    Fractie m(3,-2);
    z.afisare1();
    z.simplificare();
    z.afisare();
    m.afisare1();
    m.simplificare();
    m.afisare();
    Fractie d =z*m;
    d.afisare1();
    d.simplificare();
    d.afisare();
    z=z*m;
    z.afisare();
    //m.setFractie(6,4);
    //m.afisare1();
    //cout<<m.getnumarator()<<" "<<m.getnumitor()<<'\n';*/
    //m.afisare();
    //n.afisare();
    cin>>n>>t;
    Fractie a1(n,t);
    cin>>n>>t;
    Fractie b1(n,t);
    cin>>n>>t;
    Fractie c1(n,t);
    cin>>n>>t;
    Fractie a2(n,t);
    cin>>n>>t;
    Fractie b2(n,t);
    cin>>n>>t;
    Fractie c2(n,t);
    x.setFractie(0,0);
    y.setFractie(0,0);
    sistem(x,y,a1,b1,c1,a2,b2,c2);
    x.afisare();
    y.afisare();
    return 0;

}
