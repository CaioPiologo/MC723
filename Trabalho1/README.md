## Caio Vinícius Piologo Véras Fernandes 145574
## Relatório - Projeto 1: Benchmarks.

### Introdução

O benchmark criado ao redor do Image Magick consistiu em quatro etapas nas quais foi utilizado o programa de analise perf para serem feitas as medições:
  1. Criar uma imagem aleatóriamente de resolução 5000x5000
  2. Aplicar um filtro na imagem criada
  3. Gerar uma nova imagem de resolução 5000x5000 porém com um padrão já pré definido
  4. Aplicar o mesmo filtro à imagem

Em cada etapa o perf gerou um log com os dados retirados. Dentre eles foram considerados como mais relevantes:
  - Tempo de execução
  - Task-Clock (nível de paralelização em média)
  - Ciclos (frequência dos ciclos durante a execução)
  - Instruções (número de instruções realizadas por ciclo)

O algoritmo foi executado em um número total de 9 computadores diferentes:
  1. ~~yk0 - Yugo Kuno : AMD PhenonII, 4 cores, 3.2MHz; 10GB, ddr3, 1.333 MHz; hdd sata3, 7200rpm, 32MB buffer~~ Dados retirados incorretamente
  2. Cygnus X-1: Intel® Core™ i7 × 4;  Memory 8 GiB;  
  3. IC-legiao: Intel® Core™2 Quad CPU Q8400 @ 2.66GHz × 4 Intel® Q45/Q43 
  4. Gabriel Magalhães: Intel® Core™ i7-3612QM CPU @ 2.10GHz × 8; Memory 8GB, SSD Kingston 240GB V300 Sata III;  Ubuntu 15.04 
  5. IC301-Titan: Intel® Core™2 Quad CPU Q8400 @ 2.66GHz × 4 Intel® Q45/Q43, 3.8GB RAM
  6. IC-sepultura: Intel® Core™2 Quad CPU Q8400 @ 2.66GHz × 4 Intel® Q45/Q43 × 3.8GB RAM
  7. Wendrey: Intel Core i5-5200U CPU 2.20GHz x 4 L1 32KiB L2 256KiB L3 3MiB Memory 8GiB DDR3 Disk 1TB WDC WD10JPVX-22J Ubuntu 14.04 LTS
  8. Titouan Thibaud: Intel® Core™ i5-4590 CPU @ 3.30GHz × 4;  Memory 8 GiB;  64-bit graph: Intel® Haswell Desktop , Gnome: Version 3.18.2; Disk 216.9 GB; Fedora 23
  9. Netbook - Felipe Emos: Intel Atom Processor D4xx/D5xx/N4xx/N5xx DMI Bridge

## Desempenhos

OBS: Os dados gerados na tabela não são referentes às mesmas etapas, foi necessário conversar entre as pessoas que realizaram as medições para organizá-las.
A seguir serão ordenados os nove computadores em relação aos dados gerados para cada etapa da execução (1-4). Como a ordenação será dificultada pelo excesso de dados ela será feita em base no melhor desempenho da maioria das etapas:
###### Tempo de execução (segundos)
1. Titouan Thibaud - 1: 8.723; 2: 23.755; 3: 25.38; 4: 49.935
2. Cygnus X-1 - 1: 10.03978277; 2: 23.95558501; 3: 30.68709593; 4: 45.73278606
3. Gabriel Magalhães - 1: 10.29970084; 2: 22.67460494; 3: 86.51650059; 4: 74.25917966
4. Wendrey - 1: 10,755; 2: 30,072; 3: 31,681; 4: 53,539
5. IC301-Titan - 1: 12.53140417; 2: 58.90570496; 3: 127.021924; 4: 112.6003579
6. IC-legiao - 1: 12.7589977; 2: 38.36012319; 3: 125.5976589; 4: 111.6523577
7. IC-sepultura - 1: 14.52054618; 2: 38.18945062; 3: 127.2135043; 4: 111.6438665
8. Netbook - Felipe Emos - 1: 39.12942893; 2: 175.6376243; 3: 215.102165; 4: 336.9009071

###### Task-Clock (CPUs)
1. Cygnus X-1 - 1: 1.114; 2: 2.545; 3: 1.267; 4: 1.811
2. Gabriel Magalhães - 1: 1.186; 2: 2.429; 3: 1.015; 4: 1.165
3. Wendrey - 1: 1,116; 2: 1,918; 3: 1,227; 4: 1,517
4. Titouan Thibaud - 1: 1.068; 2: 1.602; 3: 1.027; 4: 1.341
5. IC301-Titan - 1: 1.105; 2: 1.457; 3: 1.008; 4: 1.356
6. IC-legiao - 1: 1.072; 2: 1.68; 3: 1.008; 4: 1.354
7. IC-sepultura - 1: 0.935; 2: 1.554; 3: 1; 4: 1.327
8. Netbook - Felipe Emos - 1: 1.081; 2: 1.359; 3: 1.082; 4: 1.137

###### Ciclos (GHz)
1. Titouan Thibaud - 1: 3.408; 2: 3.448; 3: 3.420; 4: 3.430
2. Cygnus X-1 - 1: 3.009; 2: 2.867; 3: 2.545; 4: 2.867
3. Gabriel Magalhães - 1: 2.922; 2: 2.429; 3: 3.023; 4: 2.908
4. IC301-Titan - 1: 2.654; 2: 2.657; 3: 2.657; 4: 2.658
5. IC-legiao - 1: 2.657; 2: 2.657; 3: 2.658; 4: 2.658
6. IC-sepultura - 1: 2.657; 2: 2.657; 3: 2.657; 4: 2.658
7. Wendrey - 1: 2,630; 2: 2,547; 3: 2,610; 4: 2,576
8. Netbook - Felipe Emos - 1: 1,652; 2: 1,653; 3: 1,653; 4: 1,652


