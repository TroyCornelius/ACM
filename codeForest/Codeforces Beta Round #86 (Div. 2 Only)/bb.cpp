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
#define Maxn 100100
#define inf 999999999
#define pb push_back
#define mp make_pair
using namespace std;

int n, m;
map<string,int> mid;
bool vis[20][20];
vector<string> ans;
string name[20];
int main()
{
    string s1, s2;
    mid.clear();
    memset(vis, false, sizeof(vis));
    cin >>n >>m;
    for (int i=0; i<n; i++)
    {
        cin >>name[i];
        mid[name[i]] = i;        
    }
    int tid1, tid2;
    for (int i=0; i<m; i++)
    {
        cin >>s1 >>s2;
        tid1 = mid[s1]; tid2 = mid[s2];
        vis[tid1][tid2] = vis[tid2][tid1] = true;                
    }
    ans.clear();
    int ct, tmp=-1, sum=0;
    bool flag;
    for (int i=0; i<(1<<n); i++)
    {
        ct = 0; flag = true;
        for (int j=0; j<n; j++)
        if ((1<<j) & i)
        {
           ct++;
           for (int k=0; k<n; k++)
           if (k!= j && ((1<<k)&i))
           {
              if (vis[j][k]) {flag = false; break;}                   
           }
           if(!flag) break;   
        }
        if (flag && ct > sum)
        {
           sum = ct; tmp = i;                 
        }
    }
    for (int j=0; j<n; j++)
    if ((1<<j)&tmp) ans.pb(name[j]);
    sort(ans.begin(), ans.end());
    cout <<int(ans.size()) <<endl;
    for (int i=0; i<ans.size(); i++) cout <<ans[i] <<endl;
    return 0;
    }
