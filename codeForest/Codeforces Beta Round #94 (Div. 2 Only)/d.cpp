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
using namespace std;

string s;
int k, len;
long long sum[30];
vector<int> loc;

void dfs(vector<int> v)
{
     vector<int> w;
     long long s1, tmp;
     char c;
     for (c ='a'; c<='z'; c++)
     {
         w.clear();
         s1 = tmp = 0;
         for (int i=0; i<v.size(); i++)
         if (s[v[i]] == c)
         {
            tmp++;
            s1 += len - v[i];
            w.pb(v[i]+1);   
         }
         if (s1 >= k) break;
         k -= s1;
     }
     printf("%c", c);
     if (tmp >= k) return;
     k -= tmp;
     dfs(w); 
     }
int main()
{
    memset(sum, 0, sizeof(sum));
    cin >>s;
    cin >>k;
    len = s.length();
    if ((long long)k > 1LL*(len + 1)*len/2) cout <<"No such line." <<endl;
    else
    {
        for (int i=0; i<s.length(); i++) loc.pb(i);
        dfs(loc);     
        printf("\n");
    }    
    return 0;
    }
