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

 //0 Acertos ; 1 Erros ; 2 Brancos
void ordernarQuestao(Questao* questoes, int opcao,int qtd){
    Questao key;
    int j;

    for(int i = 1; i < qtd; ++i){
        key = questoes[i];
        j = i - 1;

        if(opcao == 0){
            while(j>= 0 && questoes[j].acertos < key.acertos){
                questoes[j+1] = questoes[j];
                j = j-1;
            }
        }
        else if(opcao == 1){
            while(j>= 0 && questoes[j].errors < key.errors){
                questoes[j+1] = questoes[j];
                j = j-1;
            }
        }
        else{
            while(j>= 0 && questoes[j].brancos< key.brancos){
                questoes[j+1] = questoes[j];
                j = j-1;
            }
        }
        questoes[j+1] = key;
    }
}