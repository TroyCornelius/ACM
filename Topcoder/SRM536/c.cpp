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
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

priority_queue<double> q;
int n, m;
vi d;
double ans;
void dfs(int idx, double &ret)
{
    double tmp = 0.0;
    if (idx - (m-1) + 1 >= m)
    {
        dfs(idx - (m-1), ret);
        FORD(i, idx, idx-(m-1)+1) tmp += double(d[i]);
        tmp += ret;
        tmp /= (double)(m);
        ret = tmp;
        return;
    }
    else
    {
        FORD(i, idx, 0) tmp += (double)d[i];
        tmp = tmp / (double(idx+1));
        ret = tmp;
        return;
    }
    
}
class MergersDivTwo
{
    public:
    double findMaximum(vector <int> r, int k)
    {
        n = r.size();
        d = r;
        m = k;
        sort(all(d));
        dfs(n-1, ans);
        return ans;
    }

};


int main() 
{
    return 0;
}

