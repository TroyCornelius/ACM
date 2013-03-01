/*
 * Author:  Teletubbies
 * Created Time:  2012年10月22日 星期一 14时40分20秒
 * File Name: k.cpp
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

int n, k, Q;
string d[4010];
vector<string> text;
map<string, bool> ig;
map<string, int> pw;
map<pair<string,string>, int> cw;
int tot_w, tot_p;
void work() {
    text.clear();
    string s = "";
    REP(i, n) {
        REP(j, d[i].size()) {
            if (isalpha(d[i][j])) s += tolower(d[i][j]);
            else {
                if (s != "") {
                    if (ig.find(s) == ig.end())
                        text.pb(s);
                }
                s = "";
            }
        }
    }
}
void calc() {
    tot_w = tot_p = 0;
    REP(i, text.size()) {
        pw[text[i]] += 1;
        tot_w++;
        if (i != text.size() - 1) {
            string sa = text[i];
            string sb = text[i+1];
            if (sa > sb) swap(sa, sb);
            tot_p++;
            cw[mp(sa, sb)] += 1;
        }
    }
}
int main() {
    //cout <<isalpha('A') <<" "<<isalpha(' ') <<endl;
    ios::sync_with_stdio(false);
    string s;
    cin >>n;
    getline(cin, s);
    REP(i, n) getline(cin, d[i]);
    cin >>k;
    ig.clear();
    REP(i, k) {
        cin >>s;
        ig[s] = true;
    }
    work();
    calc();
    cin >>Q;
    string sa, sb;
    while (Q--) {
        cin >>sa >>sb;
        if (sa > sb) swap(sa, sb);
        double pab = 1.0 * cw[mp(sa, sb)] / tot_p;
        double pa = 1.0 * pw[sa] / tot_w;
        double pb = 1.0 * pw[sb] / tot_w;
        cout <<fixed <<setprecision(8) <<pab/(pa * pb) <<endl;
    }
    return 0;
}

