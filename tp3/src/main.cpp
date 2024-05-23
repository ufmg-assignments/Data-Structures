#include "Arvore.h"
#include <iostream>
#include <string>
#include <fstream>

int main(int argc, char* argv[]) {

	//Instanciacao da arvore
	Arvore* arvore = new Arvore();
	
	//Abertura do arquivo a ser lido
	std::ifstream arquivo(argv[1]);

	//Variaveis para auxiliar a leitura de dados
	std::string leitura;
	std::string parametro1;
	std::string parametro2;
	int indiceDeSeparacao;
	int quantidade;

	//Leitura do numero de consciencias
	std::getline(arquivo, leitura);
	quantidade = stoi(leitura);

	//Leitura das informacoes de cada consciencia
	for (int i = 0; i != quantidade; i++) {
		//Leitura da linha do arquivo
		std::getline(arquivo, leitura);

		//Geracao dos parametros
		indiceDeSeparacao = leitura.find(" ");
		parametro1 = leitura.substr(0, indiceDeSeparacao);
		parametro2 = leitura.substr(indiceDeSeparacao + 1, leitura.length());

		//Insercao da Consciencia na arvore
		arvore->inserirConsciencia(parametro1, parametro2);
	}

	//Primeira impressao da arvore em ordem
	arvore->realizarCaminhamento();
	std::cout << std::endl;

	//Realizacao das remocoes
	while (std::getline(arquivo, leitura)) {
		arvore->remove(leitura);
	}

	//Impressao da arvore em ordem apos retiradas
	arvore->realizarCaminhamento();

	//Desalocacao da arvore
	delete arvore;

	//fechamento do arquivo
	arquivo.close();

	return 0;
}