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

char ss[100000];
int main()
{
    char s[10]="b0.out";
    freopen("bout.txt","w",stdout);
    for (int i=0;i<10;i++)
    {
        s[1]=i+'0';
        freopen(s,"r",stdin);
        while (gets(ss)) puts(ss);
    }  
    char s1[10]="b0.in";
    freopen("bin.txt","w",stdout);
    for (int i=0;i<10;i++)
    {
        s1[1]=i+'0';
        freopen(s1,"r",stdin);
        while (gets(ss)) puts(ss);
    }
    //system("pause");
}
