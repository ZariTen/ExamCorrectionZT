#ifndef ORDENACAO_H
#define ORDENACAO_H

#include <candidato.hpp>
#include <questao.hpp>

void ordernarPiorCandidato(Candidato* candidatos, int qtd);
void ordernarMelhorCandidato(Candidato* candidatos,int qtd);

void ordernarQuestoesOpcao(Questao* questoes, int opcao,int qtd); //0 Acertos ; 1 Erros ; 2 Brancos

#endif