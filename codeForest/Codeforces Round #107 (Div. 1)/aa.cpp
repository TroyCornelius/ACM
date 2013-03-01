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
typedef vector<int> vi;
typedef vector<int>::iterator vit;

long long q;
vector<long long> cnt;
int main() 
{
    cin >>q;
    long long t = q;
    for (long long i = 2; i*i <= q; i++)
    if (q % i == 0)
    {
        int sum = 0;
        if (t < i) break;
        while (t % i == 0)
        {
            sum ++;
            t /= i;
        }
        if (sum > 0) cnt.pb(mp(i, sum));
    }
    //if (q != 1) cnt.pb(mp(q, 1));
    cout <<cnt.size() <<endl;
    REP(i, cnt.size()) cout <<cnt[i].fi <<" "<<cnt[i].se <<endl;
    if (cnt.size() == 0 || cnt.size() >= 2)
    {
        cout <<1 <<endl;
        if (cnt.size() == 0) cout <<0 <<endl;
        else cout <<(1LL*cnt[0].fi * cnt[1].fi) <<endl;
    }
    else cout <<2 <<endl;
    return 0;
}

