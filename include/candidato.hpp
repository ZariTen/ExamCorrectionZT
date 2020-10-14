#ifndef CANDIDATO_H
#define CANDIDATO_H

#include <string>
#include <prova.hpp>

struct Candidato{
  private:
    std::string nome;
    int acertos;

  public:
    void acertarQuestao(); //Add 1 to acertos
    int questoesCertas();
    void setNome(std::string nome);

    std::string getNome();
    std::string resposta;
    Candidato();
};

#endif