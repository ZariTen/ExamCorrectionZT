#include <ordenacao.hpp>

void trocar(Candidato *old,Candidato *newer){
    Candidato temp = *old;
    *old = *newer;
    *newer = temp;
}

void ordernarPiorCandidato(Candidato* candidatos, int qtd){
    for(int i = 0; i < qtd-i; ++i){
        for(int j  = 0; j < qtd-i-1; ++j){
            if(candidatos[j].questoesCertas() > candidatos[j+1].questoesCertas()){
                trocar(&candidatos[j],&candidatos[j+1]);
            }
        }
    }
}

void ordernarMelhorCandidato(Candidato* candidatos,int qtd){
    for(int i = 0; i < qtd-i; ++i){
        for(int j  = 0; j < qtd-i-1; ++j){
            if(candidatos[j].questoesCertas() < candidatos[j+1].questoesCertas()){
                trocar(&candidatos[j],&candidatos[j+1]);
            }
        }
    }
}

void ordernarQuestao(Questao* questoes, int opcao){

}