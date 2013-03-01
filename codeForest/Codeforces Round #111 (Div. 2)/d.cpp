/*
 * Author:  Troy
 * Created Time:  2012/3/7 0:37:37
 * File Name: d.cpp
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
#define Maxn 100100
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

int n, m;
struct Tnode
{
    int u, v, c;
    bool operator<(const Tnode &b)const
    {
        return c < b.c;
    }
}e[Maxn];

int fa1[Maxn], fa2[Maxn];
int find(int x)
{
    if (x == fa1[x]) return x;
    else return fa1[x] = find(fa1[x]);
}
int find1(int x)
{
    if (x == fa2[x]) return x;
    else return fa2[x] = find(fa2[x]);
}
void work()
{
    REP(i, n+1) fa1[i] = fa2[i] = i;
    int sum = 1, now;
    while (sum < n)
    {
        now = e[i].c;
        while (now == e[i].c)
        {
            int u = find(e[i].x), v = find(e[i].y);
            
        }
    }
    
}
int main() 
{
    int u, v, c;
    scanf("%d%d", &n, &m);
    REP(i, m) scanf("%d%d%d", &e[i].u, &e[i].v, &e[i].c);
    sort(e, e+m);
    work();
    
        
    
    return 0;
}

