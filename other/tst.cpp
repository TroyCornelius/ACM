/*
 * Author:  Troy
 * Created Time:  2012/3/13 21:07:24
 * File Name: test (2).cpp
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
    int x;
    string s = "";
    while (~scanf("%x", &x))
    {
        if (x == 0) break;
    /*    //cout <<x <<endl;
        int tmp = 255 - x;
        if (tmp >= 128) tmp -= 128;
        else tmp += 128;
        printf("%c\n", tmp);*/
        //oprintf("%c\n", x);
        s += char(x);
    }
    cout <<s <<endl;
    return 0;
}

