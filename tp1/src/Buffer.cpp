#include "Buffer.h"

Buffer::Buffer()
{
	this->portal = new Portal();
	this->ultima = portal;
	tamanho = 0;
}

Buffer::~Buffer()
{
	while (this->portal->proxima != nullptr) {
		Capsula* auxiliar = this->portal->proxima;
		this->portal->proxima = auxiliar->proxima;
		delete auxiliar;
	}

	this->ultima = portal;
	delete this->portal;
}

void Buffer::enviarTodasConsciencias()
{
	while (this->portal->proxima != nullptr) {
		this->portal->proxima->mostrarConscienciaEncapsulada();
		Capsula* auxiliar = this->portal->proxima;
		this->portal->proxima = auxiliar->proxima;
		delete auxiliar;
	}
	this->ultima = portal;
	this->tamanho = 0;
}

void Buffer::priorizarConsciencia(int localizacao)
{
	if (localizacao >= tamanho) {}
	else {
		Capsula* anterior = portal;
		Capsula* auxiliar = portal->proxima;

		for (int i = 0; i < localizacao ; i++) {
			anterior = auxiliar;
			auxiliar = auxiliar->proxima;
		}

		anterior->proxima = auxiliar->proxima;
		auxiliar->proxima = portal->proxima;
		this->portal->proxima = auxiliar;

		if (anterior->proxima == nullptr) {
			this->ultima = anterior;
		}
 
		anterior = nullptr;
		auxiliar = nullptr;
		delete anterior;
		delete auxiliar;
	}
}

std::string Buffer::realocarConsciencia()
{
	std::string dados = "";
	if (tamanho == 0) {}
	else {
		dados = this->portal->proxima->retornarDadosDaConsciencia();
		Capsula* auxiliar = portal->proxima;
		this->portal->proxima = auxiliar->proxima;
		delete auxiliar;
		this->tamanho--;
		if (tamanho == 0) {
			this->ultima = portal;
		}
		auxiliar = nullptr;
		delete auxiliar;
	}
	return dados;
}

int Buffer::retornarTamanho()
{
	return this->tamanho;
}

void Buffer::inserirCapsula(std::string dados)
{
	Capsula* nova = new Capsula(dados);

	this->ultima->proxima = nova;
	this->ultima = nova;
	this->tamanho++;

	nova = nullptr;
	delete nova;
}

