#include <ordenacao.hpp>

//Insertion sort inspirado em: https://www.geeksforgeeks.org/insertion-sort/
void ordernarPiorCandidato(Candidato* candidatos, int qtd){
    Candidato key;
    int j;

    for(int i = 1; i < qtd; ++i){
        key = candidatos[i];
        j = i - 1;

        while(j>= 0 && candidatos[j].questoesCertas() > key.questoesCertas()){
            candidatos[j+1] = candidatos[j];
            j = j-1;
        }
        candidatos[j+1] = key;
    }
}

//Insertion sort inspirado em: https://www.geeksforgeeks.org/insertion-sort/
void ordernarMelhorCandidato(Candidato* candidatos,int qtd){
    Candidato key;
    int j;

    for(int i = 1; i < qtd; ++i){
        key = candidatos[i];
        j = i - 1;

        while(j>= 0 && candidatos[j].questoesCertas() < key.questoesCertas()){
            candidatos[j+1] = candidatos[j];
            j = j-1;
        }
        candidatos[j+1] = key;
    }
}

void ordernarQuestao(Questao* questoes, int opcao){

}