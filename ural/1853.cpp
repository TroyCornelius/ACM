/*
 * Author:  Troy
 * Created Time:  2012/7/23 14:03:08
 * File Name: NSUBSTR.cpp
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
#define Maxc 29
#define Maxn 1000100
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

struct Tnode
{
    int ml;  //能接收到后缀的最大长度
    Tnode *fa, *next[Maxc];
}pool[2*Maxn], *root, *tail;
int tot;
char str[Maxn];
int dp1[2*Maxn], dp2[2*Maxn];
void add(int c, int len)
{
    Tnode *p = tail, *np = &pool[++tot];
    np->ml = len;
    for (; p && !p->next[c]; p = p->fa) p->next[c] = np;
    tail = np;
    if (!p) np->fa = root;
    else
    {
        if (p->next[c]->ml == p->ml + 1) np->fa = p->next[c];
        else
        {
            Tnode *q = p->next[c], *r = &pool[++tot];
            *r = *q;
            r->ml = p->ml + 1;
            q->fa = np->fa = r;
            for (; p && p->next[c] == q; p = p->fa) p->next[c] = r;
        }
    }
}

void dfs(Tnode *p, string st) //遍历求出所有不同的子串
{
    cout <<st <<endl;
    REP(i, 26) {
        if (p->next[i])
            dfs(p->next[i], "" + st + char('a' + i));
        }
}
int f[Maxn*2], cnt[Maxn*2], cc[Maxn*2], g[Maxn*2];
int main() 
{
    int len;
    root = tail = &pool[tot=1];
    int n = 0;
    while (~sf("%s", str+1))
    {
        //memset(pool, 0, sizeof(pool));
        int len = strlen(str+1);
        FOR(i, 1, len+1)
        {
            n++;
            if (str[i] == '@') add(26, n);
            else
            if (str[i] == '.') add(27, n);
            else add(str[i] - 'a'+1, i);
        }
        n++;
        add(28, n);

    }
    pf("5\n");
    return 0;
}


