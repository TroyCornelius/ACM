/*
 * Author:  Troy
 * Created Time:  2012/11/11 10:11:37
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

int n, m;
bool vis[15];
bool hash[11111*10];
string ans;
struct Tnode {
    int res;
    string s;
    Tnode() {}
    Tnode (int _res, string _s)
    :res(_res), s(_s){}
};
inline bool chk(int res) {
    while (res) {
        if (!vis[res%10]) return false;
        res /= 10;
    }
    return true;
}
string tostring(int num) {
    string ret = "";
    //cout <<num <<" ";
    if (num == 0) return "0";
    while (num) {
        char ch = '0' + num % 10;
        num /= 10;
        ret = ch + ret;
    }
    //cout <<ret <<endl;
    return ret;
}
bool bfs() {
    memset(hash, false, sizeof(hash));
    ans = "";
    queue<Tnode> que;
    REP(i, 10) {
        int tmp = i * n;
        if (vis[tmp%10]) {
            char ch = '0' + tmp%10;
            string ns = tostring(tmp%10);
            //cout <<ns <<" "<<tmp%10 <<endl;
            que.push(Tnode(tmp/10, ns));
            if (i > 0 && chk(tmp)) {
                ans = tostring(tmp);
                return true;
            }
        }
    }
    while (!que.empty()) {
        Tnode now = que.front();
        //cout <<now.res <<" "<<now.s <<endl;
        que.pop();
        if (ans != "" && now.s.size() >= ans.size()) break;
        REP(i, 10) {
            int tmp = i * n;
            if (vis[(now.res + tmp)%10]) {
                int nres = (now.res + tmp);
                if (!hash[nres]) {
                    hash[nres] = true;
                    char ch = '0' + nres%10;
                    string ns = tostring(nres%10) + now.s;
                    nres /= 10;
                    if  (i > 0 && chk(nres)) {
                        string t = tostring(nres) + ns;
                        //cout <<t <<" ----- " <<ans <<" "<<nres <<" "<<ns <<endl;
                        if (ans == "") ans = t;
                        else if (t.size() <= ans.size() && t < ans) ans = t;
                    }
                    que.push(Tnode(nres, ns));
                }
            }
        }
    }
    return ans != "";
}
string calc() {
    for (int i = 1; i <= n*n; i++)
        if (chk(i*n)) return tostring(i*n);
    return "-1";
}
int main() {
    int T = 1000;
    srand(time(NULL));
    //tostring(9999);
    while (T--) {
        n = rand()%100 + 1;
        m = rand()%10;
        //cin >>n >>m;
        //cout <<n <<" "<<m<<endl;
        int num;
        memset(vis, true, sizeof(vis));
        REP(i, m) {
            //cin >>num;
            num = rand()%10;
            vis[num] = false;
        }
        if (!bfs()) ans = "-1";
        cout <<ans <<endl;
        string my_ans = calc();
        if (ans != my_ans) {
            cout <<n <<" "<<m <<endl;
            REP(i, 10)
                if (!vis[i]) cout <<i <<" ";
            cout <<endl<<"-----------------" <<endl;
            cout <<ans <<" "<<my_ans <<endl;
            while (1);
        }
    }
    return 0;
}

