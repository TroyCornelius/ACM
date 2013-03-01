/*
 * Author:  Troy
 * Created Time:  2012/6/24 15:26:47
 * File Name: make.cpp
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
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

int main() 
{
    freopen("b.in", "w", stdout);
    
    srand(time(NULL));
    int T = 5;
    pf("%d\n", T);
    while (T--)
    {
        int n = rand() % 10000 + 1;
        pf("%d\n", n);
        int op, x;
        while (n--)
        {
            op = rand()%2;
            x = rand() - 10000000;
            if (op == 0) pf("add %d\n", x);
            else pf("remove %d\n", x);
        }
    }
    
    return 0;
}

