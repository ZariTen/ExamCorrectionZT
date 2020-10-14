# Como utilizar
1. Vá na pasta build e use cmake ..
2. Use make
3. Use ./programa [Localização do arquivo] [Método] [Quantidade] [Localização do Gabarito]

# Métodos disponiveis
best - Melhores alunos.
worst - Piores alunos.
best-questions - Questões com mais acertos.
worst-questions - Questões com mais erros.
blank-questions - Questões com mais brancos.
[Quantidade] é o tamanho de alunos que desejas printar.

# Formato do arquivo
[Nome] X X X X X X
Antero E A C A E C B B B B
Luca D E U B E A A B A E
Jurema D E E C A G E D E D
Daisy D C E C E B E A A D
Carla D C A D C E E D C M
Tayná B A D M W C C H B B

# Formato do gabarito
A D E E B C B A ...

# Importante
O programa vai entender que o máximo de questões é quantas questões os alunos **marcaram**.

O programa só ira reconhecer as letras de **A - E** , qualquer outra letra é considerada branco.
