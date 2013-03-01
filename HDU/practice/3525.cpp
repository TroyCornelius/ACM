/*
 * Author:  Troy
 * Created Time:  2012/8/14 21:10:18
 * File Name: 3525.cpp
 */
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <time.h>
#include <cctype>
#include <functional>
#include <deque>
#include <iomanip>
#include <bitset>
#include <assert.h>
#include <numeric>
#include <sstream>
#include <utility>

#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(a) (a).begin(),(a).end()
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define FORD(i,a,b) for (int i=(a); i>=(b); i--)
#define REP(i,b) FOR(i,0,b)
#define sf scanf
#define pf printf
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

#define max(a,b) (a>b?a:b)
const int maxn = 200010;

int next[maxn],tree[maxn];
int ff[maxn][12],f[maxn];


int lowbit(int t)
{
    return t&-t;
}

void change(int pos , int num,int n) //修改
{ 
    while (pos<=n) 
    { 
        tree[pos] = max(num,tree[pos]);
        pos += lowbit(pos); 
    }
}

int ask(int end)//查询
{ 
    int sum = 0; 
    while(end > 0) 
    { 
        sum = max(sum,tree[end]); 
        end -= lowbit(end); 
    } 
    return sum;
}

int n,m;
int str1[maxn],str2[maxn],ch;

void dp()
{
    memset(tree,0,sizeof(tree));
    int i,j,k;
    int maxres=0;
    for (i=1;i<=n*m;i++)
        for (j=m-1;j>=0;j--)
        {
            k=ff[str1[i]][j];
            int t=ask(k-1)+1;
            maxres=max(maxres,t);
            change(k,t,n*m);
        }
    printf("%d\n",maxres);
}


int main()
{
    int t,i,x,k,j,cas;
    scanf("%d",&t);
    cas = 0;
    while (t--)
    {
        scanf("%d%d",&n,&m);
        for (i=0;i<2*n*m+10;i++)
        {
            next[i] = i+1;
            str1[i] = 0;
        }
        for(i=0;i<n*m;i++)
        {
            scanf("%d%d",&ch,&x);
            k = x;
            while(str1[k] != 0) k = next[k];
            str1[k] = ch;
            j = k;
            k = x;
            while(k!=j)
            {
                int temp = next[k];
                next[k] = next[j];
                k = temp;
            }
        }
        k=i=1;
        while (k<=n*m)
        {
            while (str1[i]==0) i++;
            str1[k++]=str1[i++];
        }
        //for (int ii = 1; ii < k; ii++) cout <<str1[ii] <<" ";
        //cout <<endl;
        for (i=0;i<2*n*m+10;i++)
        {
            next[i] = i+1;
            str2[i] = 0;
        }
        for (i=0;i<n*m;i++)
        {
            scanf("%d%d",&ch,&x);
            k = x;
            while(str2[k] != 0) k = next[k];
            str2[k] = ch;
            j = k;
            k = x;
            while(k!=j)
            {
                int temp = next[k];
                next[k] = next[j];
                k = temp;
            }
        }
        k=i=1;
        while (k<=n*m)
        {
            while (str2[i]==0) i++;
            str2[k++]=str2[i++];
        }
        //for (int ii = 1; ii < k; ii++) cout <<str2[ii] <<" ";
        //cout <<endl;
        for(i=1;i<=n;i++) f[i] = 0;
        for(i=1;i<=n*m;i++) ff[str2[i]][f[str2[i]]++] = i; //记录位置?
        //for (i=1; i<=n*m; i++) {
            //cout <<str2[i] <<endl;
            //for (int j = 0; j < 10; j++) cout <<ff[str2[i]][j] <<" ";
            //cout <<endl;
        //}
        printf("Case #%d: ",++cas);
        dp();
    }

    return 0;
}



 

 

