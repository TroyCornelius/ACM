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
multiset<pair<string, string> > vis;
vector<string> ans, tmp;
string name[20];
bool check(string st)
{
     string s1, s2;
     for (int i=0; i<tmp.size(); i++)
     {
         s1 = st; s2=tmp[i];
         if (s1 > s2) swap(s1, s2);
         if (vis.find(mp(s1, s2)) != vis.end()) return false;     
     }
     return true;     
     }
int main()
{
    string s1, s2;
    mid.clear();
    vis.clear();
    cin >>n >>m;
    for (int i=0; i<n; i++)
    {
        cin >>name[i];
        mid[name[i]] = i;        
    }
    
    for (int i=0; i<m; i++)
    {
        cin >>s1 >>s2;
        if (s1 > s2) swap(s1, s2);
        vis.insert(mp(s1,s2));                
    }
    ans.clear();
    for (int i=0; i<n; i++)
    {
        tmp.clear();
        tmp.pb(name[i]);
        for (int j=0; j<n; j++)
        if (j!=i)
        {
            if (check(name[j])) tmp.pb(name[j]);
        }
        if (int(tmp.size()) > int(ans.size())) ans = tmp;        
    }
    sort(ans.begin(), ans.end());
    cout <<int(ans.size()) <<endl;
    for (int i=0; i<ans.size(); i++) cout <<ans[i] <<endl;


    return 0;
    }
