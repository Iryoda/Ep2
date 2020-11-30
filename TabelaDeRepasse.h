#ifndef TABELADEREPASSE_H
#define TABELADEREPASSE_H

#include "No.h"

#include <iostream>

using namespace std;

class TabelaDeRepasse
{
    private:
        //Vetor de enderecos

        int* enderecos;
        No** noAdjacentes;
        No* padrao;
        static const int MAXIMO_TABELA = 5;

    public:
        //Constructor
        TabelaDeRepasse();
        virtual void mapear(int endereco, No* adjacente);

        //Destructor
        virtual ~TabelaDeRepasse();

        //Getters && setters
        virtual No ** getAdjacentes();
        virtual int getQuantidadeDeAdjacentes();
        virtual No* getDestino(int endereco);
        virtual void setPadrao(No* padrao);

        //Functions
        virtual void imprimir();

};

#endif // TABELADEREPASSE_H

