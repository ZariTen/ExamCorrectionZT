#include <iostream>
#include <prova.hpp>
#include <candidato.hpp>
#include <corretor.hpp>
#include <questao.hpp>
#include <ordenacao.hpp>

void mostrarCandidatos(int quantidadeMostrar, Candidato* candidatosArr){
        for(int i = 0; i < quantidadeMostrar; ++i){
                std::cout << i+1 << " - " << candidatosArr[i].getNome() << ": " << candidatosArr[i].questoesCertas() << std::endl;
        }
}

void mostrarQuestoes(Questao* questoes,int qtdQuestao,int opcao){
        for(int i = 0; i < qtdQuestao; ++i){
                switch (opcao)
                {
                case 0:
                        std::cout << questoes[i].numQuestao << " - " << questoes[i].acertos << " acertos" <<  std::endl;
                        break;
                case 1:
                        std::cout << questoes[i].numQuestao << " - " << questoes[i].errors << " erros" <<std::endl;
                        break;

                case 2:
                        std::cout << questoes[i].numQuestao << " - " << questoes[i].brancos << " brancos" <<std::endl;
                        break;
                
                default:
                        break;
                }
        }
}

int main(int argc, char* argv[]){
        // ./programa [Localização do arquivo] [metodo] [quantidade]
        // argv[1] = localização
        // argv[2] = metodo
        // argv[3] = quantidade
        if(argc < 5){
                std::cout << "./programa [Localização do arquivo] [Método] [Quantidade] [Localização do Gabarito]" << std::endl;
                return 0;
        }
        Prova p;
        p.setGabarito(argv[4]);
        p.lerProva(argv[1]);

        

        int qtdQuestoes = p.getQtdQuestoes();
        int qtdAlunos = p.getQtdAlunos();

        Questao questoes[qtdQuestoes];
        for(int i = 0; i < qtdQuestoes; ++i){
                questoes[i].numQuestao = i+1;
        }

        Candidato candidatosArr[qtdAlunos];
        corrigirProva(candidatosArr,argv[1]);
        corrigirRespostas(candidatosArr,questoes,qtdAlunos,qtdQuestoes,p.getGabarito());

        int quantidadeMostrar = atoi(argv[3]);

        if(argv[2] == std::string("best")){
                ordernarMelhorCandidato(candidatosArr,qtdAlunos);
                mostrarCandidatos(quantidadeMostrar,candidatosArr);
        }
        else if (argv[2] == std::string("worst")){
                ordernarPiorCandidato(candidatosArr,qtdAlunos);
                mostrarCandidatos(quantidadeMostrar,candidatosArr);
        }
        else if (argv[2] == std::string("best-questions")){
                ordernarQuestoesOpcao(questoes,0,qtdQuestoes);
                mostrarQuestoes(questoes,quantidadeMostrar,0);
        }
        else if (argv[2] == std::string("worst-questions")){
                ordernarQuestoesOpcao(questoes,1,qtdQuestoes);
                mostrarQuestoes(questoes,quantidadeMostrar,1);
        }
        else if (argv[2] == std::string("blank-questions")){
                ordernarQuestoesOpcao(questoes,2,qtdQuestoes);
                mostrarQuestoes(questoes,quantidadeMostrar,2);
        }
        else{
                std::cout << "Comando inválido. Apenas: best,worst,best-questions,worst-questions,blank-questions." << std::endl;
        }

        
        return 0;
}
