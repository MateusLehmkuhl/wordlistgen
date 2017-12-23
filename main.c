#include<stdio.h>
#include<string.h>
#include "fila.h"
void mst(Fila *fila, FILE *fw)
{
    int i, n, j, l;
    char *temp;
    int m=0;
    n=fila->nelem;
    char num[n][50];
    while(fila->nelem>0)
    {
        temp = pop_fila(fila);
        strcpy(num[m],temp);
        m++;
    }
    for (j = 1; j <= n; j++)
    {
        for (i = 0; i < n-1; i++)
        {
            strcpy(temp,num[i]);
            strcpy(num[i],num[i+1]);
            strcpy(num[i+1],temp);
            for ( l = 0 ; l < n ; l++)
            {
                fprintf(fw,num[l]);
            }
            fprintf(fw,"\n");
        }
    }
}
int main()
{
    Fila *fila = inicializa_fila();
    FILE *fw;
    fw = fopen("finish.txt","w");
    if(fw==NULL)
    {
        printf("Erro ao abrir o arquivo\n");
        return -1;
    }
    unsigned MAX, MASK, NUM ;
    int i, j, n;
    printf("\nQuantas palavras voce quer digitar: ");
    scanf("%d", &n);
    char input[n][100] ;
    char str[n][100] ;
    printf("\nDigite a lista de palavras separadas por \"enter\":\n");
    for (i = 0 ; i < n; i++)
    {
        scanf("%s", &input[i]);
        fprintf(fw,"%s\n",input[i]);
    }
    MAX = ~(1 << n) ;
    NUM = 1;
    putchar('\n') ;
    while ( MAX & NUM )
    {
        MASK = 1 ;
        i = j = 0 ;
        while ( MAX & MASK )
        {
            if ( NUM & MASK )
            {
                strcpy(str[i],input[j]);
                i++ ;
            }
            j++ ;
            MASK = MASK << 1 ;
        }
        int z;
        for(z=i; z<n; z++)
        {
            strcpy(str[z],"");
        }
        int l;
        for (l = 0 ; l < n; l++)
        {
            if(strcmp(str[l],""))
            {
                push_fila(fila,str[l]);
            }
        }
        mst(fila,fw);
        NUM++ ;
    }
    return 0;
}
