/*
 * Author:  Troy
 * Created Time:  2012/7/27 23:07:13
 * File Name: Candies.cpp
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
#define Maxn 110000
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;
int n, d[Maxn];
struct Tnode
{
    int loc, val;
    Tnode(){}
    Tnode(int _loc, int _val)
        :loc(_loc), val(_val){}
    bool operator<(const Tnode &b)const
    {
        return val > b.val;
    }
};
priority_queue<Tnode> h;
int cnt[Maxn];
int main() 
{
    long long ans;
    while (cin >>n)
    {
        ans = 0;
        REP(i, n) cin >>d[i];
        memset(cnt, -1, sizeof(cnt));
        while (!h.empty()) h.pop();
        REP(i, n) h.push(Tnode(i, d[i]));
        while (!h.empty())
        {
            Tnode now = h.top();
            h.pop();
            int tmp = 1;
            if (now.loc - 1 >= 0 && cnt[now.loc-1] != -1 && d[now.loc-1] < d[now.loc]) tmp = max(tmp, cnt[now.loc-1]+1);
            if (now.loc + 1 < n && cnt[now.loc+1] != -1 && d[now.loc+1] < d[now.loc]) tmp = max(tmp, cnt[now.loc+1]+1);
            cnt[now.loc] = tmp;
            ans += tmp;
        }
        cout <<ans <<endl;
    }
    return 0;
}
