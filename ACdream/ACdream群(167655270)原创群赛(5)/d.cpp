/*
 * Author:  Troy
 * Created Time:  2012/12/7 19:20:14
 * File Name: d.cpp
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
#define Maxn 1000100
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

int m, n;
char str[Maxn*2], s[Maxn];
int p[Maxn*2];
void pk() {
    int id, mx=0;
    //memset(p, 0, sizeof(p));
    for (int i=1; i<n; i++) {  //下标从1开始 {
        p[i] = mx>i ? min(p[2*id-i], mx-i):1;
        while (str[i+p[i]] == str[i-p[i]]) p[i]++;
        if (p[i]+i > mx) {
            mx = p[i]+i;
            id = i;                    
        } 
    }
}
void init() {
    str[0]='$'; str[1] = '#';  //str[0]放越界 
    for (int i=0; i<n; i++) {
        str[i*2+2] = s[i];
        str[i*2+3] = '#';          //相邻之间加特殊符号 
    }
    n = n*2+2;
    str[n] = 0;     
}
int main() {
    while (~sf("%s", s)) {
        n = strlen(s);
        init();
        pk();
        sf("%d", &m);
        char op[3], ch[3];
        int x, y;
        while (m--) {
            sf("%s", op);
            if (op[0] == 'Q') {
                sf("%d%d", &x, &y);
                x--; y--;
                int len = y - x + 1;
                if (len & 1) {
                    int mid = (x + y) / 2;
                    if (p[mid*2+2] >= len) puts("yes");
                    else puts("no");
                }
                else {
                    int mid = (x + y) / 2;
                    if (p[mid*2+3] >= len) puts("yes");
                    else puts("no");
                }
            }
            else {
                sf("%d%s", &x, ch);
                x--;
                if (ch[0] != str[x*2+2]) {
                    str[x*2+2] = ch[0];
                    pk();
                }
            }
        }
    }
    return 0;
}

