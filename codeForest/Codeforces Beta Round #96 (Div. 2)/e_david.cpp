#include <cstdio>
#include <cstring>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <cmath>
using namespace std;

string s;
int n, m, ans;
int f[110][60][3][3];

int minn(int a, int b)
{
    if (a > 100) return b;
    if (b > 100) return a;
    return min(a, b);
}

int maxn(int a, int b)
{
    if (a > 100) return b;
    if (b > 100) return a;
    return max(a, b);
}

int main()
{
    //freopen("1.txt", "r", stdin);
    //freopen("2.txt", "w", stdout);
    cin >> s >> n;
    m = s.size();
    for (int i = 0; i <= m; i++)
        for (int j = 0; j <= n; j++)
            f[i][j][0][0] = f[i][j][0][1] = f[i][j][1][0] = f[i][j][1][1] = 300;
            
    f[0][0][1][0] = f[0][0][1][1] = 0;
    for (int i = 1; i <= m; i++)
    {
        if (s[i - 1] == 'F')
        {
                f[i][0][0][0] = minn(f[i - 1][0][0][0] - 1, f[i - 1][0][0][1] - 1);
                f[i][0][0][1] = maxn(f[i - 1][0][0][0] - 1, f[i - 1][0][0][1] - 1);
                f[i][0][1][0] = minn(f[i - 1][0][1][0] + 1, f[i - 1][0][1][1] + 1);
                f[i][0][1][1] = maxn(f[i - 1][0][1][0] + 1, f[i - 1][0][1][1] + 1);
        }
        else
        {
            f[i][0][0][0] = minn(f[i - 1][0][1][0], f[i - 1][0][1][1]);
            f[i][0][0][1] = maxn(f[i - 1][0][1][0], f[i - 1][0][1][1]);
            f[i][0][1][0] = minn(f[i - 1][0][0][0], f[i - 1][0][0][1]);
            f[i][0][1][1] = maxn(f[i - 1][0][0][0], f[i - 1][0][0][1]);
        }
        
        for (int j = 1; j <= n; j++)
        {
            if (s[i - 1] == 'F')
            {
                    f[i][j][0][0] = minn(f[i - 1][j][0][0] - 1, f[i - 1][j][0][1] - 1);
                    f[i][j][0][1] = maxn(f[i - 1][j][0][0] - 1, f[i - 1][j][0][1] - 1);
                    f[i][j][1][0] = minn(f[i - 1][j][1][0] + 1, f[i - 1][j][1][1] + 1);
                    f[i][j][1][1] = maxn(f[i - 1][j][1][0] + 1, f[i - 1][j][1][1] + 1);
                    
                    f[i][j][0][0] = minn(f[i][j][0][0], minn(f[i - 1][j - 1][1][0], f[i - 1][j - 1][1][1]));
                    f[i][j][0][1] = maxn(f[i][j][0][1], maxn(f[i - 1][j - 1][1][0], f[i - 1][j - 1][1][1]));
                    f[i][j][1][0] = minn(f[i][j][1][0], minn(f[i - 1][j - 1][0][0], f[i - 1][j - 1][0][1]));
                    f[i][j][1][1] = maxn(f[i][j][1][1], maxn(f[i - 1][j - 1][0][0], f[i - 1][j - 1][0][1]));
            }
            else
            {
                f[i][j][0][0] = minn(f[i - 1][j][1][0], f[i - 1][j][1][1]);
                f[i][j][0][1] = maxn(f[i - 1][j][1][0], f[i - 1][j][1][1]);
                f[i][j][1][0] = minn(f[i - 1][j][0][0], f[i - 1][j][0][1]);
                f[i][j][1][1] = maxn(f[i - 1][j][0][0], f[i - 1][j][0][1]);
                
                f[i][j][0][0] = minn(f[i][j][0][0], minn(f[i - 1][j - 1][0][0] - 1, f[i - 1][j - 1][0][1] - 1));
                f[i][j][0][1] = maxn(f[i][j][0][1], maxn(f[i - 1][j - 1][0][0] - 1, f[i - 1][j - 1][0][1] - 1));
                f[i][j][1][0] = minn(f[i][j][1][0], minn(f[i - 1][j - 1][1][0] + 1, f[i - 1][j - 1][1][1] + 1));
                f[i][j][1][1] = maxn(f[i][j][1][1], maxn(f[i - 1][j - 1][1][0] + 1, f[i - 1][j - 1][1][1] + 1));
            }
        }
    }
    ans = 0;
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            for (int k = n; k >= 0; k -= 2)
                ans = maxn(ans, abs(f[m][k][i][j])); 
    cout << ans << endl;
    return 0;
}
    
