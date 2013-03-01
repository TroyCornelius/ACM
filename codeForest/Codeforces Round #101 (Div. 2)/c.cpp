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
typedef pair<int,int> pii;
typedef vector<int>::iterator vit;

vector<pii> d;
int n;
string name[Maxn];


void work()
{
    vector<pii> m;
    int h = 100000000, i;
    for (i=0; i<n; i++)
    {
        if (d[i].fi == 0) m.pb(mp(d[i].se, h));
        else break;    
    }
    
    while (i < n)
    {
        int j;
        for (j = i+1; j<n; j++)
            if (d[j].fi != d[i].fi) break;        
        
        j--;
        h--;
        if (m.size() < d[i].fi) 
        {
            cout <<-1<<endl;
            return;        
        }
        vector<pii> tmp;
        REP(k, d[i].fi) tmp.pb(m[k]);
        FOR(k, i, j+1) tmp.pb(mp(d[k].se, h));
        for (int k=d[i].fi; k<m.size(); k++) tmp.pb(m[k]);
        m = tmp;
        i = j+1;    
    }
    REP(i, n)
    {
        cout <<name[m[i].fi] <<" " <<m[i].se <<endl;
    }


}
int main()
{
    //while (1){
    string s;
    cin >>n;
    d.clear();
    REP(i, n)
    {
        int x;
        cin >>s >>x;
        name[i] = s;
        d.pb(mp(x, i));        
    }
    sort(d.begin(), d.end());
    work();
//}

    return 0;
}
