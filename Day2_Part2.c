#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int check(char[]);
void maximum(char[],int,int *);
int comp(char[],char[]);

int main()
{
    FILE * ptr;
    ptr = fopen("input.txt","r");
    long int sum=0;
    for(int i = 1;i <= 100;i++)
    {
        char S[1000];
        fgets(S,1000,ptr);
        sum += check(S);
    }   
    printf("Sum = %d\n",sum);
    return 0;
}
 
int check(char A[])
{
    int t=0,a=0,valid=1,MAX[3];
    for(int z=0;z<3;z++)
        MAX[z]=0;
    while(A[t] != ':')
        t++;
    do
    {
        int tem;
        char *temp;
        temp = malloc(100*sizeof(char));
        t += 2;
        a = 0;
        while(A[t] != ' ')
        {
            temp[a]=A[t];
            a++;
            t++;
        }
        a=0;
        t++;
        sscanf(temp,"%d",&tem);
        while(A[t] >= 97 && A[t] <= 122)
        {
            temp[a]=A[t];
            a++;
            t++;
        }
        temp[a]='\0';
        printf(" %d %s,",tem,temp);
        maximum(temp,tem,MAX);
        free(temp);
    }
        while((A[t+1] != '\0'));
    printf("\n");
    return MAX[0]*MAX[1]*MAX[2];
}

void maximum(char A[],int b,int *max)
{
    if(comp(A,"red"))
    {
        if(b > *max)
            *max=b;
    }
    else if(comp(A,"green"))
    {
        if(b > *(max+1))
            *(max+1)=b;
    }
    else if(comp(A,"blue"))
    {
        if(b > *(max+2))
            *(max+2)=b;
    }
}

int comp(char A[], char B[])
{
    int a=0;
    while(B[a] != '\0')
    {
        if(A[a] != B[a])
            return 0;
        a++;
    }
    return 1;
}