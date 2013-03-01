/*
 * Author:  Troy
 * Created Time:  2012/9/16 23:27:36
 * File Name: a.cpp
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
const int inf = 1<<29;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

string s;
stack<pair<char,int> > stk;
int ans;
//string out;
pii out;
void calc(int &sum, pii &tmp) {
    if (sum > ans) {
        ans = sum;
        //out = st;
        out = tmp;
    }
    sum = 0;
    tmp = mp(inf, -1);
    //st.clear();
    //out = tmp;
    while (!stk.empty()) stk.pop();
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin >>s;
    ans = -1; 
    int sum = 0;
    //string st = "";
    pii tmp = mp(inf,-1);
    REP(i, s.size()) {
        if (s[i] == '(' || s[i] == '[') stk.push(mp(s[i], i));
        else {
            //cout <<stk.top().fi <<" "<<s[i] <<endl;
            if (s[i] == ']') {
                if (!stk.empty()) {
                    if (stk.top().fi == '[') {
                        tmp = mp(min(tmp.fi, stk.top().se), i);
                        stk.pop();
                        sum++;
                        if (sum > ans) {
                            ans = sum;
                            out = tmp;
                        }
                        //st = "[" + st + "]";
                    }
                    else {
                        calc(sum, tmp);
                    }
                }else {
                    continue;
                    //calc(0, "");
                    calc(sum, tmp);
                }
            }
            else if (s[i] == ')') {
                if (!stk.empty()) {
                    if (stk.top().fi == '(') {
                        tmp = mp(min(tmp.fi, stk.top().se), i);
                        stk.pop();
                    }
                    else {
                        calc(sum, tmp);
                    }
                }
                else {
                    calc(sum, tmp);
                }
            }
        }
    }
    if (stk.empty()) calc(sum, tmp);
    
    cout <<ans <<endl;
    if (out.fi > out.se) cout <<endl;
    else cout <<s.substr(out.fi, out.se-out.fi+1) <<endl;
    //cout <<out <<endl;
    
    return 0;
}

