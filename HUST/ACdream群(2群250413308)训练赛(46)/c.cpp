/*
 * Author:  Troy
 * Created Time:  2012/7/28 19:31:35
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
#define Maxn 1000100
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

int A, B;
bool b[Maxn];
vi p;
void init()
{
    memset(b, true, sizeof(b));
    FOR(i, 2, 1000001)
    if (b[i])
    {
        p.pb(i);
        for (int j = i+i; j <= 1000000; j+=i) b[j] = false;
    }
}
int main() 
{
    init();
    int cas = 0;
    int x, dis, ca, cb;
    while (cin >>A >>B, A+B)
    {
        x = 0;
        dis = 0;
        ca = cb = 0;
        REP(i, p.size())
        {
            ca = cb = 0;
            bool flag = false;
            while (A % p[i] == 0)
            {
                ca++;
                A /= p[i];
                flag = true;
            }
            while (B % p[i] == 0)
            {
                cb++;
                B /= p[i];
                flag = true;
            }
            if (flag) x++;
            dis += abs(ca - cb);
            if (A == 1 && B == 1) break;            
        }
        cout <<++cas <<". " <<x <<":" <<dis <<endl;
        
            
    }
    return 0;
}

