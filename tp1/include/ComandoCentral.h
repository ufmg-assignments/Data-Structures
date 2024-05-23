#ifndef COMANDOCENTRAL_H_INCLUDED
#define COMANDOCENTRAL_H_INCLUDED
#pragma once

#include <iostream>
#include <string>
#include "Buffer.h"

class ComandoCentral
{
private:
	int numeroDeServidores;
	Buffer *servidores;
	Buffer historico;

public:
	//Construtor do comando central de um sistema de Realocacao Interplanetaria
	//O parametro passado indica o tamanho do array de servidores a serem 
	//utilizados para organizacao da realocacao das consciencias
	ComandoCentral(int tamanho);

	//Metodo que implementa a funcionalidade INFO
	//Insere uma consciencia ao final de um dado servidor
	void inserirEmServidor(int servidor, std::string dados);
	
	//Metodo de WARN
	//Leva uma determinada consciencia de um dado servidor
	//para frente do portal de realocacao desse mesmo servidor
	void anteciparConsciencia(int servidor, int posicao);
	
	//Metodo de TRAN
	//Trasfere todas as consciencias de um servidor para outro
	void desabilitarServidor(int servidorDesabilitado, int servidorReceptor);
	
	//Metodo de ERRO
	//Realoca todas as consciencias de um dado servidor
	//mostrando os dados de cada uma delas e removendo-as do buffer
	void tratarErro(int servidor);
	
	//Metodo de SEND
	//Envia a primeira consciencia de cada servidor pelo portal de realocacao
	//Se o servidor estiver vazio, nada é feito nele
	//Os dados das consciencias envidas sao salvos no historico
	void enviarPrimeiraDeCadaServidor();
	
	//Metodo de FLUSH
	//Imprimi o historico de envio das conscieias
	//Alem disso, imprimi o conteudo de todos os servidores, realizando
	//a realoacao interplanetaria de cada uma das consciencias
	void imprimirHistoricoMaisTodosServidores();
};

#endif // COMANDOCENTRAL_H_INCLUDED