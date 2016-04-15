# MC723: Exercício 3
##Nome: Caio Vinícius Piologo Véras Fernandes
##RA: 145574

##Contando instruções
Inicialmente foi criado um arquivo chamado hello.c no qual foi incluída apenas um comando para imprimir a linha "Hello World!". Dessa forma, foi modificado o arquivo mips_isa.cpp para contar o número de instruções add no arquivo executado.
Obteve a seguinte saída pro hello.c:

ArchC: -------------------- Simulation Finished --------------------

DBG: Add operations = 0

DBG: @@@ end behavior @@@

Em seguida foi incluída uma soma no arquivo hello.c. para criar duas variáveis novas em que uma terá o valor da nova mais um.
Assim o simulador teve a seguinte saída:

ArchC: -------------------- Simulation Finished --------------------

DBG: Add operations = 0

DBG: @@@ end behavior @@@

Isso ocorreu pois a função de soma chamada não foi a ac_bahavior(add), mas sim as suas outras formas (ac_behavior(addu), ac_behavior(addi), etc). Caso incluída uma soma em todas essas chamadas de soma, a simulação terá a seguinte saída:

Assim o simulador teve a seguinte saída:

ArchC: -------------------- Simulation Finished --------------------

DBG: Add operations = 0x286

DBG: @@@ end behavior @@@

Mostrando que as funções de soma foram chamadas durante a execução do programa.

##Avaliando Desempenho
Em seguida serão executados alguns benchmarks procurando avaliar o CPI médio de cada um através do número de instruções. Para isso o acsim será executado com uma flag -s que mostra o número de instruções de cada etapa do código.

######jpeg coder
O benchmark acima foi executado e teve a seguinte saída:

