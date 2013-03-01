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
#define Maxn 200010
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

int h, m, n; 
long long ans;
bool table[Maxn];
map<int,int> id;
int main() 
{
    freopen("c.in", "r", stdin);
    freopen("c.out", "w", stdout);
    ios::sync_with_stdio(false);
    char op;
    int x, y;
    cin >>h >>m >>n;
    ans = 0;
    memset(table, 0, sizeof(table));
    while (n--)
    {
        cin >>op;
        if (op == '+')
        {
            cin >>x >>y;
            //cout <<endl <<y <<endl;
            while (table[y])
            {
                y = (y + m) % h;
                ans++;
                //cout <<ans <<" "<<y <<endl;
                
            }
            cout <<"-----------" <<endl;
            table[y] = true;
            id[x] = y;
            cout <<ans <<" "<< y <<endl;
        }
        else
        {
            cin >>x;
            table[id[x]] = false;
        }
    }
    cout <<ans <<endl;
    return 0;
}

