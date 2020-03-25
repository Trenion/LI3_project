

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "mainFunction.h"


// esta main é uma funçao que recebe os ficheiros mas que depois se liga a outros ficheiros independentes entre si
// daqui roupo um pouco de código da funçao mainFuncion.c



int mainAVerSeFunciona(){
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
    fexV =  fopen("V.txt","w");
    printListaC(l,fexV);
    lAux = aux(l,0,*(l->size),12);
    fexV1 =  fopen("V1.txt","w");
    printListaC(lAux,fexV1);
    
    return 0;
}





































