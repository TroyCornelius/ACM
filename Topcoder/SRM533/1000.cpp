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

#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(a) (a).begin(),(a).end()
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define FORD(i,a,b) for (int i=(a); i>=(b); i--)
#define REP(i,b) FOR(i,0,b)
#define Maxn 100100
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

struct Tnode
{
    int d, g;
    double w;
    bool operator<(const Tnode &b) const
    {
        return (d < b.d || (d == b.d && w > b.w));
    }
}a[60];
double f[55];
class MagicalGirl
{
    public:
    double maxExpectation(int M, vector <int> day, vector <int> win, vector <int> gain)
    {
        int n = day.size();
        REP(i, n)
        {
            a[i+1].d = day[i];
            a[i+1].w = double(win[i]) / 100.0;
            a[i+1].g = gain[i];
        }
        sort(a+1, a+n+1);
        a[0].d = 1;
        f[0] = 1;
        double ans = 0.0;
        int now = M - 1;
        FOR(i, 1,n+1)
        {
            int tmp =  a[i].d - a[i-1].d;
            if (now - tmp <= 0) 
            {
                ans += f[i-1] * (a[i-1].d + now);
                break;
            }
            
            
        }
        return ans;
    }
    
};
int main() 
{
    return 0;
}

