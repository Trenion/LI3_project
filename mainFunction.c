#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Struct responsavel de salvar os dados de cada venda, utiliza pointers pois é mais facil usar os dados
typedef struct
{
    char* produtoC;
    float* precoUC;
    double* unidadesC;
    char* tipoC;
    char* clienteC;
    double* mesC;
    double* filialC;
    //valC é uma variavel de validacao, se o cliente e o produto da compra sao validos e existem,
    /// entao o seu valor incrementa a 2, é utilizada na ultima validacao das vendas 
    int* valC;
}compra,* CompraP;

/*Struct responsavel de salvar uma lista com as structs 
compra de todas as vendas e o tamanho da lista de structs*/ 
typedef struct
{
    CompraP* Compras;
    int* size;
}listaCompras;

//funcao de comparacao para o qsort de strings
int cmpStr(const void *a, const void *b) 
{ 
    char **ia = (char **)a;
    char **ib = (char **)b;
    return strcmp(*ia, *ib);
} 

//funcao de comparacao para o qsort de struct compra em funcao aos produtos
int cmpStructP(const void *a, const void *b) 
{ 
    CompraP * ia = (CompraP*)a;
    CompraP * ib = (CompraP*)b;
    return strcmp(((*ia)->produtoC),((*ib)->produtoC));
}

//funcao de comparacao para o qsort de struct compra em funcao aos clientes
int cmpStructC(const void *a, const void *b) 
{ 
    CompraP * ia = (CompraP*)a;
    CompraP * ib = (CompraP*)b;
    return strcmp(((*ia)->clienteC),((*ib)->clienteC));
}  

//funcao de validacao de produtos
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

//funcao de validacao de clientes
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

//funcao que valida cada elemento da venda e retorna um pointer a struct compra com os dados validados
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
    }c->valC= malloc(sizeof(int));
    *(c->valC)=0;
    return c;
}

//funcao que cria o array ordenado crescente dos produtos validos
char** arrayP(FILE *fp,FILE *fp1){
    char str[7],*s,**m;
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
    return m;
}

//funcao que cria o array ordenado crescente dos clientes validos
char** arrayC(FILE *fp,FILE *fp1){
    char str[6],*s,**m;
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
    return m;
}

//funcao que gera uma struct listacompras com uma lista de todas as vendas com
//elementos validos e retorna o pointer
listaCompras* arrayV(FILE *fp) {
   int i,j=0;
   char str[50];
   CompraP* p;
   p = malloc(j * sizeof(CompraP));
   listaCompras * v;
   v = malloc(sizeof(listaCompras));
   while(fgets(str,50,fp)){
       CompraP c = ValidaV(str);
       if (c){
           p = realloc(p,(j+1) * sizeof(CompraP));
           p[j++]=c;
       }
   }
   v->Compras= malloc(sizeof(CompraP));
   (v->Compras) = p;
   v->size= malloc(sizeof(int));
   *(v->size) = j;
   return v;
}

//funcao que ardena a liste de vendas em funcao aos clientes e incrementa o valC 
//da compra no caso do cliente existir na lista de clientes validos, 
//para fin de teste a funcao faz print no file "V_C.txt"
void valArrayVC(listaCompras* v,char** c){
    qsort((v->Compras),*(v->size), sizeof(CompraP), cmpStructC);
    int i=0,j=0,k;
    char a[7],b[7];
    while(j<*(v->size)){
        strcpy(a,*(c+i));
        strcpy(b,(*((v->Compras)+j))->clienteC);
        if(strcmp(a,b)>0)j++;   
        if(strcmp(a,b)==0){
            *(((v->Compras)[j])->valC)+=1;
            j++;
        }
        if(strcmp(a,b)<0)i++;
    }
    FILE *fp =  fopen("V_C.txt","a");
    for (k = 0; k < *(v->size); k++){
        fprintf(fp,"%s,%.2f,%.2f,%s,%s,%.2f,%.2f,%d\n",(((v->Compras)[k])->produtoC),*(((v->Compras)[k])->precoUC),
            *(((v->Compras)[k])->unidadesC),(((v->Compras)[k])->tipoC),(((v->Compras)[k])->clienteC),
            *(((v->Compras)[k])->mesC),*(((v->Compras)[k])->filialC),*(((v->Compras)[k])->valC));   
   }

}

//funcao que ardena a liste de vendas em funcao aos produtos e incrementa o valC 
//da compra no caso do produto existir na lista de produtos validos, 
//para fin de teste a funcao faz print no file "V_P.txt"
void valArrayVP(listaCompras* v,char** c){
    qsort((v->Compras),*(v->size), sizeof(CompraP), cmpStructP);
    int i=0,j=0,k;
    char a[7],b[7];
    while(j<*(v->size)){
        strcpy(a,*(c+i));
        strcpy(b,(*((v->Compras)+j))->produtoC);
        if(strcmp(a,b)>0)j++;   
        if(strcmp(a,b)==0){
            *(((v->Compras)[j])->valC)+=1;
            j++;
        }
        if(strcmp(a,b)<0)i++;
    }
    FILE *fp =  fopen("V_P.txt","a");
    for (k = 0; k < *(v->size); k++){
        fprintf(fp,"%s,%.2f,%.2f,%s,%s,%.2f,%.2f,%d\n",(((v->Compras)[k])->produtoC),*(((v->Compras)[k])->precoUC),
            *(((v->Compras)[k])->unidadesC),(((v->Compras)[k])->tipoC),(((v->Compras)[k])->clienteC),
            *(((v->Compras)[k])->mesC),*(((v->Compras)[k])->filialC),*(((v->Compras)[k])->valC));   
   }
}

//funcao que testa quais compras tem cliente e produto existente, cria uma nova lista com as compras validas
//e retorna o pointer, 
//para fin de teste a funcao faz print no file "V.txt" 
listaCompras* validaFinal(listaCompras* v){
    int i = 0, j = 0,k = 0;
    listaCompras * l;
    l = malloc(sizeof(listaCompras));
    l->Compras= malloc(sizeof(CompraP));
    l->size= malloc(sizeof(int));
    CompraP* p;
    p = malloc(j * sizeof(CompraP));
    while(i<*(v->size)){
        k = *(((v->Compras)[i])->valC);
        if (k==2){
            p = realloc(p,(j+1) * sizeof(CompraP));
            p[j++]=((v->Compras)[i]);
        }i++;
    }
    *(l->size) = j;
    (l->Compras) = p;
    FILE *fp =  fopen("V.txt","a");
    for (k = 0; k < *(l->size); k++){
        fprintf(fp,"%s,%.2f,%.2f,%s,%s,%.2f,%.2f,%d\n",(((l->Compras)[k])->produtoC),*(((l->Compras)[k])->precoUC),
            *(((l->Compras)[k])->unidadesC),(((l->Compras)[k])->tipoC),(((l->Compras)[k])->clienteC),
            *(((l->Compras)[k])->mesC),*(((l->Compras)[k])->filialC),*(((l->Compras)[k])->valC));   
    }
    return l;
}
int main(){
    char** c,**p;
    listaCompras* v,*l;
    FILE *fp,*fp_txt,*fc,*fc_txt,*fv;
    fp = fopen("Produtos.txt","r");
    fp_txt = fopen("P.txt","a");
    fc = fopen("Clientes.txt","r");
    fc_txt = fopen("C.txt","a");
    fv = fopen("Vendas_1M.txt","r");
    p = arrayP(fp,fp_txt);
    c = arrayC(fc,fc_txt);
    v = arrayV(fv);
    valArrayVC(v,c);
    valArrayVP(v,p);
    l = validaFinal(v);
    return 0;
}
