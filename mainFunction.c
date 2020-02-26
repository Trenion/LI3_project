#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct
{
    char* produtoC;
    float* precoUC;
    double* unidadesC;
    char* tipoC;
    char* clienteC;
    double* mesC;
    double* filialC;
}compra,* CompraP;

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
CompraP ValidaV (char vendas[]) {
    compra* c = malloc(sizeof(compra));
    int iteracoes=1,j;
    char *subString;
    subString = strtok(vendas, " ");
    if (!ValidaP(subString)) {
        return NULL;
    }
    c->produtoC= malloc((strlen(subString)+1) * sizeof(char));
    for (j = 0; j < strlen(subString); j++){
        (c->produtoC)[j]=subString[j];
    }(c->produtoC)[j]='\0';
    while (subString!=NULL) {
        subString = strtok(NULL, " ");
        if (iteracoes==1) {
             //--
            float precoUnit;
            precoUnit = atof (subString);//--
            if (precoUnit<0 || precoUnit>=1000) {
                return NULL;
            }
            c->precoUC= malloc(sizeof(float));
            *(c->precoUC)=precoUnit;
        }
        if (iteracoes==2) {
            float unidades = atof (subString);
            if (unidades<1 || unidades>200) {
                return NULL;
            }
            c->unidadesC= malloc(sizeof(float));
            *(c->unidadesC)=unidades;
        }
        if (iteracoes==3) {
            if ((strcmp (subString, "P") || (strcmp (subString, "N")))==0) {
                return NULL;
            }
            c->tipoC= malloc((strlen(subString)+1) * sizeof(char));
            for (j = 0; j < strlen(subString); j++){
                (c->tipoC)[j]=subString[j];
            }(c->tipoC)[j]='\0';
        }
        if (iteracoes==4) {
            if(!ValidaC(subString)) {
                return NULL;
            }
            c->clienteC= malloc((strlen(subString)+1) * sizeof(char));
            for (j = 0; j < strlen(subString); j++){
                (c->clienteC)[j]=subString[j];
            }(c->clienteC)[j]='\0';
        }
        if (iteracoes==5) {
            float mes = atof (subString);
            if (mes<1 || mes>12) {
                return NULL;
            }
            c->mesC= malloc(sizeof(float));
            *(c->mesC)=mes;
        }
        if (iteracoes==6) {
            float filial = atof (subString);
            if (filial<1 || filial>3) {
                return NULL;
            }
            c->filialC= malloc(sizeof(float));
            *(c->filialC)=filial;
        }
        iteracoes++;
    }
    return c;
}
int arrayP(){
    FILE *fp,*fp1;
    fp = fopen("Produtos.txt","r");
    fp1 = fopen("P.txt","a");
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
    for (i = 0; i < j; i++){
        fprintf(fp1,"%s\n",m[i]);   
    } 
    return 0;
}
int arrayC(){
    FILE *fp,*fp1;
    fp = fopen("Clientes.txt","r");
    fp1 = fopen("C.txt","a");
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
    for (i = 0; i < j; i++){
        fprintf(fp1,"%s\n",m[i]);   
    } 
    return 0;
}
int arrayV () {
   int len,i,j=0;
   char str[50],*s,**m;
   FILE *fp,*fp1;
   fp = fopen("Vendas_1M.txt","r");
   fp1 = fopen("V.txt","a");
   while(fgets(str,50,fp)){
       CompraP c = ValidaV(str);
       if (c){
           fprintf(fp1,"%s,%.2f,%.2f,%s,%s,%.2f,%.2f\n",(c->produtoC),*(c->precoUC),*(c->unidadesC),
            (c->tipoC),(c->clienteC),*(c->mesC),*(c->filialC));
       }
   }
   return(0);
}
int main(){
    arrayP();
    arrayC();
    arrayV();
    return 0;
}