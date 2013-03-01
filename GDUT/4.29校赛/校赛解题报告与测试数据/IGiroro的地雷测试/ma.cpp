#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <map>
#include <set>
#define INF (1<<30)
using namespace std;

int mr(int x,int y)
{
    int t=rand()%(y-x);
    return x+t;
}
int main()
{
    //freopen(".in","r",stdin);
    srand(time(NULL));
    char s[10]="a0.in";
    int i,j,k;
    for (i=0;i<=9;i++)
    {
        s[1]=i+'0';
        freopen(s,"w",stdout);
        for (k=1;k<=20;k++)
        {
            printf("%d %d %d\n",(i+1)*20,mr(0,1000),mr(0,500) );
            for (j=1;j<=(i+1)*20;j++) printf("%d %d %d\n",mr(0,1000),mr(0,1000),mr(0,20));
        }
    }
    //system("pause");
}
