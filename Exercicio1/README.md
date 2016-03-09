#__MC723 – Ecercício1__

#Nome: Caio Vinícius Piologo Véras Fernandes
#RA: 145574

##__Otimizações por compilação__

	As seguintes medidas foram retiradas a partir do comando time para execução do programa, escolhendo o tempo real como medida. Os intervalos de tempo mostrados serão devido a outros processos do computador que podem influenciar na execução do programa.

- Sem nenhuma opção de compilação o programa teve tempos de execução entre 0.299s e 0.347s

- Com otimizações o programa possuiu os seguintes intervalos:
	- O0: 0.299s e 0.359s
	- O1: 0.292s e 0.359s
	- O2: 0.285 e 0.390s
	- O3: 0.290s e 0.400s
	- mtune=generic: 0.298s e 0.326s
	- mtune=native:  0.297s e 0.304s

- Conclui-se que as otimizações por métodos de compilação não foram capazes de melhorar muito o desempenho do programa, possuindo tempos de execução muito próximos. 
- Dentre as otimizações do tipo -O o método O2 possuiu o menor tempo, notando que este valor possa ter sido afetado por outros processos do computador, uma vez que todas as outras otimizações possuiram o limite inferior próximos.
- Já no uso do comando mtune, o compilador procurou gerar código específico para o processador especificado. No caso do comando mtune=generic, ele tetou gerar código para o modelo i686, mais comum, e no mtune=native para o processador da máquina que está compilando o programa. Percebe-se um melhor e mais constante desempenho quando utilizado o comando mtune=native.

## __Utilizando dois arquivos__

- Em seguida o arquivo foi quebrado em dois novos, um com a função main e outro com a função primos. Após compilados por comando no terminal e com o uso de um Makefile, o programa foi novamente testado com e sem a melhor otimização utilizada anteriormente, e apresentou os mesmo resultados da etapa anterior como esperado.
- No entanto, o tempo de compilação após o arquivo original ser quebrado em dois aumentou utilizando o Makefile. Possuindo originalmente um tempo de compilação no intervalo de 0.049s-0.051s, e de 0.076s-0.081s quando utilizando um Makefile.

## __Calculando o número de primos entre 1 e n__

- Modificado o arquivo main.c e a função main() do arquivo primo.c para calcular o número de primos entre 1 e n (passado por linha de comando), foi testada a entrada 100000 em ambos os programas.
- O programa com um arquivo fonte apresentou tempos de execução para esta entrada entre 1.661s e 1.700s. Já o programa com dois arquivos fonte apresentou tempos de execução entre 1.352s e 1.381s. A entrada de grande tamanho possibilitou verificar que o programa com dois códigos fontes possui uma eficiência maior do que o arquivo com um único arquivo fonte.

- Em seguida o laço da função primos foi editado para verificar apenas os números ímpares, verificando anteriormente se o número é divisível por 2, e o tempo de execução diminuiu para uma o intervalo de 0.833s a 0.860s

- Utilizando o gprof no programa, percebeu-se que que a função primo() consome mais tempo na execução do programa.

- No caso de paralelizar o programa, o ideal seria palaleliza-lo no laço da função main, o qual chama a função primo para verificar cada número primo e caso seja incrementar um contador. Como esse laço não depende dos resultados anteriores ele pode ser paralelizado, quebrando-o em partes do mesmo loop em cada thread, tendo cada uma seu próprio contador que no final se somam. Outra opção seria paralelizar o laço da função primos, que verifica se um dado número n é divisível por algum outro número, porém como esta função poderia ser interrompida ao encontrar um divisor qualquer, haverá casos em que a paralelização tornará o código mais ineficiente.
- Feito isso, o programa foi executado novamente e teve o tempo de execução medido entre 0.404s e 0.413s para 4 threads do loop.


