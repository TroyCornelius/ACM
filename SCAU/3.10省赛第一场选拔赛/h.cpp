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
#include <functional>
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

int n;
struct Res
{
    int id, ca, cb, num;
    bool ra, rb;    
}d[110];
bool b[110];
int tot, rec[110];
map<int,int> rid;
int main() 
{
    int T;
    char c1, c2;
    scanf("%d", &T);
    while (T--)
    {
        rid.clear();
        tot = 0;
        scanf("%d", &n);
        REP(i, n)
        {
            scanf("%d %d %c %d %c", &d[i].num, &d[i].ca, &c1, &d[i].cb, &c2);
            d[i].ra = (c1 == 'Y');
            d[i].rb = (c2 == 'Y');
            if (rid.find(d[i].num) == rid.end()) rid[d[i].num] = ++tot, rec[tot] = d[i].num;
            if (rid.find(d[i].ca) == rid.end()) rid[d[i].ca] = ++tot, rec[tot] = d[i].ca;
            if (rid.find(d[i].cb) == rid.end()) rid[d[i].cb] = ++tot, rec[tot] = d[i].cb;
        }
        REP(i, n)
        {
            d[i].id = rid[d[i].num];
            d[i].ca = rid[d[i].ca];
            d[i].cb = rid[d[i].cb];
        }
        int ans = -1;
        FOR(i, 1, tot+1)
        {
            memset(b, false, sizeof(b));
            bool flag = true;
            REP(j, n)
            {
                if (d[j].id == i) continue;
                if (b[d[j].ca] && !d[j].ra) {flag = false;break;}
                b[d[j].ca] = d[j].ra;
                if (b[d[j].cb] && !d[j].rb) {flag = false;break;}
                b[d[j].cb] = d[j].rb;
            }
            if (!flag) continue;
            int tmp = -1;
            FOR(j, 1, tot+1)
            {
                if (!b[j])
                {
                    if (tmp == -1) tmp = j;
                    else {flag = false; break;}
                }
            }
            if (!flag || i != tmp || b[i] || tmp == -1) continue;
            else
            {
                if (ans != -1 && tmp != ans)
                {
                    printf("impossible\n");
                    return 0;
                }
                else ans = tmp;
            }
        }
        if (ans == -1) printf("impossible\n");
        else printf("%d\n", rec[ans]);
    }
    return 0;
}

