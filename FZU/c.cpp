/*
 * Author:  Troy
 * Created Time:  2012/4/15 13:35:06
 * File Name: c.cpp
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

string name[] = {"lzs", "v11", "shadow"};
int n, ans[3], tot;

queue<string> que[3]; 
int main() 
{
    ios::sync_with_stdio(false);
    int T, ca = 0;
    cin >>T;
    while (T--)
    {
        cin >>n;
        memset(ans, -1, sizeof(ans));
        REP(i, 3) 
        {
            while (!que[i].empty()) que[i].pop();
        }
        int p;
        string op, s;
        tot = 0;
        REP(i, n)
        {
            cin >>p >>op;
            if (op == "IN")
            {
                cin >>s;
                que[p].push(s);
            }
            else
            {
                if (!que[p].empty())
                {
                    string now = que[p].front();
                    que[p].pop();
                    ++tot;
                    REP(j, 3)
                        if (now == name[j]) ans[j] = tot;
                }                
            }
        }
        cout <<"Case " <<++ca <<":" <<endl;
        REP(i, 3)
        {
            cout <<name[i]<<":" ;
            if (ans[i] == -1) cout <<"Unknown" <<endl;
            else cout <<ans[i] <<endl;
        }
    }
    return 0;
}

