/*
 * Author:  Troy
 * Created Time:  2012/12/6 23:32:18
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

int n, k;
int q[110], tar[110];
int cur[110];

void move1() {
    int tmp[110];
    FOR(i, 1, n+1) {
        tmp[i] = cur[q[i]];
    }
    memcpy(cur, tmp, sizeof(tmp));
}
void move2() {
    int tmp[110];
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
    int tmp[110], b[110];
    FOR(i, 1, n+1) tmp[i] = i;
    FOR(i, 1, n+1) {
        b[i] = tmp[q[i]];
    }
    FOR(i, 1, n+1)
        if (b[i] != tar[i]) return false;
    return true;
}
bool is_same1() {
    int tmp[110], b[110];
    FOR(i, 1, n+1) tmp[i] = i;
    FOR(i, 1, n+1) {
        b[q[i]] = tmp[i];
    }
    FOR(i, 1, n+1)
        if (b[i] != tar[i]) return false;
    return true;
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
    //cout <<need <<endl;
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
        //cout <<"..." <<is_same1() << " "<<(need == 1) << " "<<(k > 1) <<endl;
    //cout <<need <<" "<<k <<" "<<is_same1() <<" "<<(need == 1 && (k > 1) && is_same1() ) <<endl;
    if ((need == 1 && k > 1 && is_same1()) || (need == 0) || (need == -1)) {
        //cout <<"damn "<<endl;
        if (check2()) cout <<"YES" <<endl;
        else cout <<"NO" <<endl;
    }
    else {
        //cout <<"..." <<is_same1() << " "<<(need == 1) << " "<<(k > 1) <<endl;
        if ((k - need) % 2 == 0) cout <<"YES" <<endl;
        else {
            if (!check2())cout <<"NO" <<endl;
            else cout <<"YES" <<endl;
        }
    }
    return 0;
}

