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
#define all(a) (a).begin(),(a).end()
#define Maxn 10100
#define FOR(i,a,b) for (int i(a); i<(b); i++)
#define REP(i, b) FOR(i,0,b)
using namespace std;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
const int inf = 1<<29;
typedef pair<int,int> pii;
typedef vector<int>::iterator vit;

int n, m;
string s1, s2, s, ans;
bool check()
{
     string st = "";
     REP(i, s.length())
     if (s[i] == '4' || s[i] == '7') st = st + s[i];
     return st == s2;     
}
void dfs(int idx)
{
   //  cout <<s <<endl;
    if (idx >= n) return;
    else
        if (s > s1)
        {
              cout <<s <<"+++" <<endl ;
            if (check())
            {
                if (ans == "") ans = s;
                else if (s < ans) ans = s;            
            }        
        }
    char ch = s[idx];
    dfs(idx+1);
    s[idx] = '4';
    dfs(idx+1);
    s[idx] = '7';
    dfs(idx+1);
    s[idx] = ch;
    return;
}
int main()
{
    while (1){
    string ans = "";
    cin >>s1 >>s2;
    m = s2.length();
    s = string(m, '0') + s1;
    s1 = s;
    n = s.length();
    ans = "";
    cout <<s1 <<endl;
    dfs(0);
    int i = 0;
    while (ans[0] == '0') ans.erase(0, 1);
    cout <<ans <<endl;
}
    return 0;
}
