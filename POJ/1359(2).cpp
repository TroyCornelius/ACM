/*
 * Author:  Troy
 * Created Time:  2012/3/10 20:11:42
 * File Name: 1359.cpp
 */
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
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

int n, tot, ans, rec[110];
map<int,int> rid;
bool b[110];
struct Tnode
{
    int id, num;
    int ca, cb;
    bool ra, rb;
}d[110];
int add_id(int k)
{
    if (rid.find(k) == rid.end()) 
    {
         rid[k] = ++tot;
         rec[tot] = k;
         return tot;
    }
    else return rid[k];
}
int main() 
{
    int T;
    char ch1, ch2;
    cin >>T;
    while (T--)
    {
        tot = 0;
        rid.clear();
        cin >>n;
        REP(i, n)
        {
            cin >>d[i].num >>d[i].ca >>ch1 >>d[i].cb >>ch2;
            d[i].ra = (ch1 == 'Y' ? true : false);
            d[i].rb = (ch2 == 'Y' ? true : false);
            d[i].id = add_id(d[i].num);
            d[i].ca = add_id(d[i].ca);
            d[i].cb = add_id(d[i].cb);
        }
        ans = -1;
        bool flag;
        FOR(i, 1, tot+1)
        {
            flag = true;
            memset(b, true, sizeof(b));
            REP(j, n)
            {
                if (d[j].id == i) continue;
                if (!b[d[j].ca] && d[j].ra) {flag = false; break;}
                b[d[j].ca] = d[j].ra;
                if (!b[d[j].cb] && d[j].rb) {flag = false; break;}
                b[d[j].cb] = d[j].rb;
            }
            if (!flag) continue;
            int tmp = -1;
            FOR(j, 1, tot+1)
            {
                if (!b[j])
                {
                    if (j != i) {flag = false; break;}
                }
            }
            if (!flag || b[i]) continue;
            if (ans == -1) ans = i;
            else
            {
                printf("impossible\n");
                return 0;
            }
        }
        if (ans == -1) printf("impossible\n");
        else printf("%d\n", rec[ans]);
        
    }
    return 0;
}

