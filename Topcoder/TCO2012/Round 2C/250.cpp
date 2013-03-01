/*
 * Author:  Troy
 * Created Time:  2012/6/3 0:18:24
 * File Name: 250.cpp
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

int g[50][50];
bool vis[50];
class GreedyTravelingSalesman
{
    public:
    int worstDistance(vector <string> th, vector <string> hu, vector <string> te, vector <string> one)
    {
        int n = th.size();
        REP(i, n)
            REP(j, n)
            {
                g[i][j] = (th[i][j]-'0')*1000 + (hu[i][j] - '0') * 100 + (te[i][j] - '0') * 10 + (one[i][j] - '0');
            }
        int ret = 0;
        
        REP(i, n)
            REP(j, n)
            if (i != j)
            {
                int tmp = g[i][j];
                g[i][j] = 9999;
                int cnt = 0, u = 0, tot = 1;
                memset(vis, false, sizeof(vis));
                vis[0] = true;
                while (tot < n)
                {
                    int mi = maxint, v = -1;
                    REP(x, n)
                        if (!vis[x] && g[u][x] < mi)
                        {
                            mi = g[u][x];
                            v = x;
                        }
                    cnt += mi;
                    tot++;
                    u = v;
                    vis[v] = true;
                }
                cout <<g[i][j] <<" "<<cnt <<end;
                if (cnt > ret) ret = cnt;
                
                g[i][j] = tmp;
                
                int len = maxint, id = -1;
                REP(k, n)
                    if (i!= k && k!= j && g[i][k] < len) len = g[i][k], id = k;
                if (id < j) g[i][j] = g[i][id] - 1;
                else g[i][j] = g[i][id];
                if (g[i][j] <= 0) g[i][j] = 1;
                
                cout <<i <<" " <<j <<" "<<id <<" "<<len <<" "<<g[i][j] <<endl;
                cnt = 0, u = 0, tot = 1;
                memset(vis, false, sizeof(vis));
                vis[0] = true;
                while (tot < n)
                {
                    int mi = maxint, v = -1;
                    REP(x, n)
                        if (!vis[x] && g[u][x] < mi)
                        {
                            mi = g[u][x];
                            v = x;
                        }
                    cnt += mi;
                    tot++;
                    u = v;
                    vis[v] = true;
                }
                cout <<g[i][j] <<" "<<cnt <<end;
                if (cnt > ret) ret = cnt; 
                
                g[i][j] = tmp;
                cnt = 0, u = 0, tot = 1;
                memset(vis, false, sizeof(vis));
                vis[0] = true;
                while (tot < n)
                {
                    int mi = maxint, v = -1;
                    REP(x, n)
                        if (!vis[x] && g[u][x] < mi)
                        {
                            mi = g[u][x];
                            v = x;
                        }
                    cnt += mi;
                    tot++;
                    u = v;
                    vis[v] = true;
                }
                cout <<g[i][j] <<" "<<cnt <<end;
                if (cnt > ret) ret = cnt;
            }
        return ret;
    }
};

















int main() 
{
    return 0;
}

