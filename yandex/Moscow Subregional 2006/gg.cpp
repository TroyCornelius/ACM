#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <cctype>
#include <functional>
#include <assert.h>

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

char t[41000], ans[1010011];
int main() {
    while (~sf("%s", t)) {
        int len = strlen(t);
        int now = 0, p = 0, fs = 0;
        int cnt = 0, sum = 0;
        ans[0] = '0';
        if (len == 1 && t[0] == '0') {pf("0\n");continue;}
        while (p < len) {
            ans[now] = '0';
            if (t[p] == '0') {
                cnt = 0;
                while (p < len && t[p] == '0') p++, cnt++;
                if (p >= len) cnt--;
                if (fs == now) now++;
                while (sum - cnt < 0) {
                    if (ans[fs] >= '7') fs = now, ans[now] = '0', now++;
                    if (ans[fs] == '0') ans[fs] = '2', sum++;
                    else ans[fs]++, sum++;
                }
                if (p >= len) cnt++;
                while (cnt) ans[now++] = '0', cnt--, sum--;
            }
            else {
                ans[now++] = t[p];
                sum += t[p] - '0' - 1;
                ans[now] = '0';
                p++;
            }
        }
        while (sum > -1) ans[now++] = '0', sum--; 
        ans[now] = '\0';
        puts(ans);
    }
    return 0;
}


/*
020100
3020100
*/

