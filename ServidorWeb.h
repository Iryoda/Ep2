#ifndef SERVIDORWEB_H
#define SERVIDORWEB_H

#include "Roteador.h"
#include <string>
#include "Segmento.h"
#include "Processo.h"

class ServidorWeb: public Processo
{
    public:
       ServidorWeb(int endereco, int porta, Roteador* gateway, string conteudo);
       virtual ~ServidorWeb();

       virtual void receber(int origem, Segmento* mensagem);

    private:

       string conteudo;
};

#endif // SERVIDORWEB_H
