#include <stdio.h>
#include <string.h>

int find_sum(char[],char[],char[]);
int find_product(char[],char[],char[],int);
int find_num(char[],int);

int main()
{
    FILE *file;
    file = fopen("input.txt","r");
    long long int sum = 0;
    char S[1000],prev[1000],pprev[1000];

    for(int i = 0; i < 140; i++)
    {
        if(i > 1) strcpy(pprev,prev);
        if(i > 0) strcpy(prev,S);
        fgets(S,1000,file);
        
        if(i > 1) sum += find_sum(pprev,prev,S);

    }
    printf("Sum = %lld\n",sum);
    return 0;
}

int find_sum(char l[], char m[], char r[])
{
    int a = 0, t = 0, index = 0;
    long long int sum;
    do
    {
        if( ( m[a] == 42 ) )
        {
            index = a;
            sum += find_product(l,m,r,index);
        }
        a++;


    } while (m[a] != '\0');
    
    return sum;
}

int find_product(char l[], char m[], char r[], int index)
{
    int a = 0, b = 0, ind;

    for(int i = index - 1; i < index + 2; i++)
    {
        if( l[i] >= '0' && l[i] <= '9')
        {
            ind = i;
            int t = find_num(l,ind);
            if(a == 0 || a == t) a = t;
            else if(a != 0 && b == 0 ) b = t;
        }
    }
    for(int i = index - 1; i < index + 2; i++)
    {
        if( r[i] >= '0' && l[i] <= '9')
        {
            ind = i;
            int t = find_num(r,ind);
            if(a == 0 || a == t) a = t;
            else if(a != 0 && b == 0) b = t;
        }
    }
    for(int i = index - 1; i < index + 2; i++)
    {
        if( m[i] >= '0' && l[i] <= '9')
        {
            ind = i;
            int t = find_num(m,ind);
            if(a == 0 || a == t) a = t;
            else if(a != 0 && b == 0) b = t;
        }
    }

    //printf("%d %d %d\n",a,b,ind);
    return a*b;
}

int find_num(char s[], int index)
{
    int t = index, a = 1, l = index, r = index + 1, num = 0;
    
    while( s[l] >= '0' && s[l] <= '9')
    {
        num = num + a*(s[l] - '0');
        a *= 10;
        l--;
    }

    while( s[r] >= '0' && s[r] <= '9')
    {
        num = num*10 + (s[r] - '0');
        r++;
    }

    return num;
}