#include <iostream>
#include <cstdio>
#include <algorithm>
#include <functional>
#define Maxn 550
using namespace std;

int n, ip, d[Maxn];
int main()
{
    while (scanf("%d%d", &n, &ip)!=EOF){
    int s1=0, s2=0, num;
    for (int i=0; i<n; i++) scanf("%d", &d[i]);
    sort(d, d+n);
    for (int i=0; i<n; i++)
    {
        if (d[i] <= ip) s1++;
        else ip+=2;        
    }
    printf("%d\n", ip+s1);
}
    return 0;
    }
