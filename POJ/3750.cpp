#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#define Maxn 500100
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,b) FOR(i,0,b)
using namespace std;
;

int n, w, s;
int t[Maxn];
char name[Maxn][16];

void insert(int idx, int val)
{
    for (;idx<=n;idx+=idx&-idx) t[idx] += val;
}
int query(int idx)
{
    int ret = 0;
    for(;idx; idx-=idx&-idx) ret += t[idx];
    return ret;
}
int main()
{
    while (~scanf("%d", &n))
    {
        FOR(i,1,n+1) t[i] = i&-i;  //sum 1 2 3 ..
        FOR(i, 1, n+1) scanf("%s", &name[i]);
        scanf("%d,%d", &w, &s);  //从w开始数，每个s个 
        w--;
        FOR(i, 0, n)
        {                        
            int tmp = (query(w) + s ) % (n - i);  //n - i 剩余人数 
            if (tmp <= 0) tmp += n - i;
            
            int le=1, ri=n, mid;
            while (le <= ri)
            {
                mid = (le + ri) >>1;
                if (query(mid) >= tmp) ri = mid-1;
                else le = mid+1;
            }            
            w = le;
            insert(w, -1);
            printf("%s\n", name[w]);
        }     
    }
    return 0;
}

