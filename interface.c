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
/*
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

*/





SGV initSGV();
SGV destroySGV();
SGV loadSGVFromFiles(SGV sgv, char* filesFolderPath);
















void texto(){
	int x;
	printf("Bem vindo, utilizador.\n"
		"Iniciando o Sistema de Gestao de Vendas,(SGV).\n"
		"Que acao deseja que seja realizada\n"
		"Precione (1) : para receber os produtos que comecem por uma letra;\n"//<?> getProductsStartedByLetter(SGV sgv, char letter);
		"Precione (2) : para receber as vendas e lucros de um produto num certo mes;\n"//<?> getProductSalesAndProfit(SGV sgv, char* productID, int month);
		"Precione (3) : para receber os produtos que nunca foram vendidos num filial;\n"//<?> getProductsNeverBought(SGV sgv, int branchID);
		"Precione (4) : para receber todos os clientes de todos os filiais;\n"//<?> getClientsOfAllBranches(SGV sgv);
		"Precione (5) : para receber os produtos nunca comprados e os clientes que nunca compraram;\n"//<?> getClientsAndProductsNeverBoughtCount(SGV sgv);
		"Precione (6) : para receber os produtos comprados por um cliente;\n"//<?> getProductsBoughtByClient(SGV sgv, char* clientID);
		"Precione (7) : para receber as vendas e os lucros entre dois meses;\n"//<?> getSalesAndProfit(SGV sgv, int minMonth, int maxMonth);
		"Precione (8) : para receber os cliente que compraram um produto;\n"//<?> getProductBuyers(SGV sgv, char* productID, int branch);
		"Precione (9) : para receber o produto favorito de um comprador;\n"//<?> getClientFavoriteProduct(SGV sgv, char* clientID, int branch);
		"Precione (10) : para receber os produtos mais vendidos;\n"//<?> getTopSelledProducts(SGV sgv, int limit);
		"Precione (11) : para receber os produtos mais lucrativos de um cliente;\n"//<?> getClientTopProfitProducts(SGV sgv, char* clientID, int limit);
		"Precione (12) : para ;\n"
		"Precione (13) : para ;\n"
		"Precione (0) : para Fechar o SGV.\n");
	scanf("%d \n",&x);
	opcoes(x);

}


int opcoes(int x){
	switch(x){
		case(x==1):{
			char letra;
			printf("Escolha a letra para procurar nos produtos.\n");
			scanf("%c \n",&letra);
			getProductsStartedByLetter(SGV sgv, letra );
		};
		case(x==2):{
			char* identificacaoDoProduto;
			int mes;
			printf("Escolha o produto que quer procurar.\n");
			scanf("%s \n",&identificacaoDoProduto);
			printf("Digite o mes a procurar.\n");
			scanf("%d \n",&mes);
			getProductSalesAndProfit(SGV sgv, identificacaoDoProduto, mes);
		};
		case(x==3):{
			int identificacaoDoFilial;
			printf("Digite o filial a procurar.\n");
			scanf("%d \n",&identificacaoDoFilial);
			getProductsNeverBought(SGV sgv, identificacaoDoFilial);
		};
		case(x==4):{
			printf("Apresentando os clientes de todos os filiais.\n");
			getClientsOfAllBranches(SGV sgv);
		};
		case(x==5):{
			printf("Apresentando os clientes que nunca compraram e os produtos nunca comprados.\n");
			getClientsAndProductsNeverBoughtCount(SGV sgv);//<<<<<<<<<<<<<<<<<<<<-----------------------------
		};
		case(x==6):{
			char* identificacaoDoCliente;
			printf("Escreva a identificacao do cliente que quer procurar.\n");
			scanf("%s \n",&identificacaoDoCliente);
			getProductsBoughtByClient(SGV sgv, identificacaoDoCliente);
		};
		case(x==7):{
			int mesMAX;
			int mesMIN;
			printf("Digite o mes inicial.\n");
			scanf("%d \n",&mesMIN);
			printf("Digite o mes final.\n");
			scanf("%d \n",&mesMAX);
			if (mesMAX<mesMIN) getSalesAndProfit(SGV sgv, mesMAX, mesMIN);
			else getSalesAndProfit(SGV sgv, mesMIN, mesMAX);
		};
		case(x==8):{
			char* identificacaoDoProduto;
			int filial;
			printf("Escolha o produto que quer procurar.\n");
			scanf("%s \n",&identificacaoDoProduto);
			printf("Digite o filial a procurar.\n");
			scanf("%d \n",&filial);
			getProductBuyers(SGV sgv, identificacaoDoProduto, filia);
		};
		case(x==9):{
			char* identificacaoDoCliente;
			int filial;
			printf("Escolha o cliente que quer procurar.\n");
			scanf("%s \n",&identificacaoDoCliente);
			printf("Digite o filial a procurar.\n");
			scanf("%d \n",&filial);
			getClientFavoriteProduct(SGV sgv, identificacaoDoCliente, filial);
		};
		case(x==10):{
			int limite;
			printf("Digite o limite do top dos produtos mais vendidos.\n");
			scanf("%d \n",&filial);
			getTopSelledProducts(SGV sgv, limite);
		};
		case(x==11):{
			char* identificacaoDoCliente;
			int filial;
			printf("Escolha o cliente que quer procurar.\n");
			scanf("%s \n",&identificacaoDoCliente);
			printf("Digite o filial a procurar.\n");
			scanf("%d \n",&filial);
			getClientTopProfitProducts(SGV sgv, identificacaoDoCliente, filial);
		};
		case(x==12):{};
		case(x==13):{};
		case(x==0):
			destroySVG();
		default
			printf("Por favor selecione uma das opcoes validas.\n");
			opcoes(x);
	return 0;
}

































/*
int opcoesClientes(int x){
	<?> getClientsOfAllBranches(SGV sgv);
<?> getClientsAndProductsNeverBoughtCount(SGV sgv);
<?> getClientFavoriteProduct(SGV sgv, char* clientID, int branch);

	return 0;
}

int opcoesProdutos(int x){
	<?> getProductsStartedByLetter(SGV sgv, char letter);
<?> getProductSalesAndProfit(SGV sgv, char* productID, int month);
<?> getProductsNeverBought(SGV sgv, int branchID);
<?> getProductsBoughtByClient(SGV sgv, char* clientID);
<?> getProductBuyers(SGV sgv, char* productID, int branch);

	return 0;
}

int opcoesVendas(int x){
	<?> getClientTopProfitProducts(SGV sgv, char* clientID, int limit);
	<?> getTopSelledProducts(SGV sgv, int limit);
	return 0;
}
*/







