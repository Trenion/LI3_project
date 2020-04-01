
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "interface.h"


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

//CARACTERES - a primeira função valida o input, a segunda faz a recursividade

char validaCaractere(char c){
    if (c>='A' && c<='Z') {
        return c;
    }
    printf("Entrada inválida.\n");
    return '0';
}

char caractereInvalido(){
    char c;
    scanf(" %c", &c);
    return validaCaractere(c);
}

//MES - a primeira função valida o input, a segunda faz a recursividade

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

//FILIAIS - a primeira função valida o input, a segunda faz a recursividade

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

//FILIAL OU GLOBAL - a primeira função valida o input, a segunda faz a recursividade

char validaFilialGlobal(char c){
    if (c=='F' || c=='G') {
        return c;
    }
    printf("Entrada inválida.\n");
    return '0';
}

char filialGlobalInvalida(){
    char c;
    scanf(" %c", &c);
    if (c<'A' || c>'Z') c='0';
    return validaFilialGlobal(c);
}

//NÚMERO - a primeira função valida o input, a segunda faz a recursividade

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

//PRODUTOS - a primeira função valida o input, a segunda faz a recursividade

char* validaProduto(char c[]){
    char* p = malloc(sizeof(char*));
    int i;
    if (validaP(c)==1) {
        for (i=0; i<6;i++) p[i]=c[i];
        return p;
    }
    printf("Entrada inválida.\n");
    return NULL;
}

char* produtoInvalido(){
    int i;
    char c, prod[10];
    for (i=0; (c = getchar()) != '\n'; i++) prod[i]=c;
    if (i>5) prod[0]='0';
    return validaProduto(prod);
}

//CLIENTES - a primeira função valida o input, a segunda faz a recursividade

char* validaCliente(char c[]){
    char* p = malloc(sizeof(char*));
    int i;
    if (validaC(c)==1) {
        for (i=0; i<5;i++) p[i]=c[i];
        return p;
    }
    printf("Entrada inválida.\n");
    return NULL;
}

char* clienteInvalido(){
    int i;
    char c, prod[6];
    for (i=0; (c = getchar()) != '\n'; i++) prod[i]=c;
    if (i>4) prod[0]='0';
    return validaCliente(prod);
}


//Função que permite a normal utilização do sistema; possui as várias opções do programa que levam para determinados quesitos e objetivos.


void opcoes(){
    menu();
    printf(" Por favor, insira o número correspondente à ação que pretende.\n\n");
    int op;
    scanf(" %d",&op);
    
    int mes, mes1, filial, h;
    char x, *p = malloc(sizeof(char*));
    switch(op){
            
        case(1):{
            
//            Função do exercício 1
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
            
//            Função do exercício 2
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
            printf("\nRegistos de venda e faturação do produto e mês indicados.\n");

//            Função do exercício 3
            opcoes();
        };
        case(4):{
            x='0';
            while ((getchar()) != '\n');
            printf("\nIntroduza um tipo de distribuição válido. Hint: F para dados filial a filial, G para dados globais.\n");
            while (x=='0') {
                x = filialGlobalInvalida();
                if (x!='0') break;
            }
            printf("\nRegistos de produtos não vendidos.\n");
            
//            Função do exercício 4
            opcoes();
        };
        case(5):{
            while ((getchar()) != '\n');
            printf("\nRegistos de clientes que efetuaram compras em todas as filiais.\n");
            
//            Função do exercício 5
            opcoes();
        };
        case(6):{
            while ((getchar()) != '\n');
            printf("\nRegistos de produtos e clientes sem menções de venda e compra.\n");

//            Função do exercício 6
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

//            Função do exercício 7
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
            
//            Função do exercício 8
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

//            Função do exercício 9
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

//            Função do exercício 10
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
            
//            Função do exercício 11
            opcoes();
        };
        case(12):{
            p = NULL;h=0;
            while ((getchar()) != '\n');
            printf("\nIntroduza um cliente válido. Hint: 1 letra maiúscula seguida de 4 números.\n");
            while (p==NULL) {
                p = clienteInvalido();
                if (p!=NULL) break;
            }
            printf("\nIntroduza um número inteiro válido.\n");
            while (h==0) {
                h = numeroInvalido();
                if (h!=0) break;
            }
            printf("\nRegistos do número de produtos de maior faturação do cliente inseridos.\n");

//            Função do exercício 12
            opcoes();
        };
        case(13):{
            
//            Função de print dos produtos
            opcoes();
        };
        case(14):{

//          Função de print dos clientes
            opcoes();
        };
        case(15):{

//            Função de print das vendas
            opcoes();
        };
        case(0):{
            
//            Função que apaga tudo o que foi feito
            break;
        };
        default:{
            printf("Entrada inválida.\n");
            opcoes();
        }
    }
}


//função de teste main - a eliminar mais tarde!
int main() {

    texto();
    opcoes();
    return 0;
}

//maybe ??
void destroySGV(SGV sgv){
	remove(sgv);// a funçao remove apaga o ficheiro selecionado
	free(sgv);// supostamente liberta a memoria. é que a free recebe um pointer.
}
