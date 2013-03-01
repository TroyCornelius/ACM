/*
 * Author:  Troy
 * Created Time:  2012/5/27 23:31:41
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
#define Maxn 500010
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

int n;
int c1[50][3], c2[50][3];
string name[Maxn];/*
void update(int c[][], int pos, int now, int l)
{
    if ((int)name[c[pos][0]].size() < l)
    {
        c[pos][1] = c[pos][0];
        c[pos][0] = now;
    }
    else
    {
        if (l > name[c[pos][1]].size() )
            c[pos][1] = now;
    }
}*/
int main() 
{
    ios::sync_with_stdio(false);
    cin >>n;
    memset(c1, -1, sizeof(c1));
    memset(c2, -1, sizeof(c2));
    int l, now, pos;
    REP(i, n)
    {
        cin >>name[i];
        l = name[i].length();
        pos = (int)(name[i][0] - 'a'), now = i;
        //cout <<name[i] <<" "<<pos <<" "<<now <<" "<<l <<endl;
        if (c1[pos][0] == -1) c1[pos][0] = now;
        else
        if ((int)name[c1[pos][0]].length() < l)
        {
            c1[pos][1] = c1[pos][0];
            c1[pos][0] = now;
            //cout <<"shit" <<endl;
        }
        else
        {
            if (c1[pos][1] == -1) c1[pos][1] = now;
            else
            if (l > (int)name[c1[pos][1]].length() )
                c1[pos][1] = now;
        }

        pos = name[i][l-1] - 'a', now = i;
        //cout <<name[i] <<" "<<pos <<" "<<now <<" "<<l <<endl;
        if (c2[pos][0] == -1) c2[pos][0] = now;
        else
        if ((int)name[c2[pos][0]].size() < l)
        {
            c2[pos][1] = c2[pos][0];
            c2[pos][0] = now;
        }
        else
        {
            if (c2[pos][1] == -1) c2[pos][1] = now;
            else
            if (l > name[c2[pos][1]].size() )
                c2[pos][1] = now;
        }
    }
    int ans = 0;
    REP(i, 26)
    {
        if (c1[i][0] == -1 || c2[i][0] == -1) continue;
        if (c1[i][0] != c2[i][0])
        {
            ans = max(ans, (int)name[c1[i][0]].length() + (int)name[c2[i][0]].length());
        }
        else
        {
            ans = max(ans, (int)name[c1[i][0]].size());
            int tmp = 0;
            if (c2[i][1] != -1) tmp = max(tmp,(int)name[c1[i][0]].length() + (int)name[c2[i][1]].length());
            if (c1[i][1] != -1) tmp = max(tmp, (int)name[c2[i][0]].length() +(int)name[c1[i][1]].length());
            ans = max(ans, tmp);
        }
    }
    //REP(i, 10) cout <<c1[i][0] <<" "<<c1[i][1] <<" + "<<c2[i][0] <<" "<<c2[i][1] <<endl;
    cout <<ans <<endl;
    return 0;
}

