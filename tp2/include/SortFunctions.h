#pragma once
#include <iostream>
#include <string>
#include "Consciencia.h"

//Funcoes de ordenacao: NOME
//Quicksort
//Essa funcao chama o metodo de particao recursivamente passando 
//como parametros os limites de um subvetor ainda não ordenado.
void QuickSort(Consciencia* vetor, int indiceEsquerda, int indiceDireita);

//A seguinte funcao escolhe o pivo e realiza as trocas que resultarao em dois subvetores ordenados.
void ParticionarQuick(int limEsq, int limDir, int* i, int* j, Consciencia* vet);

//Mergesort
//A funcao divide o problema de ordenacao ate que reste apenas um elemento no vetor.
//Depois dessa divisão a funcao Merge é chamada para combinar os subvetores gerados.
void MergeSort(Consciencia* vet, int esq, int dir);

//A funcao Merge combina dois vetores ordenados adicionando o menor elemento de cada um deles
//ate que nao reste nenhum elemento nos dois vetores
void Merge(Consciencia* vetor, int indiceEsquerda, int indiceMeio, int indiceDireita);

//Funcoes de ordenacao: DADOS
//Heapsort
//Essa funcao realiza a trocao do primeiro elemento do vetor com o ultimo e, em seguida, refaz o heap 
//desconsiderando o ultimo elemento. Esse processo é repetido ate que o vetor fique devidamente ordenado.
void HeapSort(Consciencia* vet, int tamanho);

//A funcao a seguir transforma o vetor ou subvetor em um heap, sendo que nessa estruturacao, 
//o maior elemento estara na primeira posicao do vetor
void RefazerHeap(int indiceEsquerda, int indiceDireita, Consciencia* vetor);

//Radix Exchange Sort
//A funcao Radixsort realiza comparacoes e trocas considerando o bit mais signicativo
//de uma string binaria composta de 0's e 1's.
//As chamadas recursivas ao final ordenam os subvetores gerados, passando
//como parametro o indice do proximo bit mais significativo
void RadixSort(Consciencia* vetor, int indiceEsquerda, int indiceDireita, int totalBits, int bitAnalisado);