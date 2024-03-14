#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int check(char[]);
int validity(char[],int);
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
        sum += (check(S)?i:0);
    }   
    printf("Sum = %d\n",sum);
    return 0;
}
 
int check(char A[])
{
    int t=0,a=0,valid=1;
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
        valid = validity(temp,tem);
        free(temp);
    }
        while((A[t+1] != '\0') && valid);
    printf("\n");
    return valid;
}

int validity(char A[],int b)
{
    if(comp(A,"red"))
    {
        if(b < 13 && b >= 0)
            return 1;
    }
    else if(comp(A,"green"))
    {
        if(b < 14 && b >= 0)
            return 1;
    }
    else if(comp(A,"blue"))
    {
        if(b < 15 && b >= 0)
            return 1;
    }
    return 0;
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