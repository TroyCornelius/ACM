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
#define Maxn 5000000
#define FOR(i,a,b) for (int i(a); i<(b); i++)
#define REP(i, b) FOR(i,0,b)
using namespace std;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
const int inf = 1<<29;
typedef pair<int,int> pii;
typedef vector<int>::iterator vit;

int c1, c2, d1, d2, r1, r2;
int ans[5];
bool vis[10];
bool dfs(int idx)
{
    if (idx >= 4)
    {
        if (ans[0]+ans[1]==r1 && ans[2]+ans[3]==r2 && ans[0]+ans[2]==c1 && 
                ans[1]+ans[3]==c2 && ans[0]+ans[3]==d1 && ans[1]+ans[2]==d2) return true;
        return false;    
    }
    for (int i=1; i<=9; i++)
    if (!vis[i])
    {
        vis[i] = true;
        ans[idx] = i;
        bool f = dfs(idx+1);
        if (f) return f;
        else vis[i] = false;    
    }
    return false;
}
int main()
{
  //  while (1){
    cin >>r1 >>r2;
    cin >>c1 >>c2;
    cin >>d1 >>d2;
    memset(vis, false, sizeof(vis));
    if (!dfs(0)) cout <<-1 <<endl;
    else cout <<ans[0]<<" "<<ans[1]<<endl<<ans[2] <<" "<<ans[3]<<endl;
//}
    return 0;
}
