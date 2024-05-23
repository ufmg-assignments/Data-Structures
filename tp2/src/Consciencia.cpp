#include "Consciencia.h"

Consciencia::Consciencia(std::string nomeConsciencia, std::string dadosConsciencia)
{
	this->nome = nomeConsciencia;
	this->dados = dadosConsciencia;
}

std::string Consciencia::getNome()
{
	return this->nome;
}

std::string Consciencia::getDados()
{
	return this->dados;
}

void Consciencia::mostrarConsciencia()
{
	std::cout << this->nome << " " << this->dados << std::endl;
}
