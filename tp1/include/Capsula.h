#ifndef CAPSULA_H_INCLUDED
#define CAPSULA_H_INCLUDED
#pragma once

#include <iostream>
#include <string>
#include "Consciencia.h"

class Capsula
{
private:
	Consciencia conscienciaEncapsulada;
	Capsula *proxima;

public:
	//Construtor que instancia a consciencia diretamente na Capsula
	Capsula(std::string dados);
	
	//Construtor padrao
	Capsula() {};

	//Imprime os dados da consciencia que se encotra na Capsula
	void mostrarConscienciaEncapsulada();

	//Retorna os dados da consciencia que se encontra na Capsula
	std::string retornarDadosDaConsciencia();

	//Objetos "Buffer" pode manipular os atributos de "Capsula" diretamente
	friend class Buffer;
};

#endif // CAPSULA_H_INCLUDED