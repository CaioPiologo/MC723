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
A seguir serão ordenados os nove computadores em relação aos dados gerados para cada etapa da execução:
###### Criar imagem aleatoriamente
1. Gabriel Magalhães - Tempo de execução: 10.29970084; Task-Clock: 1.186 CPUs; Ciclos: 2.922 GHz; Instruções: 1.22
2. Cygnus X-1 - Tempo de execução: 10.03978277; Task-Clock: 1.114 CPUs; Ciclos: 3.009 GHz; Instruções: 1.28
3. 

