# MC723: Exercício 4
##Nome: Caio Vinícius Piologo Véras Fernandes
##RA: 145574

##Periférico Lock

Para iniciar a atividade no simulador ArchC, foi inicialmente modificado o arquivo [ac_tlm_peripheral.cpp](mips-tlm/ac_tlm_peripheral.cpp) para que funcione como um periférico de Lock, ou seja, a cada leitura nas posições de memória deste periférico, ele irá ler o valor atual de uma variável interna e então transformá-la em 1, e alterará o valor para o valor da escrita. A ideia será que algoritmos que usem este Lock travem a sua execução de certo bloco enquanto a variável ter o valor 1, e quando se tornar outro valor através de alguma escrita, terá o acesso liberado.

Dessa forma, uma simples trava do algoritmo seria instanciar uma variável _*lock_ no endereço de memória coordenado pelo periférico e executar uma função _while(*lock)_ para travar a execução e _*lock = 0_ para liberá-la.

Essa trava possui como finalidade gerenciar o acesso de memória por diferentes processos. Impedindo que dois processos acessem uma mesma variável ao mesmo tempo e modifiquem-na, podendo receber valores errôneos.

##Plataforma Multicore

Para criar uma plataforma multicore, foi necessário alterar o arquivo [main.cpp](mips-tlm/main.cpp) para instanciar um novo processador. Tomando os cuidados necessários o novo processador foi instanciado, possuindo uma região de pilha própria diferente do primeiro processador.

Dessa forma, foi criado um código simples em C que calcula a [soma de elementos de um vetor](mips-tlm/sumVector.c), pode-se ver nesse código que foram criados dois locks diferentes, um global e outro local. Para o programa citado não havia necessidade de um lock local, porém por fins de estudo foi implementado os dois locks.

#####Lock Global e Local
Um lock local seria interessante para não bloquear toda a memória a cada acesso, mas apenas as regiões onde pode haver conflito entre processadores.

Dessa forma, o lock global funcionaria como já explicado e o lock local precisaria verificar o global para se destravar, porém para que um processador possa liberar o seu lock local ele também precisa verificar o global, e para evitar o problema de um processo adquirir o lock global enquanto outro precisa dele para liberar um lock, ao adquirir o lock global o processo irá liberá-lo e adquirí-lo novamente enquanto aguarda sua trava local ser liberada.

#####Funcionamento
Por fim, o código foi paralelisado de forma a funcionar com dois processadores, em que um processador irá somar metade do vetor, o outro processador a outra metade e no final um deles irá juntar as duas somas e exibir o resultado.

O programa foi inicialmente feito realizando leituras à partir da entrada padrão e realizando a soma para estudar como os processadores lidam com as regiões de memória e ponteiros, concluindo que ele pode instanciar um vetor em apenas um processador, ou seja localmente, e tornar o ponteiro para o mesmo global enquanto outras variáveis locais precisam ter versões globais caso sejam instanciadas em apenas um processador e então atualizadas.

Assim, para fins de análise, o programa foi modificado de forma a gerar um vetor com 1000000 (um milhão) de elementos, todos iguais a 1 e somá-los. Em seguida foi criada uma constante que define o número de processadores que serão executados para facilitar os testes e obter um resultado mais consiso (executando o mesmo overhead nos dois casos de número de processadores), de forma que esta constante seria verificadas pelos processadores ao iniciarem a execução do programa e caso o seu id seja maior ou igual a esta constante ele termina a sua execução e o programa se adapta para calcular a soma de todos os elementos do vetor.

######Resultados e Conclusões
Executando o programa com dois processadores foi obtida a seguinte saída do simulador:

ArchC: -------------------- Simulation Finished --------------------

Soma total = 1000000

ArchC: -------------------- Simulation Finished --------------------

Info: /OSCI/SystemC: Simulation stopped by user.

ArchC: Simulation statistics

    Times: 0.69 user, 0.00 system, 0.71 real
    Number of instructions executed: 6005538
    Simulation speed: 8703.68 K instr/s
ArchC: Simulation statistics

    Times: 0.69 user, 0.00 system, 0.71 real
    Number of instructions executed: 6000644
    Simulation speed: 8696.58 K instr/s

Pode-se verificar pela saída que o número de instruções executadas foram 6005538 (o maior número de intruções executadas dentre os dois processadores)
E executando o mesmo programa, porém com a constante descrita modificada para 1, foi obtido o seguinte resultado:

ArchC: -------------------- Simulation Finished -------------------- 

Soma total = 1000000

ArchC: -------------------- Simulation Finished -------------------- 

Info: /OSCI/SystemC: Simulation stopped by user.

ArchC: Simulation statistics

    Times: 0.80 user, 0.00 system, 0.80 real
    Number of instructions executed: 9005522
    Simulation speed: 11256.90 K instr/s
ArchC: Simulation statistics

    Times: 0.80 user, 0.00 system, 0.80 real
    Number of instructions executed: 4000613
    Simulation speed: 5000.77 K instr/s

E, da mesma forma, verifica-se que o número de instruções executadas foram de 9005522, uma vez que o  segundo processador terminou a sua execução no começo do programa.

Dessa forma, pode-se concluir que a execução do programa foi feita em um número menor de instruções quando dual core, o que significaria um tempo de execução menor em, no caso quase um terço do programa single core a menos. 
Vale ressaltar também que a otimização feita deveria, em tese, ser executada em metade das instruções. Porém, devido à necessidade de várias instruções sequênciais para inicializar o vetor e exibir a saída, sobram um número diferente de instruções a serem paralelisadas.
