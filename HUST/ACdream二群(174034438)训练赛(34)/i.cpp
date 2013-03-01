/*
 * Author:  Troy
 * Created Time:  2012/5/25 20:52:30
 * File Name: i.cpp
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
#define FOR(i,a,b) for (long i=(a);i<(b);i++)
#define FORD(i,a,b) for (long i=(a); i>=(b); i--)
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
/*
void f(long &x, long &y)
{
    if (x > 0 && y > 0)
    {
        for (int i = 1; i<=x+y; i++)
        {
            y = x*x + y;
            x = x*x + y;
            y = (int)sqrt(x + (y / abs(y)) * (-abs(y)));
            for (int j = 1; j<= y+y; j++) x -= y;
        }
    }
}*/int main() 
{
    long long x, y;
    /*//while (cin >>x >>y)
    {
        FOR(i, 1, 11){
            FOR(j, 1, 11)
            {
                x = i, y = j;
        f(x, y);
        cout <<x <<" "<<y <<" | ";
        //if (x == i && y == j) cout <<1 <<" | ";
        //else cout <<0 <<" | ";
            }
        cout <<endl;}
    }*/
    while (cin >>x >>y)
    {
        if (x > 0 && y > 0){
        if (x % 2 == 1)
        {
            if (y % 2 == 0) cout <<y <<" "<<x <<endl;
            else cout <<x <<" "<<y <<endl;
        }
        else
        {
            if (y % 2 == 1) cout <<y <<" "<<x <<endl;
            else cout <<x <<" "<<y <<endl;
        }
        }
        else cout <<x <<" "<<y <<endl;
            
    }
    return 0;
}

