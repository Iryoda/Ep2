#include "Hospedeiro.h"

Hospedeiro::Hospedeiro(int endereco, Roteador* gateway) :  No(endereco) {
    this->gateway = gateway;
    processos = new vector<Processo*>();
}

Hospedeiro::~Hospedeiro() {
    while (!processos->empty()) {
		processos->pop_back();
	}
	delete processos;
}

void Hospedeiro::adicionarServidorWeb(int porta, string conteudo) {
    for(unsigned int i = 0; i < processos->size(); i++) {
		if(processos->at(i)->getPorta() == porta)
            throw new logic_error("erro");
	}
	ServidorWeb* s1 = new ServidorWeb(endereco, porta, gateway, conteudo);
    processos->push_back(s1);
}

void Hospedeiro::adicionarNavegador(int porta) {
    for(unsigned int i = 0; i < processos->size(); i++){
        if(processos->at(i)->getPorta() == porta)
            throw new logic_error("erro");
    }
    processos->push_back(new Navegador(endereco, porta, gateway));
}

Processo* Hospedeiro::getProcesso(int porta) {
    for(unsigned int i = 0; i < processos->size(); i++){
        if(processos->at(i)->getPorta() == porta)
            return processos->at(i);
    }
    return NULL;
}

void Hospedeiro::processar() {
    Datagrama *datagrama;
    int destino;

    try {
        datagrama = fila->dequeue();
    } catch (underflow_error *e) {
        delete e;
        return;
    }

    destino = datagrama->getDado()->getPortaDeDestino();

    for(unsigned int i = 0; i < processos->size(); i++) {
        if(processos->at(i)->getPorta() == destino) {
            Navegador *navegador = dynamic_cast<Navegador*>(processos->at(i));

            if(navegador != NULL) {
                navegador->receber(datagrama->getOrigem(), datagrama->getDado());
                delete datagrama;
                return;
            }
            ServidorWeb *servidorWeb = dynamic_cast<ServidorWeb*>(processos->at(i));
            servidorWeb->receber(datagrama->getOrigem(), datagrama->getDado());
        }
    }
    delete datagrama;
}

vector<Processo*>* Hospedeiro::getProcessos() {
    return processos;
}
