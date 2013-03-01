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
    char s[10]="b0.in";
    int i,j,k,x;
    for (i=0;i<=9;i++)
    {
        s[1]=i+'0';
        freopen(s,"w",stdout);
        k=mr(1,3);
        j=mr(1,10000);
        if (k>1 && j%2!=0) j++;
        x=0;
        while (j--)
        {
              k=mr(1,100);
              if (j==0) putchar(')');
              else
              if (k<=25) putchar('(');
              else if (k>=50) putchar('?') , x++;
              else putchar(')');
        }
        puts("");
        while (x--) printf("%d %d\n",mr(1,1000),mr(1,1000));
    }
    //system("pause");
}
