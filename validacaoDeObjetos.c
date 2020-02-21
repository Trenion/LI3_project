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

int main () {
    
    char vendas[5] = "KR1583 77.72 128 P L4891 2 1";
    estaFuncaoValidaVendas(vendas);
    
     return 0;
}
