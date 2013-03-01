/*
 * Author:  Troy
 * Created Time:  2012/8/20 0:50:23
 * File Name: 3525-bit.cpp
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
const int maxn = 200010;
int next[maxn],tree[maxn];
int ff[maxn][12],f[maxn];
//ff[str2[i]][j]记录str2[i]出现j次的位置
//f[str2[i]]记录str2[i]出现的次数
//时间复杂度为O(nlogn)
int lim;
void change(int idx, int val) {
    for (;idx<=lim; idx+=idx&-idx) tree[idx] = max(tree[idx], val);
}
int ask(int idx) {
    int ret = 0;
    for (;idx; idx-=idx&-idx) ret = max(ret, tree[idx]);
    return ret;
}
int n,m;
int str1[maxn],str2[maxn],ch;
void dp() {
    memset(tree,0,sizeof(tree));
    int i,j,k;
    int maxres=0;
    lim = n*m;
    for (i=1;i<=n*m;i++)
        for (j=f[str1[i]]-1;j>=0;j--) {
            k=ff[str1[i]][j];
            int t=ask(k-1)+1;
            maxres=max(maxres,t);
            change(k,t);
        }
    printf("%d\n",maxres);
}
int main()
{
    int t,i,x,k,j,cas;
    scanf("%d",&t);
    cas = 0;
    while (t--) {
        scanf("%d%d",&n,&m);
        for (i=0;i<2*n*m+10;i++) {
            next[i] = i+1;
            str1[i] = 0;
        }
        for(i=0;i<n*m;i++) {
            scanf("%d%d",&ch,&x);
            k = x;
            while(str1[k] != 0) k = next[k];
            str1[k] = ch;
            j = k;
            k = x;
            while(k!=j) {
                int temp = next[k];
                next[k] = next[j];
                k = temp;
            }
        }
        k=i=1;
        while (k<=n*m) {
            while (str1[i]==0) i++;
            str1[k++]=str1[i++];
        }
        for (i=0;i<2*n*m+10;i++) {
            next[i] = i+1;
            str2[i] = 0;
        }
        for (i=0;i<n*m;i++) {
            scanf("%d%d",&ch,&x);
            k = x;
            while(str2[k] != 0) k = next[k];
            str2[k] = ch;
            j = k;
            k = x;
            while(k!=j) {
                int temp = next[k];
                next[k] = next[j];
                k = temp;
            }
        }
        k=i=1;
        while (k<=n*m) {
            while (str2[i]==0) i++;
            str2[k++]=str2[i++];
        }
        for(i=1;i<=n;i++) f[i] = 0;
        for(i=1;i<=n*m;i++) ff[str2[i]][f[str2[i]]++] = i; //记录位置
        printf("Case #%d: ",++cas);
        dp();
    }
    return 0;
}
