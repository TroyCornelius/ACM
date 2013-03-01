#include <iostream>
#include <cstdio>

using namespace std;

long long ans;
int a[2][3];
int main()
{
    int T, ca = 0;
    cin >>T;
    while (T--)
    {
        for (int i=0; i<3; i++) cin >>a[0][i];
        for (int i=0; i<3; i++) cin >>a[1][i];
        ans = 0;
        
        int p[2], add = 0;
        p[0] = p[1] = 0;
        for (int i=0; i<3; i++)
        {
            if (!a[0][i]) continue;
            if (a[0][i] + add > a[1][i])
            {
                ans += 2LL * a[1][i];
                add = 1;
            }
            else
            {
                ans += 2LL * (a[0][i] + add);
                add = 0;
            }                
        }
        ans += add;
        cout <<"Case "<<++ca <<": " <<ans <<endl;
    }
    return 0;
}
