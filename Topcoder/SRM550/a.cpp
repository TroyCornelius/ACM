/*
 * Author:  Troy
 * Created Time:  2012/7/22 0:07:23
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
const int inf = 1<<29;


struct Line
{
    pii p1, p2;
    Line(){}
    Line(pii a, pii b)
    {
        p1 = a; p2 = b;
    }
};
const int dx[] = {1,0,-1,0};
const int dy[] = {0,1,0,-1};
bool check(vector<Line> d, Line t)
{
if (d.size() > 1) {
    REP(i, d.size()-1)
    {
        if (d[i].p1.se == d[i].p2.se)
        {
            int x1 = min(t.p1.fi, t.p2.fi), x2 = max(t.p1.fi, t.p2.fi);
            int yy = min(t.p1.se, t.p2.se), y2 = max(t.p1.se, t.p2.se);
            if (x1 >= min(d[i].p1.fi, d[i].p2.fi) && x2 <= max(d[i].p1.fi, d[i].p2.fi))
            {
                if (yy <= d[i].p1.se && y2 >= d[i].p1.se) return false;
            }
        }
        else
        if (d[i].p1.fi == d[i].p2.fi)
        {
            int x1 = min(t.p1.fi, t.p2.fi), x2 = max(t.p1.fi, t.p2.fi);
          //  int yy = min(t.p1.se, t.p2.se), y2 = max(t.p1.se, t.p2.se);
            if (x1 <= d[i].p1.fi && x2 >= d[i].p1.fi)
            {
                if (t.p1.se >= min(d[i].p1.se, d[i].p2.se) && t.p1.se <= max(d[i].p1.se, d[i].p2.se))
                    return false;
            }            
        }
    }
    }
    return true;
}
class RotatingBot
{
    public:
    int minArea(vector <int> moves)
    {
        vector<Line> d;
        d.pb(Line(mp(0,0), mp(moves[0], 0)));
        int dir = 1, k = 0;
        pii ansx, ansy;
        ansx = mp(moves[0], 0);
        ansy = mp(0, 0);
        
        FOR(i, 1, moves.size())
        {
            Line now;
            now.p1 = d[k].p2;
            now.p2 = mp(d[k].p2.fi + moves[i] * dx[dir], d[k].p2.se + moves[i] * dy[dir]);
            cout <<now.p1.fi <<" "<<now.p1.se <<"---" <<now.p2.fi <<" "<<now.p2.se <<endl;
            dir = (dir + 1) % 4;
            if (moves[i] == 0) continue;
            if (check(d, now))
            {
                d.pb(now);
                k++;
                ansx.fi = max(now.p2.fi, ansx.fi);
                ansx.se = min(now.p2.fi, ansx.se);
                ansy.fi = max(now.p2.se, ansy.fi);
                ansy.se = min(ansy.se, now.p2.se);
            } 
            else return -1;
        }
        cout <<ansx.fi <<" " <<ansx.se  <<" "<<ansy.fi << " "<<ansy.se <<endl;
        return (ansx.fi - ansx.se + 1) * (ansy.fi - ansy.se + 1);
    }
    
};


