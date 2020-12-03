#include "Roteador.h"

Roteador::Roteador(int endereco) :  No(endereco) {
    tabela = new TabelaDeRepasse();
}

Roteador::~Roteador() {
    delete tabela;
}

TabelaDeRepasse* Roteador::getTabela() {
    return tabela;
}

void Roteador::processar() {
    Datagrama *datagrama;

    try {
        datagrama = fila->dequeue();
    } catch (underflow_error *e) {
    delete e;
    return;
    }

    datagrama->processar();

    cout << "Roteador " << this->endereco << endl;
    if(!datagrama->ativo()) {
        //Verifica se o datagrama tem ttl > 0
        cout << "\tDestruido por TTL: Origem: "  << datagrama->getOrigem() << ", Destino: " << datagrama->getDestino() << ", TTL: 0,"
        << datagrama->getDado()->getDado() << endl;
        delete datagrama;
        return;
    }

    int enderecoDatagrama = datagrama->getDestino();

    if(enderecoDatagrama == endereco) {
        cout << "\tRecebido: Origem: " << datagrama->getOrigem() << ":" << datagrama->getDado()->getPortaDeOrigem() << ", Destino: " << datagrama->getDestino()
        << ":" << datagrama->getDado()->getPortaDeDestino() << ", TTL: " << datagrama->getTtl() << ", " << datagrama->getDado()->getDado() << endl;
        delete datagrama;
    } else {
        if(tabela->getDestino(enderecoDatagrama) == NULL) {
            cout << "\tSemProximo: Origem: " << datagrama->getOrigem() << ":" << datagrama->getDado()->getPortaDeOrigem() << ", Destino: " << datagrama->getDestino()
            << ":" << datagrama->getDado()->getPortaDeDestino() << ", TTL: " << datagrama->getTtl() << ", " << datagrama->getDado()->getDado() << endl;
        }

        //Retorna o roteador que tem o endereço caso não tiver retorna o padrão, e envia o datagrama para ele.
        cout << "\tEnviado para " << tabela->getDestino(enderecoDatagrama)->getEndereco() << ": Origem: " << datagrama->getOrigem()
        << ":" << datagrama->getDado()->getPortaDeOrigem() << ", Destino: " << datagrama->getDestino() << ":" << datagrama->getDado()->getPortaDeDestino()
        << ", TTL: " << datagrama->getTtl() << ", " << datagrama->getDado()->getDado() << endl;
        tabela->getDestino(enderecoDatagrama)->receber(datagrama);
    }
}
