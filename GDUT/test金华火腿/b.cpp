/*
 * Author:  Troy
 * Created Time:  2012/5/2 20:10:28
 * File Name: b.cpp
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
const int sum[] = {25, 18, 15, 12, 10, 8, 6, 4, 2, 1,0};
int n, m, k;
struct Tnode
{
    int cnt[110], pt;
    string name;
}a[1100];
map<string,int> id;

bool cmp1(Tnode a1, Tnode b1)
{
    if (a1.pt != b1.pt) return a1.pt > b1.pt;
    else
    {
        REP(i, 51)
            if (a1.cnt[i] != b1.cnt[i]) return a1.cnt[i] > b1.cnt[i];
    }
    return true;
}
bool cmp2(Tnode a1, Tnode b1)
{
    if (a1.cnt[0] != b1.cnt[0]) return a1.cnt[0] > b1.cnt[0];
    else
    {
        if (a1.pt != b1.pt) return a1.pt > b1.pt;
        else
        {
            FOR(i, 1, 51)
                if (a1.cnt[i] != b1.cnt[i]) return a1.cnt[i] > b1.cnt[i];
        }
    }
    return true;
}
int main() 
{
    int T;
    string s;
    cin >>T;
    m = 0;
    k = T;
    REP(i, 1001) 
    {
        memset(a[i].cnt, 0, sizeof(a[i].cnt));
        a[i].pt = 0;
        a[i].name.clear();
    }
    id.clear();
    while (T--)
    {
        cin >>n;
        REP(i, n)
        {
            cin >>s;
            if (id.find(s) == id.end()) id[s] = m++;
            int pid = id[s];
            a[pid].name = s;
            if (i < 10) a[pid].pt += sum[i];
            a[pid].cnt[i]++;
        }        
    }
    //cout <<a[0].pt <<" "<<a[0].name <<endl;
    sort(a, a+m, cmp1);
    cout <<a[0].name <<endl;
    sort(a, a+m, cmp2);
    cout <<a[0].name <<endl;
    return 0;
}

