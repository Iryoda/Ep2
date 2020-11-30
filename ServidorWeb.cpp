#include "ServidorWeb.h"

ServidorWeb::ServidorWeb(int endereco, int porta, Roteador* gateway, string conteudo):
    Processo(endereco, porta, gateway), conteudo(conteudo)
{
}

ServidorWeb::~ServidorWeb()
{

}

void ServidorWeb:: receber(int origem, Segmento* mensagem)
{
    int portaOrigem = mensagem->getPortaDeOrigem();

    //Cria um segmento e um datagrama
    Segmento* s1 = new Segmento(porta,
                                portaOrigem,
                                conteudo);

    Datagrama*d1 = new Datagrama(endereco, origem , padrao, s1);

    //Joga o datagrama no roteador
    gateway->receber(d1);

    //Imprimi os bagulhos

    cout << "ServidorWeb " << porta
    << endl
    << "\tDevolvendo mensagem para " << origem << ":"<< portaOrigem
    << endl;
}
