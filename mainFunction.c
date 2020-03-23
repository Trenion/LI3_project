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

typedef struct
{
    char* produtoT;
    int* unidadesT;
}cell;

//funcao de comparacao para o qsort de strings
int cmpStr(const void *a, const void *b) 
{ 
    char **ia = (char **)a;
    char **ib = (char **)b;
    return strcmp(*ia, *ib);
} 

//funcao de comparacao para o qsort de struct compra em funcao aos produtos
int cmpStruct1(const void *a, const void *b) 
{ 
    CompraP * ia = (CompraP*)a;
    CompraP * ib = (CompraP*)b;
    return strcmp(((*ia)->produtoC),((*ib)->produtoC));
}

//funcao de comparacao para o qsort de struct compra em funcao aos precos unitarios
int cmpStruct2(const void *a, const void *b) 
{ 
    CompraP * ia = (CompraP*)a;
    CompraP * ib = (CompraP*)b;
    return (*((*ia)->precoUC)*1000 - *((*ib)->precoUC)*1000);
} 

//funcao de comparacao para o qsort de struct compra em funcao as unidades
int cmpStruct3(const void *a, const void *b) 
{ 
    CompraP * ia = (CompraP*)a;
    CompraP * ib = (CompraP*)b;
    return (*((*ia)->unidadesC) - *((*ib)->unidadesC));
}

//funcao de comparacao para o qsort de struct compra em funcao aos tipos
int cmpStruct4(const void *a, const void *b) 
{ 
    CompraP * ia = (CompraP*)a;
    CompraP * ib = (CompraP*)b;
     return strcmp(((*ia)->tipoC),((*ib)->tipoC));
} 

//funcao de comparacao para o qsort de struct compra em funcao aos clientes
int cmpStruct5(const void *a, const void *b) 
{ 
    CompraP * ia = (CompraP*)a;
    CompraP * ib = (CompraP*)b;
    return strcmp(((*ia)->clienteC),((*ib)->clienteC));
} 

//funcao de comparacao para o qsort de struct compra em funcao aos meses
int cmpStruct6(const void *a, const void *b) 
{ 
    CompraP * ia = (CompraP*)a;
    CompraP * ib = (CompraP*)b;
    return (*((*ia)->mesC) - *((*ib)->mesC));
} 

//funcao de comparacao para o qsort de struct compra em funcao as filiais
int cmpStruct7(const void *a, const void *b) 
{ 
    CompraP * ia = (CompraP*)a;
    CompraP * ib = (CompraP*)b;
    return (*((*ia)->filialC) - *((*ib)->filialC));
} 

//funcao de comparacao para o qsort de struct compra em funcao as validacoes 
int cmpStruct8(const void *a, const void *b) 
{ 
    CompraP * ia = (CompraP*)a;
    CompraP * ib = (CompraP*)b;
    return (*((*ib)->valC) - *((*ia)->valC));
}

//funcao de comparacao para o qsort de struct compra em funcao da faturação (preço * unidades)
int cmpStruct9(const void *a, const void *b)
{
    CompraP * ia = (CompraP*)a;
    CompraP * ib = (CompraP*)b;
    return ((*((*ib)->precoUC))*(*((*ib)->unidadesC)) - (*((*ia)->precoUC))*(*((*ia)->unidadesC)));
}

//funcao que gera a matriz de posicoes inicial
int** posMatrix(int i){
    int** pos;
    pos = malloc((i+2)*sizeof(int*));
    for (int j = 0; j < i+2; j++){
        pos[j]=malloc(sizeof(int));
        pos[j][0]=0; 
     }
     return pos; 
}

//funcao para comparar char* na multipla ordenacao 
int cmp(int a[], int b[], int c){
    int r=0;
    for(int i=0;i<c;i++){
        r+=(a[i]-b[i]);
        if(r)return r;       
    }return r;
}

//funcao que faz multiplas ordenacoes utilizando o qsort entre posicoes obtidas pela aterior ordenacao
//e gera uma matriz de posicoes para cada nivel de ordenacao pode ser testada na lista de vendas no ficheiro de texto
void cmpStruct(listaCompras * l, int* caso, int** pos, int n){
    pos[0][0]=1;
    pos[1]=realloc(pos[1],2*sizeof(int));
    pos[1][1]=*(l->size);
    int c, q, x;
    int lvl;
    for (lvl = 1; lvl <= n; lvl++){
        if(caso[lvl-1]!=0){
            c = 1,q = 1;
        for(int i=0;i<pos[0][lvl-1];i++){
            switch(caso[lvl-1]){
            case(1):
                qsort((l->Compras)+(pos[lvl][i]),pos[lvl][i+1]-pos[lvl][i], sizeof(CompraP), cmpStruct1);
                break;
            case(10):
                qsort((l->Compras)+(pos[lvl][i]),pos[lvl][i+1]-pos[lvl][i], sizeof(CompraP), cmpStruct1);
                break;
            case(11):
                qsort((l->Compras)+(pos[lvl][i]),pos[lvl][i+1]-pos[lvl][i], sizeof(CompraP), cmpStruct1);
                break;
            case(2):
                qsort((l->Compras)+(pos[lvl][i]),pos[lvl][i+1]-pos[lvl][i], sizeof(CompraP), cmpStruct2);
                break;
            case(3):
                qsort((l->Compras)+(pos[lvl][i]),pos[lvl][i+1]-pos[lvl][i], sizeof(CompraP), cmpStruct3);
                break;
            case(4):
                qsort((l->Compras)+(pos[lvl][i]),pos[lvl][i+1]-pos[lvl][i], sizeof(CompraP), cmpStruct4);
                break;
            case(5):
                qsort((l->Compras)+(pos[lvl][i]),pos[lvl][i+1]-pos[lvl][i], sizeof(CompraP), cmpStruct5);
                break;
            case(50):
                qsort((l->Compras)+(pos[lvl][i]),pos[lvl][i+1]-pos[lvl][i], sizeof(CompraP), cmpStruct5);
                break;
            case(6):
                qsort((l->Compras)+(pos[lvl][i]),pos[lvl][i+1]-pos[lvl][i], sizeof(CompraP), cmpStruct6);
                break;
            case(7):
                qsort((l->Compras)+(pos[lvl][i]),pos[lvl][i+1]-pos[lvl][i], sizeof(CompraP), cmpStruct7);
                break; 
            case(8):
                qsort((l->Compras)+(pos[lvl][i]),pos[lvl][i+1]-pos[lvl][i], sizeof(CompraP), cmpStruct8);
                break;
            case(9):
                qsort((l->Compras)+(pos[lvl][i]),pos[lvl][i+1]-pos[lvl][i], sizeof(CompraP), cmpStruct9);
                break;
            }
        }
        int a[6], b[6], j=1;
        while(c < *(l->size)){
            x = pos[lvl][j];
            switch(caso[lvl-1]){
            case(1):                
                while(c < *(l->size)){
                    for (int i = 0; i < 6; i++){
                        a[i]=((*((l->Compras)+(c)))->produtoC)[i];
                        b[i]=((*((l->Compras)+(c-1)))->produtoC)[i];
                    }
                    if (!(cmp(a,b,6))){
                        c++;
                    }else break;
                }
                break;
            case(10):                
                while(c < *(l->size)){
                    a[0]=((*((l->Compras)+(c)))->produtoC)[0];
                    b[0]=((*((l->Compras)+(c-1)))->produtoC)[0];
                    if(!(a[0]-b[0])){
                        c++;
                    }else break;
                }
                break;
            case(11):                
                while(c < *(l->size)){
                    a[1]=((*((l->Compras)+(c)))->produtoC)[1];
                    b[1]=((*((l->Compras)+(c-1)))->produtoC)[1];
                    if(!(a[1]-b[1])){
                        c++;
                    }else break;
                }
                break;
            case(2):
                while(c < *(l->size)){
                    if(!(*((l->Compras)[c]->precoUC)-*((l->Compras)[c-1]->precoUC))){
                        c++;
                    }else break;
                }
                break;
            case(3):
                while(c < *(l->size)){
                    if(!(*((l->Compras)[c]->unidadesC)-*((l->Compras)[c-1]->unidadesC))){
                        c++;
                    }else break;
                }
                break;
            case(4):
                while(c < *(l->size)){
                    a[0]=((*((l->Compras)+(c)))->tipoC)[0];
                    b[0]=((*((l->Compras)+(c-1)))->tipoC)[0];
                    if(!(a[0]-b[0])){
                        c++;
                    }else break;
                }
                break;
            case(5):               
                while(c < *(l->size)){
                    for (int i = 0; i < 5; i++){
                        a[i]=((*((l->Compras)+(c)))->clienteC)[i];
                        b[i]=((*((l->Compras)+(c-1)))->clienteC)[i];
                    }
                    if (!(cmp(a,b,5))){
                        c++;
                    }else break;
                }
                break;
            case(50):                
                while(c < *(l->size)){
                    a[0]=((*((l->Compras)+(c)))->clienteC)[0];
                    b[0]=((*((l->Compras)+(c-1)))->clienteC)[0];
                    if(!(a[0]-b[0])){
                        c++;
                    }else break;
                }
                break;
            case(6):
                while(c < *(l->size)){
                    if(!(*((l->Compras)[c]->mesC)-*((l->Compras)[c-1]->mesC))){
                        c++;
                    }else break;
                }break;
            case(7):
                while(c < *(l->size)){
                    if(!(*((l->Compras)[c]->filialC)-*((l->Compras)[c-1]->filialC))){
                        c++;
                    }else break;
                }break;
            case(8):
                while(c < *(l->size)){
                    if(!(*((l->Compras)[c]->valC)-*((l->Compras)[c-1]->valC))){
                        c++;
                    }else break;
                }break;
            case(9):
                while(c < *(l->size)){
                    int tst1 = (*((l->Compras)[c]->precoUC))*(*((l->Compras)[c]->unidadesC));
                    int tst2 = (*((l->Compras)[c-1]->precoUC))*(*((l->Compras)[c-1]->unidadesC));
                    if(!(tst1-tst2)){
                        c++;
                    }else break;
                }break;
            }if (c>x){
                q++;
                pos[lvl+1]=realloc(pos[lvl+1],(q)*sizeof(int));
                pos[lvl+1][q-1]=x;
                j++;
            }else{
                if(c==x)j++;
                q++;
                pos[lvl+1]=realloc(pos[lvl+1],(q)*sizeof(int));
                pos[lvl+1][q-1]=c;
                c++;
            }
        }
        pos[0]=realloc(pos[0],(lvl+1)*sizeof(int));
        pos[0][lvl]=q-1;
        q++;
        pos[lvl+1]=realloc(pos[lvl+1],(q)*sizeof(int));
        pos[lvl+1][q-1]=(-1);
        }
    }
    pos[1]=realloc(pos[1],3*sizeof(int));
    pos[1][2]=(-1);
    pos[0]=realloc(pos[0],(lvl+1)*sizeof(int));
    pos[0][lvl]=(-1);

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
//    for (i = 0; i < j; i++){
//        fprintf(fp1,"%s\n",m[i]);
//    }
    m = realloc(m,(j+1) * sizeof(char*));
    m[j]=NULL;
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
//    for (i = 0; i < j; i++){
//        fprintf(fp1,"%s\n",m[i]);
//    }
    m = realloc(m,(j+1) * sizeof(char*));
    m[j]=NULL;
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
    qsort((v->Compras),*(v->size), sizeof(CompraP), cmpStruct5);
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
//    FILE *fp =  fopen("V_C.txt","a");
//    for (k = 0; k < *(v->size); k++){
//        fprintf(fp,"%s,%.2f,%.2f,%s,%s,%.2f,%.2f,%d\n",(((v->Compras)[k])->produtoC),*(((v->Compras)[k])->precoUC),
//            *(((v->Compras)[k])->unidadesC),(((v->Compras)[k])->tipoC),(((v->Compras)[k])->clienteC),
//            *(((v->Compras)[k])->mesC),*(((v->Compras)[k])->filialC),*(((v->Compras)[k])->valC));   
//   }

}

//funcao que ardena a liste de vendas em funcao aos produtos e incrementa o valC 
//da compra no caso do produto existir na lista de produtos validos, 
//para fin de teste a funcao faz print no file "V_P.txt"
void valArrayVP(listaCompras* v,char** c){
    qsort((v->Compras),*(v->size), sizeof(CompraP), cmpStruct1);
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
//    FILE *fp =  fopen("V_P.txt","a");
//    for (k = 0; k < *(v->size); k++){
//        fprintf(fp,"%s,%.2f,%.2f,%s,%s,%.2f,%.2f,%d\n",(((v->Compras)[k])->produtoC),*(((v->Compras)[k])->precoUC),
//            *(((v->Compras)[k])->unidadesC),(((v->Compras)[k])->tipoC),(((v->Compras)[k])->clienteC),
//            *(((v->Compras)[k])->mesC),*(((v->Compras)[k])->filialC),*(((v->Compras)[k])->valC));
//   }
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
    return l;
}

//funcao para imprimir uma listaCompra num ficheiro de texto 
void printListaC(listaCompras* l,FILE* fp){
    for (int k = 0; k < *(l->size); k++){
        fprintf(fp,"%s,%.2f,%.2f,%s,%s,%.2f,%.2f,%d\n",(((l->Compras)[k])->produtoC),*(((l->Compras)[k])->precoUC),
            *(((l->Compras)[k])->unidadesC),(((l->Compras)[k])->tipoC),(((l->Compras)[k])->clienteC),
            *(((l->Compras)[k])->mesC),*(((l->Compras)[k])->filialC),*(((l->Compras)[k])->valC));
    }
}

//funcao para imprimir uma matriz de posicoes num ficheiro de texto 
void printM(int** pos, int n){
    FILE *fp =  fopen("V2.txt","a");
    for (int i = 0; i <= n+1; i++){
        for (int j = 0; pos[i][j]>(-1); j++){
            fprintf(fp,"%d,",pos[i][j]);
        }fprintf(fp,"\n\n");
    }fprintf(fp,"\n\n");
}

listaCompras* aux(listaCompras* l,int a, int b, int x){
    listaCompras* lAux;
    lAux = malloc(sizeof(listaCompras));
    lAux->Compras=malloc(sizeof(CompraP));
    lAux->Compras=(l->Compras)+a;
    lAux->size=malloc(sizeof(int));
    *(lAux->size)=b-a;
    int j=0,i1=0,** pos = posMatrix(1),caso[]={1};
    cmpStruct(lAux, caso, pos, 1);
    switch(x){
        case(12):
            while(i1 <=pos[0][1]){
                int i=0;
                j=pos[2][i1];
                *(((lAux->Compras)[j+i])->valC)=*(((lAux->Compras)[j+i])->precoUC)*(*(((lAux->Compras)[j+i])->unidadesC))*100;
                i++;
                while(i+j<pos[2][i1+1]){
                    *(((lAux->Compras)[j+i])->valC)=*(((lAux->Compras)[j+i])->precoUC)*(*(((lAux->Compras)[j+i])->unidadesC))*100;
                    *(((lAux->Compras)[j+i])->valC)+=*(((lAux->Compras)[j+i-1])->valC);
                    *(((lAux->Compras)[j+i-1])->valC)=0;
                    i++;
                }i1++;
            }
            break;
        case(10):
            while(i1 <= pos[0][1]){
                int i=0;
                j=pos[2][i1];
                *(((lAux->Compras)[j+i])->valC)=*(((lAux->Compras)[j+i])->unidadesC);
                i++;
                while(i+j<pos[2][i1+1]){
                    *(((lAux->Compras)[j+i])->valC)=*(((lAux->Compras)[j+i])->unidadesC);
                    *(((lAux->Compras)[j+i])->valC)+=*(((lAux->Compras)[j+i-1])->valC);
                    *(((lAux->Compras)[j+i-1])->valC)=0;
                    i++;
                }i1++;
            }
            break;
    }
    return lAux;
}

listaCompras* ex2(listaCompras* l,char c){
    FILE* fex2;
    fex2 =  fopen("Ex2.txt","a");
    int cId = c-65, ** pos = posMatrix(1),caso[]={10};
    listaCompras* lx;
    lx = malloc(sizeof(listaCompras));
    cmpStruct(l, caso, pos, 1);
    fprintf(fex2,"%d\n",pos[2][cId+1]-pos[2][cId]);
    lx->Compras= malloc(sizeof(CompraP));
    (lx->Compras) = (l->Compras)+pos[2][cId];
    lx->size= malloc(sizeof(int));
    *(lx->size) = pos[2][cId+1]-pos[2][cId];
    printListaC(lx,fex2);
    return lx;
}

float* ex3(listaCompras* l,int mes,char* p,char c){
    int i=0,q, pId0 = p[0]-65, pId1 = p[1]-65, ** pos = posMatrix(6),caso[]={10,11,6,1,4,7};
    char a[6];
    float *f;
    f= malloc(6*sizeof(float));
    cmpStruct(l, caso, pos, 6);
    i=pos[4][pId0*26*12+pId1*12+mes-1];
    strncpy(a,((*((l->Compras)+i))->produtoC),6);
    while((i<(pos[4][pId0*26*12+pId1*12+mes]))&&(strncmp(a,p,6))){
        i++;
        strncpy(a,((*((l->Compras)+i))->produtoC),6);
    }
    FILE* fex3;
    fex3 =  fopen("Ex3.txt","a");
    fprintf(fex3,"%d\n",i);
    if(strncmp(a,p,6)){
        fprintf(fex3,"ese mes no se vendio ese producto\n");
    }else{
        q=0;
        for (int j = 0; j < 6; j++){
            f[j]=0;
        }while(!(strncmp(a,p,6))){
            int k1 = ((*((l->Compras)+i))->tipoC)[0],k2=0;
            k1-='N';
            k2 = *((*((l->Compras)+i))->filialC);
            if(!k1){
              f[k2-1]+= *((*((l->Compras)+i))->precoUC)*(*((*((l->Compras)+i))->unidadesC));
            }else{
                f[k2+2]+= *((*((l->Compras)+i))->precoUC)*(*((*((l->Compras)+i))->unidadesC));
            }q++;i++;
            strncpy(a,((*((l->Compras)+i))->produtoC),6);
        }fprintf(fex3,"numero de vendas = %d\n",q);
        if(c-'f'){
            fprintf(fex3,"total faturado N = %.2f\ntotal faturado P = %.2f\n",f[0]+f[1]+f[2],f[3]+f[4]+f[5]);
        }else{
            fprintf(fex3,"total faturado N1 = %.2f\ntotal faturado N2 = %.2f\ntotal faturado N3 = %.2f\n"
                "total faturado P1 = %.2f\ntotal faturado P2 = %.2f\ntotal faturado P3 = %.2f\n"
                ,f[0],f[1],f[2],f[3],f[4],f[5]);
        }
    }return f;    
}

//No momento, esta função só cria a lista com os produtos que não foram comprados!
char** ex4(char** p, listaCompras* l, char c) {
    int j=0, f[]={0,0,0}, f3=0, qp=0;
    char **produtos,a[6],b[6];
    FILE* fex4;
    fex4 =  fopen("Ex4.txt","a");
    produtos = malloc(qp * sizeof(char*));
    if (!(c-'f')){
        int ** pos = posMatrix(2),caso[]={7,1},i3=0;
        cmpStruct(l, caso, pos, 2);
        for (int i1 = 0; i1 < 3; i1++){
            int i2;
            fprintf(fex4,"Produtos não comprados na filial %d:\n",i1+1);
            for (i2 = 0; p[i2]&&(pos[3][i3]<(pos[2][i1+1])); i2++){
                strncpy(a,p[i2],6);
                strncpy(b,((*((l->Compras)+pos[3][i3]))->produtoC),6);
                if(strncmp(a,b,6)<0){ 
                    qp++;
                    f[i1]++;
                    produtos = realloc(produtos,qp * sizeof(char*));
                    produtos[qp-1]=p[i2];
                    fprintf(fex4,"%s\n",produtos[qp-1]);
                }
                else{   
                    i3++;
                }
            }while(p[i2]){
                qp++;
                f[i1]++;
                produtos = realloc(produtos,qp * sizeof(char*));
                produtos[qp-1]=p[i2];
                fprintf(fex4,"%s\n",produtos[qp-1]);
            }fprintf(fex4,"numero produtos não comprados filial %d: %d\n",i1+1,f[i1]);
        }
    }else{
        int ** pos = posMatrix(1),caso[]={1};
        cmpStruct(l, caso, pos, 1);
        for(int i=0;p[i];i++){
            strncpy(a,p[i],6);
            strncpy(b,((*((l->Compras)+pos[2][j]))->produtoC),6);
            if(strncmp(a,b,6)<0){ 
                qp++;
                produtos = realloc(produtos,qp * sizeof(char*));
                produtos[qp-1]=p[i];
            }
            else{   
                j++;
            }
        }
        fprintf(fex4,"Produtos não comprados: %d\n",qp);
        for (int i = 0; i < qp; i++){
            fprintf(fex4,"%s\n",produtos[i]);
        }
    }
    return produtos;
}



char** ex5(listaCompras* l){
    int j=0,k, ** pos = posMatrix(2),caso[]={5,7},a[6],b[6],c[6];
    char **clients;
    clients = malloc(j * sizeof(char*));
    cmpStruct(l, caso, pos, 2);
    for(int i = 2; i<pos[0][2];i++){
        for (int k = 0; k < 6; k++){
            a[k]=((*((l->Compras)+pos[3][i]))->clienteC)[k];
            b[k]=((*((l->Compras)+pos[3][i-1]))->clienteC)[k];
            c[k]=((*((l->Compras)+pos[3][i-2]))->clienteC)[k];
        }
        if ((!cmp(a,b,6))){
            if(!cmp(b,c,6)){
                j++;
                clients = realloc(clients,j * sizeof(char*));
                clients[j-1]=((*((l->Compras)+pos[3][i]))->clienteC);
                i+=2;
            }
        }
    }
    FILE* fex5;
    fex5 =  fopen("Ex5.txt","a");
    fprintf(fex5,"numero de clientes que compraron nas 3 filiais= %d\n",j);
    for (int i = 0; i < j; i++){
        fprintf(fex5,"%s\n",clients[i]);
    }return clients;
}

int* ex6(char** c,char** p,listaCompras* l){
    int* r,** posc = posMatrix(1),**posp = posMatrix(1),casop[]={1},casoc[]={5},j=0,qp=0,qc=0;
    char a[6],b[6];
    cmpStruct(l, casop, posp, 1);
    for(int i=0;p[i];i++){
        strncpy(a,p[i],6);
        strncpy(b,((*((l->Compras)+posp[2][j]))->produtoC),6);
        if(strncmp(a,b,6)<0){
            qp++;
        }else if(!strncmp(a,b,6)){
            j++;
        }else{
            if(posp[2][j+1]>(-1)){
                    j++;
            }else qp++;
        }
    }j=0;
    cmpStruct(l, casoc, posc, 1);
    for(int i=0;c[i];i++){
        strncpy(a,c[i],6);
        strncpy(b,((*((l->Compras)+posc[2][j]))->clienteC),6);
        if(strncmp(a,b,6)<0){
            qc++;
        }else if(!strncmp(a,b,6)){
            j++;
        }else{
            if(posc[2][j+1]>(-1)){
                    j++;
            }else qc++;
        }
    }r=malloc(2*sizeof(int));
    r[0]=qc;
    r[1]=qp;
    return r;
}

cell*** ex7(listaCompras* l,char* c){
    FILE* fp;
    fp =  fopen("Ex7.txt","a");
    fprintf(fp,"cliente: %s\n", c);
    int i,q,k, cId0 = c[0]-65, ** pos = posMatrix(5),caso[]={50,5,6,7,1};
    cell*** table;
    char* n = malloc(12);
    n[0]='S';n[1]='e';n[2]='m';n[3]=' ';n[4]='C';n[5]='o';n[6]='m';
    n[7]='p';n[8]='r';n[9]='a';n[10]='s';n[11]='\0';
    table = malloc(12*sizeof(cell**));
    cmpStruct(l, caso, pos, 5);
    i=pos[2][cId0];
    char a[6],b[6],d1[6],d2[6]; 
    for (int j = 0; j < 6; j++){
        a[j]= ((*((l->Compras)+i))->clienteC)[j];
        d1[j]=c[j];
    }
    while(strncmp(a,d1,6)){
        i++;
        for (int j = 0; j < 6; j++){
            a[j]= ((*((l->Compras)+i))->clienteC)[j];
        }
    }
    for(int j1 = 0;(!strncmp(a,d1,6));j1++){
        fprintf(fp,"mes: %d\n", j1+1);
        table[j1] = malloc(3*sizeof(cell*));
        q = *((*((l->Compras)+i))->mesC);
        if(q-j1-1){
            for (int j = 0; j < 3; j++){
                fprintf(fp,"filial: %d\n", j+1);
                table[j1][j] = malloc(sizeof(cell));
                (table[j1][j][0]).produtoT = malloc(sizeof(char*));
                (table[j1][j][0]).produtoT = n;
                (table[j1][j][0]).unidadesT = malloc(sizeof(int));
                *((table[j1][j][0]).unidadesT) = 0;
                fprintf(fp,"produto: %s, unidades: %d.\n",table[j1][j][0].produtoT,*(table[j1][j][0].unidadesT));
            }
        }
        for(int j2=0;(j2<3);j2++){
            if((q!=j1+1)&&j2==0){
                j2+=2;
            }else{
            fprintf(fp,"filial: %d\n", j2+1);
            table[j1][j2] = malloc(sizeof(cell));
            k =  *((*((l->Compras)+i))->filialC);
            int j3 = 0;
            if (k-j2-1&&!(q-j1-1)){
                 table[j1][j2] = malloc(sizeof(cell));
                (table[j1][j2][0]).produtoT = malloc(sizeof(char*));
                (table[j1][j2][0]).produtoT = n;
                (table[j1][j2][0]).unidadesT = malloc(sizeof(int));
                *((table[j1][j2][0]).unidadesT) = 0;
                fprintf(fp,"produto: %s, unidades: %d.\n",table[j1][j2][0].produtoT,*(table[j1][j2][0].unidadesT));
            }
            while(!(k-j2-1)&&!(q-j1-1)){
                for (int j = 0; j < 6; j++){
                    b[j]= ((*((l->Compras)+i))->produtoC)[j];
                    d2[j]=((*((l->Compras)+i))->produtoC)[j];
                }
                int units = 0;
                while(!strncmp(b,d2,6)){
                    units += *((*((l->Compras)+i))->unidadesC);
                    i++;
                    for (int j = 0; j < 6; j++){
                        b[j]= ((*((l->Compras)+i))->produtoC)[j];
                    }
                }
                if(units > 0){
                    j3++;
                    table[j1][j2] = realloc(table[j1][j2],j3*sizeof(cell));
                    (table[j1][j2][j3-1]).produtoT = malloc(sizeof(char*));
                    (table[j1][j2][j3-1]).produtoT = ((*((l->Compras)+i-1))->produtoC);
                    (table[j1][j2][j3-1]).unidadesT = malloc(sizeof(int));
                    *((table[j1][j2][j3-1]).unidadesT) = units;
                }fprintf(fp,"produto: %s, unidades: %d.\n",table[j1][j2][j3-1].produtoT,*(table[j1][j2][j3-1].unidadesT));
                k =  *((*((l->Compras)+i))->filialC);              
            }
            if (q-j1-1){
                 table[j1][j2] = malloc(sizeof(cell));
                (table[j1][j2][0]).produtoT = malloc(sizeof(char*));
                (table[j1][j2][0]).produtoT = n;
                (table[j1][j2][0]).unidadesT = malloc(sizeof(int));
                *((table[j1][j2][0]).unidadesT) = 0;
                fprintf(fp,"produto: %s, unidades: %d.\n",table[j1][j2][0].produtoT,*(table[j1][j2][0].unidadesT));
            }
            q = *((*((l->Compras)+i))->mesC);
        }}
        for (int j = 0; j < 6; j++){
            a[j]= ((*((l->Compras)+i))->clienteC)[j];
        }
    }
    return table;
}

float* ex8(listaCompras* l,int mes1,int mes2){
    float* vendas;
    vendas = malloc(2*sizeof(float));
    int** pos = posMatrix(1),caso[]={6},i,j;
    cmpStruct(l, caso, pos, 1);
    i = pos[2][mes1-1];
    j= pos[2][mes2];
    while(i<j){
        vendas[0]+=(*((*((l->Compras)+i))->precoUC)*(*((*((l->Compras)+i))->unidadesC)));
        vendas[1]+=1;
        i++;
    }return vendas;
}

char*** ex9(listaCompras* l,char* p,int f){
    FILE* fp;
    fp =  fopen("Ex9.txt","a");
    fprintf(fp,"Produto: %s, filial: %d\n", p,f);
    int** pos = posMatrix(6),caso[]={10,11,1,7,4,5},pId0=p[0]-65,pId1=p[1]-65,a[6],b[6],qn=0,qp=0;
    cmpStruct(l, caso, pos, 6);
    char*** clientesPF,**cN,**cP;
    clientesPF= malloc(2*sizeof(char**));
    cN= malloc(sizeof(char*));
    cP= malloc(sizeof(char*));
    int i=pos[3][pId0*26+pId1];
    for (int j = 0; j < 6; j++){
        a[j]=p[j];
        b[j]=((*((l->Compras)+i))->produtoC)[j];
    }
    while(cmp(a,b,6)){
        i++;
        for (int j = 0; j < 6; j++){
            b[j]=((*((l->Compras)+i))->produtoC)[j];
        }
    }int k = *((*((l->Compras)+i))->filialC);
    while(f-k&&(!(strncmp(p,((*((l->Compras)+i))->produtoC),6)))){
        i++;
        k = *((*((l->Compras)+i))->filialC);
    }k = ((*((l->Compras)+i))->tipoC)[0]-65;
    while((!(k-13))&&(!(*((*((l->Compras)+i))->filialC)-f))&&(!(strncmp(p,((*((l->Compras)+i))->produtoC),6)))){
        if(i-(*(l->size)-1)){
            for (int j = 0; j < 6; j++){
                a[j]=((*((l->Compras)+i+1))->clienteC)[j];
                b[j]=((*((l->Compras)+i))->clienteC)[j];
            }
            if(cmp(a,b,6)){
                qn++;
                cN= realloc(cN,qn*sizeof(char*));
                cN[qn-1]=((*((l->Compras)+i))->clienteC);
            }
        }else{
            for (int j = 0; j < 6; j++){
                a[j]=((*((l->Compras)+i-1))->clienteC)[j];
                b[j]=((*((l->Compras)+i))->clienteC)[j];
            }
            if(cmp(a,b,6)){
                qn++;
                cN= realloc(cN,qn*sizeof(char*));
                cN[qn-1]=((*((l->Compras)+i))->clienteC);
            }
        }
        i++;
        k = ((*((l->Compras)+i))->tipoC)[0]-65;
    }while((!(k-15))&&(!(*((*((l->Compras)+i))->filialC)-f))&&(!(strncmp(p,((*((l->Compras)+i))->produtoC),6)))){
        if(i-(*(l->size)-1)){
            for (int j = 0; j < 6; j++){
                a[j]=((*((l->Compras)+i+1))->clienteC)[j];
                b[j]=((*((l->Compras)+i))->clienteC)[j];
            }
            if(cmp(a,b,6)){
                qp++;
                cP= realloc(cP,qp*sizeof(char*));
                cP[qp-1]=((*((l->Compras)+i))->clienteC);
            }
        }else{
            for (int j = 0; j < 6; j++){
                a[j]=((*((l->Compras)+i-1))->clienteC)[j];
                b[j]=((*((l->Compras)+i))->clienteC)[j];
            }
            if(cmp(a,b,6)){
                qp++;
                cP= realloc(cP,qp*sizeof(char*));
                cP[qp-1]=((*((l->Compras)+i))->clienteC);
            }
        }
        i++;
        k = ((*((l->Compras)+i))->tipoC)[0]-65;
    }
    if (!qn){
        cN= NULL;
        fprintf(fp,"clientes Normais: nao tem\n");
    }if (!qp){
        cP= NULL;
        fprintf(fp,"clientes Promocao: nao tem\n");
    }clientesPF[0]=cN;
    clientesPF[1]=cP;
    if (qn){
        cN= NULL;
        fprintf(fp,"clientes Normais tem %d: \n",qn);
        for(int j =0;j<qn;j++){
            fprintf(fp,"%s\n",clientesPF[0][j]);
        }
    }if (qp){
        cP= NULL;
        fprintf(fp,"clientes Promocao tem %d: \n",qp);
        for(int j =0;j<qp;j++){
            fprintf(fp,"%s\n",clientesPF[1][j]);
        }
    }return clientesPF;
}

char** ex10(listaCompras* l, char* c, int N){
    listaCompras* lAux;
    int i,j,k=0, ** pos = posMatrix(3),caso[]={50,6,5}, cId0 = c[0]-65,pc=0,q=0,** posAux = posMatrix(1),casoAux[]={8},a[6],b[6];
    char **produtos;
    produtos = malloc(pc * sizeof(char*));
    cmpStruct(l, caso, pos, 3);
    i = pos[3][cId0*12+(N-1)];
    for (int j1 = 0; j1 < 6; j1++){
        b[j1]=c[j1];
        a[j1]=((*((l->Compras)+i))->clienteC)[j1];
    }
    while(cmp(a,b,6)<0){
        i++;
        for (int j1 = 0; j1 < 6; j1++){
            a[j1]=((*((l->Compras)+i))->clienteC)[j1];
        }
    }
    if (cmp(a,b,6)>0){
        printf("\nO cliente introduzido nao efetuou compras nesse mes ou nao existe nos registos!\n");
        return NULL;
    }
    q=i;
    while(!cmp(a,b,6)){
        q++;
        for (int j1 = 0; j1 < 6; j1++){
            a[j1]=((*((l->Compras)+q))->clienteC)[j1];
        }
    }
    lAux=aux(l,i,q,10);
    cmpStruct(lAux, casoAux, posAux, 1);
    while(k<*(lAux->size)) {
        if(*((*((lAux->Compras)+k))->valC)){
            pc++;
            produtos = realloc(produtos,pc * sizeof(char*));
            produtos[pc-1]=((*((lAux->Compras)+k))->produtoC);
        }k++;
    }FILE * fex10;
    fex10 =  fopen("Ex10.txt","a");
    fprintf(fex10,"Produtos comprados pelo cliente %s no mes %d ordenados por unidades: \n",c,N);
    for (int j = 0; j < pc; j++){
        fprintf(fex10,"%s\n",produtos[j]);
    }
    return produtos;
}

char** ex11(listaCompras* l, int N){
    
    listaCompras* lAux;
    int i=0,j1=0,k=0, h=0, ** pos = posMatrix(1),caso[]={1},** posAux = posMatrix(1),casoAux[]={8},a[6],b[6], pId0, pId1, m;
    double num[6];
    char **produtos;
    
    for (j1=0; j1<6;j1++) num[j1]=0;
    produtos = malloc(h * sizeof(char*));
    lAux=aux(l,0,(*(l->size))-1,12);
    cmpStruct(lAux, casoAux, posAux, 1);

    while (k<N) {
        produtos = realloc(produtos,k * sizeof(char*));
        produtos[k]=((*((lAux->Compras)+k))->produtoC);
        k++;
    }

    cmpStruct(l, caso, pos, 1);
    FILE * fex11;
    fex11 =  fopen("Ex11.txt","a");
    fprintf(fex11,"%d produtos mais comprados durante o ano: \n\n", N);
    
    while(i<N) {

        pId0 = (produtos[i])[0]-65; pId1 = (produtos[i])[1]-65;
        m = pos[2][26*pId0+pId1];
        for (j1 = 0; j1 < 6; j1++){
            b[j1]=(produtos[i])[j1];
            a[j1]=((*((l->Compras)+m))->produtoC)[j1];
        }
        
        while(cmp(a,b,6)<0){
            m++;
            for (j1 = 0; j1 < 6; j1++){
                a[j1]=((*((l->Compras)+m))->produtoC)[j1];
            }
        }
        
        while(cmp(a,b,6)==0){
            if (*((*((l->Compras)+m))->filialC)==1.0) {
                num[0]+=*((*((l->Compras)+m))->unidadesC);
                if (((*((l->Compras)+m))->clienteC)!=((*((l->Compras)+m-1))->clienteC)) {
                    num[1]+=1;
                }
            }
            else if (*((*((l->Compras)+m))->filialC)==2.0) {
                num[2]+=*((*((l->Compras)+m))->unidadesC);
                if (((*((l->Compras)+m))->clienteC)!=((*((l->Compras)+m-1))->clienteC)) {
                    num[3]+=1;
                }
            }
            else {
                num[4]+=*((*((l->Compras)+m))->unidadesC);
                if (((*((l->Compras)+m))->clienteC)!=((*((l->Compras)+m-1))->clienteC)) {
                    num[5]+=1;
                }
            }
            m++;
            for (int j1 = 0; j1 < 6; j1++){
                a[j1]=((*((l->Compras)+m))->produtoC)[j1];
            }
        }
        
        fprintf(fex11,"\n Produto: %s\n\n", produtos[i]);
        fprintf(fex11,"Filial 1: %.0f clientes comparam, %.2f unidades vendidas \n", num[1], num[0]);
        fprintf(fex11,"Filial 2: %.0f clientes comparam, %.2f unidades vendidas \n", num[3], num[2]);
        fprintf(fex11,"Filial 3: %.0f clientes comparam, %.2f unidades vendidas \n\n", num[5], num[4]);
        for (j1=0; j1<6;j1++) num[j1]=0;
        i++;
    }

    return produtos;
}

char** ex12(listaCompras* l, char* c, int N){
    listaCompras* lAux;
    int i,j,k=0, ** pos = posMatrix(2),caso[]={50,5}, cId0 = c[0]-65,pc=0,q=0,** posAux = posMatrix(1),casoAux[]={8},a[6],b[6];
    char **produtos;
    produtos = malloc(pc * sizeof(char*));
    cmpStruct(l, caso, pos, 2);
    i = pos[2][cId0];
    for (int j1 = 0; j1 < 6; j1++){
        b[j1]=c[j1];
        a[j1]=((*((l->Compras)+i))->clienteC)[j1];
    }
    while(cmp(a,b,6)<0){
        i++;
        for (int j1 = 0; j1 < 6; j1++){
            a[j1]=((*((l->Compras)+i))->clienteC)[j1];
        }
    }
    if (cmp(a,b,6)>0){
        printf("\nO cliente introduzido nao efetuou compras ou nao existe nos registos!\n");
        return NULL;
    }
    q=i;
    while(!cmp(a,b,6)){
        q++;
        for (int j1 = 0; j1 < 6; j1++){
            a[j1]=((*((l->Compras)+q))->clienteC)[j1];
        }
    }
    lAux=aux(l,i,q,12);
    cmpStruct(lAux, casoAux, posAux, 1);
    while (k<N) {
        pc++;
        produtos = realloc(produtos,pc * sizeof(char*));
        produtos[k]=((*((lAux->Compras)+k))->produtoC);
        k++;
    }
    if (k<N) printf("\nO cliente introduzido nao efetuou um número de %d compras.", N);
    else {
        FILE * fex12;
        fex12 =  fopen("Ex12.txt","a");
        fprintf(fex12,"%d produtos onde o cliente %s gastou mais dinheiro: \n", N, c);
        for (int j = 0; j < k; j++){
            fprintf(fex12,"%s\n",produtos[j]);
        }
    }
    return produtos;
}

int main(){
    char** c,**p,*prod,**cEx5, **cEx4, **cEx10, **cEx11, **cEx12;
    listaCompras* v,*l,*lEx2,*lAux;
    cell *** Ex7;
    float* fEx3,*fEx8;
    int mes,*cpEx6;
    FILE *fp,*fp_txt,*fc,*fc_txt,*fv,*fexV, *fexV1;
    fp = fopen("Produtos.txt","r");
    //fp_txt = fopen("P.txt","a");
    fc = fopen("Clientes.txt","r");
    //fc_txt = fopen("C.txt","a");
    fv = fopen("Vendas_1M.txt","r");
    p = arrayP(fp,fp_txt);
    c = arrayC(fc,fc_txt);
    v = arrayV(fv);
    valArrayVC(v,c);
    valArrayVP(v,p);
    l = validaFinal(v);
    //char x = 'C';
    //lEx2 = ex2(l,x);
    //mes = 8;prod = p[8079];x='f';
    //fEx3 = ex3(l,mes,prod,x);
    //cEx4 = ex4(p, l, 'f');
    //cEx5 = ex5(l);
    //cpEx6=ex6(c,p,l);
    //printf("numero de clientes = %d, numero de productos = %d\n",cpEx6[0],cpEx6[1]);
    //Ex7 = ex7(l,c[15079]);
    //fEx8 = ex8(l,2,7);
    //printf("numero de vendas = %.1f, total faturado = %f\n",fEx8[1],fEx8[0]);
    //cEx9 = ex9(l,p[13056],2);
//    char *t = "A1231";
//    cEx10 = ex10(l, t, 10);
    cEx11 = ex11(l, 10);
    //cEx12 = ex12(l, t, 10);
//    int n=3;
//    int** pos = posMatrix(n),caso[]={50,6,5};
//    cmpStruct(l, caso, pos, n);
//    printM(pos,n);
//
//
//    fexV =  fopen("V.txt","a");
//    printListaC(l,fexV);
//
//    lAux = aux(l,0,891107,12);
//    fexV1 =  fopen("V1.txt","a");
//    printListaC(lAux,fexV1);
    
    return 0;
}
