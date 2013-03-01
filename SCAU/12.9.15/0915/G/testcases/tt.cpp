#include <iostream>
#include <string>
using namespace std;

int main()
{
    freopen("max.in", "r", stdin);
    freopen("max2.in", "w", stdout);
    
    int T;
    cin>>T;
    
    for(int tcase = 1; tcase <= T; tcase++)
    {
        int r, n;
        cin>>r>>n;
        if(tcase <= T / 2) printf("%d %d\n", r, n);
        for(int i = 1; i <= n; i++)
        {
            int x, y;
            scanf("%d %d", &x, &y);
            if(tcase <= T / 2) printf("%d %d\n", x, y);    
        }    
    }    
}
