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
#define Maxn 101000
#define FOR(i,a,b) for (int i(a); i<(b); i++)
#define REP(i, b) FOR(i,0,b)
using namespace std;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
const int inf = 1<<29;
typedef pair<int,int> pii;
typedef vector<int>::iterator vit;

int w, b;
double f[1010][1010][2];

void dfs(int cw, int cb, int who)
{
    if (!cw || !cb) return ;
    if (who == 1)
    {
        double p1 =  (1.0*cw/double(cw+cb));
        double p2 = 1.0 - p1;
        f[cw-1][cb][0] += f[cw][cb][1] * p1; dfs(cw-1, cb, 0);
        f[cw][cb-1][0] += f[cw][cb][1] * p2; dfs(cw, cb-1, 0);    
    }
    else
    {
        double p1 = 1.0 * cw / double(cw+cb);
        if (cw - 1 > 0)
        {
            double t1 = 1.0 * (cw-1)/double(cw-1+cb);
            double t2 = 1.0 * (cb-1)/double(cw+cb-1);
            f[cw-2][cb][1] += f[cw][cb][0]*p1*t1; dfs(cw-2, cb, 1);  
            f[cw-1][cb-1][1] += f[cw][cb][0]*p1*t2; dfs(cw-1, cb-1, 1);      
        }
        else
        if (cw - 1 == 0)
        {
            f[cw-1][cb-1][1] += f[cw][cb][0]*p1; 
            return ;        
        }
        
        if  (cb - 1 > 0)
        {
            double t1 = 1.0*(cw)/(cw+cb-1);
            f[cw-1][cb-1][1] += f[cw][cb][0]*(1.0-p1)*t1; dfs(cw-1, cb-1, 1);
            f[cw][cb-2][1] += f[cw][cb][0]*(1.0-p1)*(1.0-t1); dfs(cw, cb-2,1);
        }
        else
        if (cb - 1 == 0)
        {
            f[cw-1][cb-1][1] += f[cw][cb][0] * p1;        
            return;
        }        
    }

}
int main()
{
    while (1){
    
    cin >>w >>b;
    memset(f, 0, sizeof(f));
    
    f[w][b][1] = 1.0;
    dfs(w, b, 1);
    
    double ans = 0.0;
    
    for (int i=w; i>0; i--)
        for (int j=b; j>=0; j--)
        {
            cout <<f[i][j][0] << " "<<f[i][j][1] * (1.0 * (i)/(i+j)) <<endl;
            ans += f[i][j][1] * (1.0 * (i)/(i+j));
        }
    
    printf("%.10f\n", ans);
    
    
    }   
    return 0;
}
