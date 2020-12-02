#ifndef PERSISTENCIADEREDE_H
#define PERSISTENCIADEREDE_H

#include <iostream>
#include <string>
#include <fstream>

#include "Rede.h"

class PersistenciaDeRede
{
    public:
      PersistenciaDeRede();
      virtual ~PersistenciaDeRede();
      virtual Rede* carregar(string arquivo);
    private:
        Rede* rede;

};

#endif // PERSISTENCIADEREDE_H
