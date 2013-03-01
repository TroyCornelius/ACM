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
#define Maxn 10100
using namespace std;
int n, d[Maxn];
bool vis[Maxn];
int main()
{
    memset(vis, false, sizeof(vis));
    int ans = 0;    
    cin >>n;
    for (int i=0; i<n; i++)
    {
        cin >>d[i];
        if (!vis[d[i]]) vis[d[i]] = true;    
    }
    for (int i=1; i<=n; i++)
    if (!vis[i]) ans++;
    cout <<ans <<endl;
    return 0;
}

