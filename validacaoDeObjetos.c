#include <stdio.h>
#include <string.h>
#include <ctype.h>


int estaFuncaoValidaProdutos (char produtos[]) {
    
    int i, validacao=1, caracteresLidos=0;
    for (i=0; produtos[i]; i++) {
        if (caracteresLidos> 6) validacao=0;
        if (!isalpha(produtos[0]) || produtos[0]<'A' || produtos[0]>'Z' || produtos[1]<'A' || produtos[1]>'Z') validacao=0;
        if (produtos[2]!='1') validacao=0;
        if (i>=2 && !isdigit(produtos[i])) validacao=0;
        caracteresLidos++;
    }
    if (caracteresLidos != 6) validacao=0;
    printf("%d\n", validacao);
    return validacao;
}


int estaFuncaoValidaClientes (char clientes[]) {
    
    int i, validacao=1, caracteresLidos=0;
    for (i=0; clientes[i]; i++) {
        if (caracteresLidos> 5) validacao=0;
        if (!isalpha(clientes[0]) || clientes[0]<'A' || clientes[0]>'Z') validacao=0;
        if (i>=1 && !isdigit(clientes[i])) validacao=0;
        if (clientes[1]<'1' || clientes[1]>'5' ) validacao=0;
        if (clientes[1]=='5' && (clientes[2]!='0' || clientes[3]!='0' || clientes[4]!='0')) validacao=0;
        caracteresLidos++;
    }
    if (caracteresLidos != 5) validacao=0;
    printf("%d\n", validacao);
    return validacao;
}

int estaFuncaoValidaVendas (char vendas[]) {
    
    int validacao=1, iteracoes=1;
    char *subString;
    subString = strtok(vendas, " ");
    if (!estaFuncaoValidaProdutos(subString)) {
        return 0;
    }
    while (subString!=NULL) {
        subString = strtok(NULL, " ");
        if (iteracoes==1) {
            long double precoUnit = atof (subString);
            if (precoUnit<0 || precoUnit>=1000) {
                validacao=0;
                break;
            }
        }
        if (iteracoes==2) {
            double unidades = atof (subString);
            if (unidades<1 || unidades>200) {
                validacao=0;
                break;
            }
        }
        if (iteracoes==3) {
            if ((strcmp (subString, "P") || (strcmp (subString, "N")))==0) {
                validacao=0;
                break;
            }
        }
        if (iteracoes==4) {
            if(!estaFuncaoValidaClientes(subString)) {
                validacao=0;
                break;
            }
        }
        if (iteracoes==5) {
            double mes = atof (subString);
            if (mes<1 || mes>12) {
                validacao=0;
                break;
            }
        }
        if (iteracoes==6) {
            double filial = atof (subString);
            if (filial<1 || filial>3) {
                validacao=0;
                break;
            }
        }
        iteracoes++;
    }
    
    printf("%d\n\n", validacao);
    return validacao;
}


int procuraSeq (char *lista[], char pedido[], int n) {
    
    int i, contagem=0;
    for (i=0; i<n; i++) {
        char *contido = strstr(lista[i], pedido);
        if (contido!=NULL) {
            printf("%s\n", lista[i]);
            contagem++;
        }
    }
    printf("\n");
    return contagem;
}

int procuraSeqInicial (char *lista[], char pedido[], int n) {

    int i, contagem=0;
    for (i=0; i<n; i++) {
        if (strncmp(lista[i], pedido, strlen(pedido))==0) {
            printf("%s\n", lista[i]);
            contagem++;
        }
        else break;
    }
    printf("\n");
    return contagem;
}







void getProductSalesAndProfitGlobal (listaCompras* lista, char* productID, int month) {
    
    int i; float vendasN=0, faturacaoN=0, vendasP=0, faturacaoP=0;
    for (i=0; i<*(lista->size); i++) {
        if (productID == (lista->Compras)[i]->produtoC) {
            if (month == *(lista->Compras)[i]->mesC) {
                if (*(lista->Compras)[i]->tipoC == 'N') {
                    vendasN+=*(lista->Compras)[i]->unidadesC;
                    faturacaoN+=(*(lista->Compras)[i]->precoUC)*(*(lista->Compras)[i]->unidadesC);
                }
                else if (*(lista->Compras)[i]->tipoC == 'P') {
                    vendasP+=*(lista->Compras)[i]->unidadesC;
                    faturacaoP+=(*(lista->Compras)[i]->precoUC)*(*(lista->Compras)[i]->unidadesC);
                }
            }
        }
    }
    printf("\nProductID: %s"
           "\nMonth: %d"
           "\n\nTotal de vendas: %f"
           "\n      Total de vendas normais: %f"
           "\n      Total de vendas promocionais: %f"
           "\n\nTotal faturado: %f"
           "\n      Total faturado em vendas normais: %f"
           "\n      Total faturado em vendas promocionais: %f"
           "\n\n", productID, month, vendasN+vendasP, vendasN, vendasP, faturacaoN+faturacaoP, faturacaoN, faturacaoP);
}

void getProductSalesAndProfitFilialAFilial (listaCompras* lista, char* productID, int month) {
    
    int i; float vendas1N=0, faturacao1N=0, vendas1P=0, faturacao1P=0, vendas2N=0, faturacao2N=0, vendas2P=0, faturacao2P=0, vendas3N=0, faturacao3N=0, vendas3P=0, faturacao3P=0;
    for (i=0; i<*(lista->size); i++) {
        if (productID == (lista->Compras)[i]->produtoC) {
            if (month == *(lista->Compras)[i]->mesC) {
                if (*(lista->Compras)[i]->filialC == 1){
                    if (*(lista->Compras)[i]->tipoC == 'N') {
                        vendas1N++;
                        faturacao1N+=(*(lista->Compras)[i]->precoUC)*(*(lista->Compras)[i]->unidadesC);
                    }
                    else if (*(lista->Compras)[i]->tipoC == 'P') {
                        vendas1P++;
                        faturacao1P+=(*(lista->Compras)[i]->precoUC)*(*(lista->Compras)[i]->unidadesC);
                    }
                }
                else if (*(lista->Compras)[i]->filialC == 2){
                    if (*(lista->Compras)[i]->tipoC == 'N') {
                        vendas2N++;
                        faturacao2N+=(*(lista->Compras)[i]->precoUC)*(*(lista->Compras)[i]->unidadesC);
                    }
                    else if (*(lista->Compras)[i]->tipoC == 'P') {
                        vendas2P++;
                        faturacao2P+=(*(lista->Compras)[i]->precoUC)*(*(lista->Compras)[i]->unidadesC);
                    }
                }
                else if (*(lista->Compras)[i]->filialC == 3){
                    if (*(lista->Compras)[i]->tipoC == 'N') {
                        vendas3N++;
                        faturacao3N+=(*(lista->Compras)[i]->precoUC)*(*(lista->Compras)[i]->unidadesC);
                    }
                    else if (*(lista->Compras)[i]->tipoC == 'P') {
                        vendas3P++;
                        faturacao3P+=(*(lista->Compras)[i]->precoUC)*(*(lista->Compras)[i]->unidadesC);
                    }
                }
            }
        }
    }
    printf("\nProductID: %s"
           "\nMonth: %d"
           "\n\n\nBranch 1"
           "\n\n    Total de vendas: %.3f"
           "\n          Total de vendas normais: %.3f"
           "\n          Total de vendas promocionais: %.3f"
           "\n\n    Total faturado: %.3f"
           "\n          Total faturado em vendas normais: %.3f"
           "\n          Total faturado em vendas promocionais: %.3f"
           "\n\n\nBranch 2"
           "\n\n    Total de vendas: %.3f"
           "\n          Total de vendas normais: %.3f"
           "\n          Total de vendas promocionais: %.3f"
           "\n\n    Total faturado: %.3f"
           "\n          Total faturado em vendas normais: %.3f"
           "\n          Total faturado em vendas promocionais: %.3f"
           "\n\n\nBranch 3"
           "\n\n    Total de vendas: %.3f"
           "\n          Total de vendas normais: %.3f"
           "\n          Total de vendas promocionais: %.3f"
           "\n\n    Total faturado: %.3f"
           "\n          Total faturado em vendas normais: %.3f"
           "\n          Total faturado em vendas promocionais: %.3f"
           "\n\n", productID, month, vendas1N+vendas1P, vendas1N, vendas1P, faturacao1N+faturacao1P, faturacao1N, faturacao1P, vendas2N+vendas2P, vendas2N, vendas2P, faturacao2N+faturacao2P, faturacao2N, faturacao2P, vendas3N+vendas3P, vendas3N, vendas3P, faturacao3N+faturacao3P, faturacao3N, faturacao3P);
}


void getSalesAndProfit (listaCompras* lista, int minMonth, int maxMonth) {
    
    int i; float vendas=0, faturacao=0;
       for (i=0; i<*(lista->size); i++) {
               if (*(lista->Compras)[i]->mesC>=minMonth && (*(lista->Compras)[i]->mesC<=maxMonth)) {
                   vendas++;
                   faturacao+=(*(lista->Compras)[i]->precoUC)*(*(lista->Compras)[i]->unidadesC);
               }
       }
    printf("\nMonth: from %d to %d"
           "\n\n    Total de vendas: %.3f"
           "\n      Total faturado: %.3f", minMonth, maxMonth, vendas, faturacao);
}


void getProductBuyers (listaCompras* lista, char* productID, int branch) {
   
    int i; float vendasN=0, faturacaoN=0, vendasP=0, faturacaoP=0;
    printf("\nLista de compradores do produto %s\n\n", productID);
        for (i=0; i<*(lista->size); i++) {
            if (productID == (lista->Compras)[i]->produtoC) {
                if (branch == *(lista->Compras)[i]->filialC) {
                    if (*(lista->Compras)[i]->tipoC == 'N') {
                        vendasN++;
                        faturacaoN+=(*(lista->Compras)[i]->precoUC)*(*(lista->Compras)[i]->unidadesC);
                    }
                    else {
                        vendasP++;
                        faturacaoP+=(*(lista->Compras)[i]->precoUC)*(*(lista->Compras)[i]->unidadesC);
                    }
                    printf(" %s\n", (lista->Compras)[i]->clienteC);
                }
            }
        }
    printf("\nProductID: %s"
           "\nBranch: %d"
           "\n\nTotal de vendas: %f"
           "\n      Total de vendas normais: %f"
           "\n      Total de vendas promocionais: %f"
           "\n\nTotal faturado: %f"
           "\n      Total faturado em vendas normais: %f"
           "\n      Total faturado em vendas promocionais: %f"
           "\n\n", productID, branch, vendasN+vendasP, vendasN, vendasP, faturacaoN+faturacaoP, faturacaoN, faturacaoP);
}




int main () {
    
    char vendas[5] = "KR1583 77.72 128 P L4891 2 1";
    
    
    return 0;
}
