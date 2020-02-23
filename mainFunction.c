#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int cmpStr(const void *a, const void *b) 
{ 
    char **ia = (char **)a;
    char **ib = (char **)b;
    return strcmp(*ia, *ib);
} 

int ValidaP (char produtos[]) {
    int i, validacao=1, caracteresLidos=0;
    for (i=0; produtos[i]; i++) {
        if (caracteresLidos> 6) validacao=0;
        if (!isalpha(produtos[0]) || produtos[0]<'A' || produtos[0]>'Z' || produtos[1]<'A' || produtos[1]>'Z') validacao=0;
        if (produtos[2]!='1') validacao=0;
        if (i>=2 && !isdigit(produtos[i])) validacao=0;
        caracteresLidos++;
    }
    if (caracteresLidos != 6) validacao=0;
    return validacao;
}
int ValidaC (char clientes[]) {
    
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
    return validacao;
}
int arrayP(){
	FILE *fp,*fp1;
    fp = fopen("Produtos.txt","r");
//    fp1 = fopen("P.txt","a");
    char str[6],*s,**m;
	int i,j=0;
	m = malloc(j * sizeof(char*));
	while(fgets(str,7,fp)){
        if (ValidaP(str)){
        	s = malloc(7 * sizeof(char));
            for (i = 0; i < 6; i++){
                s[i]=str[i];
            }s[i]='\0';
            m = realloc(m,(j+1) * sizeof(char*));
            m[j++]=s;
        }    
    }qsort(m, j, sizeof(char*), cmpStr);
    fp1 = fopen("P.txt","a");
    for (i = 0; i < j; i++){
        fprintf(fp1,"%s\n",m[i]);	
    } 
    return 0;
}
int arrayC(){
    FILE *fp,*fp1;
    fp = fopen("Clientes.txt","r");
//    fp1 = fopen("C.txt","a");
    char str[5],*s,**m;
    int i,j=0;
    m = malloc(j * sizeof(char*));
    while(fgets(str,6,fp)){
        if (ValidaC(str)){
            s = malloc(6 * sizeof(char));
            for (i = 0; i < 5; i++){
                s[i]=str[i];
            }s[i]='\0';
            m = realloc(m,(j+1) * sizeof(char*));
            m[j++]=s;
        }    
    }qsort(m, j, sizeof(char*), cmpStr);
    fp1 = fopen("C.txt","a");
    for (i = 0; i < j; i++){
        fprintf(fp1,"%s\n",m[i]);   
    } 
    return 0;
}
int main(){
    arrayP();
    arrayC();
    return 0;
}
