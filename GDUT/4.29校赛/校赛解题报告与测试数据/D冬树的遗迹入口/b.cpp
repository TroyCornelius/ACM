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
#define MAXN 50005
using namespace std;

__int64 ans;
char s[MAXN];
int n,m;
pair<int,int> a[MAXN];
priority_queue < pair<int,int> > heap;
int main()
{
    char s1[10]="b0.in";
    char s2[10]="b0.out";
    int T;
    for (T=0;T<=9;T++)
    {
        s1[1]=s2[1]=T+'0';
        freopen(s1,"r",stdin);
        freopen(s2,"w",stdout);
        int i;
        while (!heap.empty()) heap.pop();
        gets(s);
        n=strlen(s);
        for (i=0;i<n;i++)
            if (s[i]=='?')
               scanf("%d%d",&a[i].first , & a[i].second );
        m=0;
        ans=0;
        for (i=0;i<n;i++)
        {
            if (s[i]=='(') m++;
            else
            if (s[i]==')') m--;
            else
            if (s[i]=='?')
            {
               s[i]=')';
               m--;
               ans+=a[i].second;
               heap.push( make_pair(a[i].second-a[i].first , i) );
            }
            if (m<0)
            {
               if (heap.empty()) break;
               ans-=heap.top().first;
               s[heap.top().second]='(';
               m+=2;
               heap.pop();
            }
        }
        if (i<n || m>0) printf("-1\n");
        else
        printf("%I64d\n",ans);
        //system("pause");
    }
}
