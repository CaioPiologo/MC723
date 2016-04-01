#Nome: Caio Vinícius Piologo Véras Fernandes 145574
##Exercicio 2: Configuração de Cache

No seguinte exercício será simulado um programa com dois níveis de cache no entuito de encontrar a melhor configuração para os dois níveis (L1 de instruções, L1 de dados e L2 unificado). No caso, o programa executado foi o trace 300.twolf.f2b e para encontrar a melhor configuração será focado no número de "misses" dados em cada cache, procurando a configuração com o menor número e taxa de "misses".

######Tamanho da cache
A seguir serão variados os tamanhos de cada cache nos seguintes valores: 8K, 16K, 32K, 64K:
* 8K

*l1-icache (cache de instruções L1)*

| Metrics             | Total       | Instrn             | Data        | Read        |Write        |Misc|
| -------------       |:-----------:|-------------------:| -----------:|------------:|------------:|---:|
| Demand Misses		    |16578452	    |16578452	           |0	           |0	           |0	           |0   |
| Demand miss rate	      |0.0414	      |0.0414	      |0.0000	      |0.0000	      |0.0000	      |0.0000|

*l1-dcache (cache de dados L1)*

| Metrics             | Total       | Instrn             | Data        | Read        |Write        |Misc|
| -------------       |:-----------:|-------------------:| -----------:|------------:|------------:|---:|
| Demand Misses		    |2505476	    |0	                 |2505476	     |1896920	     |608556	      |0|
| Demand miss rate	      |0.0179	      |0.0000	      |0.0179	      |0.0180	      |0.0178	      |0.0000|

*l2-ucache (cache unificada L2)*

| Metrics             | Total       | Instrn             | Data        | Read        |Write        |Misc|
| -------------       |:-----------:|-------------------:| -----------:|------------:|------------:|---:|
| Demand Misses		    |19157605	    |16578452	           |2579153	     |1574292	     |1004861	     |0|
| Demand miss rate	      |0.9536	      |1.0000	      |0.7347	      |0.6283	      |1.0000	      |0.0000|
