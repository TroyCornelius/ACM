/*
 * Author:  Troy
 * Created Time:  2012/2/24 23:29:39
 * File Name: b.cpp
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
#define Maxn 100000
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

int n, m;
bool b[Maxn+10];
vi p;
bool vis[Maxn+10];
int s[Maxn+10];
vi t[Maxn+10];
void init()
{
    memset(b, true, sizeof(b));
    for (int i=2; i<=Maxn; i++)
    if (b[i])
    {
        p.pb(i);
        t[i].pb(i);
        for (int j=i+i; j<=Maxn; j+=i) 
        {
            b[j] = false;
            t[j].pb(i);
        }
    }
}

bool check(int num)
{
    REP(i, t[num].size())
    {
        if (s[t[num][i]] != -1) {printf("Conflict with %d\n", s[t[num][i]]); return false;}
    }
    return true;
}
int main() 
{
    char op[3];
    int num;
    init();
    memset(vis, false,sizeof(vis));
    memset(s, -1, sizeof(s));
    scanf("%d%d", &n, &m);
    while (m--)
    {
        scanf("%s", op);
        scanf("%d", &num);
        if (op[0] == '+')
        {
            if (vis[num]) printf("Already on\n");
            else
            if (check(num))
            {
                REP(i, t[num].size()) s[t[num][i]] = num;
                vis[num] = true;
                printf("Success\n");
            }
        }
        else
        {
            if (!vis[num]) printf("Already off\n");
            else
            {
                vis[num] = false;
                REP(i, t[num].size()) s[t[num][i]] = -1;
                printf("Success\n");
            }
        }
        
    }
    
    return 0;
}

