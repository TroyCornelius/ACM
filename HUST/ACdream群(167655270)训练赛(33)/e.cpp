/*
 * Author:  Troy
 * Created Time:  2012/5/18 19:30:13
 * File Name: e.cpp
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
#define sf scanf
#define pf printf
#define Maxn 100000000
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

int n;
bool b[Maxn+10];
vi p;
void init()
{
    memset(b, true, sizeof(b));
    FOR(i, 2, Maxn)
        if (b[i])
        {
            p.pb(i);
            for (int j = i+i; j<=Maxn; j+=i) b[j] = false;
        }
    cout <<p.size() <<endl;
}
int main() 
{
    int T, ca = 0;
    init();
    
    return 0;
}

