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
#define Maxn 3010
using namespace std;

int use_ti[2][Maxn][Maxn];
int n, ans, s1, s2;
int p[Maxn], q[Maxn];
int s[2][Maxn];
int f[Maxn][2];
int main()
{
    
    scanf("%d", &n);
    for (int i=1; i<=n; i++) scanf("%d %d", &p[i], &q[i]);
    
    
    
    ans = 0;
    memset(f, 0, sizeof(f));
    memset(s, 0, sizeof(s));
    
    for (int i=1; i<=n; i++)
    {
        s[0][i] = s[0][i-1] + p[i];
        s[1][i] = s[2][i-1] + p[i];        
    }
    
    for (int i=2; i<=n+1; i++)
    {
        for (int k=0; k<2; k++)
        {
            for (int t=0; t<2; t++)
            {
                if (k == t) f[i][k] =max(f[i][k], f[i-1][t]);
                else
                {
                    for (int j=i-1; j>=1; j--)
                    {
                        f[i][k] =max(f[i][k], f[j][t] + (s[k][i-1] - s[k][j-1])*(i-j));                        
                    }                    
                }      
            }
            
        }
        
    }
    
    printf("%d\n", max(f[n+1][0], f[n+1][1]));
    
    
    system("pause");
    return 0;
    }
