#include "Consciencia.h"

Consciencia::Consciencia(std::string dados)
{
	this->conteudo = dados;
}

void Consciencia::exibirConsciencia()
{
	std::cout << conteudo << std::endl;
}
