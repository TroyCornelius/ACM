/*
 * Author:  Troy
 * Created Time:  2012/4/2 13:38:31
 * File Name: h.cpp
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

struct Tnode
{
    int bel;
    vi rev;
}aut[1024];
int k, n, m, cnt;
map<string,int> ins;
void init()
{
    ins.clear();
    m = 0;
    REP(i, n+1)
    {
        aut[i].rev.clear();
        aut[i].bel = -1;
    }
}
int main() 
{
    ios::sync_with_stdio(false);
    string corp;
    int num;
    while (cin >>k >>n)
    {
        init();
        if (!k && !n) break;
        REP(i, n)
        {
            cin >>corp;
            if (ins.find(corp) == ins.end())
            {
                ins[corp] = ++m;
            }
            aut[i].bel = ins[corp];
            REP(j, k)
            {
                cin >>num;
                num--;
                aut[num].rev.pb(i);                
            }
        }
        cnt = 0;
        REP(i, n)
        {
            if (aut[i].rev.size() != k) cnt++;
            else
            {
                sort(all(aut[i].rev));
                bool flag = true;
                REP(j, k)
                {
                    if (aut[i].bel == aut[aut[i].rev[j]].bel)
                    {
                        flag = false;
                        cnt++;
                        break;
                    }
                }
                if (!flag) continue;
                FOR(j, 1, k)
                    if (aut[i].rev[j] == aut[i].rev[j-1])
                    {
                        cnt++;
                        break;
                    }
            }
        }
        if (cnt == 0) cout <<"NO PROBLEMS FOUND" <<endl;
        else if (cnt == 1) cout <<"1 PROBLEM FOUND" <<endl;
        else cout <<cnt <<" PROBLEMS FOUND" <<endl;
    }
    return 0;
}

