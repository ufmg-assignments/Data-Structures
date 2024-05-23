#include <iostream>
#include <string>
#include <fstream>
#include "Buffer.h"
#include "Capsula.h"
#include "Consciencia.h"
#include "ComandoCentral.h"

int main(int argc, char* argv[]) {
	//Abertura do arquivo a ser lido
	std::ifstream arquivo(argv[1]);
	
	//Instanciaçao do comando central com o numero de servidores total
	std::string qnt = "";
	std::getline(arquivo, qnt);
	int quantServidores = stoi(qnt);
	ComandoCentral sistema(quantServidores);

	//Variaveis necessarias para leitura dos dados
	std::string comando = "";
	int parametro1 = 0;
	int parametro2 = 0;
	int aux = 0;
	std::string dados = "";

	//Leitura dos dados e execucao dos comandos associados
	while (std::getline(arquivo, comando)) {
		if (comando.substr(0,4)== "INFO") {
			//formatacao da entrada
			comando.replace(0,5, "");
			
			aux = comando.find(" ");
			parametro1 = stoi(comando.substr(0,aux));
			
			comando.replace(0, aux+2, "");
			dados = comando.substr(0,comando.length()-1);
			
			//Execucao do comando associado a INFO, se o parametro for valido
			if(parametro1 < 0 || parametro1 >= quantServidores){}
			else {
				sistema.inserirEmServidor(parametro1, dados);
			}
		}
		else if (comando.substr(0, 4) == "WARN") {
			//formatacao da entrada
			comando.replace(0, 5, "");

			aux = comando.find(" ");
			parametro1 = stoi(comando.substr(0, aux));

			comando.replace(0, aux + 1, "");
			parametro2 = stoi(comando);

			//Execucao do comando associado a WARN, se o parametro for valido
			if (parametro1 < 0 || parametro1 >= quantServidores) {}
			else {
				sistema.anteciparConsciencia(parametro1, parametro2);
			}
		}
		else if (comando.substr(0, 4) == "TRAN") {
			//Formatacao da entrada
			comando.replace(0, 5, "");

			aux = comando.find(" ");
			parametro1 = stoi(comando.substr(0, aux));

			comando.replace(0, aux + 1, "");
			parametro2 = stoi(comando);

			//Execucao do comando associado a TRAN, se o parametros forem validos
			if (parametro1 < 0 || parametro1 >= quantServidores
				|| parametro2<0 || parametro2 >=quantServidores) {}
			else {
				sistema.desabilitarServidor(parametro1, parametro2);
			}
		}
		else if (comando.substr(0, 4) == "ERRO"){
			//Formatacao da entrada
			comando.replace(0, 5, "");
			parametro1 = stoi(comando);

			//Execucao do comando associado a ERRO, se o parametro for valido
			if (parametro1 < 0 || parametro1 >= quantServidores) {}
			else {
				std::cout << "ERRO " << parametro1 << std::endl;
				sistema.tratarErro(parametro1);
			}
		}
		else if (comando.substr(0, 4) == "SEND") {
			//Execucao do comando associado a SEND
			sistema.enviarPrimeiraDeCadaServidor();
		}
		else if (comando.substr(0, 5) == "FLUSH") {
			//Execucao do comando associado a FLUSH
			sistema.imprimirHistoricoMaisTodosServidores();
		}
		else {}
	}
	
	//Fechamento do arquivo
	arquivo.close();

	return 0;
}