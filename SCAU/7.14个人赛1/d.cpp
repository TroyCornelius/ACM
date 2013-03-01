/*
 * Author:  Troy
 * Created Time:  2012/7/14 14:47:46
 * File Name: d.cpp
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
#include <cctype>
#include <functional>
#include <deque>
#include <iomanip>


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

int n;
int fa[100];
struct point{int x,y;};
struct segment{point p1,p2;};
segment d[100];
int mul(point p1,point p2,point p3)
{
    return (p2.x-p1.x)*(p3.y-p2.y)-(p3.x-p2.x)*(p2.y-p1.y);
}
bool cross(segment s1,segment s2)
{
     if(min(s1.p1.x,s1.p2.x)>max(s2.p1.x,s2.p2.x)||max(s1.p1.x,s1.p2.x)<min(s2.p1.x,s2.p2.x)) return false;
     if(min(s1.p1.y,s1.p2.y)>max(s2.p1.y,s2.p2.y)||max(s1.p1.y,s1.p2.y)<min(s2.p1.y,s2.p2.y)) return false;
     if(mul(s1.p1,s1.p2,s2.p1)*mul(s1.p1,s1.p2,s2.p2)<=0&&mul(s2.p1,s2.p2,s1.p1)*mul(s2.p1,s2.p2,s1.p2)<=0) return true;
     return false;
}

int find(int x)
{
    if (fa[x] == x) return x;
    else return fa[x] = find(fa[x]);
}
int main() 
{
    while (~sf("%d", &n), n)
    {
        REP(i, n+5) fa[i] = i;
        REP(i, n) sf("%d%d%d%d", &d[i].p1.x, &d[i].p1.y, &d[i].p2.x, &d[i].p2.y);
        REP(i, n)
            REP(j, n)
            if (i != j)
            {
                if (cross(d[i], d[j]))
                {
                    int f1 = find(i), f2 = find(j);
                    if (f1 != f2) fa[f1] = f2;
                }
            }
        int a, b;
        while (sf("%d%d", &a, &b))
        {
            if (!a && !b) break;
            a--; b--;
            if (find(a) == find(b)) pf("CONNECTED\n");
            else pf("NOT CONNECTED\n");
        }
    }
    
    return 0;
}

