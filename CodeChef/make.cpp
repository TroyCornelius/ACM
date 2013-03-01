/*
 * Author:  Troy
 * Created Time:  2012/8/6 19:37:05
 * File Name: 
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

int fa[50100];
int find(int x)
{
    if (fa[x] == x) return x;
    else return fa[x] = find(fa[x]);
}
int main() 
{
    freopen("tst.in", "w", stdout);
    srand(time(NULL));
    int n = 50000 ;
    cout <<n <<endl;
    REP(i, n) fa[i] = i;
    int tot = 0;
    vi owe, now;
    owe.pb(1);
    owe.pb(2);
    fa[find(1)] = find(2);
    FOR(i, 3, n) now.pb(i);
    now.pb(0);
    random_shuffle(all(now));
    cout <<"1 2" <<endl;
    
    while (tot < n-2)
    {
        int u = owe[rand()%(int(owe.size()))];
        int v = now[tot];
        owe.pb(v);
        //if (u == v || find(u) == find(v)) continue;
        tot++;
        cout <<u <<" "<<v <<endl;
        fa[find(u)] = find(v);
    }
    REP(i, n)
    {
        int num = rand()%1000+1;
        cout <<num;
        if (i == n-1) cout <<endl;
        else cout <<" ";
    }
    int q = 50000;
    cout <<q <<endl;
    while (q--)
    {
        int cmd = rand()%2;
        if (cmd == 0)
        {
            int u = rand()%n, v = rand()%n;
            cout <<"F " <<u <<" "<<v <<endl;
        }
        else
        {
            int u = rand()%n, v = rand()%n, c = rand()%10000;
            cout <<"C " <<u <<" "<<v <<" "<<c <<endl;
        }
    }
    return 0;
}

