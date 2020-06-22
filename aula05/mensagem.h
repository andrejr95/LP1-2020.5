#ifndef MENSAGEM_H
#define MENSAGEM_H

#include "Datahora.h"

struct Mensagem {

    Data data;
    Hora hora;

    void add(std::string arquivo_saida, std::string msninput);
    void list(std::string arquivo_saida);
};

#endif
