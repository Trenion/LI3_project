
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//Nas funções seguintes, para ver os parâmetros e comentários das funções com mais detalhe, abrir o ficheiro .c com o mesmo nome

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
