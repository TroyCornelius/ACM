#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

int d[110], n, ans;
int main()
{
    int T, ca = 0;
    cin >>T;
    while (T--)
    {
        cin >>n;
        for (int i=0; i<n; i++) cin >>d[i];
        d[n] = d[0];
        ans = 0;
        for (int i=0; i<n; i++) ans += abs(d[i] - d[i+1]); 
        printf("Case %d: %d\n", ++ca, ans);
        if (T) cout <<endl;
    }
    
    return 0;
}
