#ifndef CORRETOR_H
#define CORRETOR_H

#include <candidato.hpp>

void corrigirProva(Candidato* candidatos,std::string path);

void corrigirRespostas(Candidato* candidatos,Questao* questoes,int qtdCand,int qtdQuest, std::string gabarito);

#endif