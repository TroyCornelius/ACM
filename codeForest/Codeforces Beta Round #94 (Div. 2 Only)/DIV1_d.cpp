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
#define inf 1<<30
#define Maxn 100100
using namespace std;

int n, minnum, maxnum;
int d[Maxn], cnt[Maxn];

void print(bool op)
{
     if (op) printf("YES\n");
     else printf("NO\n");
     }
int main()
{
    scanf("%d", &n);
    minnum = inf, maxnum = -inf;
    for (int i=0; i<n; i++) 
    {
        scanf("%d", &d[i]);
        minnum = min(minnum, d[i]);
        maxnum = max(maxnum, d[i]);  
    }
    if (maxnum - minnum >= n)
    {
       print(false);
       return 0;               
    }
    memset(cnt, 0, sizeof(cnt));
    
    for (int i=0; i<n; i++)
    {
        d[i] -= minnum;
        cnt[d[i]]++;        
    }
    bool ans = true;
    if (cnt[1] < 2) print(false);
    else
    {
        cnt[0]--; cnt[1] -=2;
        queue<int> q;
        q.push(1); q.push(1);        
        while (!q.empty())
        {
              int now = q.front();
              q.pop();
              if (now-1>=0 && cnt[now-1])
              {
                 cnt[now-1]--;
                 q.push(now-1);                             
              }
              else
              if (cnt[now+1])
              {
                 cnt[now+1]--;
                 q.push(now+1);                             
              }
              else
              if (q.size()==1 && abs(q.front() - now) == 1)
              {
                 q.pop();                              
              }
              else 
              {
                 ans = false;
                 break;                   
              }
        }
        for (int i=0; i<=maxnum - minnum; i++)
        if (cnt[i]) {ans = false; break;}
        print(ans);     
    }
   // system("pause");    
    return 0;
    }
