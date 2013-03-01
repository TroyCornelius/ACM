/*
 * Author:  Troy
 * Created Time:  2012/12/12 20:19:01
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
#define ll long long
#define sf scanf
#define pf printf
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

class AlternateColors {

    public:
    string get_ans(int id) {
        if (id == 0) return "RED";
        else if (id == 1) return "GREEN";
        else return "BLUE";
    }
    string getColor(long long r, long long g, long long b, long long k) {
        long long num[3] = {r, g, b};
        while (true) {
            if (!num[0] && !num[1] && !num[2]) break;
            int cnt = 0;
            long long mi = max(r, max(g, b));
            REP(i, 3) {
                if (num[i] != 0) {
                    cnt++;
                    mi = min(mi, num[i]);
                }
            }
            if (cnt * mi >= k) {
                k %= cnt;
                if (k == 0) k = cnt;
                for (int i = 0, tot = 0; i < 3; i++) {
                    if (num[i]) tot++;
                    if (tot == k) return get_ans(i);
                }
            }
            else {
                k -= 1LL * cnt * mi;
                REP(i, 3)
                    if (num[i] != 0) num[i] -= mi;
            }
        }
    }
};


int main() 
{
    return 0;
}

