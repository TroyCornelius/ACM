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
const int inf = 1<<30;
string s;
struct Tnode
{
    int len, val;
}dp[512][512];
int k, g[512][512];
vector<string> res;
inline int calc(int x, int y)
{
    int ret = 0;
    while (x <= y)
    {
        if (s[x] != s[y]) ret++;
        x++; y--;    
    }
    return ret;
}
string check(string st)
{
       int le = 0, ri = st.length()-1;
       while (le <= ri)
       {
             if (st[le] != st[ri]) st[le] = st[ri];
             le++; ri--;             
       }
       return st;
       }
int main()
{
   // while (1){
    cin >>s;
    cin >>k;
    int n = s.length();
    for (int i=0; i<=n; i++)
       for (int j=0; j<=k; j++)
           dp[i][j].val=inf, dp[i][j].len = 0;
    
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
            g[i][j] = calc(i, j);
    dp[0][1].len = 1, dp[0][1].val = 0;
   // dp[0][0].len = dp[0][0].val = 0;
    
    for (int i=1; i<n; i++)
    {
        for (int t=1; t<=k; t++)
        {
            for (int j=i; j>=0; j--)
            {
                if (j==i && t>1) dp[i][t].val = dp[i-1][t-1].val, dp[i][t].len = 1;
                else
                {
                    int tmp = (j==0?0:dp[j-1][t-1].val);
                    if (g[j][i] + tmp < dp[i][t].val)
                    {
                        dp[i][t].val = g[j][i] + tmp;
                        dp[i][t].len = i-j+1;
                    }                
                }            
            }        
        }    
    }
    int pp, ans = inf;
    for (int i=1; i<=k; i++) 
      if (dp[n-1][i].val < ans)
      {
          ans = dp[n-1][i].val;
          pp = i;                  
      }
    cout <<ans <<endl;
    res.clear();
    int tt = pp, idx;
    for (idx=n-1; tt>0;)
    {
        string str="";
        str = s.substr(idx - dp[idx][tt].len+1, dp[idx][tt].len);
        str = check(str);
        res.pb(str);
      //  cout <<str <<" "<<idx-dp[idx][tt].len+1<<" "<<dp[idx][tt].len<<" "<<tt <<endl;
        if (idx - dp[idx][tt].len+1 <= 0) break;  
        idx -= dp[idx][tt].len;
        tt--;      
    }
    for (int i=res.size()-1; i>0; i--)
    {
        cout <<res[i]<<"+";        
    }
    cout <<res[0] <<endl;
//}
    return 0;
}
