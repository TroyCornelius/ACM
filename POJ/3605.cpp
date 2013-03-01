#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <functional>
#include <vector>
#include <map>
#include <cstring>
#include <string>
#include <list>
#include <set>
#include <bitset>
#include <cctype>
#include <cmath>
#include <ctime>
#include <numeric>
#include <utility>
#include <stack>
#include <queue>
#include <deque>
#include <iomanip>
#include <cassert>
#define pb push_back
#define mp make_pair
#define inf 999999999
#define Maxn 11000

using namespace std;


int T, n, op[Maxn], ans;
int f[Maxn*10][2], st, en;
string s;
int dfs(int x, int k)
{
    if (f[x][k] != -1) return f[x][k];
    if (x>=st && x<=en) return f[x][k] = (k==1);
    if (op[x] == 1)
    {
        if (k == 1) f[x][k] = dfs(x<<1, 1) + dfs(x<<1|1, 1);
        else
        {
            f[x][k] = dfs(x<<1, 0) + dfs(x<<1|1, 1);
            f[x][k] = min(f[x][k], dfs(x<<1, 1)+dfs(x<<1|1, 0));
            f[x][k] = min(f[x][k], dfs(x<<1, 0)+dfs(x<<1|1, 0));    
        }
    }
    else
    {
         if (k == 0) f[x][k] = dfs(x<<1, 0) + dfs(x<<1|1, 0);
        else
        {
            f[x][k] = dfs(x<<1, 0) + dfs(x<<1|1, 1);
            f[x][k] = min(f[x][k], dfs(x<<1, 1)+dfs(x<<1|1, 0));
            f[x][k] = min(f[x][k], dfs(x<<1, 1)+dfs(x<<1|1, 1));
        }
    }
    return f[x][k];  
}
int main()
{
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &n);
        cin >>s;
        for (int i=1; i<=n-1; i++) scanf("%d", &op[i]);
        memset(f, -1, sizeof(f));
        int k = 0;
        while ((1<<(k)) < n) k++;
        st = 1<<(k);
        en = st+n-1;               
        ans = dfs(1, 1);
        int anss=0, i=0;
        for(;i<s.size(); i++)
          if (s[i]=='1') {anss=ans;break;}
        i++;        
        for (;i<s.size(); i++)
            if (s[i] != s[i-1]) anss++;
       cout << anss << endl;
    }
    return 0;
}
