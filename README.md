# Ajuste de Curvas

Este repositório contém o código fonte para o programa desenvolvido como parte do trabalho prático sobre Ajustes de Curvas da disciplina Algoritmos Numéricos.

## Descrição

O trabalho tem como objetivo a implementação e cálculo do ajuste de curvas para conjuntos de dados fornecidos. A técnica utilizada é baseada no modelo exponencial definido por:

\[ N = \beta_0 \cdot e^{\beta_1 \cdot t} \]

onde:
- \( N \) é a quantidade de carbono-14 na amostra,
- \( t \) é a idade da amostra em anos,
- \( \beta_0 \) e \( \beta_1 \) são coeficientes a serem determinados.

A partir do cálculo dos coeficientes \( \beta_0 \) e \( \beta_1 \), o programa é capaz de determinar a estimativa de idade de uma amostra, fornecida uma quantidade específica de carbono-14.

## Compilação

Para compilar o programa, utilize o seguinte comando:

```bash
make
```

Este comando irá compilar o programa principal e criar o executável "ajusteDeCurva".

## Execução

Para executar o programa, utilize o seguinte comando:

```bash
./ajusteDeCurva
```

O programa utilizará os dados do arquivo dados.dat para o ajuste de curvas e fornecerá os coeficientes \( \beta_0 \) e \( \beta_1 \), bem como a estimativa de idade para uma quantidade específica de carbono-14.

## Limpeza

Para limpar os arquivos gerados durante a compilação, utilize o seguinte comando:

```bash
make clean
```

Este comando removerá os arquivos objetos, bibliotecas e o executável.