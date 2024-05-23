#ifndef CONSCIENCIA_H_INCLUDED
#define CONSCIENCIA_H_INCLUDED
#pragma once

#include <iostream>
#include <string>

class Consciencia
{
private:
	std::string conteudo;

public:
	//Construtor que tem como parametro os dados da Consciencia
	Consciencia(std::string dados);
	
	//Construtor padrao
	Consciencia(){};
	
	//Mostra o conteudo (dados) da Consciencia
	void exibirConsciencia();

	//Objetos "Capsula" pode manipular os atributos de "Consciencia" diretamente
	friend class Capsula;
};

#endif // CONSCIENCIA_H_INCLUDED