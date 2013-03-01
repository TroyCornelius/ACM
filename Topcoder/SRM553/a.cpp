/*
 * Author:  Troy
 * Created Time:  2012/8/23 9:33:57
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


void push(long long x) {
    stk[top++] = x;
}
long long get_top() {
    if (top == 0) return 0;
    else {
        return stk[top-1];
    }
}
long long go(vi pro,  int val) {
    top = 0;
    REP(i, pro.size()) {
        int num = pro[i];
        if (num == -1) num = val;
        if (num == 0) {
            long long a = get_top();
            if (top > 1) top--;
            long long b = get_top();
            if (top > 1) top--;
            push(a+b);
        }
        else push(num);
    }
    return get_top();

}
class Suminator {
    public :int findMissing(vector <int> program, int wt) {
                if (go(program, 0) == wt) return 0;
                long long ans = go(program, -1);
                if (ans >= wt - 1) return -1;
                else return wt - 1  - ans;
            }
};




int main() 
{
    return 0;
}

