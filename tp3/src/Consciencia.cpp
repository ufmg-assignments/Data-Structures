#include "Consciencia.h"

Consciencia::Consciencia(std::string nomePassado, std::string dadoPassado)
{
	this->tamanho = 1;
	this->nome = nomePassado;
	primeiro = new Dado(dadoPassado);
	ultimo = primeiro;
	this->direita = nullptr;
	this->esquerda = nullptr;
}

int Consciencia::calcularSomaDados()
{
	int soma = 0;
	while (this->tamanho != 0) {
		Dado* auxiliar;
		soma += stoi(primeiro->dado, 0, 2);

		auxiliar = primeiro;
		primeiro = primeiro->next;
		delete auxiliar;

		this->tamanho--;
	}

	return soma;
}

void Consciencia::adicionarDado(std::string dadoNovo)
{
	Dado* novo = new Dado(dadoNovo);

	this->ultimo->next = novo;
	this->ultimo = novo;
	this->tamanho++;

	novo = nullptr;
	delete novo;
}

void Consciencia::exibirConsciencia()
{
	std::cout << this->nome;
}

void Consciencia::exibirConscienciaMaisDados()
{
	int somatorio = this->calcularSomaDados();

	std::cout << this->nome << " " << somatorio << std::endl;
}
