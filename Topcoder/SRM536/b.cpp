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


class RollingDiceDivTwo
{
    public:
    int minimumFaces(vector <string> rolls)
    {
        int n = rolls[0].length();
        vi ret(n+2);
        REP(i, n) ret[i] = 0;
        REP(i, rolls.size())
        {
            vi tmp;
            tmp.clear();
            REP(j, rolls[i].length()) tmp.pb(rolls[i][j] - '0');
            sort(all(tmp));
            REP(j, tmp.size())
                if (tmp[j] > ret[j]) ret[j] = tmp[j];            
        }
        int ans = 0;
        REP(i, n) ans += ret[i];
        return ans;
        
    }
};

int main() 
{
    return 0;
}

