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
#define Maxn 5000
#define inf 999999999
#define pb push_back
using namespace std;

string s, ans;
int k,cnt[30], ans1;
struct Tnode
{
       int id, tot;
       Tnode(int a, int b)
       :id(a), tot(b){}
       };
vector<Tnode> d;
bool cmp(const Tnode &a, const Tnode &b)
{
     if (a.tot != b.tot) return a.tot < b.tot;
     else return a.id < b.id;
     }
int main()
{
    cin >>s;
    cin >>k;
    if (k >= s.length()) printf("0\n\n");
    else
    {
        memset(cnt, 0, sizeof(cnt));
        for (int i=0; i<s.length(); i++) cnt[s[i]-'a']++;
        d.clear();
        for (int i=0; i<=26; i++)
          if (cnt[i] != 0) d.pb(Tnode(i, cnt[i]));
        sort(d.begin(), d.end(), cmp);
        ans1 = d.size();
        for (int i=0; i<d.size() && k>0; i++)
        {
            if (k >= d[i].tot)
            {
               k -= d[i].tot;
               cnt[d[i].id] = 0;   
               ans1--;
            }
            else cnt[d[i].id] -= k, k=0;
        }
       // for (int i=0; i<=26; i++) if (cnt[i]) ans1++;
        ans.clear();
        for (int i=0; i<s.length(); i++)
        {
            if (cnt[s[i]-'a'] > 0)
            {
               ans += s[i];
               cnt[s[i]-'a']--;                              
            }            
        }
        cout <<ans1 <<endl;
        cout <<ans <<endl;  
    }
   // system("pause");
    return 0;
    }
