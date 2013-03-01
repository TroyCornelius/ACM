/*
 * Author:  Troy
 * Created Time:  2012/4/29 13:33:00
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
    freopen("k.in", "w", stdout);
    srand(time(NULL));
    int T = 10;
    cout <<T <<endl;
    while (T--)
    {
        int n = rand()%10 + 1;
        cout <<n <<endl;
        REP(i, n)
        {
            int num = rand()%1000 + 1;
            cout <<num <<" ";
        }
        cout <<endl;
        int m = rand()%10+1;
        cout <<m <<endl;
        REP(i, m)
        {
            int a = rand()%n + 1;
            int b = rand()%n + 1;
            int c = rand()%1000 + 1;
            if (a > b) swap(a, b);
            cout <<a <<" "<<b <<" " <<c <<endl;
        }
    }
    return 0;
}

