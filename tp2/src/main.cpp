#include <iostream>
#include <string>
#include <fstream>
#include "Consciencia.h"
#include "SortFunctions.h"

int main(int argc, char* argv[]) {
	//abertura do arquivo a ser lido
	std::ifstream arquivo(argv[1]);
	
	//variaveis que determinam os parametros de execucao
	std::string parametroAuxiliar1 = "";
	std::string parametroAuxiliar2 = "";

	parametroAuxiliar1 = argv[3];
	parametroAuxiliar2 = argv[2];

	int quantidade = stoi(parametroAuxiliar1);
	int configuracao = stoi(parametroAuxiliar2);

	//criacao do vetor a ser ordenado
	Consciencia *vetor;
	vetor = new Consciencia[quantidade];

	//variaveis para auxiliar a leitura de dados
	std::string leitura;
	std::string parametro1;
	std::string parametro2;
	int indiceDeSeparacao;

	//leitura das informacoes de cada consciencia
	for (int i = 0; i != quantidade; i++) {
		//leitura da linha do arquivo
		std::getline(arquivo, leitura);

		//geracao dos parametros
		indiceDeSeparacao = leitura.find(" ");
		parametro1 = leitura.substr(0, indiceDeSeparacao);
		parametro2 = leitura.substr(indiceDeSeparacao+1, leitura.length());
		
		//instanciacao da consciencia e atribuicao a uma posicao do vetor
		Consciencia auxiliar(parametro1, parametro2);
		vetor[i] = auxiliar;
	}

	//execucao da configuracao de ordenacao escolhida
	if (configuracao == 1) {
		HeapSort(vetor, quantidade);
		QuickSort(vetor, 0, quantidade - 1);
	}
	else if (configuracao == 2) {
		RadixSort(vetor, 0, quantidade - 1, 8, 0);
		QuickSort(vetor, 0, quantidade - 1);
	}
	else if (configuracao == 3) {
		HeapSort(vetor, quantidade);
		MergeSort(vetor, 0, quantidade - 1);
	}
	else if (configuracao == 4) {
		RadixSort(vetor, 0, quantidade - 1, 8, 0);
		MergeSort(vetor, 0, quantidade - 1);
	}

	//impressao do resultado da ordenacao
	for (int i = 0; i != quantidade; i++) {
		vetor[i].mostrarConsciencia();
	}

	//desaloca o vetor criado
	delete [] vetor;

	//fechamento do arquivo
	arquivo.close();

	return 0;
}