/*
 * Author:  Troy
 * Created Time:  2012/6/25 0:52:56
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

int n, m, k;
int fc[1010][8];
string fname[1010];
map<string,int> vid;

void sep(int p, string s)
{
    int tot = 1;
    int loc = s.find("(", 0) + 1;
    //cout <<loc <<endl;
    while (1)
    {
        if (s[loc] == 'T') fc[p][tot] = 0;
        else if (s[loc] == 'i') fc[p][tot] = 1;
        else if (s[loc] == 'd') fc[p][tot] = 2;
        else if (s[loc] == 's') fc[p][tot] = 3;
        tot++;
        //cout <<fname[p][loc] <<" "<<fc[p][tot] <<endl;
        loc = s.find(",", loc);
       if (loc == string::npos) break;
       else loc++; 
    }
    fc[p][0] = tot;
    //cout <<tot <<" ";
    //FOR(x, 1, tot) cout <<fc[p][x] <<" ";
    //cout <<endl;
}
int main() 
{
    ios::sync_with_stdio(false);
    string s;
    cin >>n;
    //getchar();
    getline(cin, s);
    memset(fc, 0, sizeof(fc));
    REP(i, n)
    {
        getline(cin, s);
        s.erase(remove_if(all(s), bind2nd(equal_to<char>(), ' ')), s.end());
        fname[i] = s.substr(0, s.find('('));
        sep(i, s);
    }
    //REP(i, n) cout <<fname[i] <<endl;
    string vn;
    cin >>m;
    getline(cin, s);
    REP(i, m)
    {
        getline(cin, s);
        s.erase(remove_if(all(s), bind2nd(equal_to<char>(), ' ')), s.end());
        if (s[0] == 'i')
        {
            vn = s.substr(3);
            vid[vn] = 1;        
        }
        else
        if (s[0] == 'd')
        {
            vn = s.substr(6);
            vid[vn] = 2;        
        }
        else
        {
            vn = s.substr(6);
            vid[vn] = 3;        
        }
        //cout <<vn <<" "<<vid[vn] <<endl;
    }
    cin >>k;
    getline(cin, s);
    int ans = 0;
    int tmp[8];
    REP(i, k)
    {
        ans = 0;
        getline(cin, s);
        s.erase(remove_if(all(s), bind2nd(equal_to<char>(), ' ')), s.end());
        //erase_all(s, " ");
        
        memset(tmp, 0, sizeof(tmp));
        string fn = s.substr(0, s.find('('));
        fn = "void" + fn;
        int loc = s.find("(", 0) + 1, tot = 1;
        while (1)
        {
            //if (s[loc] == 'T') s[tot] = 0;
            //else 
            {
                string str = "";
                FOR(y, loc, s.size())
                    if (s[y] == ',' || s[y] == ')') break;
                    else str += s[y];
                //cout <<str <<endl;
                tmp[tot] = vid[str];
            }
            tot++;
            loc = s.find(",", loc);
            if (loc == string::npos) break;
            else loc++; 
        }
        tmp[0] = tot;
        
        //cout <<fn <<endl;
        //cout <<tmp[0] <<" ";
        //FOR(x, 1, tmp[0]) cout <<tmp[x] <<" ";
        //cout <<endl;
        
        REP(j, n)
            if (fname[j] == fn && fc[j][0] == tmp[0])
            {
                bool flag = true;
                FOR(x, 1, tmp[0])
                    if (fc[j][x] == 0 || fc[j][x] == tmp[x]) continue;
                    else
                    if (fc[j][x] != tmp[x])
                    {
                        flag = false;
                        break;
                    }
                if (flag) ans++;
            }
        cout <<ans <<endl;
    }
    return 0;
}

