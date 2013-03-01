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
#define all(a) (a).begin(),(a).end()
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define Maxn 10100
#define FOR(i,a,b) for (int i(a); i<(b); i++)
#define REP(i, b) FOR(i,0,b)
using namespace std;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
const int inf = 1<<29;
typedef pair<int,int> pii;
typedef vector<int>::iterator vit;

vector <string> cu, now, d;
int n, m, r, c;
bool check(int x, int y)
{
     if (x+r > n || y+c > m) return false;
     FOR(i, x, x+r)
       FOR(j, y, y+c)
       {
           if (cu[i-x][j-y]=='.' && d[i][j]=='X') return false;  
           if (cu[i-x][j-y]=='.' && now[i][j]=='.') return false;            
       }
     return true;    
     
}
bool f()
{
     REP(i, n)
       REP(j, m)
       if (now[i][j] != d[i][j]) return false;
     return true;     
}
class GogoXCake
{
    public:
    string solve(vector <string> cake, vector <string> cutter)
    {
         d = cake; cu = cutter;
         n = cake.size(), m = cake[0].length();
         r = cutter.size(), c = cutter[0].length();
        // cout <<n <<" "<<m <<" "<<r <<" "<<c <<endl;
        REP(i, n) now.pb(string(m, 'X'));
     //   REP(i, n) cout <<now[i] <<endl;
     //   REP(i, n) cout <<d[i] <<endl;
        REP(i, n)
        {
            REP(j, m)
            {
                  // cout <<i<<" "<<j <<endl;
                   if (check(i, j))
                   {
                          //      cout <<i<<" "<<j <<endl;
                       FOR(x, i, i+r)
                         FOR(y, j, j+c)
                         if (cutter[x-i][y-j]=='.') now[x][y] = '.';    
                         REP(i, n) cout <<now[i] <<endl;                            
                   }                   
            }               
        }
        cout <<endl;
        REP(i, n) cout <<now[i] <<endl;
        string ans;
        if (f())  ans = "YES";
        else ans =  "NO";
        return ans;
    }


} t;

int main()
{
    vector<string> a, b;
    a.pb("X.X");
    a.pb("...");
    a.pb("...");
    a.pb("X.X");
    b.pb(".");
    cout <<t.solve(a, b) <<endl;;
    
    system("pause");
    
    return 0;
    }
