#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#define all(a) (a).begin(),(a).end()
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define Maxn 10100
#define FOR(i,a,b) for (int i(a); i<(b); i++)
#define REP(i, b) FOR(i,0,b)
using namespace std;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
const int inf = 1<<29;
typedef pair<int,int> pii;
typedef vector<int>::iterator vit;
const int MOD = 1000000007;

int f[110][110][110];
class NoRepeatPlaylist
{
    public:
    int numPlaylists(int N, int M, int p)
    {
        memset(f, 0, sizeof(f));
        REP(i, N+1) f[1][1][i] = 1;
        
        FOR(i, 2, p+1)
        {
               FOR(j, 1, N+1)
                 FOR(k, 1, N+1)
                 {
                      FOR(q, 1, N+1)
                      if (q == k)
                      {
                            if (i-M-1>=1) f[i][j][k] += f[i-M-1][j][q];
                            if (f[i][j][k] >= MOD) f[i][j][k] -= MOD;
                      }
                      else
                      {
                          f[i][j][k] += f[i-1][j-1][q];
                          if (f[i][j][k] >= MOD) f[i][j][k] -= MOD;                          
                      }
                 }               
        }
        int ans = 0;
        FOR(i, 1, N+1)
        {
             ans += f[p][N][i];
             if (ans >= MOD) ans -= MOD;               
        }        
        return ans;
    }
}t;

int main()
{
    int a, b, c;
    while (cin >>a >>b >>c)
    {
        cout <<t.numPlaylists(a, b, c) <<endl; 
    }
    return 0;
    }
