#include <stdio.h>  
#include <memory.h>  
const int BASE=10000;  
int bignum[1000][90];  
int p2[90];  
int n;  
void mul(int y)  
{  
    for (int i=1; i<=p2[0]; ++i)  
    {  
        p2[i]*=y;  
    }  
    for (int i=1; i<=p2[0]; ++i)  
    {  
        if (p2[i]>=BASE)  
        {  
           p2[i+1]+=p2[i]/BASE;  
           p2[i]%=BASE;  
        }  
    }  
    if ( p2[ p2[0]+1 ]>0 )  
    {  
        ++p2[0];  
    }  
}  
void add(int y,int x)  
{  
    int len=p2[0] > bignum[y][0]? p2[0]: bignum[y][0];  
    bignum[x][0]=len;  
    for (int i=1; i<=len; ++i)  
    {  
        bignum[x][i]+=(bignum[y][i]+p2[i]);  
        bignum[x][i+1]+=bignum[x][i]/BASE;  
        bignum[x][i]%=BASE;  
    }  
    if ( bignum[x][len+1]>0 )  
    {  
        ++bignum[x][0];  
    }  
}  
void pre()  
{  
   memset(bignum, 0, sizeof(bignum));  
   bignum[0][1]=0;  
   bignum[1][1]=1;  
   bignum[2][1]=1;  
   bignum[3][1]=3;  
   bignum[0][0]=bignum[1][0]=bignum[2][0]=bignum[3][0]=1;  
   p2[0]=1;  
   p2[1]=2;  
   for (int i=4; i<1000; ++i)  
   {  
       mul(2);  
       add(i-2,i);  
   }  
}  
void output(int x)  
{  
    printf("%d", bignum[x][ bignum[x][0] ]);  
    for (int i=bignum[x][0]-1; i>0; --i)  
    {  
        printf("%04d", bignum[x][i]);  
    }  
    printf("\n");  
}  
int main(int argc, char *argv[])  
{  
    pre();  
    while ( scanf("%d", &n)!=EOF )  
    {  
        output(n-1);  
    }  
    return 0;  
}  
