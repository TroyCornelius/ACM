/*
 * Author:  Troy
 * Created Time:  2012/3/11 17:15:38
 * File Name: e.cpp
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

#include <cctype>
#include <functional>
#include <deque>
#include <iomanip>


#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(a) (a).begin(),(a).end()
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define FORD(i,a,b) for (int i=(a); i>=(b); i--)
#define REP(i,b) FOR(i,0,b)
#define Maxn 50050
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

int n, m, gv[15];
struct Tnode
{
    int t[4], cand, ti;
    string cel;
    bool operator<(const Tnode &b)const
    {
        /*if (t[0] != b.t[0]) return t[0] < b.t[0];
        else
        {
            if (t[1] != b.t[1]) return t[1] < b.t[1];
            else return t[2] < b.t[2];
        }*/
        return ti < b.ti;
    }
}vote[Maxn];
map<string,int> last;
int trans_to_num(string s)
{
    int ret = 0;
    REP(i, s.length()) ret = ret*10 + (s[i] - '0');
    return ret;
}
Tnode div(string s, string s2, int id)
{
    Tnode ret;
    string s1;
    int loc = s.find(":", 0);
    s1 = s.substr(0, loc);
    ret.t[0] = trans_to_num(s1);
    int loc2 = s.find(":", loc+1);
    s1 = s.substr(loc+1, loc2 - loc - 1);
    ret.t[1] = trans_to_num(s1);
    s1 = s.substr(loc2+1, s.length() - loc2 - 1);
    ret.t[2] = trans_to_num(s1);
    ret.cel = s2;
    ret.cand = id;
    ret.ti = ret.t[0]*60*60 + ret.t[1]*60 + ret.t[2];
    return ret;
}
int main() 
{
    string s, s2;
    int id;
    ios::sync_with_stdio(false);
    while (cin >>n)
    {
        m = 0;
        cout <<n <<endl;
        while (cin >>s)
        {
            if (s == "#end") break;
            cin >>s2;
            cin >>id;
            vote[m++] = div(s, s2, id);
        }
        sort(vote, vote+m);
        last.clear();
        memset(gv, 0, sizeof(gv));
        REP(i, m)
        {
            int now = last[vote[i].cel];
            if (now == 0 || vote[i].ti - now >= 60)
            {
                gv[vote[i].cand]++;
                last[vote[i].cel] = vote[i].ti;
            }
           // cout <<now <<" "<<vote[i].cand <<" "<<gv[vote[i].cand] <<endl;
        }
        cout <<"The result is :"<<endl;
        FOR(i, 1, n+1)
        {
            if (i < 10) cout <<"0";
            cout <<i <<" : ";
            REP(j, gv[i]) cout <<"*";
            cout <<endl;
        }
    }
    
    return 0;
}

