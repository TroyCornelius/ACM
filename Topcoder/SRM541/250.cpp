/*
 * Author:  Troy
 * Created Time:  2012/4/23 22:52:00
 * File Name: 250.cpp
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

/*
bool check(int x1, int y1, int x2, int y2, char d1, int d2)
{
    int t1 = 0, t2 = 0;
    if (d1 == 'N')
    {
        if (d2 == 'S') return (x1 == x2 && y2 > y1 && (y2 - y1) % 2 == 0);
        else 
            if (d2 == 'E') return (x2 < x1 && y2 > y1 && (y2 - y1) == (x1 - x2));
            else if (d2 == 'W') return (x2 > x1 && y2 > y1 && (y2 - y1) == (x2 - x1));
    }
    else
    if (d1 == 'E')
    {
        if (d2 == 'W') return (y1 == y2 && y1 < y2 && (y2 - y1) % 2 == 0);
        else if (d2 == 'N') return (x2 > x1 && y1 > y2 && (y1 - y2) == (x2 - x1));
        else if (d2 == 'S') return (x1 < x2 && y1 < y2 && (y2 - y1) == (x2 - x1));
    }
    else
    if (d1 == 'W')
    {
        if (d2 == ')
    }
}*/
const int dx[] = {1,-1,0,0};
const int dy[] = {0,0,1,-1};
class AntsMeet
{
    public:
    int countAnts(vector <int> x, vector <int> y, string dir)
    {
        int n = x.size(), ans = 0;
       /* REP(i, n)
        {
            REP(j, n)
                if (i != j && dir[i] != dir[j])
                {
                    if (check(x[i], y[i], x[j], y[j], dir[i], dir[j])) 
                    {
                        ans++;
                        break;
                    }
                }
        }*/
        REP(i, n) x[i] <<=1, y[i] <<=1;
        char c[256];
        c[int('E')] = 0; c[int('W')] = 1; c[int('N')] = 2; c[int('S')] = 3;
        REP(i, 4010)
        {
            REP(j, n)
            if (x[j] != -9999)
            {
                int op = c[int(dir[j])];
                x[j] += dx[op]; y[j] += dy[op];
            }
            REP(j, n)
            if (x[j] != -9999)
            {
                bool flag = false;
                REP(k, n)
                    if (j != k && x[k] != -9999 && x[j] == x[k] && y[j] == y[k])
                    {
                        flag = true;
                        x[k] = y[k] = -9999;
                    } 
                if (flag) x[j] = y[j] = -9999;
            }
        }
        REP(i, n) 
            if (x[i] != -9999) ans++;
        return ans;
    }

};
int main() 
{
    return 0;
}

