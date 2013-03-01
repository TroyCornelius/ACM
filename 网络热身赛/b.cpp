#include <iostream>
#include <vector>
#include <set>
#include <cmath>
using namespace std;

typedef pair<int,int> points;
int T, n;
vector<points> ans;
bool cmp(points a, points b)
{
     return a.first > b.first;
     }
int main()
{
    freopen("std.in", "r", stdin);
    freopen("b.out", "w", stdout);
    cin >>T;
    for (int i=1; i<=T; i++)
    {
        cin >>n;
        ans.clear();
        for (int j=1; j<=n; j++)
        if ((n*n)%j==0)
        {
            int a2 = n*n/j;
            if ((j+a2)%2!=0) continue;
            int c = (j + a2) / 2;            
            int a = c - j;
            if (c == j) continue;
            if (a+c<n || c - a > n) continue;
            if (c*c == a*a + n*n) ans.push_back(make_pair(c,a));
        }
        for (int j=1; j<n; j++)
        {
            int c = j;
            int a = int(sqrt(double(n*n-c*c)));
            if (a > c) continue;
            if (a+c<n || c - a > n) continue;
            if (n*n == a*a + c*c) ans.push_back(make_pair(c,a));     
        }
        sort(ans.begin(), ans.end(), cmp);
        for (int p=0; p<ans.size(); p++)
        {
            printf("%d,%d\n", ans[p].first, ans[p].second);            
        }
        if (i != T) printf("\n");
    }

    return 0;
    }
