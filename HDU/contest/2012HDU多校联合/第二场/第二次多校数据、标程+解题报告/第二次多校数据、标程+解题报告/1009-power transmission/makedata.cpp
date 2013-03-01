#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstdlib>
using namespace std;

int main()
{
    int N,s,t;
    double M;
    int i,j,k,a;
    int b;
    int T = 10;
    srand(0);
    freopen("Power.in","w",stdout);
    for(i = 0; i < T; i++)
    {
        if(i < 3)
        {
            N = 500;
        }else if(i < 8)
        {
            N = 5000;
        }else
        {
            N = 50000;
        }
        printf("%d\n",N);
        for(j = 0; j < N; j++)
        {
            k = rand()%51;
            printf("%d\n",k);
            while(k--)
            {
                do
                {
                    a = rand()%N + 1;
                }while(a == j + 1);
                b = rand()%100;
                printf("%d %d\n",a,b);
            }
        }
        s = rand()%N + 1;
        t = rand()%N + 1;
        M = N * 20;
        printf("%d %d %lf\n",s,t,M);
    }
    return 0;
}
