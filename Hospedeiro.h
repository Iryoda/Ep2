#ifndef HOSPEDEIRO_H
#define HOSPEDEIRO_H

#include <stdexcept>
#include <iostream>
#include <list>
#include <vector>

#include "Datagrama.h"
#include "Segmento.h"
#include "TabelaDeRepasse.h"
#include "No.h"
#include "Roteador.h"
#include "Processo.h"
#include "ServidorWeb.h"
#include "Navegador.h"


using namespace std;

class Hospedeiro : public No {
public:
    Hospedeiro(int endereco, Roteador* gateway);
    virtual ~Hospedeiro();

    virtual void adicionarServidorWeb(int porta, string conteudo);
    virtual void adicionarNavegador(int porta);

    virtual Processo* getProcesso(int porta);
    virtual vector<Processo*>* getProcessos();

    virtual void processar();

private:
    Roteador *gateway;
    vector<Processo*>* processos;
};

#endif // HOSPEDEIRO_H
