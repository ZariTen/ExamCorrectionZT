#include <ordenacao.hpp>

//Insertion sort inspirado em: https://www.geeksforgeeks.org/insertion-sort/
void ordernarPiorCandidato(Candidato* candidatos, int qtdQuestoes){
    Candidato cand;
    int posicaoOrdenado;

    for(int numCand = 1; numCand < qtdQuestoes; ++numCand){
        cand = candidatos[numCand];
        posicaoOrdenado = numCand - 1;

        while(posicaoOrdenado>= 0 && candidatos[posicaoOrdenado].questoesCertas() > cand.questoesCertas()){
            candidatos[posicaoOrdenado+1] = candidatos[posicaoOrdenado];
            posicaoOrdenado = posicaoOrdenado-1;
        }
        candidatos[posicaoOrdenado+1] = cand;
    }
}

//Insertion sort inspirado em: https://www.geeksforgeeks.org/insertion-sort/
void ordernarMelhorCandidato(Candidato* candidatos,int qtdQuestoes){
    Candidato cand;
    int posicaoOrdenado;

    for(int i = 1; i < qtdQuestoes; ++i){
        cand = candidatos[i];
        posicaoOrdenado = i - 1;

        while(posicaoOrdenado>= 0 && candidatos[posicaoOrdenado].questoesCertas() < cand.questoesCertas()){
            candidatos[posicaoOrdenado+1] = candidatos[posicaoOrdenado];
            posicaoOrdenado = posicaoOrdenado-1;
        }
        candidatos[posicaoOrdenado+1] = cand;
    }
}

 //Essa função ordena todas as questões do array Questao de acordo com a opção dada
void ordernarQuestoesOpcao(Questao* questoes, int opcao,int qtdQuestoes){
    Questao questao;
    int posicaoOrdenado;

    for(int numQuestao = 1; numQuestao < qtdQuestoes; ++numQuestao){ 
        questao = questoes[numQuestao];
        posicaoOrdenado = numQuestao - 1;

        //De acordo com a opção, ordernar as questões
        switch(opcao){
            case 0: //best-questions
                while(posicaoOrdenado>= 0 && questoes[posicaoOrdenado].acertos < questao.acertos){
                    questoes[posicaoOrdenado+1] = questoes[posicaoOrdenado];
                    posicaoOrdenado = posicaoOrdenado-1;
                }
                break;
            case 1: //worst-questions
                while(posicaoOrdenado>= 0 && questoes[posicaoOrdenado].errors < questao.errors){
                    questoes[posicaoOrdenado+1] = questoes[posicaoOrdenado];
                    posicaoOrdenado = posicaoOrdenado-1;
                }
                break;

            default: //blank-questions
                while(posicaoOrdenado>= 0 && questoes[posicaoOrdenado].brancos< questao.brancos){
                    questoes[posicaoOrdenado+1] = questoes[posicaoOrdenado];
                    posicaoOrdenado = posicaoOrdenado-1;
                }
        }
        questoes[posicaoOrdenado+1] = questao;
    }
}