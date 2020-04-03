#include "mainFunction.h"


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

extern int cLidos;
extern int cValidos;
extern int pLidos;
extern int pValidos;

void iniciar(){
    printf("\n A iniciar: SGV - Sistema de Gestão de Vendas.\n"
           "\n ... \n"
           "\n Bem vindo, utilizador!\n\n");
}
           
void menu(){
        printf(" A seguir apresenta-se o menu deste sistema.\n\n"
               "\n  1: Carregar registos no servidor.\n"
               "\n  2: Registos de produtos ordenados por uma dada letra.\n"
               "\n  3: Registos de venda e faturação de um dado produto num dado mês.\n"
               "\n  4: Registos de produtos não vendidos.\n"
               "\n  5: Registos de clientes que efetuaram compras em todas as filiais.\n"
               "\n  6: Registos de produtos e clientes sem menções de venda e compra.\n"
               "\n  7: Registos de compra por um dado cliente.\n"
               "\n  8: Registos de vendas e lucros entre dois dados meses.\n"
               "\n  9: Registos de clientes que compraram um dado produto numa dada filial, divididos por tipo.\n"
               "\n  10: Registos de compra de um dado cliente num dado mês, por ordem decrescente de quantidade.\n"
               "\n  11: Registos de produtos mais vendidos.\n"
               "\n  12: Registos de maior faturação de um dado cliente.\n"
               "\n  13: Registos de produtos em stock.\n"
               "\n  14: Registos de clientes.\n"
               "\n  15: Registos de vendas.\n"
               "\n  0: Encerrar SGV - Sistema de Gestão de Vendas.\n\n  ");
}

//CARACTERES - Certo

char validaCaractere(char c[]){
    if (c[0]>='A' && c[0]<='Z') {
        return c[0];
    }
    printf("Entrada inválida.\n");
    return '0';
}

char caractereInvalido(){
    int i;
    char c, prod[2];
    for (i=0; (c = getchar()) != '\n'; i++) prod[i]=c;
    if (i>1) prod[0]='0';
    return validaCaractere(prod);
}

//MES - Certo

int validaMes(int c){
    if (c>=1 && c<=12) {
        return c;
    }
    printf("Entrada inválida.\n");
    return 0;
}

int mesInvalido(){
    int c;
    scanf(" %d", &c);
    return validaMes(c);
}

//FILIAIS - Certo

int validaFilial(int c){
    if (c==1 || c==2 || c==3) {
        return c;
    }
    printf("Entrada inválida.\n");
    return 0;
}

int filialInvalida(){
    int c;
    scanf(" %d", &c);
    return validaFilial(c);
}

//FILIAL OU GLOBAL - Certo

char validaFilialGlobal(char c[]){
    if (c[0]=='f' || c[0]=='G') {
        return c[0];
    }
    printf("Entrada inválida.\n");
    return '0';
}

char filialGlobalInvalida(){
    int i;
    char c, prod[2];
    for (i=0; (c = getchar()) != '\n'; i++) prod[i]=c;
    if (i>1) prod[0]='0';
    return validaFilialGlobal(prod);
}

//NÚMERO - Certo

int validaNumero(int c){
    if (c>=1 && c<=15000) {
        return c;
    }
    printf("Entrada inválida.\n");
    return 0;
}

int numeroInvalido(){
    int c;
    scanf(" %d", &c);
    return validaMes(c);
}

//PRODUTOS - Certo

char* validaProduto(char c[]){
    char* p = malloc(sizeof(char*));
    int i;
    if (ValidaP(c)==1) {
        for (i=0; i<6;i++) p[i]=c[i];
        return p;
    }
    printf("Entrada inválida.\n");
    return NULL;
}

char* produtoInvalido(){
    int i;
    char c, prod[6];
    for (i=0; (c = getchar()) != '\n'; i++) {
        if (i>5) {
            prod[0]='0';
            break;
        }
        else prod[i]=c;
    }
    return validaProduto(prod);
}

//CLIENTES - Certo

char* validaCliente(char c[]){
    char* p = malloc(sizeof(char*));
    int i;
    if (ValidaC(c)==1) {
        for (i=0; i<5;i++) p[i]=c[i];
        return p;
    }
    printf("Entrada inválida.\n");
    return NULL;
}

char* clienteInvalido(){
    int i;
    char c, prod[5];
    for (i=0; (c = getchar()) != '\n'; i++) {
        if (i>4) {
            prod[0]='0';
            break;
        }
        else prod[i]=c;
    }
    return validaCliente(prod);
}

//INPUT - Certo

char validaInput(char c[]){
    if (c[0]=='D' || c[0]=='U') {
        return c[0];
    }
    printf("Entrada inválida.\n");
    return '0';
}

char inputInvalido(){
    int i;
    char c, prod[2];
    for (i=0; (c = getchar()) != '\n'; i++) {
        if (i>4) {
            prod[0]='0';
            break;
        }
        else prod[i]=c;
    }
    return validaInput(prod);
}

char* getLine() {
    int i;
    char* p = malloc(sizeof(char*)), c;
    for (i=0; (c = getchar()) != '\n'; i++) p[i]=c;
    return p;
}

void opcoes(){
    
    menu();
    printf(" Por favor, insira o número correspondente à ação que pretende.\n\n");
    int op;
    scanf(" %d",&op);
    
    FILE *fp, *fc, *fv;
    int mes, mes1, filial, h, autodefault=0, printa=0, *cpEx6;
    char x, *p = malloc(sizeof(char*)), *fpr, *fcl, *fve, **clientes, **produtos, **cEx4, **cEx5, ***cEx9, **cEx10, **cEx12;
    listaCompras* v, *l, *lEx2;
    cell *** Ex7, *cEx11;
    float* fEx3, *fEx8;
    switch(op){
        case(1):{
            x='0';
            while ((getchar()) != '\n');
            printf("\n Por favor, insira o caractere correspondente à ação que pretende.\n"
                   "\n  U: Introduzir os ficheiros a carregar.\n"
                   "\n  A: Carregar os ficheiros default.\n\n");
            while (x=='0') {
                x = inputInvalido();
                if (x!='0') break;
            }
            printa=1;
            if (x=='U') {
                printf("\nIntroduza um ficheiro de produtos válido.\n");
                fpr = getLine();
                fp = fopen(fpr, "r");
                printf("\nIntroduza um ficheiro de clientes válido.\n");
                fcl = getLine();
                fc = fopen(fcl, "r");
                printf("\nIntroduza um ficheiro de vendas válido.\n");
                fve = getLine();
                fv = fopen(fve, "r");
                printf("\nAbrindo o conjunto de ficheiros inserido.\n");
                produtos = arrayP(fp,NULL);
                clientes = arrayC(fc,NULL);
                v = arrayV(fv);
                valArrayVC(v,clientes);
                valArrayVP(v,produtos);
                l = validaFinal(v);
                printf("\nConcluído!\n");
            }
            else {
                autodefault=1;
                printf("\nAbrindo o conjunto de ficheiros default: Produtos.txt, Clientes.txt, Vendas_1M.txt.\n");
                fp = fopen("Produtos.txt", "r");
                fc = fopen("Clientes.txt", "r");
                fv = fopen("Vendas_1M.txt", "r");
                produtos = arrayP(fp,NULL);
                clientes = arrayC(fc,NULL);
                v = arrayV(fv);
                valArrayVC(v,clientes);
                valArrayVP(v,produtos);
                l = validaFinal(v);
                printf("\nConcluído!\n");
            }
            
            opcoes();
       };
        case(2):{
            x='0';
            while ((getchar()) != '\n');
            printf("\nIntroduza um caractere válido. Hint: 1 letra maiúscula.\n");
            while (x=='0') {
                x = caractereInvalido();
                if (x!='0') break;
            }
            printf("\nRegistos de produtos ordenados pela letra inserida.\n");
            lEx2 = ex2(l,x);
            opcoes();
        };
        case(3):{
            mes=0; p = NULL;
            while ((getchar()) != '\n');
            printf("\nIntroduza um produto válido. Hint: 2 letras maiúsculas seguidas de 4 números.\n");
            while (p==NULL) {
                p = produtoInvalido();
                if (p!=NULL) break;
            }
            printf("\nIntroduza um mês válido.\n");
            while (mes==0) {
                mes = mesInvalido();
                if (mes!=0) break;
            }
            printf("\nIntroduza um tipo de distribuição válido. Hint: f para dados filial a filial, g para dados globais.\n");
            while (x=='0') {
                x = filialGlobalInvalida();
                if (x!='0') break;
            }
            printf("\nRegistos de venda e faturação do produto e mês indicados.\n");
            fEx3 = ex3(l,mes,p,x);
            opcoes();
        };
        case(4):{
            x='0';
            while ((getchar()) != '\n');
            printf("\nIntroduza um tipo de distribuição válido. Hint: f para dados filial a filial, g para dados globais.\n");
            while (x=='0') {
                x = filialGlobalInvalida();
                if (x!='0') break;
            }
            printf("\nRegistos de produtos não vendidos.\n");
            cEx4 = ex4(produtos, l, x);
            opcoes();
        };
        case(5):{
            while ((getchar()) != '\n');
            printf("\nRegistos de clientes que efetuaram compras em todas as filiais.\n");
            cEx5 = ex5(l);
            opcoes();
        };
        case(6):{
            while ((getchar()) != '\n');
            printf("\nRegistos de produtos e clientes sem menções de venda e compra.\n");
            cpEx6=ex6(clientes,produtos,l);
            opcoes();
        };
        case(7):{
            p = NULL;
            while ((getchar()) != '\n');
            printf("\nIntroduza um cliente válido. Hint: 1 letra maiúscula seguida de 4 números.\n");
            while (p==NULL) {
                p = clienteInvalido();
                if (p!=NULL) break;
            }
            printf("\nRegistos de compra pelo cliente inserido.\n");
            Ex7 = ex7(l,p);
            opcoes();
        };
        case(8):{
            mes = 0; mes1 = 0;
            while ((getchar()) != '\n');
            printf("\nIntroduza um mês válido.\n");
            while (mes==0) {
                mes = mesInvalido();
                if (mes!=0) break;
            }
            printf("\nIntroduza um mês válido.\n");
            while (mes1==0) {
                mes1 = mesInvalido();
                if (mes1!=0) break;
            }
            printf("\nRegistos de vendas e lucros entre dois dados meses.\n");
            fEx8 = ex8(l,mes,mes1);
            opcoes();
        };
        case(9):{
            p=NULL; filial=0;
            while ((getchar()) != '\n');
            printf("\nIntroduza um produto válido. Hint: 2 letras maiúsculas seguidas de 4 números.\n");
            while (p==NULL) {
                p = produtoInvalido();
                if (p!=NULL) break;
            }
            printf("\nIntroduza uma filial válida.\n");
            while (filial==0) {
                filial = filialInvalida();
                if (filial!=0) break;
            }
            printf("\nRegistos de clientes que compraram o produto na filial inseridos, divididos por tipo.\n");
            cEx9 = ex9(l,p,filial);
            opcoes();
        };
        case(10):{
            p = NULL;mes=0;
            while ((getchar()) != '\n');
            printf("\nIntroduza um cliente válido. Hint: 1 letra maiúscula seguida de 4 números.\n");
            while (p==NULL) {
                p = clienteInvalido();
                if (p!=NULL) break;
            }
            printf("\nIntroduza um mês válido.\n");
            while (mes==0) {
                mes = mesInvalido();
                if (mes!=0) break;
            }
            printf("\nRegistos de compra do cliente no mês inseridos, por ordem decrescente de quantidade.\n");

            cEx10 = ex10(l, p, mes);
            opcoes();
        };
        case(11):{
            h=0;
            printf("\nIntroduza um número inteiro válido.\n");
            while (h==0) {
                h = numeroInvalido();
                if (h!=0) break;
            }
            printf("\nRegistos do número inserido de produtos mais vendidos, por ordem decrescente de faturação.\n");
            
            cEx11 = ex11(l, h);
            opcoes();
        };
        case(12):{
            p = NULL;h=0;
            while ((getchar()) != '\n');
            printf("\n Introduza um cliente válido. Hint: 1 letra maiúscula seguida de 4 números.\n");
            while (p==NULL) {
                p = clienteInvalido();
                if (p!=NULL) break;
            }
            printf("\n Introduza um número inteiro válido.\n");
            while (h==0) {
                h = numeroInvalido();
                if (h!=0) break;
            }
            printf("\n Registos do número de produtos de maior faturação do cliente inseridos.\n");

            cEx12 = ex12(l, p, h);
            opcoes();
        };
        case(13):{
            if (printa==1){
                if (autodefault==0) {
                    printf(" Apresentando os ficheiros lidos:\n"
                           "\n Ficheiro de produtos: %s - %d linhas lidas, %d validadas."
                           "\n Ficheiro de clientes: %s - %d linhas lidas, %d validadas."
                           "\n Ficheiro de vendas: %s - %d linhas lidas, %d validadas.", fpr, pLidos, pValidos, fcl, cLidos, cValidos, fve, *(l->linhasLidas), *(l->size));
                }
                else {
                    printf(" Apresentando os ficheiros lidos:\n"
                           "\n Ficheiro de produtos: %s - %d linhas lidas, %d validadas."
                           "\n Ficheiro de clientes: %s - %d linhas lidas, %d validadas."
                           "\n Ficheiro de vendas: %s - %d linhas lidas, %d validadas.", fpr, pLidos, pValidos, fcl, cLidos, cValidos, fve, *(l->linhasLidas), *(l->size));
                }
            }
            else printf("Não foram introduzidos quaisquer ficheiros para leitura.");
            opcoes();
        };
        case(0):{
            break;
        };
        default:{
            printf("Entrada inválida.\n");
            opcoes();
        }
    }
}



int main() {
    iniciar();
    opcoes();
    return 0;
}
