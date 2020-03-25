#ifndef FRACTIE_H
#define FRACTIE_H

class Fractie
{
    int numarator,numitor;
public:
    Fractie();
    Fractie(int x,int y);
    Fractie(const Fractie &q);
    ~Fractie();
    void afisare();
    void afisare1();
    void simplificare();
    Fractie operator+(const Fractie&q);
    Fractie operator-(const Fractie&q);
    Fractie operator*(const Fractie&q);
    Fractie operator/(const Fractie&q);
    Fractie operator*(int w);


void setFractie(int numa,int numi);
int getnumarator();
int getnumitor();
};

#endif // FRACTIE_H
