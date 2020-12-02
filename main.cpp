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

int main()
{
    Rede* rede = new Rede();

    PersistenciaDeRede* pr = new PersistenciaDeRede();

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

    cout << r1->getTabela()->getDestino(4)->getEndereco() << endl;
    cout << r1->getTabela()->getQuantidadeDeAdjacentes() << endl;


    cout << r2->getTabela()->getDestino(2)->getEndereco() << endl;
    cout << r2->getTabela()->getQuantidadeDeAdjacentes() << endl;



    return 0;
}
