/*
 * Author:  Troy
 * Created Time:  2012/6/10 23:44:56
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

int n, m;
struct basket
{
    int id, cnt;
    basket() {}
    basket(int _a, int _b)
    :id(_a), cnt(_b){}
    bool operator<(const basket b) const
    {
        if (cnt != b.cnt) return cnt > b.cnt;
        else
        {
            int l1 = abs((m+1)/2 - id), l2 = abs((m+1)/2 - b.id);
            if (l1 != l2) return l1 > l2;
            else return id > b.id;
        }
    }
    
};
priority_queue<basket> h;
int main() 
{
    ios::sync_with_stdio(false);
    cin >>n >>m;
    FOR(i, 1, m+1) h.push(basket(i, 0));
    
    REP(i, n)
    {
        basket now = h.top();
        h.pop();
        cout <<now.id <<endl;
        now.cnt++;
        h.push(now);
    }
    return 0;
}

