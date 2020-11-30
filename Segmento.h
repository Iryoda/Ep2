#ifndef SEGMENTO_H
#define SEGMENTO_H

#include <iostream>

using namespace std;

class Segmento {
public:
    Segmento(int portaDeOrigem, int portaDeDestino, string dado);
    virtual ~Segmento();

    virtual int getPortaDeOrigem();
    virtual int getPortaDeDestino();
    virtual string getDado();

    virtual void imprimir();

private:
    string dado;

    int portaDeOrigem;
    int portaDeDestino;
};

#endif // SEGMENTO_H
