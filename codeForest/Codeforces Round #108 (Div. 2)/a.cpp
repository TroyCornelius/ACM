/*
 * Author:  Troy
 * Created Time:  2012/2/20 22:56:09
 * File Name: a.cpp
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
int n, m;
int mark[110][110];
int main() 
{
    char ch;
    cin >>n >>m;
    REP(i, n)
    {
        
        REP(j, m)
        {
            cin >>ch;
            mark[i][j] = ch - '0';
        }        
    }
    int ans = 0;
    bool flag ;
    REP(i, n)
    {
        REP(j, m)
        {
            flag = true;
            REP(k, n)
                if (i != k)
                {
                    if (mark[k][j] > mark[i][j]) {flag = false;break;}
                }
            if (flag) {ans++;break;}
        }    
    }
    cout <<ans <<endl;
    
    
    return 0;
}

