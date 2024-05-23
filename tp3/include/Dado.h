#ifndef DADO_H_INCLUDED
#define DADO_H_INCLUDED
#pragma once

#include <iostream>
#include <string>

class Dado
{
private:
	std::string dado;
	Dado* next;

public:
	//cria um Dado com o parametro passado
	Dado(std::string dadoPassado);

	//Objetos "Consciencia" e "Arvore" pode manipular os atributos de "Dado" diretamente
	friend class Consciencia;
	friend class Arvore;
};

#endif // DADO_H_INCLUDED
