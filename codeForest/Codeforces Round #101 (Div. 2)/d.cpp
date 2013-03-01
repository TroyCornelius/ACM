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
#define Maxn 200100
#define FOR(i,a,b) for (int i(a); i<(b); i++)
#define REP(i, b) FOR(i,0,b)
using namespace std;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int>::iterator vit;

vector<int> b;
int n, L, m;
struct Tnode
{
    int xi, di, ti, pi;
    Tnode(){}
    Tnode(int _a, int _b, int _c, int _d)
    :xi(_a), di(_b), ti(_c), pi(_d){}        
}p[Maxn];
int main()
{
    int xi, di, ti, pi;
    m = 0;
    scanf("%d%d", &n, &L);
    REP(i, n)
    {
        scanf("%d%d%d%d", &p[i].xi, &p[i].di, &p[i].ti, &p[i].pi);
        if (p[i].xi - p[i].pi>=0) b.pb(p[i].xi-p[i].pi);
        if (p[i].xi+p[i].di <= L) b.pb(p[i].xi+p[i].di);
    }
    b.pb(0); b.pb(L);
    b.erase(unqiue(b.begin(), b.end()), b.end());
    sort(b.begin(), b.end());
    //p[m++] = Tnode(0, 0, 0);
    //p[m++] = Tnode(L, 0, 0);
    
    return 0;
}
