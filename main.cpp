#include <iostream>
#include <fstream>
#include <stdexcept>
#include <list>

#include "PersistenciaDeRede.h"
#include "Rede.h"
#include "Roteador.h"
#include "Hospedeiro.h"
#include "ServidorWeb.h"
#include "Navegador.h"

using namespace std;

void imprimirHospedeiro( Rede* rede){

    int tamanho = rede->getHospedeiros()->size();

    for(int i = 0; i < tamanho; i++){

        Hospedeiro* h1 = rede->getHospedeiros()->front();
        cout << "Hospedeiro " << h1->getEndereco() << endl;

        for( int j = 0; j < h1->getProcessos()->size(); j++ ){

            Processo* p1 = h1->getProcessos()->pop_back();

            Navegador* n1 = dynamic_cast<Navegador*>(p1);

            if( n1 != NULL){
                cout << "\tNavegador " << p1->getEndereco() << endl;
            } else {
                cout << "\tServidorWeb " << p1->getEndereco() << endl;
            }

        }

        h1 = rede->getHospedeiros()->pop_front();
    }
}





int main()
{
    int opcao;
    string arquivo;

    Rede* rede = new Rede();

    PersistenciaDeRede* pr = new PersistenciaDeRede();

    cout << "Digite o nome do arquivo: " << end;
    cin >> arquivo

    pr->carregar(arquivo);

    while(!sair){
        cout << "Simulador de Rede"<< endl
        << "---"<< endl
        <<"1) User Navegador" << endl
        <<"2) Passar Tempo" << endl
        <<"3) Alterar TTL" << endl
        <<"4) Sair" << endl
        <<"Escolha uma opcao: " << end;
        cin << opcao;


        if(opcao == 1){

        }
    }










    /*
    try {
        rede = pr->carregar("arquivo.txt");
    }catch (logic_error* e){
        cout << e->what() << endl;
    }catch (invalid_argument* e){
        cout << e->what() << endl;
    }

    Hospedeiro* h1 =  rede->getHospedeiros()->back();//Lista com hospedeiros
    Roteador* r1 =  dynamic_cast<Roteador*>(rede->getNo(1));
    Roteador* r2 = dynamic_cast<Roteador*>(rede->getNo(2));
    */



    return 0;
}
