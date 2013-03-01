/*
 * Author:  Troy
 * Created Time:  2012/6/24 23:49:53
 * File Name: 
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

struct team
{
    int points, goal, miss;
    int played;
    string name;
}d[6];
map<string,int> nid; 
bool cmp(const team &a, const team &b)
{
    if (a.points != b.points) return a.points > b.points;
    else
    {
        int s1 = (a.goal - a.miss);
        int s2 = (b.goal - b.miss);
        if (s1 != s2) return  s1 > s2;
        else if (a.goal != b.goal) return a.goal > b.goal;
        else return a.name < b.name;
    }
}


pii work()
{
    int ber, op;
    REP(i, 4)
        if (d[i].name == "BERLAND")
        {
            ber = i;
            break;
        }
    REP(i, 4)
        if (i != ber && d[i].played == 2)
        {
            op = i;
            break;
        }
    
    //string op_name = d[op].name;
    team tmp[6];
    pii ret(-1, -1);
    int ansx = -1, ansy = -1;
    REP(x, 1001)
        REP(y, x)
        {
            REP(i, 4) tmp[i] = d[i];

            int id1 = ber, id2 = op;
            tmp[id1].goal += x; tmp[id1].miss += y;
            tmp[id2].goal += y; tmp[id2].miss += x;
            //tmp[id1].played++; tmp[id2].played++;
            tmp[id1].points += 3;
            //else if (x == y) tmp[id1].points++, tmp[id2].points++;
            //else tmp[id2].points++;

            sort(tmp, tmp+4, cmp);
            int nrank;
            REP(i, 4)
                if (tmp[i].name == "BERLAND") nrank = i;
            if (nrank <= 1)
            {
                if (ansx == -1)
                {
                    ansx = x; ansy = y;
                    ret = mp(x, y);
                }
                else
                {
                    if (x - y < ansx - ansy)
                    {
                        ansx = x; ansy = y;
                        ret = mp(x, y);
                    }
                    else
                        if (x - y == ansx - ansy && y < ansy)
                        {
                            ansx = x; ansy = y;
                            ret = mp(x, y);
                        }
                }
            }
        }
    return ret;
}
int main() 
{
    int n = 0;
    nid.clear();
    REP(i, 5)
        d[i].points = d[i].goal = d[i].miss = d[i].played = 0;
    string s1, s2;
    char ch;
    int x, y;
    REP(i, 5)
    {
        cin >>s1 >>s2 >>x >>ch >>y;
        if (nid.find(s1) == nid.end()) d[n].name = s1, nid[s1] = n++;
        if (nid.find(s2) == nid.end()) d[n].name = s2, nid[s2] = n++;

        int id1 = nid[s1], id2 = nid[s2];
        d[id1].goal += x; d[id1].miss += y;
        d[id2].goal += y; d[id2].miss += x;
        d[id1].played++; d[id2].played++;
        if (x > y) d[id1].points += 3;
        else if (x == y) d[id1].points++, d[id2].points++;
        else if (x < y) d[id2].points += 3;
    }

    sort(d, d+4, cmp);
    //REP(i, 4)
    //{
        //cout <<d[i].name <<" "<<d[i].points <<" "<<d[i].goal <<" "<<d[i].miss <<" "<<d[i].played<<endl;
    //}
    pii ans = work();
    
    if (ans.fi == -1) cout <<"IMPOSSIBLE" <<endl;
    else cout <<ans.fi <<":" <<ans.se <<endl;
    return 0;
}

