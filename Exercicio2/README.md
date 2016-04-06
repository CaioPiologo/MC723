#Nome: Caio Vinícius Piologo Véras Fernandes 145574
#Exercicio 2: Configuração de Cache

No seguinte exercício será simulado um programa com dois níveis de cache no entuito de encontrar a melhor configuração para os dois níveis (L1 de instruções, L1 de dados e L2 unificado). No caso, o programa executado foi o trace 300.twolf.f2b e para encontrar a melhor configuração será focado no número de "misses" dados em cada cache, procurando a configuração com o menor número e taxa de "misses".

##Tamanho da cache
A seguir serão variados os tamanhos de cada cache nos seguintes valores: 8K, 16K, 32K, 64K, todos com bloco de 32 bits:

######*l1-icache (cache de instruções L1)*

| Metrics             | Total       | Instrn             | Data        | Read        |Write        |Misc|
| -------------       |:-----------:|-------------------:| -----------:|------------:|------------:|---:|
| Demand Misses 8k    |16578452	    |16578452	           |0	           |0	           |0	           |0   |
| Demand Misses 16k   |5950201	    |5950201	           |0	           |0	           |0	           |0|
| Demand Misses 32k   |4634437	    |4634437	           |0	           |0	           |0	           |0|
| Demand Misses 64k   |640562	      |640562	             |0	           |0	           |0	           |0|
---

######*l1-dcache (cache de dados L1)*

| Metrics             | Total       | Instrn             | Data        | Read        |Write        |Misc|
| -------------       |:-----------:|-------------------:| -----------:|------------:|------------:|---:|
| Demand Misses	8k    |2505476	    |0	                 |2505476	     |1896920	     |608556	      |0|
| Demand Misses	16k   |555970	      |0	                 |555970	     |484041	     |71929	        |0|
| Demand Misses 32k   |229054	      |0	                 |229054	     |182521	     |46533	       |0|
| Demand Misses 64k   |112725	      |0	                 |112725	     |72603	       |40122	       |0|
---
######*l2-ucache (cache unificada L2)*

| Metrics             | Total       | Instrn             | Data        | Read        |Write        |Misc|
| -------------       |:-----------:|-------------------:| -----------:|------------:|------------:|---:|
| Demand Misses	8K    |19157605	    |16578452	           |2579153	     |1574292	     |1004861	     |0|
| Demand Misses	16k   |6546875	    |5950201	           |596674	     |500688	     |95986	       |0|
| Demand Misses 32k   |4898297	    |4634437	           |263860	     |201651	     |62209	       |0|
| Demand Misses 64k   |787108	      |640562	             |146546	     |97165	       |49381	       |0|
---

######Conclusões para o tamanho da cache
Pode-se ver que o número total de misses em ambas as caches L1 e L2 diminui conforme o tamanho da cache aumenta, portanto assume-se que a melhor configuração em relação ao tamanho da cache, no mundo real, será a maior possível de ser fabricada. No entanto, estamos focados no desempenho através da taxa de erros, aumentar o tamanho da cache possui lados negativos que também afetam seu desempenho como por exemplo, caches maiores possuem tempos de acesso menores, etc.

##Tamanho do bloco
Porém, o tamanho do bloco é tão importante quanto o tamanho da cache para avaliar seu desempenho. Iremos agora testar as caches L1 e L2 com um tamanho fixo de 64K para blocos de 32b, 64b, 128b e 512b:

###### 32b

*l1-icache*

| Metrics             | Total       | Instrn             | Data        | Read        |Write        |Misc|
| -------------       |:-----------:|-------------------:| -----------:|------------:|------------:|---:|
| Demand Misses 32b   |640562	      |640562	             |0	           |0	           |0	           |0|
| Demand Misses 64b   |602579	      |602579	             |0	           |0	           |0	           |0|
| Demand Misses 128b  |528728	      |528728	             |0	           |0	           |0	           |0|
| Demand Misses 512b  |674611	      |674611	             |0	           |0	           |0	           |0|
---

*l1-dcache*

| Metrics             | Total       | Instrn             | Data        | Read        |Write        |Misc|
| -------------       |:-----------:|-------------------:| -----------:|------------:|------------:|---:|
| Demand Misses 32b   |112725	      |0	                 |112725	     |72603	       |40122	       |0|
| Demand Misses 64b   |78598	      |0	                 |78598	       |55616	       |22982	       |0|
| Demand Misses 128b  |92133	      |0	                 |92133	       |77153	       |14980	       |0|
| Demand Misses 512b  |385823	      |0	                 |385823	     |372769	     |13054	       |0|
---
*l2-ucache*

| Metrics             | Total       | Instrn             | Data        | Read        |Write        |Misc|
| -------------       |:-----------:|-------------------:| -----------:|------------:|------------:|---:|
| Demand Misses 32b   |787108	      |640562	             |146546	     |97165	       |49381	       |0|
| Demand Misses 64b   |699137	      |602579	             |96558	       |63499	       |33059	       |0|
| Demand Misses 128b  |631234	      |528728	             |102506	     |68714	       |33792	       |0|
| Demand Misses 512b  |1066854	    |674611	             |392243	     |219369	     |172874	     |0|
---
######Conclusões para o tamanho do bloco cache
Percebe-se um comportamento diferente ao aumentar o tamanho do bloco das caches L1 e L2 em relação a aumentar o tamanho total da cache. Para o tamanho avaliado, as caches L1 e L2 diminuiram o número de misses até 128b e em um ponto entre 128b e 512b alcançaram o melhor desempenho e então começaram a subir o número de misses de forma abrupta. concluindo que para um tamanho de cache haverá um tamanho de bloco ideal.
