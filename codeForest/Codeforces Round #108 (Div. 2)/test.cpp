/*
 * Author:  Troy
 * Created Time:  2012/2/21 0:08:00
 * File Name: test.cpp
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

int main() 
{
    srand(time(NULL));
    freopen("d.in", "w", stdout);
    int n = 1000, m = 1000, a;
    cout <<n <<" "<<m <<endl;
    REP(i, n)
    {
        REP(j, m)
        {
            a = rand()%2;
            if (a == 1) cout <<"#";
            else cout <<".";
        }
        cout <<endl;
    
    }
    return 0;
}

