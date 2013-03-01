/*
 * Author:  Troy
 * Created Time:  2012/5/13 12:46:47
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
#define sf scanf
#define pf printf
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

string s;
int ans = 0;
int main() 
{
    while (cin >>s)
    {
        ans = 0;
        if (s[1] == 'A') ans += 4;
        else if (s[1] == 'K') ans += 3;
        else if (s[1] == 'Q') ans += 2;
        else if (s[1] == 'J') ans++;
        REP(i, 12)
        {
            cin >>s;
            if (s[1] == 'A') ans += 4;
            else if (s[1] == 'K') ans += 3;
            else if (s[1] == 'Q') ans += 2;
            else if (s[1] == 'J') ans++;
        }
        cout <<ans <<endl;
    }
    return 0;
}

