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
#define FOR(i,a,b) for (int i(a); i<(b); i++)
#define REP(i, b) FOR(i,0,b)
using namespace std;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
const int inf = 1<<29;
typedef pair<int,int> pii;
typedef vector<int>::iterator vit;
typedef pair<string, pii > psi;

const string num[50]={"I","II","III","IV","V","VI","VII","VIII","IX","X","XI","XII","XIII","XIV","XV","XVI","XVII","XVIII","XIX","XX","XXI","XXII","XXV","XXIX","XXX","XXXI","XXXIV","XXXV","XXXIX","XL","L","L","L","L","L","L","L","L","L","L","L","L","L","L","L","L","L","L","L","L"};
bool cmp(psi a, psi b)
{
     return (a.fi < b.fi) || (a.fi == b.fi && a.se.fi < b.se.fi);
     }
class KingSort
{
      public:      
      vector <string> getSortedList(vector <string> kings)
      {
             vector<string> ret;
             vector<psi> d;
             REP(i, kings.size())
             {
                    string st = kings[i], s1, s2;
                    int loc = st.find(" ", 0), tmp;
                    s1 = st.substr(0, loc);
                    s2 = st.substr(loc+1, st.length()-loc-1);
                    
                    tmp = 0;
                    REP(j, 50)
                    {
                           if (s2 == num[j]) {tmp = j+1;break;}                           
                    }
                   // cout <<s1 <<" "<<s2 <<" " <<tmp <<endl;
                    d.pb(mp(s1, mp(tmp, i)));                    
             }     
             sort(d.begin(), d.end(), cmp);
             REP(i, d.size()) ret.pb(kings[d[i].se.se]);
             return ret;
      }      
      }tt;
int main()
{
    vector<string> t;
    string s1, s2;
    int n;
    while (1){
          t.clear();
          cin >>n;
          for (int i=0; i<n; i++)
          {
              cin >>s1 >>s2;
              t.pb(s1+" "+s2);
          }
          vector<string> a = tt.getSortedList(t);
          REP(i, a.size()) cout <<a[i]<<endl;
          }
    return 0;
    }
