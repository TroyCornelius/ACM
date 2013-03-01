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
stack<pair<pii,int> > stk;
int ans;
//string out;
pii out;
/*
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
*/
int main() {
    ios::sync_with_stdio(false);
    cin >>s;
    ans = -1; 
    //out = "";
    out = mp(0, -1);
    REP(i, s.size()) {
        if (s[i] == '(') stk.push(mp(mp(i,i), -1));
        else if (s[i] == '[') stk.push(mp(mp(i, i), -1));
        else if (s[i] == ']') {
            if (stk.empty()) continue;
            //if (stk.top().se >= 0) {
            //pair<string,int> tt = stk.top();
            //stk.pop();
            pair<pii, int> tt = mp(mp(i, i-1), 0);
            if (!stk.empty() && stk.top().se >= 0) {
                tt = stk.top();
                stk.pop();
            }
            if (!stk.empty()) {
                if (s[stk.top().fi.fi] == '[') {
                    //tt.fi = "[" + tt.fi + "]";
                    tt.fi = mp(tt.fi.fi-1, tt.fi.se + 1);
                    tt.se++;
                    stk.pop();
                    while (!stk.empty() && stk.top().se >= 0) {
                        //tt.fi = stk.top().fi + tt.fi;
                        tt.fi = mp(stk.top().fi.fi, tt.fi.se);
                        tt.se += stk.top().se;
                        stk.pop();
                    }
                    stk.push(tt);
                    //cout <<tt.fi <<" "<<tt.se <<endl;
                }
                else {
                    while (!stk.empty()) {
                        if (stk.top().se > ans) {
                            ans = stk.top().se;
                            out = stk.top().fi;
                        }
                        stk.pop();
                    }
                }
            }
            else {
                if (tt.se > ans) {
                    ans = tt.se;
                    out = tt.fi;
                }
            }
                        
        }
        else if (s[i] == ')') {
            if (stk.empty()) continue;
            //if (stk.top().se >= 0) {
                //pair<string,int> tt = stk.top();
                //stk.pop();
            pair<pii, int> tt = mp(mp(i, i-1), 0);
            if (!stk.empty() && stk.top().se >= 0) {
                tt = stk.top();
                stk.pop();
            }
            if (!stk.empty()) {
                if (s[stk.top().fi.fi] == '(') {
                    //tt.fi = "(" + tt.fi + ")";
                    tt.fi = mp(tt.fi.fi-1, tt.fi.se+1);
                    //tt.se++;
                    stk.pop();
                    while (!stk.empty() && stk.top().se >= 0) {
                        //tt.fi = stk.top().fi + tt.fi;
                        tt.fi = mp(stk.top().fi.fi, tt.fi.se);
                        tt.se += stk.top().se;
                        stk.pop();
                    }
                    stk.push(tt);
                }
                else {
                    while (!stk.empty()) {
                        if (stk.top().se > ans) {
                            ans = stk.top().se;
                            out = stk.top().fi;
                        }
                        stk.pop();
                    }
                }
            }
            else {
                if (tt.se > ans) {
                    ans = tt.se;
                    out = tt.fi;
                }
            }
        }
        }

        while (!stk.empty()) {
            //cout <<stk.top().fi <<" "<<stk.top().se <<endl;
            if (stk.top().se > ans) {
                ans = stk.top().se;
                out = stk.top().fi;
            }
            stk.pop();
        }

        if (ans == -1) cout <<0 <<endl<<endl;
        else {
            cout <<ans <<endl;
            //cout <<out <<endl;
            cout <<s.substr(out.fi, out.se-out.fi+1) <<endl;
        }

        return 0;
        }

