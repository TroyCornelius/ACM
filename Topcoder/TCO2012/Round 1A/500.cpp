/*
 * Author:  Troy
 * Created Time:  2012/4/1 0:38:28
 * File Name: 500.cpp
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
#include <functional>

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

bool b[1000];
vi p, num;
void init()
{
    memset(b, true, sizeof(b));
    for (int i=2; i<=300; i++)
        if (b[i])
        {
            p.pb(i);
            for (int j=i+i; j<=300; j+=i) b[j] = false;
        }
}
long long calc(int k)
{
    REP(i, p.size())
        if (k % p[i] == 0 && !b[p[i]]){ num.pb(p[i]); b[p[i]] = true;}
        else if (p[i] > k) break;
    int n = num.size();
    long long ret = (1LL <<(n-1)) ;
    //cout <<n <<" "<<k <<" "<<ret <<endl;
    return ret;
}
class EllysFractions
{
    public:
    long long getCount(int N)
    {
        init();
        num.clear();
        memset(b, false, sizeof(b));
        long long ans = 0;
        FOR(i, 2, N+1) {ans += calc(i); }
        return ans;
    }

}t;

int main() 
{
    cout <<t.getCount(1) <<endl;
    return 0;
}

