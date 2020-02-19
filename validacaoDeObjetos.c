#include <stdio.h>
#include <string.h>
#include <ctype.h>


int estaFuncaoValidaProdutos (char produtos[]) {
    
    int i, validacao=1, caracteresLidos=0;
    
    for (i=0; produtos[i]; i++) {
        if (caracteresLidos > 6) validacao=0; //verificar sem são menos
        if (!isalpha(produtos[0]) || produtos[0]<'A' || produtos[0]>'Z' || produtos[1]<'A' || produtos[1]>'Z') validacao=0;
        if (produtos[2]!='1') validacao=0;
        if (i>=2 && !isdigit(produtos[i])) validacao=0;
        caracteresLidos++;
    }
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
        if (clientes[1]=='5' && (clientes[2]!='0' || clientes[2]!='0' || clientes[2]!='0')) validacao=0;
        caracteresLidos++;
    }
    printf("%d\n", validacao);
    return validacao;
}

int main () {
    
    char clientes[5] = "A6000";
    estaFuncaoValidaClientes(clientes);
    
     return 0;
}
