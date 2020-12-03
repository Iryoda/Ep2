#include <iostream>
#include <fstream>
#include <stdexcept>
#include <list>
#include <string>

#include "PersistenciaDeRede.h"
#include "Rede.h"
#include "Roteador.h"
#include "Hospedeiro.h"
#include "ServidorWeb.h"
#include "Navegador.h"

using namespace std;


void imprimirHospedeiro(Rede* rede) {
    int tamanhoList = rede->getHospedeiros()->size();
    int tamanhoVector;
    Hospedeiro* hospedeiro;
    list<Hospedeiro*>* hospedeiros = new list<Hospedeiro*>();
    hospedeiros = rede->getHospedeiros();

    for(int i = 0; i < tamanhoList; i++) {
        hospedeiro = hospedeiros->front();
        cout << "Hospedeiro " << hospedeiro->getEndereco() << endl;
        tamanhoVector = hospedeiro->getProcessos()->size();

        for(int j = 0; j < tamanhoVector; j++) {
            Navegador *navegador = dynamic_cast<Navegador*>(hospedeiro->getProcessos()->at(j));

            if(navegador != NULL)
                cout << "\tNavegador " << navegador->getPorta() << endl;
            else
                cout << "\tServidorWeb " << hospedeiro->getProcessos()->at(j)->getPorta() << endl;
        }
        hospedeiros->pop_front();
    }
    cout << "" << endl;
}


int main()
{

    int opcao, enderecoHospedeiro, portaNavegador, portaServidor, enderecoPagina, tempo, ttl;
    bool sair = false;
    string arquivo;

    Rede* rede = new Rede();

    PersistenciaDeRede* pr = new PersistenciaDeRede();

    cout << "Digite o nome do arquivo: ";
    cin >> arquivo;

     try {
        rede = pr->carregar(arquivo);
    }catch (invalid_argument* e){
        cout << e->what() << endl;
        return 1;
    }catch (logic_error* e){
        cout << e->what() << endl;
        return 1;
    }

    while(!sair) {
        cout << "" << endl;
        cout << "Simulador de Rede"<< endl
        << "---"<< endl
        <<"1) Usar Navegador" << endl
        <<"2) Passar Tempo" << endl
        <<"3) Alterar TTL" << endl
        <<"4) Sair" << endl
        <<"Escolha uma opcao: ";
        cin >> opcao;
        cout << "" << endl;

        if(opcao == 1) {
            imprimirHospedeiro(rede);

            cout << "Digite o endereco do hospedeiro : ";
            cin >> enderecoHospedeiro;
            cout << "Digite a porta do navegador: ";
            cin >> portaNavegador;
            cout << "Abrir pagina no endereco: ";
            cin >> enderecoPagina;
            cout << "Porta do Servidor Web: ";
            cin >> portaServidor;

            Hospedeiro *hospedeiro = dynamic_cast<Hospedeiro*>(rede->getNo(enderecoHospedeiro));

                if(hospedeiro != NULL) {
                    Navegador *navegador = dynamic_cast<Navegador*>(hospedeiro->getProcesso(portaNavegador));

                    if(navegador != NULL) {
                    navegador->abrir(enderecoPagina, portaServidor);

                    } else {
                        cout << "Porta Invalida" << endl;
                    }
                } else {
                    cout << "Endereco Invalido" << endl;
                }
        }

        if(opcao == 2) {
            cout << "Quantidade de tempo: ";
            cin >> tempo;
            for(int i = 0; i < tempo; i++) {
                cout << "" << endl;
                cout << "Instante " << i + 1 << endl;
                cout << "---" << endl;
                rede->passarTempo();
            }
        }

        if(opcao == 3) {

            cout << "TTL atual: "<< Processo::getTtlPadrao()<< endl;
            cout << "Novo TTL: ";
            cin >> ttl;

            Processo::setTtlPadrao(ttl);
        }

        if(opcao == 4)
            sair = true;
    }


    return 0;
}
