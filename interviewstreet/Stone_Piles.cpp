#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <functional>
#include <vector>
#define N 51
#define pb push_back
#define all(a) (a).begin(),(a).end()
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,b) FOR(i,0,b)
using namespace std;

typedef vector<int> vi;

int n, x[55];
int sg[55];
/*vi t;

void calc(int x, vi v)
{
    if (!x)
    {
        int r = 0;
        REP(i, v.size()) r ^= sg[v[i]];
    //    REP(i, v.size()) cout <<v[i] << " ";
    //    cout <<endl;
        t.pb(r);
        return;
    }
    
    int now = v.size() ? v.back() : 0;
    FOR(i, now+1, x+1)
    {
        if (now == 0 && i == x) break;
        int tmp = x - i;
        if (tmp < 0) break;
        v.pb(i);
        calc(tmp, v);
        v.pop_back();
    }
}*/
void init()
{
  /*  memset(sg, 0, sizeof(sg));
    FOR(i, 3, N)
    {
        cout <<"check " <<i <<endl;
        t.clear();
        vi v;
        calc(i, v);
        sort(all(t));
        t.erase(unique(all(t)), t.end());
        if (t[0] != 0) sg[i] = 0;
        else
        {
            int x = 1;
            for (int j=1; j<t.size(); j++, x++)
            {
                if (t[j] != x) break;
            }
            sg[i] = x;
        }
        cout <<i<<" sg is  " << sg[i] <<endl;
    }*/
    memset(sg, -1, sizeof(sg));
    sg[1] = sg[2] = sg[4] = sg[8] = 0;
    for (int i=3, j=1; i<N; i++)
    {
        if (sg[i] == 0) continue;
        sg[i] = j++;
    }
}
int main()
{
    init();
    int T;
    cin >>T;
    while (T--)
    {
        cin >>n;
        int ans = 0;
        for (int i=0; i<n; i++)
        {
             cin >>x[i];
             ans ^= sg[x[i]];
        }
        if (ans == 0) cout <<"BOB" <<endl;
        else cout <<"ALICE" <<endl;
    }
    return 0;
}
