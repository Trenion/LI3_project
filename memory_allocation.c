#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main () {
   int len,i,j=0;
   char str[50],*s,**m;
   FILE *fp,*fp1;
   fp = fopen("P.txt","r");
   fp1 = fopen("P.txt","a");
   m = malloc(j * sizeof(char*));
   while(fgets(str,50,fp)){
    len = strlen(str);
    s = malloc((len-1) * sizeof(char));
    for (i = 0; i < len-2; i++){
    	s[i]=str[i];
    }s[i]='\0';
    m = realloc(m,(++j) * sizeof(char*));
    m[j-1]=s;
    fprintf(fp1,"%s,%d\n",s,len);
   }
   for (i = 0; i < j; i++){
        fprintf(fp1,"%s\n",m[i]);	
    } 
   return(0);
}