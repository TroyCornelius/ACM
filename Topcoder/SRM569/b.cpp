/*
 * Author:  Troy
 * Created Time:  2013/2/7 11:02:40
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

long long d[55];
int n, k;
class TheJediTest {
    public:
    int calc(int mid) {
        REP(i, n) d[i] = d[i];
        REP(i, mid) {
            if (d[i] < k) {
                int tmp = min(k - d[i], d[i+1]);
                d[i] += tmp;
                d[i+1] -= tmp;
            }
            else if (d[i] > k) {
                d[i+1] += d[i] - k;
                d[i] = k;
            }
        }
        for (int i = n-1; i > mid; i--) {
            if (d[i] < k) {
                int tmp = min(k - d[i], d[i+1]);
                d[i] += tmp;
                d[i+1] -= tmp;
            }
            else if (d[i] > k) {
                d[i+1] += d[i] - k;
                d[i] = k;
            }
        }        
        int ret = 0;
        REP(i, n) {
            ret += d[i] / k;
            if (d[i] % k != 0) ret++;
        }
        return ret;
            
    }
    int minimumSupervisors(vector <int> stu, int K) {
        n = stu.size();
        k = K;
        int ans = 1<<30;
        for (int i = 0; i < n; i++) {
            REP(j, n) d[i] = stu[i];
            ans = min(ans, calc(i));
        }
        return ans;
        
    }
};

int main() {
    return 0;
}

