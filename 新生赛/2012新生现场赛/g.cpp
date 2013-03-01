#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

long long ans;
int a[2][4];
int main()
{
  //  freopen("g.in", "r", stdin);
   // freopen("g.out", "w", stdout);
    int T, ca = 0;
    cin >>T;
    while (T--)
    {
        memset(a, 0, sizeof(a));
        for (int i=0; i<3; i++) cin >>a[0][i];
        for (int i=0; i<3; i++) cin >>a[1][i];
        ans = 0;
        int v[2], p = 0;
        bool flag = false;
        v[0] = v[1] = 0;
        while (v[0] < 3 && v[1] < 3)
        {
            if (a[0][v[0]] == 0) {v[0]++; continue;}        
            if (a[1][v[1]] == 0) {v[1]++;continue;}
            if (v[1] < v[0]) {v[1]++;continue;}
            if (v[1] > v[0])
            {
                ans += 2;
                v[0]++;
                a[1][v[1]]--;
                flag = true;
            }
            else
            {
                flag = true;
                if (a[0][v[0]] <= a[1][v[1]]) 
                {
                    ans += 2LL * a[0][v[0]];
                    v[0]++;
                /*    while (v[0] < 3 && a[0][v[0]] == 0) v[0]++;
                    if (v[0] < 3) ans++;
                    a[0][v[0]]--;*/
                }
                else
                {
                    a[0][v[0]+1]++;
                    ans += 2LL * a[1][v[1]];
                    v[0]++; v[1]++;
                }
            }            
        }        
        if ((v[0] < 3 && a[0][v[0]] > 0 && !flag) || (a[0][v[0]] > 0)) ans++;
        cout <<"Case "<<++ca <<": " <<ans <<endl;
    }
    return 0;
}
