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
        SystemC 2.3.1-Accellera --- Apr 15 2016 08:25:42
        Copyright (c) 1996-2014 by all Contributors,
        ALL RIGHTS RESERVED
ArchC: Reading ELF application file: jpeg-6a/cjpeg
ArchC: -------------------- Starting Simulation --------------------

ArchC: -------------------- Simulation Finished --------------------

Info: /OSCI/SystemC: Simulation stopped by user.
ArchC: Simulation statistics
    Times: 0.46 user, 0.00 system, 0.47 real
    Number of instructions executed: 29857750
    Simulation speed: 64908.15 K instr/s

[ArchC 2.1] Printing GLOBAL statistics from processor module mips:
     INSTRUCTIONS : 29857500
     SYSCALLS : 250
[ArchC 2.1] Printing INSTRUCTION statistics from processor module mips:
[ArchC 2.1] Printing statistics from instruction lb:
     COUNT : 24201
[ArchC 2.1] Printing statistics from instruction lbu:
     COUNT : 427634
[ArchC 2.1] Printing statistics from instruction lh:
     COUNT : 531003
[ArchC 2.1] Printing statistics from instruction lhu:
     COUNT : 515
[ArchC 2.1] Printing statistics from instruction lw:
     COUNT : 5568788
[ArchC 2.1] Printing statistics from instruction lwl:
     COUNT : 49232
[ArchC 2.1] Printing statistics from instruction lwr:
     COUNT : 49232
[ArchC 2.1] Printing statistics from instruction sb:
     COUNT : 254658
[ArchC 2.1] Printing statistics from instruction sh:
     COUNT : 98613
[ArchC 2.1] Printing statistics from instruction sw:
     COUNT : 2707732
[ArchC 2.1] Printing statistics from instruction swl:
     COUNT : 49272
[ArchC 2.1] Printing statistics from instruction swr:
     COUNT : 49272
[ArchC 2.1] Printing statistics from instruction addi:
     COUNT : 0
[ArchC 2.1] Printing statistics from instruction addiu:
     COUNT : 4628068
[ArchC 2.1] Printing statistics from instruction slti:
     COUNT : 117568
[ArchC 2.1] Printing statistics from instruction sltiu:
     COUNT : 6010
[ArchC 2.1] Printing statistics from instruction andi:
     COUNT : 45230
[ArchC 2.1] Printing statistics from instruction ori:
     COUNT : 601
[ArchC 2.1] Printing statistics from instruction xori:
     COUNT : 32781
[ArchC 2.1] Printing statistics from instruction lui:
     COUNT : 13910
[ArchC 2.1] Printing statistics from instruction add:
     COUNT : 0
[ArchC 2.1] Printing statistics from instruction addu:
     COUNT : 4089708
[ArchC 2.1] Printing statistics from instruction sub:
     COUNT : 0
[ArchC 2.1] Printing statistics from instruction subu:
     COUNT : 893530
[ArchC 2.1] Printing statistics from instruction slt:
     COUNT : 726929
[ArchC 2.1] Printing statistics from instruction sltu:
     COUNT : 17489
[ArchC 2.1] Printing statistics from instruction instr_and:
     COUNT : 20728
[ArchC 2.1] Printing statistics from instruction instr_or:
     COUNT : 38034
[ArchC 2.1] Printing statistics from instruction instr_xor:
     COUNT : 19
[ArchC 2.1] Printing statistics from instruction instr_nor:
     COUNT : 20188
[ArchC 2.1] Printing statistics from instruction nop:
     COUNT : 2506141
[ArchC 2.1] Printing statistics from instruction sll:
     COUNT : 2023905
[ArchC 2.1] Printing statistics from instruction srl:
     COUNT : 9389
[ArchC 2.1] Printing statistics from instruction sra:
     COUNT : 545185
[ArchC 2.1] Printing statistics from instruction sllv:
     COUNT : 57485
[ArchC 2.1] Printing statistics from instruction srlv:
     COUNT : 0
[ArchC 2.1] Printing statistics from instruction srav:
     COUNT : 349936
[ArchC 2.1] Printing statistics from instruction mult:
     COUNT : 38505
[ArchC 2.1] Printing statistics from instruction multu:
     COUNT : 0
[ArchC 2.1] Printing statistics from instruction div:
     COUNT : 13176
[ArchC 2.1] Printing statistics from instruction divu:
     COUNT : 87
[ArchC 2.1] Printing statistics from instruction mfhi:
     COUNT : 78
[ArchC 2.1] Printing statistics from instruction mthi:
     COUNT : 0
[ArchC 2.1] Printing statistics from instruction mflo:
     COUNT : 51700
[ArchC 2.1] Printing statistics from instruction mtlo:
     COUNT : 0
[ArchC 2.1] Printing statistics from instruction j:
     COUNT : 301917
[ArchC 2.1] Printing statistics from instruction jal:
     COUNT : 34673
[ArchC 2.1] Printing statistics from instruction jr:
     COUNT : 49962
[ArchC 2.1] Printing statistics from instruction jalr:
     COUNT : 15284
[ArchC 2.1] Printing statistics from instruction beq:
     COUNT : 1797828
[ArchC 2.1] Printing statistics from instruction bne:
     COUNT : 1109799
[ArchC 2.1] Printing statistics from instruction blez:
     COUNT : 39123
[ArchC 2.1] Printing statistics from instruction bgtz:
     COUNT : 1934
[ArchC 2.1] Printing statistics from instruction bltz:
     COUNT : 447745
[ArchC 2.1] Printing statistics from instruction bgez:
     COUNT : 2703
[ArchC 2.1] Printing statistics from instruction bltzal:
     COUNT : 0
[ArchC 2.1] Printing statistics from instruction bgezal:
     COUNT : 0
[ArchC 2.1] Printing statistics from instruction sys_call:
     COUNT : 0
[ArchC 2.1] Printing statistics from instruction instr_break:
     COUNT : 0

