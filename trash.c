#include <stdio.h>
#include <string.h>
#include <ctype.h>


//no interface s]o se pode interagir com:
//////////catalogo dos produtos
//////////catalogo do clientes 
//////////faturacao global
//////////gestao filial 1
//////////gestao filial 2 
//////////gestao filial 3 

void initSGV(){
	int x;
	printf("Bem vindo, utilizador.\n"
		"Iniciando o Sistema de Gestao de Vendas,(SGV).\n"
		"Que acao deseja que seja realizada\n"
		"Precione (1) : para aceder ao Catalogo dos Produtos;\n"
		"Precione (2) : para aceder ao Catalogo dos Clientes;\n"
		"Precione (3) : para aceder ao Faturacao Global;\n"
		"Precione (4) : para aceder ao Gestao Filial 1;\n"
		"Precione (5) : para aceder ao Gestao Filial 2;\n"
		"Precione (6) : para aceder ao Gestao Filial 3;\n"
		"Precione (0) : para Fechar o SGV.\n");
	scanf("%d",&x);
	opcoes(x);

}

int opcoes(int x){
	switch(x){
		case(x==1):{};
		case(x==2):{};
		case(x==3):{};
		case(x==4):{};
		case(x==5):{};
		case(x==6):{};
		case(x==0):
			destroySVG();
		default
			printf("Por favor selecione uma das opcoes validas.\n");
			opcoes(x);
			
	}
	return 0;
}












