#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <cstring>
#define FOR(i, a, b) for(int i(a); i<(b); i++)
#define REP(i, b) FOR(i, 0, b)
using namespace std;

vector<int> d;
bool vis[10];
void dfs(int num)
{
    if (num > 10000000) return;
    d.push_back(num);
    REP(i, 10)
    if (!vis[i])
    {
        vis[i] = true;
        dfs(num*10+i);
        vis[i] = false;    
    }
    return ;
}
int main()
{
    int n;
    memset(vis, false, sizeof(vis));
    FOR(i, 1, 10) 
    {
        vis[i] = true;
        dfs(i);
        vis[i] = false;
    }
    d.push_back(0);
    sort(d.begin(), d.end());
    while (~scanf("%d", &n))
    {
        //vector<int>::iterator
        int ans = lower_bound(d.begin(), d.end(), n) - d.begin() - 1;
        //ans--;
        if (n <= 1) printf("0\n");
        else printf("%d\n", ans);
    }

    return 0;
}
