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
#define pb push_back
#define fi first
#define se second
#define mp make_pair
using namespace std;

string s;
int cnt[30], len;
bool p[1020];
char ans[1024];
bool vis[1024];
vector<int> pri;
struct Tnode
{
       int tot;
       char c;
       Tnode(){}
       Tnode(char _c, int _tot)
       :c(_c), tot(_tot){}
       bool operator<(const Tnode &b) const
       {
           return tot > b.tot;    
       }
       };
vector<Tnode> d;
void make_pri()
{
     memset(p, true, sizeof(p));
     pri.clear();
     for (int i=2; i<=1000; i++)
     if (p[i])
     {
        pri.pb(i);
        for (int j=i*i; j<=1000; j+=i) p[j] = false;              
     }
     }
pair<int, int> calc(int m)
{
    int ret = 0;
    int flag = -1;
    for (int j=m; j<=len; j+=m)
    if (!vis[j]) ret++, vis[j]=true;
    else flag = 1;
    return pair<int,int>(ret, flag);    
    }
int main()
{
    cin >>s;
    make_pri();
    memset(cnt, 0, sizeof(cnt));
    memset(vis, false, sizeof(vis));
    for (int i=0; i<s.length(); i++) cnt[s[i]-'a']++;
    for (int i=0; i<=26; i++)
    if (cnt[i] != 0) d.pb(Tnode('a'+i, cnt[i]));
    for (int i=0; i<=s.length(); i++) ans[i] = '#';    
    len = s.length();
    int p = 0, tmp=0, sum=0;
    sort(d.begin(), d.end());
   // for (int i=0; i<d.size(); i++) cout <<d[i].c <<" "<<d[i].tot <<endl;
    for (int i =0; i<pri.size(); i++)
    {
        if (pri[i] > len || p >= int(d.size())) break;
        pair<int,int> t = calc(pri[i]);
       // cout <<t.fi <<" "<<t.se<<endl;
        if (t.se == -1 && pri[i] != 2)
        {
           if (d[p].tot < sum) {cout <<"NO" <<endl;return 0;}
           else
           {
               for (int j=0; j<i; j++)
               {
                   for (int k=pri[j]; k<=len; k+=pri[j])
                   if (ans[k] == '#')
                   {
                      ans[k] = d[p].c;
                      d[p].tot--;                              
                   }                   
               }   
           }
           break;
        }
        else sum += t.fi;        
       // cout  <<sum <<endl;
    }
    for (int i=1; i<=len; i++)
    if (ans[i] == '#')
    {
       if (d[p].tot <= 0) p++;
       ans[i] = d[p].c;         
       d[p].tot--;      
    }
    cout <<"YES" <<endl;
    for (int i=1; i<=len; i++) cout <<ans[i];
    cout <<endl;    
    return 0;
    }
