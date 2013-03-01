/*
 * Author:  Troy
 * Created Time:  2012/2/17 23:30:41
 * File Name: 
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
typedef pair<long long,int> pii;
typedef vector<long long> vi;
typedef vector<int>::iterator vit;

long long q;
vector<long long> cnt;
bool b[10000100];
vi p;
int main() 
{
    cin >>q;

    memset(b, true, sizeof(b));
    for (long long i=2; i<=10000000; i++)
    if (b[i])
    {
        p.pb(i);
        for (long long j = i+i; j<=10000000; j+= i) b[j] = false;
    }
    REP(i, p.size())
    {
        if (q % p[i] == 0)
        {
            while (q % p[i] == 0)
            {
                q /= p[i];
                cnt.pb(p[i]);
            }
        }
    }
    if (q > 1) cnt.pb(q);
   // cout <<cnt.size() <<endl;
    if (cnt.size() == 0 || cnt.size() > 2 || cnt.size() == 1)
    {
        cout <<1 <<endl;
        if (cnt.size() == 1 || cnt.size() == 0) cout <<0 <<endl;
        else cout <<(1LL*cnt[0] * cnt[1]) <<endl;
    }
    else cout <<2 <<endl;
    return 0;
}


