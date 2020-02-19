


#include <stdio.h>
#include <stdlib.h>
#include <string.h>




int PraAnalisarFicheiro (){
	char *nomeDoFicheiroAUsar;
	printf("Qual é o ficheiro a analisar?\n");
	scanf("%s",&nomeDoFicheiroAUsar);
	ficheiroAUsar = fopen(nomeDoFicheiroAUsar,"r");
	



	fclose(fp);
	return(0);
}

char*produto = strtok(buf,"_");
     preco = strtok(NULL,"_");