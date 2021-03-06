
#ifndef mainFunction_h
#define mainFunction_h

#include <stdio.h>

char* ficVendas;
char* ficProdutos;
char* ficClientes;
int cLidos;
int cValidos;
int pLidos;
int pValidos;

// Struct responsável de salvar os dados de cada venda; utiliza pointers pois é mais facil usar os dados.
typedef struct
{
    char* produtoC;
    float* precoUC;
    double* unidadesC;
    char* tipoC;
    char* clienteC;
    double* mesC;
    double* filialC;
    //valC é uma variável de validação - se o cliente e o produto da compra são válidos e existem, então o seu valor incrementa a 2.
    //É utilizada na última validação das vendas.
    int* valC;
}compra,* CompraP;

//Struct responsável de salvar uma lista com as structs compra de todas as vendas e o tamanho da lista de structs
typedef struct
{
    CompraP* Compras;
    int* size;
    int* linhasLidas;
}listaCompras;

//Struct responsável de fazer as tabelas de produtos
typedef struct
{
    char* produtoT;
    int* unidadesT;
}cell;


//Nas funções seguintes, para ver os parâmetros e comentários das funções com mais detalhe, abrir o ficheiro .c com o mesmo nome

int cmpStr(const void *a, const void *b);
int cmpStruct1(const void *a, const void *b);
int cmpStruct2(const void *a, const void *b);
int cmpStruct3(const void *a, const void *b);
int cmpStruct4(const void *a, const void *b);
int cmpStruct5(const void *a, const void *b);
int cmpStruct6(const void *a, const void *b);
int cmpStruct7(const void *a, const void *b);
int cmpStruct8(const void *a, const void *b);

int** posMatrix(int i);

int cmp(int a[], int b[], int c);
void cmpStruct(listaCompras * l, int* caso, int** pos, int n);

int ValidaP (char produtos[]);
int ValidaC (char clientes[]);
CompraP ValidaV (char vendas[]);

char** arrayP(FILE *fp,FILE *fp1);
char** arrayC(FILE *fp,FILE *fp1);
listaCompras* arrayV(FILE *fp);

void valArrayVC(listaCompras* v,char** c);
void valArrayVP(listaCompras* v,char** c);
listaCompras* validaFinal(listaCompras* v);

void printListaC(listaCompras* l,FILE* fp);
void printM(int** pos, int n);

listaCompras* aux(listaCompras* l,int a, int b, int x);
listaCompras* ex2(listaCompras* l,char c);
float* ex3(listaCompras* l,int mes,char* p,char c);
char** ex4(char** p, listaCompras* l, char c);
char** ex5(listaCompras* l);
int* ex6(char** c,char** p,listaCompras* l);
cell*** ex7(listaCompras* l,char* c);
float* ex8(listaCompras* l,int mes1,int mes2);
char*** ex9(listaCompras* l,char* p,int f);
char** ex10(listaCompras* l, char* c, int N);
cell* ex11(listaCompras* l, int N);
char** ex12(listaCompras* l, char* c, int N);

#endif
