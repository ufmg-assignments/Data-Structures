#ifndef ARVORE_H_INCLUDED
#define ARVORE_H_INCLUDED
#pragma once

#include "Consciencia.h"

class Arvore
{
private:
	Consciencia* raiz;

	//Adiciona a nova Consciencia na sua posicao correta na arvore
	//Se ela ja estiver presente, adiciona-se o dado passado como parametro a ela
	void adicionarConsciencia(Consciencia*& local, std::string nomeConsciencia, std::string dadoConsciencia);
	
	//Recebe como parametro o nome da Consciencia a ser removida e, realizando a busca pela
	//arvore, remove quando a consciencia estiver presente
	void removerConsciencia(Consciencia*& local, std::string nomeConsciencia);

	//Se a Consciencia a ser removida tiver outras consciencias tanto na esquerda como na
	//direita, ela sera substituida pela maior Consciencia antecessora a ela
	void substituirPeloAntecessor(Consciencia* c1, Consciencia*& c2);

	//Realiza a impressao da Arvore em ordem
	void caminhamentoCentral(Consciencia *& local, Consciencia* ultima);

public:
	//Construtor padrao de objetos da classe Arvore
	//Apenas inicializa a raiz apontando-a para nullptr 
	Arvore();

	//Chama o metodo adicionarConsciencia passando a raiz como parametro
	void inserirConsciencia(std::string nomeConsciencia, std::string dadoConsciencia);

	//Chama o metodo removerConsciencia passando a raiz como parametro
	void remove(std::string nomeConsciencia);

	//Chama o metodo caminhamentoCentral passando a raiz como parametro
	void realizarCaminhamento();
};

#endif // ARVORE_H_INCLUDED