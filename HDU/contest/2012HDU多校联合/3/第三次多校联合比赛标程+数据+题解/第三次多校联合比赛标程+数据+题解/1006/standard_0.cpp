#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

#define INF 0x3fffffff
#define LL long long
#define N 100005
struct Node
{
    int l, r, v;
};
Node tree[12 * N];
int xarr[N], np;
int n, m, si[N], ti[N], que[N];

int bifind(int num)
{
    int l = 1, r = np, mid;
    while(l <= r)
    {
        mid = (l + r) / 2;
        if(xarr[mid] == num)        return mid;
        else if(xarr[mid] > num)    r = mid - 1;
        else if(xarr[mid] < num)    l = mid + 1;
    }
    return -1;
}
void build(int pos, int l, int r)
{
    tree[pos].l = l;
    tree[pos].r = r;
    tree[pos].v = 0;
    if(l == r)
        return ;
    int mid = (l + r) / 2;
    build(pos * 2, l , mid);
    build(pos * 2 + 1, mid + 1, r);
}
void push_down(int pos)
{
    if(tree[pos].v)
    {
        tree[pos * 2].v += tree[pos].v;
        tree[pos * 2 + 1].v += tree[pos].v;
        tree[pos].v = 0;
    }
}
void update(int pos, int l, int r, int v)
{
    if(l <= tree[pos].l && tree[pos].r <= r)
    {
        tree[pos].v += v;
        return ;
    }
    int mid = (tree[pos].l + tree[pos].r) / 2;
    if(l <= mid)
        update(pos * 2, l, r, v);
    if(r > mid)
        update(pos * 2 + 1, l, r, v);
}
int query(int pos, int idx)
{
    if(tree[pos].l == tree[pos].r)
        return tree[pos].v;
    int mid = (tree[pos].l + tree[pos].r) / 2;
    push_down(pos);
    if(idx <= mid)
        return query(pos * 2, idx);
    else
        return query(pos * 2 + 1, idx);
}
int main()
{
    freopen("data.in", "r", stdin);
    freopen("data2.out", "w", stdout);
    int i, j, t, cas = 1;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d%d", &n, &m);
        for(i = 1; i <= n; i++)
        {
            scanf("%d%d", &si[i], &ti[i]);
            xarr[i] = si[i];
            xarr[n + i] = ti[i];
        }
        for(i = 1; i <= m; i++)
        {
            scanf("%d", &que[i]);
            xarr[2 * n + i] = que[i];
        }
        sort(xarr + 1, xarr + 1 + 2 * n + m);
        for(i = 1, np = 1; i <= 2 * n + m; i++)
        {
            if(xarr[i] != xarr[np])
            {
                xarr[++np] = xarr[i];
            }
        }
        build(1, 1, np);
        for(i = 1; i <= n; i++)
        {
            update(1, bifind(si[i]), bifind(ti[i]), 1);
        }
        printf("Case #%d:\n", cas++);
        for(i = 1; i <= m; i++)
        {
            printf("%d\n", query(1, bifind(que[i])));
        }
    }
    return 0;
}
