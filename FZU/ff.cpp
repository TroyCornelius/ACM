#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <time.h>
#include <cctype>
#include <functional>
#include <deque>
#include <iomanip>
#include <bitset>
#include <assert.h>
#include <numeric>
#include <sstream>
#include <utility>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(a) (a).begin(),(a).end()
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define FORD(i,a,b) for (int i=(a); i>=(b); i--)
#define REP(i,b) FOR(i,0,b)
#define sf scanf
#define pf printf
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;
string op;
typedef pair<int,string> pis;
map<string, int> d;
map<string, int> ft;
int main() 
{
    ios::sync_with_stdio(false);
    int T, ca = 0, ti;
    string s;
    cin >>T;
    while (T--)
    {
        ft.clear();
        d.clear();
        ti = 0;
        cout <<"Case "<<++ca <<":" <<endl;
        while (cin >>op)
        {
            if (op == "EXIT") break;
            if (op == "IN")
            {
                cin >>s;
                if (d.find(s) != d.end() && d[s] == 1) cout <<"Error" <<endl;
                else
                {
                    d[s] = 1;
                    if (ft.find(s) == ft.end()) ft[s] = ++ti;
                }
            }
            else
            if (op == "OUT")
            {
                cin >>s;
                if (d.find(s) == d.end())
                {
                    d[s] = 1;
                    if (ft.find(s) == ft.end()) ft[s] = ++ti;
                }
                int tmp = d[s];
                if (tmp != 1) cout <<"Error" <<endl;
                else
                {
                    tmp = 0;
                    d[s] = 0;
                }
            }
            else 
                if (op == "LIST")
                {
                    vector<pis> ans;
                    ans.clear();
                    for (map<string,int>::iterator it = d.begin(); it != d.end(); it++)
                    {
                        if (it->se == 1) ans.pb(pis(ft[it->fi], it->fi));
                    }
                    sort(all(ans));
                    for (vector<pis>::iterator it = ans.begin(); it != ans.end(); it++)
                        cout <<it->se <<endl;
                }
            
        }
    }
        return 0;
}
