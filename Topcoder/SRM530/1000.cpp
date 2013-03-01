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

int f[Maxn], n;
vector <string> g;
class GogoXReimuHakurai
{
    public:
    int dfs(int rt)
    {
        if (f[rt] != -1) return f[rt];
        f[rt] = 0;
        REP(i, n)
            if (g[i][rt] == 'Y') f[rt] += dfs(i);
        return f[rt]; 
    
    }
    int solve(vector <string> choices)
    {
        n = choices.size();
        g = choices;
        memset(f, -1, sizeof(f));
        f[0] = 1;
        
        return dfs(n-1);       
    }


};
