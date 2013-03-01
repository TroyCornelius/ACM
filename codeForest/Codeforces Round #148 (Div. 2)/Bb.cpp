#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <sstream>
#include <string>
#include <set>
#include <map>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pii> vp;
typedef vector<vi> vvi;

const int N = 33;
const int M = 50010;
const int K = 3;
const int LIT = 2500;
const int INF = 1 << 30;
const int dir[][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

#define mp make_pair
#define pb push_back
#define fst first
#define snd second

int n, q;
string s, ss;

void init()
{
    cin>>s;
}

vi ans;

void solve()
{
    while(q--)
    {
        ans = vi(10);
        ss = s;
        int lt, rt;
        cin>>lt>>rt;
        lt--, rt--;
        int cp = lt, dp = 1;
        while(1)
        {
            if(cp < lt || cp > rt) break;
            if(ss[cp] == '-') cp += dp;
            else if(ss[cp] >= '1' && ss[cp] <= '9')
            {
                int x = ss[cp] - '0';
                ans[x]++;
                x--;
                ss[cp] = x + '0';
                cp += dp;
            } 
            else if(ss[cp] == '0')
            {
                ans[0]++;
                ss[cp] = '-';
                cp += dp;    
            }
            else
            {
                int pre = cp;
                if(ss[cp] == '>') dp = 1;
                else dp = -1;
                bool f = 0;
                while(1)
                {
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
}

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    
    while(cin>>n>>q)
    {
        init();
        solve();
    }
    //while(1);
}
