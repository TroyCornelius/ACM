/*
 * Author:  Troy
 * Created Time:  2012/4/24 23:23:46
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

string s1, s2;
int next[100100];
void solve_kmp_next(string s){
    next[0]=0;
    //sn = s.length()<F4>
    int sn = s.length(), temp;
    for(int i = 1; i < sn; i++){
        temp=next[i-1];
        while(temp && s[temp]!=s[i])
            temp=next[temp-1];
        if(s[temp]==s[i])
            next[i]=temp+1;
        else
            next[i]=0;
    }   
    return ;
}

int main() 
{
    cin >>s1;
    cin >>s2;
    if (s1.length() > s2.length()) swap(s1, s2);
    int ans = 0;
    int len1 = s1.size(), len2 = s2.size();
    solve_kmp_next(s1);
    int t1 = (len1 % (len1 - next[len1 - 1]) == 0) ? len1 - next[len1-1] : len1;
    solve_kmp_next(s2);
    int t2 = (len2 % (len2 - next[len2 - 1]) == 0) ? len2 - next[len2-1] : len2;
    if (t1 != t2 || s1.substr(0, t1) != s2.substr(0, t2)) ans = 0;
    else
    {
        for (int i=t1; i<=len1; i+=t1)
            if (len1%i == 0 && len2%i == 0) ans++;
    }
    cout <<ans <<endl;
    
    
    return 0;
}

