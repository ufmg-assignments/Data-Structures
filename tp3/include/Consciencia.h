#ifndef CONSCIENCIA_H_INCLUDED
#define CONSCIENCIA_H_INCLUDED
#pragma once

#include <iostream>
#include <string>
#include "Dado.h"

class Consciencia
{
private:
	std::string nome;
	Dado* primeiro;
	Dado* ultimo;
	int tamanho;
	Consciencia* esquerda;
	Consciencia* direita;

public:
	//Construtor que tem como parametro o nome e o dado inicial da Consciencia
	Consciencia(std::string nomePassado, std::string dadoPassado);

	//Converte as strings binarias para inteiro e realiza a soma delas
	int calcularSomaDados();

	//Adiciona mais um dado a sequencia
	void adicionarDado(std::string dadoNovo);

	//Mostra o nome da Consciencia
	void exibirConsciencia();

	//Mostra o nome da Conscienca seguido da soma dos dados
	void exibirConscienciaMaisDados();

	//Objetos "Arvore" pode manipular os atributos de "Consciencia" diretamente
	friend class Arvore;
};

#endif // CONSCIENCIA_H_INCLUDED