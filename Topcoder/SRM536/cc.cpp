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
#include <iostream>
#include <map>

#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(a) (a).begin(),(a).end()
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define FORD(i,a,b) for (int i=(a); i>=(b); i--)
#define REP(i,b) FOR(i,0,b)
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
const double inf = 999999999.9;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

priority_queue<double> q;
int n, m;
vi d;
double ans, f[80], s[80];
class MergersDivTwo
{
    public:
    double findMaximum(vector <int> r, int k)
    {
        n = r.size();
        d = r;
        m = k;
        sort(all(r));
        REP(i, n+1) f[i] = -inf;
        s[0] = 0;
        REP(i, n) s[i+1] = s[i] + r[i];
        
        f[0] = 0;
        FOR(i, k, n+1)
        {
            FOR(j, k-1, i)
            {
                if (f[])
            }

        }
        cout <<f[n] <<endl;      
        return f[n];
    }

};


int main() 
{
    return 0;
}

