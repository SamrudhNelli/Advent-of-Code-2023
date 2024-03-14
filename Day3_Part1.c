#include <stdio.h>
#include <string.h>

int find_num(char[],char[],char[]);
int find_sum(char[],char[],char[],int,int);

int main()
{
    FILE *file;
    file = fopen("input.txt","r");
    char prev[1000],pprev[1000],S[1000];
    for(int i=0;i<999;i++)
    {
        pprev[i]='.';
        prev[i]='.';
    }
    long int sum=0;
    for(int i=0;i<140;i++)
    {
        if(i > 1) strcpy(pprev,prev);
        if(i > 0) strcpy(prev,S);
        fgets(S,1000,file);
        if(i > 0) sum += find_num(pprev,prev,S);
        if(i == 139)
        {
            for(int i=0;i<999;i++)
            {
                pprev[i] = '.';
            }
            int t = find_num(pprev,S,prev);
            printf("%d\n",t);
            sum += t;
        }
    }
    printf("Sum : %ld\n",sum);
    return 0;
}

int find_num(char l[],char m[],char r[])
{
    int a = 0, t = 0, num, c = 0, index = 0, digit = 0;
    long int sum = 0;
    char temp[100];
    do
    {
        while( m[a] >= 48 && m[a] <= 57)
        {
            temp[t] = m[a];
            t++;
            a++;
            c = 1;
        }
        if( c == 1)
        {
            temp[t] = '\0';
            digit = t;
            index = a - t;
            t = 0;
            sscanf(temp,"%d",&num);
            //printf("%d ",num);
            sum += find_sum(l, m, r, digit, index)? num : 0 ;
            c = 0;
        }
        else
            a++;
    } while( m[a] != '\0');

    //printf("\n");
    return sum;
}

int find_sum( char l[], char m[], char r[], int digit, int index)
{
    for(int i = index-1; i < index+digit+1; i++)
        if( ( l[i] >= 33 && l[i] <= 47 && l[i] != 46 ) || ( l[i] >= 58 && l[i] <= 64 ) )
           {
                return 1;
           }
    for(int i = index-1; i < index+digit+1; i++)
        if( ( r[i] >= 33 && r[i] <= 47 && r[i] != 46 ) || ( r[i] >= 58 && r[i] <= 64 ) )
           {
                return 1;
           }
    char b = m[index-1];
    char f = m[index+digit];
    if( ( b >= 33 && b <= 47 && b != 46 ) || ( b >= 58 && b <= 64 ) )
           {
                return 1;
           }
    if( ( f >= 33 && f <= 47 && f != 46 ) || ( f >= 58 && f <= 64 ) )
           {
                return 1;
           }
    return 0;
}