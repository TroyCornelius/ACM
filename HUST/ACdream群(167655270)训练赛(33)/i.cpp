/*
 * Author:  Troy
 * Created Time:  2012/5/18 19:11:10
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

int a, b;
inline int solve(int x)
{
    int ret = 0;
    while (x > 0)
    {
        ret += x % 10;
        x /= 10;
    }
    return ret;
}
int gao(int x)
{
    return x == 0 ? 0 : x-1 - (x-1)/3;
}
int main() 
{
    int T, ca = 0;
 /*   
    int s = 0, cnt = 0;
    FOR(i, 1, 100)
    {
        s += solve(i);
        if (s % 3 == 0) cnt++;
        cout <<"The " <<i <<" is : " <<cnt <<endl;
    }*/
    
    
    cin >>T;
    while (T--)
    {
        cin >>a >>b;
        cout <<"Case " <<++ca  <<": " <<gao(b) - gao(a-1) <<endl;
        
    }
        
    return 0;
}

