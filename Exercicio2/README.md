#Nome: Caio Vinícius Piologo Véras Fernandes 145574
#Exercicio 2: Configuração de Cache

No seguinte exercício será simulado um programa com dois níveis de cache no entuito de encontrar a melhor configuração para os dois níveis (L1 de instruções, L1 de dados e L2 unificado). No caso, o programa executado foi o trace 300.twolf.f2b e para encontrar a melhor configuração será focado no número de "misses" dados em cada cache, procurando a configuração com o menor número e taxa de "misses".

##Tamanho da cache
A seguir serão variados os tamanhos de cada cache nos seguintes valores: 8K, 16K, 32K, 64K, todos com bloco de 32 bits:
###### 8K

*l1-icache (cache de instruções L1)*

| Metrics             | Total       | Instrn             | Data        | Read        |Write        |Misc|
| -------------       |:-----------:|-------------------:| -----------:|------------:|------------:|---:|
| Demand Misses		    |16578452	    |16578452	           |0	           |0	           |0	           |0   |
| Demand miss rate	      |0.0414	      |0.0414	      |0.0000	      |0.0000	      |0.0000	      |0.0000|
---

*l1-dcache (cache de dados L1)*

| Metrics             | Total       | Instrn             | Data        | Read        |Write        |Misc|
| -------------       |:-----------:|-------------------:| -----------:|------------:|------------:|---:|
| Demand Misses		    |2505476	    |0	                 |2505476	     |1896920	     |608556	      |0|
| Demand miss rate	      |0.0179	      |0.0000	      |0.0179	      |0.0180	      |0.0178	      |0.0000|
---
*l2-ucache (cache unificada L2)*

| Metrics             | Total       | Instrn             | Data        | Read        |Write        |Misc|
| -------------       |:-----------:|-------------------:| -----------:|------------:|------------:|---:|
| Demand Misses		    |19157605	    |16578452	           |2579153	     |1574292	     |1004861	     |0|
| Demand miss rate	      |0.9536	      |1.0000	      |0.7347	      |0.6283	      |1.0000	      |0.0000|
---
###### 16K

*l1-icache*

| Metrics             | Total       | Instrn             | Data        | Read        |Write        |Misc|
| -------------       |:-----------:|-------------------:| -----------:|------------:|------------:|---:|
| Demand Misses		    |5950201	    |5950201	           |0	           |0	           |0	           |0|
| Demand miss rate	  |0.0149	      |0.0149	             |0.0000	     |0.0000	     |0.0000	     |0.0000|
---

*l1-dcache*

| Metrics             | Total       | Instrn             | Data        | Read        |Write        |Misc|
| -------------       |:-----------:|-------------------:| -----------:|------------:|------------:|---:|
| Demand Misses		    |555970	      |0	                 |555970	     |484041	     |71929	        |0|
| Demand miss rate	  |0.0040	      |0.0000	             |0.0040	     |0.0046	     |0.0021	      |0.0000|
---
*l2-ucache*

| Metrics             | Total       | Instrn             | Data        | Read        |Write        |Misc|
| -------------       |:-----------:|-------------------:| -----------:|------------:|------------:|---:|
| Demand Misses		    |6546875	    |5950201	           |596674	     |500688	     |95986	       |0|
| Demand miss rate	  |0.9916	      |1.0000	             |0.9151	     |0.9006	     |0.9992	     |0.0000|
---
###### 32K

*l1-icache*

| Metrics             | Total       | Instrn             | Data        | Read        |Write        |Misc|
| -------------       |:-----------:|-------------------:| -----------:|------------:|------------:|---:|
| Demand Misses		    |4634437	    |4634437	           |0	           |0	           |0	           |0|
| Demand miss rate	  |0.0116	      |0.0116	             |0.0000	     |0.0000	     |0.0000	     |0.0000|
---

*l1-dcache*

| Metrics             | Total       | Instrn             | Data        | Read        |Write        |Misc|
| -------------       |:-----------:|-------------------:| -----------:|------------:|------------:|---:|
| Demand Misses		    |229054	      |0	                 |229054	     |182521	     |46533	       |0|
| Demand miss rate	  |0.0016	      |0.0000	             |0.0016	     |0.0017	     |0.0014	     |0.0000|
---
*l2-ucache*

| Metrics             | Total       | Instrn             | Data        | Read        |Write        |Misc|
| -------------       |:-----------:|-------------------:| -----------:|------------:|------------:|---:|
| Demand Misses		    |4898297	    |4634437	           |263860	     |201651	     |62209	       |0|
| Demand miss rate	  |0.9944	      |1.0000	             |0.9052	     |0.8804	     |0.9963	     |0.0000|
---
###### 64K

*l1-icache*

| Metrics             | Total       | Instrn             | Data        | Read        |Write        |Misc|
| -------------       |:-----------:|-------------------:| -----------:|------------:|------------:|---:|
| Demand Misses		    |640562	      |640562	             |0	           |0	           |0	           |0|
| Demand miss rate	  |0.0016	      |0.0016	             |0.0000	     |0.0000	     |0.0000	     |0.0000|
---

*l1-dcache*

| Metrics             | Total       | Instrn             | Data        | Read        |Write        |Misc|
| -------------       |:-----------:|-------------------:| -----------:|------------:|------------:|---:|
| Demand Misses		    |112725	      |0	                 |112725	     |72603	       |40122	       |0|
| Demand miss rate	  |0.0008	      |0.0000	             |0.0008	     |0.0007	     |0.0012	     |0.0000|
---
*l2-ucache*

| Metrics             | Total       | Instrn             | Data        | Read        |Write        |Misc|
| -------------       |:-----------:|-------------------:| -----------:|------------:|------------:|---:|
| Demand Misses		    |787108	      |640562	             |146546	     |97165	       |49381	       |0|
| Demand miss rate	  |0.9800	      |1.0000	             |0.9013	     |0.8620	     |0.9902	     |0.0000|
---

######Conclusões para o tamanho da cache
Pode-se ver que o número total de misses em ambas as caches L1 e L2 diminui conforme o tamanho da cache aumenta, portanto assume-se que a melhor configuração em relação ao tamanho da cache, no mundo real, será a maior possível de ser fabricada. No entanto, estamos focados no desempenho através da taxa de erros, aumentar o tamanho da cache possui lados negativos que também afetam seu desempenho como por exemplo, caches maiores possuem tempos de acesso menores, etc.

##Tamanho do bloco
Porém, o tamanho do bloco é tão importante quanto o tamanho da cache para avaliar seu desempenho. Iremos agora testar as caches L1 e L2 com um tamanho fixo de 64K para blocos de 32b, 64b, 128b e 512b:

###### 32b

*l1-icache*

| Metrics             | Total       | Instrn             | Data        | Read        |Write        |Misc|
| -------------       |:-----------:|-------------------:| -----------:|------------:|------------:|---:|
| Demand Misses		    |640562	      |640562	             |0	           |0	           |0	           |0|
| Demand miss rate	  |0.0016	      |0.0016	             |0.0000	     |0.0000	     |0.0000	     |0.0000|
---

*l1-dcache*

| Metrics             | Total       | Instrn             | Data        | Read        |Write        |Misc|
| -------------       |:-----------:|-------------------:| -----------:|------------:|------------:|---:|
| Demand Misses		    |112725	      |0	                 |112725	     |72603	       |40122	       |0|
| Demand miss rate	  |0.0008	      |0.0000	             |0.0008	     |0.0007	     |0.0012	     |0.0000|
---
*l2-ucache*

| Metrics             | Total       | Instrn             | Data        | Read        |Write        |Misc|
| -------------       |:-----------:|-------------------:| -----------:|------------:|------------:|---:|
| Demand Misses		    |787108	      |640562	             |146546	     |97165	       |49381	       |0|
| Demand miss rate	  |0.9800	      |1.0000	             |0.9013	     |0.8620	     |0.9902	     |0.0000|
---
###### 64b

*l1-icache*

| Metrics             | Total       | Instrn             | Data        | Read        |Write        |Misc|
| -------------       |:-----------:|-------------------:| -----------:|------------:|------------:|---:|
| Demand Misses		    |602579	      |602579	             |0	           |0	           |0	           |0|
| Demand miss rate	  |0.0015	      |0.0015	             |0.0000	     |0.0000	     |0.0000	     |0.0000|
---

*l1-dcache*

| Metrics             | Total       | Instrn             | Data        | Read        |Write        |Misc|
| -------------       |:-----------:|-------------------:| -----------:|------------:|------------:|---:|
| Demand Misses		    |78598	      |0	                 |78598	       |55616	       |22982	       |0|
| Demand miss rate	  |0.0006	      |0.0000	             |0.0006	     |0.0005	     |0.0007	     |0.0000|
---
*l2-ucache*

| Metrics             | Total       | Instrn             | Data        | Read        |Write        |Misc|
| -------------       |:-----------:|-------------------:| -----------:|------------:|------------:|---:|
| Demand Misses		    |699137	      |602579	             |96558	       |63499	       |33059	       |0|
| Demand miss rate	  |0.9785	      |1.0000	             |0.8629	     |0.8079	     |0.9929	     |0.0000|
---
