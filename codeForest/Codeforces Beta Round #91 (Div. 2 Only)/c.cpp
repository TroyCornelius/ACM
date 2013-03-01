#include <iostream>
#include <cstdio>
#include <algorithm>
#include <functional>
#define Maxn 10000
using namespace std;

const long long ri = 77777777777LL;
long long l, r, tot;
long long num[Maxn], ans;

void dfs(long long k)
{
     if (k > ri) return;
     num[tot++] = k;
     dfs(k*10+4);
     dfs(k*10+7); 
     }
void make_luck()
{
     tot = 0;
     dfs(4);
     dfs(7);
     sort(num, num+tot);     
     }

int main()
{
    cin >>l >>r;
    make_luck();
    int t1 = lower_bound(num, num+tot, l) - num;
    int t2 = lower_bound(num, num+tot, r) - num;
    ans = (min(num[t1], r) - l + 1) * num[t1];
    for (int i=t1+1; i<=t2-1; i++) ans += (num[i] - num[i-1]) * num[i];
    if (t1 != t2) ans+= (min(r, num[t2]) - num[t2-1]) * num[t2];
    cout <<ans <<endl;
    return 0;
    }
