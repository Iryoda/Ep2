#ifndef PROCESSO_H
#define PROCESSO_H

#include <iostream>

#include "Roteador.h"
#include "Segmento.h"

using namespace std;

class Processo
{
    protected:
        static int padrao;
        int endereco;
        int porta;
        Roteador* gateway;

    public:
    //Constructor
    Processo(int endereco, int porta, Roteador* gateway);
    //Destructor
    virtual ~Processo();
    //getters  && setterssss
    virtual int getEndereco();
    virtual int getPorta();
    static int getTtlPadrao();

    static void setTtlPadrao(int padrao);
    //Functions
    virtual void receber(int origem, Segmento* mensagem) = 0;
    virtual void imprimir();

};

#endif // PROCESSO_H
