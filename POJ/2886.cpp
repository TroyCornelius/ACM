#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <algorithm>
#define Maxn 500100
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,b) FOR(i,0,b)
using namespace std;
const int nop[] = {1,2,4,6,12,24,36,48,60,120,180,240,360,720,
    840,1260,1680,2520,5040,7560,10080,15120,
    20160,25200,27720,45360,50400,55440,83160,
    110880,166320, 221760, 277200, 332640, 498960, 554400, 665280};
const int fact[] = {1, 2, 3, 4, 6, 8, 9, 10, 12, 16, 18, 20, 24, 
    30, 32, 36, 40, 48, 60, 64, 72, 80, 84, 90, 
    96, 100, 108, 120, 128, 144, 160, 168, 180, 192, 200, 216, 224};

int n, k, next[Maxn];
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
    while (~scanf("%d%d", &n, &k))
    {
        FOR(i,1,n+1) t[i] = i&-i;
        FOR(i, 1, n+1) scanf("%s %d", &name[i], &next[i]);
        
        int idx = 0, tmp;
        while (nop[idx] <= n) idx++;
        
        FOR(i, 1, nop[idx-1])
        {
            if (next[k] > 0) tmp = (next[k] + query(k) - 1) % (n - i);
            else tmp = (next[k] + query(k)) % (n - i);
            if (tmp <= 0) tmp += n-i;
            insert(k, -1);
            
            int le=1, ri=n, mid;
            while (le <= ri)
            {
                mid = (le + ri) >>1;
                if (query(mid) >= tmp) ri = mid-1;
                else le = mid+1;
            }            
            k = le;
        }     
        printf("%s %d\n", name[k], fact[idx-1]);    
    }
    return 0;
}
