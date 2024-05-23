#include "Arvore.h"

Arvore::Arvore()
{
	this->raiz = nullptr;
}

void Arvore::inserirConsciencia(std::string nomeConsciencia, std::string dadoConsciencia)
{
	adicionarConsciencia(this->raiz, nomeConsciencia, dadoConsciencia);
}

void Arvore::adicionarConsciencia(Consciencia*& local, std::string nomeConsciencia, std::string dadoConsciencia)
{
	if (local == nullptr) {
		local = new Consciencia(nomeConsciencia, dadoConsciencia);
	}
	else {
		if (nomeConsciencia < local->nome) {
			adicionarConsciencia(local->esquerda, nomeConsciencia, dadoConsciencia);
		}
		else if (nomeConsciencia > local->nome) {
			adicionarConsciencia(local->direita, nomeConsciencia, dadoConsciencia);
		}
		else {
			local->adicionarDado(dadoConsciencia);
		}
	}
}

void Arvore::remove(std::string nomeConsciencia)
{
	removerConsciencia(this->raiz, nomeConsciencia);
}

void Arvore::removerConsciencia(Consciencia* &local, std::string nomeConsciencia)
{
	Consciencia* auxiliar;

	if (nomeConsciencia < local->nome) {
		removerConsciencia(local->esquerda, nomeConsciencia);
	}
	else if (nomeConsciencia > local->nome) {
		removerConsciencia(local->direita, nomeConsciencia);
	}
	else {
		if (local->direita == nullptr) {
			auxiliar = local;
			local = local->esquerda;
			auxiliar->exibirConscienciaMaisDados();
			delete auxiliar;
		}
		else if (local->esquerda == nullptr) {
			auxiliar = local;
			local = local->direita;
			auxiliar->exibirConscienciaMaisDados();
			delete auxiliar;
		}
		else {
			local->exibirConscienciaMaisDados();
			substituirPeloAntecessor(local, local->esquerda);
		}
	}
}

void Arvore::substituirPeloAntecessor(Consciencia* c1, Consciencia* &c2)
{

	if(c2->direita != nullptr) {
		substituirPeloAntecessor(c1, c2->direita);
		return;
	}

	c1->nome = c2->nome;
	c1->primeiro = c2->primeiro;
	c1->ultimo = c2->ultimo;
	c1->tamanho = c2->tamanho;
	
	c1 = c2;
	c2 = c2->esquerda;
	
	delete c1;
}

void Arvore::realizarCaminhamento()
{
	Consciencia* maior = this->raiz;

	while (maior->direita != nullptr) {
		maior = maior->direita;
	}

	caminhamentoCentral(this->raiz, maior);

	maior = nullptr;
	delete maior;
}

void Arvore::caminhamentoCentral(Consciencia*& local, Consciencia *ultima)
{
	if(local->esquerda != nullptr) {
		caminhamentoCentral(local->esquerda, ultima);
	}
	
	local->exibirConsciencia();

	if (local != ultima) {
		std::cout << " ";
	}

	if(local->direita != nullptr) {
		caminhamentoCentral(local->direita, ultima);
	}

}
