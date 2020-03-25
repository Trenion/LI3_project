









#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void iniciar();
void menu();
char validaCaractere(char c);
char caractereInvalido();
int validaMes(int c);
int mesInvalido();
int validaFilial(int c);
int filialInvalida();
char validaFilialGlobal(char c);
char filialGlobalInvalida();
int validaNumero(int c);
int numeroInvalido();
char* validaProduto(char c[]);
char* produtoInvalido();
char* validaCliente(char c[]);
char* clienteInvalido();
void opcoes();
int main();



void destroySGV(SGV sgv);























/*

SGV initSGV();
SGV destroySGV();
SGV loadSGVFromFiles(SGV sgv, char* filesFolderPath);
<?> getProductsStartedByLetter(SGV sgv, char letter);
<?> getProductSalesAndProfit(SGV sgv, char* productID, int month);
<?> getProductsNeverBought(SGV sgv, int branchID);/////////////////////
<?> getClientsOfAllBranches(SGV sgv);/////////////////////
<?> getClientsAndProductsNeverBoughtCount(SGV sgv);/////////////////////
<?> getProductsBoughtByClient(SGV sgv, char* clientID);/////////////////////
<?> getSalesAndProfit(SGV sgv, int minMonth, int maxMonth);
<?> getProductBuyers(SGV sgv, char* productID, int branch);
<?> getClientFavoriteProduct(SGV sgv, char* clientID, int branch);/////////////////////
<?> getTopSelledProducts(SGV sgv, int limit);/////////////////////
<?> getClientTopProfitProducts(SGV sgv, char* clientID, int limit);/////////////////////
*/