/*
 * Author:  Troy
 * Created Time:  2012/7/22 1:00:30
 * File Name: aa.cpp
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

const int dx[] = {1,0,-1,0};
const int dy[] = {0,1,0,-1};

class RotatingBot
{
    public:
    int minArea(vector <int> mo)
    {
        pii ansx = mp(0,0);
        pii ansy = mp(0,0);
        pii now = mp(0,0);
        int dir = 0;
        if (mo.size() < 4)
        {
            REP(i, mo.size())
            {
                now.fi = now.fi + mo[i] * dx[dir];
                now.se = now.se + mo[i] * dy[dir];
                dir = (dir + 1) % 4;
                ansx.fi = max(now.fi, ansx.fi);
                ansx.se = min(now.fi, ansx.se);
                ansy.fi = max(now.se, ansy.fi);
                ansy.se = min(ansy.se, now.se);
            }
            return (ansx.fi - ansx.se + 1) * (ansy.fi - ansy.se + 1);
        }
        else
        {
            ansx = mp(mo[0], mo[0] - mo[2]);
            ansy = mp(mo[1], mo[1] - mo[3]);
            if (ansx.fi > 0 || ansy.se > 1) return -1;
            if (ansx.se == 0 && (ansy.se <= 0 || ansy.se > 1)) return -1;
            else
            {
                int ret = (ansx.fi - ansx.se + 1) * (ansy.fi - ansy.se + 1);
                now = mp(mo[0] - mo[2], mo[1] - mo[3]);
                if (ansy.se == 0) ansx.fi = 0;
                else if (ansy.se < 0)
                {
                    ansx.fi++;
                    ansy.fi = 0;
                }
                
                FOR(i, 4, mo.size())
                {
                    now.fi = now.fi + mo[i] * dx[dir];
                    now.se = now.se + mo[i] * dy[dir];
                    if (dir == 0)
                    {
                        if (now.fi != ansx.fi - 1 || (i == mo.size() && now.fi >= ansx.fi)) return -1;
                        else ansx.fi--;
                    }
                    else if (dir == 1)
                    {
                        if (now.se != ansy.fi - 1 || (i == mo.size() && now.se >= ansy.fi)) return -1;
                        else ansy.fi--;
                    }
                    else if (dir == 2)
                    {
                        if (now.fi != ansx.se + 1 || (i == mo.size() && now.fi <= ansx.se)) return -1;
                        else ansx.se++;
                    }
                    else if (dir == 3)
                    {
                        if (now.se != ansy.se + 1 || (i == mo.size() && now.se <= ansy.se)) return -1;
                        else ansy.se++;
                    }
                    dir = (dir + 1) % 4;
                }
                return ret;

            }
        }

    }
};



int main() 
{
    return 0;
}

