/*
 * Author:  Troy
 * Created Time:  2012/4/8 14:44:49
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
#define sf scanf
#define pf printf
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

string h[]={"Jia", "Yi", "Bing", "Ding", "Wu", "Ji", "Geng", "Xin", "Ren", "Gui"};
string e[]={"zi","chou", "yin", "mao", "chen", "si", "wu", "wei", "shen", "you", "xu","hai"};
string ans[70];
int tot;
int main() 
{
    int T, n;
    tot = 1;
    for (int i=0,j=0; tot <=60; tot++, i=(i+1)%10, j=(j+1)%12) ans[tot] = h[i] + e[j];
    ans[0] = ans[60];
    sf("%d", &T);
    while (T--)
    {
        sf("%d", &n);
        if (n == 1) cout <<ans[58] <<endl;
        else if (n == 2) cout <<ans[59] <<endl;
        else if (n == 3) cout <<ans[60] <<endl;
        else
        if (n > 3) cout <<ans[(n-3)%60] <<endl;
        else if (n <= 0) cout <<ans[60 - (abs(n)+2)%60] <<endl;
        
    }
    return 0;
}

