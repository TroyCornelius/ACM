/*
 * Author:  Troy
 * Created Time:  2012/12/1 10:17:59
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



bool bw[55][55], b[55][55];
int n, m;

void get_new() {
    memset(b, false, sizeof(b));
    FOR(i, 1, n)
        FOR(j, 1, m)
        b[i-1][j-1] = bw[i][j];
    memset(bw, false, sizeof(bw));
    memcpy(bw, b, sizeof(b));
    //REP(i, n) {
    	//REP(j, m) cout <<bw[i][j];
    	//cout <<endl;
    //}
}
bool check() {
    FOR(i, 1, n)
        FOR(j, 1, m)
        if (bw[i][j] != b[i-1][j-1]) return false;
    return true;
}
void get_b() {
    memset(b, false, sizeof(n));
    FOR(i, 1, n)
        FOR(j, 1, m)
        b[i-1][j-1] = bw[i][j];
}
class PastingPaintingDivTwo {
    
    public:

    long long countColors(vector <string> cli, int T) {
        memset(bw, false, sizeof(bw));
        n = cli.size(), m = cli[0].size();
        long long ans = 0;
        int cnt;
        REP(i, n)
            REP(j, m)
            if (cli[i][j] == 'B') bw[i][j]  = true, ans++;
            //cout <<ans <<endl;
        if (T == 1) return ans;
        else {
            cnt = 0;
            T--;
            //cout <<T <<" "<<ans <<" "<<cnt <<endl;
            while (T--) {
                get_new();
                cnt = 0;
                REP(i, n)
                    REP(j, m)
                    if (cli[i][j] == 'B') {
                        if (!bw[i][j])
                            bw[i][j] = true, cnt++;
                    }
                ans += cnt;
                //cout <<cnt <<" "<<T <<" "<<ans <<endl;
                if (check()) {
                //cout <<cnt <<" "<<T <<" "<<ans <<endl;
                    ans += 1LL * T * cnt;
                    break;
                }
                //else get_b();
            }
        }
        return ans;
    }


};






