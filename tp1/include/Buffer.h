#ifndef BUFFER_H_INCLUDED
#define BUFFER_H_INCLUDED
#pragma once

#include <iostream>
#include <string>
#include "Capsula.h"

typedef Capsula Portal;

class Buffer
{
private:
	Portal *portal;
	Capsula *ultima;
	int tamanho = 0;

public:
	//Construtor padrao
	//Inicializa o portal de realocacao interplanetaria
	Buffer();

	//Destrutor esvazia o buffer e exclui o portal
	~Buffer();

	//Metodos que modificam o Buffer:
	
	//Cria uma Consciecia diretamente em uma Capsula
	//Entao, a Capsula é adicionada a fila de realocacao interplanetaria
	void inserirCapsula(std::string dados);
	
	//Uma determinada consciencia vai para frente do portal
	//Assim, essa consciencia sera a proxima a ser realocada
	void priorizarConsciencia(int localizacao);

	//Esvazia o Buffer, imprimindo os dados de todas as consciencias
	void enviarTodasConsciencias();

	//A primeira consciencia do Buffer é trasportada pelo portal
	//Seus dados sao retornados para armazenamento no historico
	std::string realocarConsciencia();

	//Retorna o tamanho atual do Buffer
	int retornarTamanho();

};

#endif // BUFFER_H_INCLUDED