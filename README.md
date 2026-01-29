# Produto Matricial Paralelo com OpenMP

Este projeto implementa o cálculo do produto de duas matrizes quadradas utilizando programação paralela em C com a biblioteca OpenMP.

## Objetivo

Demonstrar os princípios básicos da programação paralela por meio da divisão do cálculo do produto matricial entre múltiplas threads.

## Descrição

O programa:
- Define duas matrizes quadradas de tamanho N x N
- Preenche as matrizes com valores aleatórios
- Utiliza a diretiva `parallel for` do OpenMP para paralelizar o cálculo
- Gera e exibe a matriz resultante do produto

## Compilação

Para compilar o programa, utilize:

```bash
gcc -fopenmp produto_matricial.c -o produto_matricial
