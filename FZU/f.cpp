/*
 * Author:  Troy
 * Created Time:  2012/4/15 13:56:23
 * File Name: f.cpp
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
string op;
typedef pair<int,string> pis;
map<string, int> rec;
set<string> vis;
set<pis> d;
int main() 
{
    ios::sync_with_stdio(false);
    int T, ca = 0, ti;
    string s;
    cin >>T;
    while (T--)
    {
        rec.clear();
        d.clear();
        vis.clear();
        ti = 0;
        cout <<"Case "<<++ca <<":" <<endl;
        while (cin >>op)
        {
            if (op == "EXIT") break;
            if (op == "IN")
            {
                cin >>s;
                if (rec[s] >= 1) cout <<"Error" <<endl;
                else
                {
                    rec[s]++;
                    d.insert(pis(++ti, s));
                    vis.insert(s);
                }
            }
            else
            if (op == "OUT")
            {
                cin >>s;
                if (vis.find(s) == vis.end())
                {
                    vis.insert(s);
                    rec[s] = 0;
                }
                else
                {
                    if (rec[s] - 1 < 0) cout <<"Error" <<endl;
                    else rec[s]--;
                }
            }
            else 
                if (op == "LIST")
                {
                    for (set<pis>::iterator it = d.begin(); it != d.end(); it++)
                    {
                        string t = it ->se;
                        if (rec[t] == 1) cout << t<<endl;
                    }                   
                }
        }
    }
    return 0;
}
