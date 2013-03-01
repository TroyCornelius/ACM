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

char t[41000], ans[3010011];
int main() {
    //freopen("g.in", "r", stdin);
    //freopen("g.txt", "w", stdout);
    while (~sf("%s", t)) {
        int len = strlen(t);
        int now = 1, p = 0, fs = 0;
        int cnt = 0;
        ans[0] = 's';
        while (p < len) {
            assert(t[p] >= '0' && t[p] <= '7');
            if (t[p] == '0') {
                cnt = 0;
                while (p < len && t[p] == '0') p++, cnt++;
                if (p < len) cnt++; //留一个s给下一个非0用
                //cout <<cnt <<endl;
                while (now - fs + 6 <= cnt) {
                    ans[fs++] = '7';
                    REP(j, 7) ans[now++] = 's';
                }
                //cout <<now <<" "<<fs <<" "<<cnt <<endl;
                if (now - fs < cnt) {
                    int tmp = cnt - (now - fs);
                    tmp++;
                    assert(tmp >= 2 && tmp <= 7);
                    ans[fs++] = '0'+tmp;
                    REP(j, tmp) ans[now++] = 's';
                }
                if (p < len) cnt--;
                REP(j, cnt) ans[fs++] = '0';
            }
            else {
                ans[fs++] = t[p];
                REP(j, (int)(t[p]-'0')) ans[now++] = 's';
                p++;
           }
        }
        assert(now <= 8*len);
        REP(i, now)
            if (ans[i] == 's') ans[i] = '0';
        
        int p1 = 0, p2 = 0;
        now--;
        /*
        while (p2 < now) {
            while (p1 < len && p2 < now && (ans[p2] == t[p1] || t[p2] == '7')) p1++, p2++;
            if (p2 < now && ans[now] == '0') {
                ans[p2]++;
                now--;
            }
            else break;
        }*/
        ans[++now] = '\0';
        puts(ans);
        //cout << strlen(s) << endl;
    }
    return 0;
}


/*
020100
3020100
*/

