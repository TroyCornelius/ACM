/*
 * Author:  Troy
 * Created Time:  2012/11/5 0:25:29
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

int n, q;
string s, ss;
vi ans;
int main() 
{
    cin >>n >>q;
    cin >>s; 
    while(q--) {
        ans = vi(10);
        ss = s;
        int lt, rt;
        cin>>lt>>rt;
        lt--, rt--;
        int cp = lt, dp = 1;
        while(true) {
            if(cp < lt || cp > rt) break;
            if(ss[cp] == '-') cp += dp;
            else if(ss[cp] >= '1' && ss[cp] <= '9') {
                int x = ss[cp] - '0';
                ans[x]++;
                x--;
                ss[cp] = x + '0';
                cp += dp;
            } 
            else if(ss[cp] == '0') {
                ans[0]++;
                ss[cp] = '-';
                cp += dp;    
            }
            else {
                int pre = cp;
                if(ss[cp] == '>') dp = 1;
                else dp = -1;
                bool f = 0;
                while(1) {
                    cp += dp;
                    if(cp < lt || cp > rt) {f = 1; break;}
                    if(ss[cp] == '-') continue;
                    if(ss[cp] == '>' || ss[cp] == '<') ss[pre] = '-';
                    break; 
                }
                if(f) break;
            }
        }
        for(int i = 0; i < 10; i++) printf("%d ", ans[i]);
        printf("\n");
    }
    return 0;
}

