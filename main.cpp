#include <iostream>
#include <fstream>
#include <stdexcept>
#include <list>
#include<string>

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
                cout << "\tNavegador " << navegador->getPorta();
            else
                cout << "\tServidorWeb " << hospedeiro->getProcessos()->at(j)->getPorta();
        }
        hospedeiros->pop_front();
    }
}





int main()
{
    int opcao;
    int sair;
    string arquivo;

    Rede* rede = new Rede();

    PersistenciaDeRede* pr = new PersistenciaDeRede();

    cout << "Digite o nome do arquivo: " << endl;
    cin >> arquivo;

    pr->carregar(arquivo);

    while(!sair){
        cout << "Simulador de Rede"<< endl
        << "---"<< endl
        <<"1) User Navegador" << endl
        <<"2) Passar Tempo" << endl
        <<"3) Alterar TTL" << endl
        <<"4) Sair" << endl
        <<"Escolha uma opcao: " << endl;
        cin >> opcao;


        if(opcao == 1)
            imprimirHospedeiro(rede);
    }










    /*try {
        rede = pr->carregar("arquivo.txt");
    }catch (logic_error* e){
        cout << e->what() << endl;
    }catch (invalid_argument* e){
        cout << e->what() << endl;
    }

    Hospedeiro* h1 =  rede->getHospedeiros()->back();//Lista com hospedeiros
    Roteador* r1 =  dynamic_cast<Roteador*>(rede->getNo(1));
    Roteador* r2 = dynamic_cast<Roteador*>(rede->getNo(2));*/



    return 0;
}
