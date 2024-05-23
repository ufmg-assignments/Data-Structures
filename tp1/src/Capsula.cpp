#include "Capsula.h"

Capsula::Capsula(std::string dados)
{
	this->conscienciaEncapsulada = Consciencia(dados);
	this->proxima = nullptr;
}

void Capsula::mostrarConscienciaEncapsulada()
{
	conscienciaEncapsulada.exibirConsciencia();
}

std::string Capsula::retornarDadosDaConsciencia()
{
	return this->conscienciaEncapsulada.conteudo;
}
