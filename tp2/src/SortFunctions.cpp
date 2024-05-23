#include "SortFunctions.h"

//QUICKSORT
void QuickSort(Consciencia* vetor, int indiceEsquerda, int indiceDireita) {
	int i = 0, j = 0;
	ParticionarQuick(indiceEsquerda, indiceDireita, &i, &j, vetor);
	if (indiceEsquerda < j) QuickSort(vetor, indiceEsquerda, j);
	if (i < indiceDireita) QuickSort(vetor, i, indiceDireita);

}

void ParticionarQuick(int limEsq, int limDir, int* i, int* j, Consciencia* vet)
{
	Consciencia pivo, auxiliar;
	*i = limEsq; *j = limDir;
	pivo = vet[(*i + *j) / 2];
	do
	{
		while (pivo.getNome() > vet[*i].getNome()) (*i)++;
		while (pivo.getNome() < vet[*j].getNome()) (*j)--;
		if (*i <= *j)
		{
			auxiliar = vet[*i];
			vet[*i] = vet[*j];
			vet[*j] = auxiliar;
			(*i)++; (*j)--;
		}
	} while (*i <= *j);
}


//MERGESORT
void MergeSort(Consciencia* vet, int esq, int dir)
{
	if (esq < dir)
	{
		int meio = (esq + dir) / 2;
		MergeSort(vet, esq, meio);
		MergeSort(vet, meio + 1, dir);
		Merge(vet, esq, meio, dir);
	}
}

void Merge(Consciencia* vetor, int indiceEsquerda, int indiceMeio, int indiceDireita) {

	int tamanho = indiceDireita - indiceEsquerda + 1;
	Consciencia* auxiliar = new Consciencia[tamanho];

	int i = indiceEsquerda;
	int j = indiceMeio + 1;
	int contador = 0;
	
	while (i <= indiceMeio && j <= indiceDireita) {
		if (vetor[i].getNome() <= vetor[j].getNome()) {
			auxiliar[contador] = vetor[i];
			i++;
			contador++;
		}
		else {
			auxiliar[contador] = vetor[j];
			j++;
			contador++;
		}
	}

	while (i <= indiceMeio) {
		auxiliar[contador] = vetor[i];
		i++;
		contador++;
	}

	while (j <= indiceDireita) {
		auxiliar[contador] = vetor[j];
		j++;
		contador++;
	}

	for (int k = indiceEsquerda; k <= indiceDireita; k++) {
		vetor[k] = auxiliar[k - indiceEsquerda];
	}

	delete [] auxiliar;
}

//HEAPSORT
void HeapSort(Consciencia* vet, int tamanho) {
	//transformacao do vetor em Heap
	int indiceEsquerda = tamanho / 2 + 1;
	while (indiceEsquerda > 1) {
		indiceEsquerda--;
		RefazerHeap(indiceEsquerda, tamanho, vet);
	}

	indiceEsquerda = 1;
	int indiceDireita = tamanho;
	Consciencia auxiliar;;

	//ordenacao usando o Heap
	while (indiceDireita > 1) {
		auxiliar = vet[0];
		vet[0] = vet[indiceDireita - 1];
		vet[indiceDireita - 1] = auxiliar;
		indiceDireita--;
		RefazerHeap(indiceEsquerda, indiceDireita, vet);
	}
}

void RefazerHeap(int indiceEsquerda, int indiceDireita, Consciencia* vetor) {
	int i, j;
	i = indiceEsquerda;
	j = i * 2;
	Consciencia auxiliar = vetor[i - 1];

	while (j <= indiceDireita) {
		if (j < indiceDireita) {
			if (vetor[j - 1].getDados() < vetor[j].getDados()) j++;
		}
		if (auxiliar.getDados() >= vetor[j - 1].getDados())
			break;
		vetor[i - 1] = vetor[j - 1];
		i = j;
		j = i * 2;
	}
	vetor[i - 1] = auxiliar;

}

//RADIXSORT
void RadixSort(Consciencia* vetor, int indiceEsquerda, int indiceDireita,
	int totalBits, int bitAnalisado) {

	int i = indiceEsquerda, j = indiceDireita;
	Consciencia auxiliar;

	if (indiceDireita <= indiceEsquerda || bitAnalisado >= totalBits) return;
	while (j != i) {
		while (vetor[i].getDados()[bitAnalisado] == '0' && (i < j)) i++;
		while (vetor[j].getDados()[bitAnalisado] == '1' && (j > i)) j--;

		auxiliar = vetor[i];
		vetor[i] = vetor[j];
		vetor[j] = auxiliar;
	}

	if (vetor[indiceDireita].getDados()[bitAnalisado] == '0') j++;
	RadixSort(vetor, indiceEsquerda, j - 1, totalBits, bitAnalisado + 1);
	RadixSort(vetor, j, indiceDireita, totalBits, bitAnalisado + 1);
}
