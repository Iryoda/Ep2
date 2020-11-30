#ifndef ROTEADOR_H
#define ROTEADOR_H
#include <stdexcept>
#include <iostream>
#include <list>

#include "Datagrama.h"
#include "TabelaDeRepasse.h"
#include "No.h"


using namespace std;

class Roteador : public No {
public:
    Roteador(int endereco);
    virtual ~Roteador();

    virtual TabelaDeRepasse* getTabela();
    virtual void processar();
private:
    TabelaDeRepasse *tabela;
};

#endif // ROTEADOR_H
