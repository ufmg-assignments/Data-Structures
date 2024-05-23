#ifndef CONSCIENCIA_H_INCLUDED
#define CONSCIENCIA_H_INCLUDED

#pragma once
#include <iostream>
#include <string>

class Consciencia
{
private:
	std::string nome;
	std::string dados;

public:
	//Construtor padrao de objetos da classe Consciencia
	Consciencia() {};

	//Construtor que cria uma consciencia com base nos parametros passados na chamada
	Consciencia(std::string nomeConsciencia, std::string dadosConsciencia);
	
	//Retorna o atributo "nome"
	std::string getNome();

	//Retorna o atributo "dados"
	std::string getDados();

	//Imprime os atributos "nome" e "dados" da Consciencia
	void mostrarConsciencia();
};

#endif // CONSCIENCIA_H_INCLUDED