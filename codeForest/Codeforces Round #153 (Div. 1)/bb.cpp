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
#include <deque>
#include <iomanip>

#define all(a) (a).begin(),(a).end()
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define FORD(i,a,b) for (int i=(a); i>=(b); i--)
#define REP(i,b) FOR(i,0,b)

using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

int n, k;
int q[120], tar[120];
int cur[120];

void move1() {
    int tmp[120];
    FOR(i, 1, n+1) {
        tmp[i] = cur[q[i]];
    }
    memcpy(cur, tmp, sizeof(tmp));
}
void move2() {
    int tmp[120];
    FOR(i, 1, n+1) {
        tmp[q[i]] = cur[i];
    }
    memcpy(cur, tmp, sizeof(tmp));
}
bool check() {
    FOR(i, 1, n+1)
        if (cur[i] != tar[i]) return false;
    return true;
}
bool is_same2() {
    int tmp[120];
    FOR(i, 1, n+1) tmp[i] = i;
    move1();
    return check();
}
bool is_same1() {
    int tmp[120];
    FOR(i, 1, n+1) tmp[i] = i;
    move2();
    return check();
}
bool check2() {
    FOR(i, 1, n+1) cur[i] = i;
    int need = -1;
    REP(i, k+1) {
        if (check()) {
            need = i;
            break;
        }
        else {
            move2();
        }
    }
    if (need == -1 || (need == 1 && k > 1 && is_same2()) || need == 0) return false;
    else {
        if ((k - need) % 2 == 0) return true;
        else return false;
    }
}
int main() {
    cin >>n >>k;
    FOR(i, 1, n+1) cin >>q[i];
    FOR(i, 1, n+1) cin >>tar[i];
    FOR(i, 1, n+1) cur[i] = i;
    int need = -1;
    REP(i, k+1) {
        if (check()) {
            need = i;
            break;
        }
        else {
            move1();
        }
    }
    if (need == -1 || (need == 1 && k > 1 && is_same1()) || need == 0) {
        if (check2()) cout <<"YES" <<endl;
        else cout <<"NO" <<endl;
    }
    else {
        if ((k - need) % 2 == 0) cout <<"YES" <<endl;
        else {
            if (!check2())cout <<"NO" <<endl;
            else cout <<"YES" <<endl;
        }
    }
    return 0;
}


