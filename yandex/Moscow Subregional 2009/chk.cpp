/*
 * Author:  Troy
 * Created Time:  2012/10/3 22:11:25
 * File Name: chk.cpp
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

int n, m, b, c, d;
int w[256];
char ch;
string s;

bool find_ans() {
    return false;
}
bool check() {
    if (s.length() > 4*(n+m)) return false;
    int x = 1, y = b;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'F') {
            x++;
            if (x > n) return false;
            if (ch == 'L' || ch == 'R') continue;
            else if (ch == 'F') return false;
            else if (ch == 'T') ch = 'F';
            else if (ch == 'B') ch = 'T';
        }
        else if (s[i] == 'B') {
            x--;
            if (x < 1) return false;
            if (ch == 'L' || ch == 'R') continue;
            else if (ch == 'B') return false;
            else if (ch == 'T') ch = 'B';
            else if (ch == 'F') ch = 'T';
        }
        else if (s[i] == 'L') {
            y--;
            if (y < 1) return false;
            if (ch == 'F' || ch == 'B') continue;
            else if (ch == 'L') return false;
            else if (ch == 'T') ch = 'L';
            else if (ch == 'R') ch = 'T';
        }
        else if (s[i] == 'R') {
            y++;
            if (y > m) return false;
            if (ch == 'F' || ch == 'B') continue;
            else if (ch == 'R') return false;
            else if (ch == 'T') ch = 'R';
            else if (ch == 'L') ch = 'T';
        }
        else return false;
    }
    return x == c && y == d;
}
int main() {
    ios::sync_with_stdio(false);
    freopen("d.out", "r", stdin);
    freopen("res.txt", "w", stdout);
    //freopen("res.txt", "w", stdout);
    w['T'] = 1; w['F'] = 2; w['B'] = 3; w['L'] = 4; w['R'] = 5;
    while (cin >>n >>m >>b >>c >>d) {
        cin >>ch;
        cin >>s;
        if (s == "IMPOSSIBLE") {
            if (find_ans()) {
                cout <<n <<" " <<m <<" "<<b <<" " <<c <<" "<<d <<" "<<ch <<" is wrong!" <<endl;
                cout <<s <<endl;
                while (1);
            }
        }
        else
            if (!check()) {
                cout <<n <<" " <<m <<" "<<b <<" " <<c <<" "<<d <<" "<<ch <<" is wrong!" <<endl;
                cout <<s <<endl;
                while (1);
            }
    }
    cout <<"zayhero" <<endl;
    return 0;
}

