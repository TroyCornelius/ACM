/*
 * Author:  Troy
 * Created Time:  2012/5/2 19:38:29
 * File Name: a.cpp
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

int n, ans1, ans2;
int c[110][110];
bool g[110][110];

void dfs(int u, int fa)
{
    if (u == 1) return ;
    FOR(i, 1, n+1)
        if (i != fa && g[u][i])
        {
            ans1 += c[u][i];
            ans2 += c[i][u];
    //cout <<ans1 <<" "<<ans2 <<" "<<i <<endl;
            dfs(i, u);
            break;
        }    
}


int main() 
{
    int a, b, val;
    memset(g, false, sizeof(g));
    memset(c, 0, sizeof(c));
    cin >>n;
    REP(i, n)
    {
        cin >>a >>b >>val;
        g[a][b] = g[b][a] = true;
        c[b][a] = val;        
    }
    
    ans1 = 0;
    ans2 = 0;
    
    FOR(i,1,n+1)
        if (g[1][i])
        {
            ans1 += c[1][i]; ans2 += c[i][1];
    //cout <<ans1 <<" "<<ans2 <<" "<<i <<endl;
            dfs(i, 1);
            break;
        }
    //cout <<ans1 <<" "<<ans2 <<endl;
    cout <<min(ans1, ans2) <<endl;
    return 0;
}

