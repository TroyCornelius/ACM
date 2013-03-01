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

long long f[110][110];
class NoRepeatPlaylist
{
    public:
    int numPlaylists(int N, int M, int p)
    {
        memset(f, 0, sizeof(f));
        f[0][0] = 1;
        
        FOR(i, 1, p+1)
        {
            FOR(j, 1, N+1)
            {
                   f[i][j] += (f[i-1][j-1] * (N - j + 1) % MOD);
                   if (j - M > 0) f[i][j] += f[i-1][j] * (j - M) % MOD;
                   f[i][j] %= MOD;                   
            }               
        }
        return f[p][N];
    }
};

int main()
{
    int a, b, c;
    while (cin >>a >>b >>c)
    {
        cout <<t.numPlaylists(a, b, c) <<endl; 
    }
    return 0;
    }
