#include <stdio.h>
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>

using namespace std;

int process3(char[],int);
int process4(char[],int);
int process5(char[],int);
int compare(char[],char[],int);

int main()
{
    FILE *fptr;
    fptr=fopen("input.txt","r");
    long int sum=0;

    for(int i=0;i<1000;i++)
    {
        int size=0;
        char S[100];
        fgets(S,100,fptr);
        while(S[size]!='\0')
         size++;
         for(int j=0;j<size;j++)
         printf("%c",S[j]);
        int token=0,first=0,second=0;
        for(int j=0;j<size-1;j++)
        {
            if((int)S[j]>48 && (int)S[j]<=57)
                if(!token)
                    {
                        first=(int)S[j]-48;
                        token = 1;
                        second=(int)S[j]-48;
                    }
                else
                    second=(int)S[j]-48;
            int temp=-1;
            if(j>1)temp = process3(S,j);
            if(temp>0)
                {
                    if(!token)
                    {
                        first=temp;
                        token=1;
                        second=temp;
                    }
                    else
                        second=temp;
                }
            else
            {
                if(j>2)temp = process4(S,j);
                if(temp>0)
                   { if(!token)
                    {
                        first=temp;
                        token=1;
                        second=temp;
                    }
                    else
                        second=temp;
                   }
                else
                {
                    if(j>3)temp = process5(S,j);
                    if(temp>0)
                        if(!token)
                        {
                            first=temp;
                            token=1;
                            second=temp;
                        }
                        else
                            second=temp;
                }
            }
         }
         printf("Iteration : %d\t%d\t%d\tSum : %d\n\n\n",i,first,second,sum);
        sum+=(first*10)+second; 
    }
    printf("\nSum = %ld\n",sum);
    return 0;
}

int process3(char S[],int j)
{
    char char3[3],a[]={'o','n','e'},b[]={'t','w','o'},c[]={'s','i','x'};
    for(int i=0;i<3;i++)
        char3[i]=S[j-2+i];
    if(compare(char3,a,3))
            return 1;
    else if(compare(char3,b,3))
        return 2;
    else if(compare(char3,c,3))
        return 6;
    else
        return -1;
}

int process4(char S[],int j)
{
    char char4[4],a[]={'f','o','u','r'},b[]={'f','i','v','e'},c[]={'n','i','n','e'};
    for(int i=0;i<4;i++)
        char4[i]=S[j-3+i];
    if(compare(char4,a,4))
        return 4;
    else if(compare(char4,b,4))
        return 5;
    else if(compare(char4,c,4))
        return 9;
    else
        return -1;
}

int process5(char S[],int j)
{
    char char5[5],a[]={'t','h','r','e','e'},b[]={'s','e','v','e','n'},c[]={'e','i','g','h','t'};
    for(int i=0;i<5;i++)
        char5[i]=S[j-4+i];
    if(compare(char5,a,5))
        return 3;
    if(compare(char5,b,5))
        return 7;
    if(compare(char5,c,5))
         return 8;
    else
        return -1;
}

int compare(char A[],char B[],int j)
{
    for(int i=0;i<j;i++)
        if(A[i]!=B[i])
            return 0;
    return 1;
}