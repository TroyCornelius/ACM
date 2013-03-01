#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <set>
#include <map>
using namespace std;

const int N = 3;
const int M = 100010;
const int INF = 1 << 30;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pii> vp;
typedef vector<vi> vvi;

#define mp make_pair
#define pb push_back
#define fst first
#define snd second

vi v[2]; 

void init() 
{
    v[0] = vi(N); v[1] = vi(N);
    for(int i = 0; i < N; i++) cin>>v[0][i];
    for(int i = 0; i < N; i++) cin>>v[1][i];
}

void solve(int tcase)
{
    ll res = 0;
    int add = 0;
    
    for(int i = 0; i < N; i++)
    {
        if(!v[0][i]) continue;
        if((v[0][i] + add) <= v[1][i])
        {
            res += 2 * (v[0][i] + add);
            add = 0;
        }
        else
        {
            res += 2 * v[1][i];
            add = 1;
        }
    }
    if(add) res++;
    
    cout<<"Case "<<tcase<<": "<<res<<endl;
}

int main()
{
    //freopen("C.in", "r", stdin); 
    //freopen("C.out", "w", stdout);
    
    int T;
    cin>>T;
    
    for(int i = 1; i <= T; i++)
    {
        init();
        solve(i);
    }
    //while(1);
} 
