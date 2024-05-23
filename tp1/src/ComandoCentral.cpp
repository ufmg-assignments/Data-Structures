#include "ComandoCentral.h"

ComandoCentral::ComandoCentral(int tamanho)
{
	this->numeroDeServidores = tamanho;
	this->servidores = new Buffer[tamanho];
}

void ComandoCentral::inserirEmServidor(int servidor, std::string dados)
{
	servidores[servidor].inserirCapsula(dados);
}

void ComandoCentral::anteciparConsciencia(int servidor, int posicao)
{
	servidores[servidor].priorizarConsciencia(posicao);
}

void ComandoCentral::desabilitarServidor(int servidorDesabilitado, int servidorReceptor)
{
	std::string auxiliar = "";
	while (servidores[servidorDesabilitado].retornarTamanho() != 0) {
		auxiliar = servidores[servidorDesabilitado].realocarConsciencia();
		servidores[servidorReceptor].inserirCapsula(auxiliar);
	}
}

void ComandoCentral::tratarErro(int servidor)
{
	servidores[servidor].enviarTodasConsciencias();
}

void ComandoCentral::enviarPrimeiraDeCadaServidor()
{
	for (int i = 0; i < numeroDeServidores; i++) {
		if (servidores[i].retornarTamanho() == 0){}
		else {
			std::string dadosDaConscienciaEnviada= servidores[i].realocarConsciencia();
			historico.inserirCapsula(dadosDaConscienciaEnviada);
		}
	}
}

void ComandoCentral::imprimirHistoricoMaisTodosServidores()
{
	historico.enviarTodasConsciencias();

	for (int i = 0; i < this->numeroDeServidores; i++) {
		servidores[i].enviarTodasConsciencias();
	}
}




