/*
 * Author:  Teletubbies
 * Created Time:  2012年09月15日 星期六 14时24分16秒
 * File Name: 1003.cpp
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
const int INT_MAX = -1u>>1;
string a, b;
string s, t;
pair<string, string> rule[30];
int tot;

const int MOD = 1870667;

bool bhash[MOD];
char vhash[MOD][110];
char str[110];
int goal;
int cal_str() {
    int i = 0, pos = 0, j = 1;
    for(; str[i]; i++, j = (j * 27) & INT_MAX, pos &= INT_MAX) {
        int num = str[i];
        pos += j * num;
    }
    return pos % MOD;
}

bool find_hash(int &pos) {
    pos = cal_str();
    for(; bhash[pos]; pos = (pos + 1) % MOD) {
        if(strcmp(vhash[pos], str) == 0) return true;
    }
    return false;
}
int make_hash() {
    int pos;
    if(!find_hash(pos)) {
        bhash[pos] = true;
        strcpy(vhash[pos], str);
    }
    return pos;
}

void dfs1(string a, int len) {
    if(len == goal) {
        strcpy(str, a.c_str());
        make_hash();
        return;
    }
    for(int i = 0; i < tot; i++) {
        for(int j = 0; j < len - 1; j++) {
            if(rule[i].fi[0] == a[j] && rule[i].fi[1] == a[j+1]) {
                string tmp = a;
                tmp.replace(j, 2, rule[i].se);
                dfs1(tmp, len - 1);
            }
        }
    }
    return;
}
bool dfs2(string a, int len) {
    if(len == goal) {
        strcpy(str, a.c_str());
        int pos;
        if(find_hash(pos)) return true;
        else return false;
    }
    for(int i = 0; i < tot; i++) {
        for(int j = 0; j < len; j++) {
            if(rule[i].se[0] == a[j]) {
                string tmp = a;
                tmp.replace(j, 1, rule[i].fi);
                if(dfs2(tmp, len + 1)) return true;
            }
        }
    }
    return false;
}

int main() 
{
    //freopen("C.in", "r", stdin);
    //freopen("C2.out", "w", stdout);
    
    ios::sync_with_stdio(false);
    int T, Case = 0;
    cin >> T;
    while(T--) {
        tot = 0;
        while(cin >> a) {
            if(a == "$") break;
            cin >> b;
            rule[tot++] = mp(b, a);
        }
        cout << "Test case: " << Case++ << endl;
        while(cin >> t) {
            if(t == "#") break;
            cin >> s;
            if(s == t) {
                cout << "Derive \""<< s <<"\" from \"" << t << "\"? YES! (trivially)"<< endl;
                continue;
            }
            cout << "Derive \""<< s <<"\" from \"" << t << "\"?";
            memset(bhash, false, sizeof(bhash));
            goal = s.length() / 2;
            dfs1(s, s.length());
            if(dfs2(t, 1)) {
                cout << " YES!" << endl;
            } else {
                cout << " NO!" << endl;
            }
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}

