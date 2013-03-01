#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pii> vp;
typedef vector<vi> vvi;
const int N = 10010;
const int M = 10010;
const int K = 510;
const int LIT = 2500;
const int INF = 1 << 30;
#define mp make_pair
#define pb push_back
#define fst first
#define snd second
int n, k;
bool f;
string s[13];
char stmp[M];
vi ans;
bool check(char c)
{
    if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') return 1;
    return 0;    
}
string getstr(int p, int pp)
{
    int len = s[p].size(), j;
    for(j = len-1; j >= 0; j--)
    {
        if(check(s[p][j])) pp--;
        if(!pp) break;
    }
    if(pp) f = 1;
    string tmp = "";
    for(; j < len; j++) tmp += s[p][j];
    return tmp;
}

void work()
{
    f = 0;
    ans = vi(4);
    for(int i = 0; i <= 3; i++) ans[i] = 0;
    for(int i = 1; i <= n; i++)
    {
        bool b[5][5] = {0};
        for(int j = 0; j <= 3; j++)
        {
            scanf("%s", &stmp);
            s[j] = stmp;
            s[j] = getstr(j, k);
        }
        for(int j = 0; j <= 3; j++)
        {
            for(int p = j+1; p <= 3; p++)
            {
                if(s[j] == s[p]) b[j][p] = 1;    
            }    
        }
        if(b[0][1] && b[0][2] && b[0][3]) ans[0]++;
        if(b[0][1] && b[2][3]) ans[1]++;
        if(b[0][2] && b[1][3]) ans[2]++;
        if(b[0][3] && b[1][2]) ans[3]++;
    }
    if(f) 
    {
        cout<<"NO"<<endl;
        return ;
    }
    else
    {
        for(int i = 0; i <= 3; i++)
        {
            if(ans[i] == n)
            {
                if(i == 0) cout<<"aaaa"<<endl;
                if(i == 1) cout<<"aabb"<<endl;
                if(i == 2) cout<<"abab"<<endl;
                if(i == 3) cout<<"abba"<<endl;
                return ;    
            }    
        }    
    }
    cout<<"NO"<<endl;
}


int main()
{

    cin>>n>>k;
    work();
    return 0;

}

