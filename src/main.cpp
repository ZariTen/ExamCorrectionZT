#include <iostream>
#include <prova.hpp>
#include <candidato.hpp>
#include <corretor.hpp>
#include <questao.hpp>
#include <ordenacao.hpp>

void mostrarCandidatos(int tamanhoTabela, Candidato* candidatosArr){
        for(int i = 0; i < tamanhoTabela; ++i){
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

int metodoEmInt(std::string metodo){
        if(metodo == std::string("best")){return 0;}
        else if (metodo == std::string("worst")){return 1;}
        else if (metodo == std::string("best-questions")){return 2;}
        else if (metodo == std::string("worst-questions")){return 3;}
        else if (metodo == std::string("blank-questions")){return 4;}
        else{return -1;}
}

void escolherMetodo(std::string metodo, int tamanhoTabela, Questao* questoes,Candidato* candidatos,Prova* prv){
        int qtdAlunos = prv->getQtdAlunos();
        int qtdQuestoes = prv->getQtdQuestoes();
        int metodoParaInt = metodoEmInt(metodo);
        int metodoQuestao = metodoParaInt - 2;

        switch(metodoParaInt){
                default:
                        std::cout << "Método inválido. São válidos apenas: best,worst,best-questions,worst-questions,blank-questions." << std::endl;
                        break;
                case 0:
                        ordernarMelhorCandidato(candidatos,qtdAlunos);
                        mostrarCandidatos(tamanhoTabela,candidatos);
                        break;
                case 1:
                        ordernarPiorCandidato(candidatos,qtdAlunos);
                        mostrarCandidatos(tamanhoTabela,candidatos);
                        break;
                case 2: case 3: case 4:
                        ordernarQuestoesOpcao(questoes,metodoQuestao,qtdQuestoes);
                        mostrarQuestoes(questoes,tamanhoTabela,metodoQuestao);
                        break;
        }
}

int main(int argc, char* argv[]){
        if(argc < 5){
                std::cout << "./programa [Arquivo respostas] [Método] [Quantidade] [Arquivo Gabarito]" << std::endl;
                return 0;
        }
        std::string respostasPath = argv[1];
        std::string metodo = argv[2];
        int tamanhoTabela = atoi(argv[3]);
        std::string gabaritoPath = argv[4];

        Prova p;
        p.setGabarito(gabaritoPath);
        p.lerProva(respostasPath);

        

        int qtdQuestoes = p.getQtdQuestoes();
        int qtdAlunos = p.getQtdAlunos();

        Questao questoes[qtdQuestoes];
        for(int questao = 0; questao < qtdQuestoes; ++questao){
                questoes[questao].numQuestao = questao+1;
        }

        Candidato candidatosArr[qtdAlunos];
        corrigirProva(candidatosArr,respostasPath);
        corrigirRespostas(candidatosArr,questoes,qtdAlunos,qtdQuestoes,p.getGabarito());

        

        escolherMetodo(metodo,tamanhoTabela,questoes,candidatosArr,&p);

        
        return 0;
}
