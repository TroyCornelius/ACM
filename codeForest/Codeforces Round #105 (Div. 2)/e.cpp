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

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define all(a) (a).begin(),(a).end()
#define Maxn 101000
#define FOR(i,a,b) for (int i(a); i<(b); i++)
#define REP(i, b) FOR(i,0,b)
using namespace std;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
const int inf = 1<<29;
typedef pair<int,int> pii;
typedef vector<int>::iterator vit;

int sum[110][110], n, m;
int d[110][110], f[110][110];
int dp[110][10010];

void calc(int row)
{
    int tot, kn = d[row][0];
    REP(i, kn+1)
    {
        if (i > m) break;
        f[row][i] = max(f[row][i], sum[row][i]);
        for (int j=kn; j>i; j--)
        {
            tot = i + kn - j + 1;
            if (tot > m) break;
            f[row][tot] = max(f[row][tot], sum[row][i]+sum[row][kn]-sum[row][j-1]);
        }
    }
}
int main()
{
  //  while (1){
    memset(f, 0, sizeof(f));
    memset(dp, 0, sizeof(dp));
    cin >>n >>m;
    FOR(i, 1, n+1)
    {
        cin >>d[i][0];
        sum[i][0] = 0;
        FOR(j, 1, d[i][0]+1)
        {
            cin >>d[i][j];
            sum[i][j] = sum[i][j-1] + d[i][j];
        }
        calc(i);    
    }

    for (int i=1; i<=n; i++)
    {
        for (int j=0; j<=m; j++)
        {
            for (int k=0; k<=min(d[i][0], j); k++)
                dp[i][j] = max(dp[i][j], dp[i-1][j-k] + f[i][k]);        
        }    
    }
    cout <<dp[n][m] <<endl;  
   // }   
    return 0;
}
