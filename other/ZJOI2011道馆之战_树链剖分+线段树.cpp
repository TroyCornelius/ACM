/*
Author: LTL
Data: 2011-6-8
*/

#include <iostream>
#include <memory.h>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>

#define InputFileName        "Data.in"
#define OutputFileName        "Data.out"
#define Max(a, b)            (a > b   a : b)

using namespace std;

const int MaxN = 31000, MaxE = MaxN*2, oo = 1000000000;

int n, m, Next[MaxE], v[MaxE], Head[MaxN], ENum, Total, d[MaxE][20], Depth[MaxN], Size[MaxN], Heavy[MaxN], Father[MaxN], Pos[MaxN];
bool View[MaxN];
int Seq[MaxN], STNum[MaxN], STPos[MaxN], STSize[MaxN], STTail[MaxN], Root[MaxN], STTotal, Left[MaxN*4], Right[MaxN*4], f[MaxN*4][2][2], L[MaxN*4][2], R[MaxN*4][2];
char a[MaxN][3];

inline void AddEdge(const int x, const int y)
{
    Next[++ENum] = Head[x];
    v[Head[x] = ENum] = y;
}

void Init()
{
    scanf("%d%d", &n, &m);
    for (int i = 1, x, y; i < n; ++i)
    {
        scanf("%d%d", &x, &y);
        AddEdge(x, y);
        AddEdge(y, x);
    }
    for (int i = 1; i <= n; ++i)
        scanf("%s", a[i]);
}

void DFS(const int t)
{
    View[t] = Size[t] = 1;
    d[Pos[t] = ++Total][0] = t;
    for (int i = Head[t]; i; i = Next[i])
        if (! View[v[i]])
        {
            Depth[v[i]] = Depth[t]+1;
            Father[v[i]] = t;
            DFS(v[i]);
            Size[t] += Size[v[i]];
            d[++Total][0] = t;
            if (! Heavy[t] || Size[v[i]] > Size[Heavy[t]])
                Heavy[t] = v[i];
        }
}

inline int RMQMin(const int x, const int y)
{
    return Depth[x] < Depth[y]   x : y;
}

inline int LCA(int x, int y)
{
    if ((x = Pos[x]) > (y = Pos[y]))
        swap(x, y);
    const int k = (int)log2(y-x+1);
    return RMQMin(d[x][k], d[y-(1 << k)+1][k]);
}

inline void Combine(int c[2][2], int a[2][2], int b[2][2])
{
    int Res[2][2];
    Res[0][0] = Max(a[0][0]+b[0][0], a[0][1]+b[1][0]);
    Res[0][1] = Max(a[0][0]+b[0][1], a[0][1]+b[1][1]);
    Res[1][0] = Max(a[1][0]+b[0][0], a[1][1]+b[1][0]);
    Res[1][1] = Max(a[1][0]+b[0][1], a[1][1]+b[1][1]);
    c[0][0] = Max(Res[0][0], -oo);
    c[0][1] = Max(Res[0][1], -oo);
    c[1][0] = Max(Res[1][0], -oo);
    c[1][1] = Max(Res[1][1], -oo);
}

inline void CalcL(int c[2], int s[2][2], int a[2], int b[2])
{
    int r[2];
    r[0] = Max(s[0][0]+b[0], s[0][1]+b[1]);
    r[1] = Max(s[1][1]+b[1], s[1][0]+b[0]);
    c[0] = Max(r[0], a[0]);
    c[1] = Max(r[1], a[1]);
}

inline void CalcR(int c[2], int s[2][2], int a[2], int b[2])
{
    int r[2];
    r[0] = Max(a[0]+s[0][0], a[1]+s[1][0]);
    r[1] = Max(a[1]+s[1][1], a[0]+s[0][1]);
    c[0] = Max(r[0], b[0]);
    c[1] = Max(r[1], b[1]);
}

void Build(int &t, const int l, const int r)
{
    t = ++Total;
    if (l == r)
    {
        f[t][0][0] = a[Seq[l]][0] == '.'   1 : -oo;
        f[t][0][1] = f[t][1][0] = a[Seq[l]][0] == '.' && a[Seq[l]][1] == '.'   2 : -oo;
        f[t][1][1] = a[Seq[l]][1] == '.'   1 : -oo;
        L[t][0] = Max(f[t][0][0], f[t][0][1]);
        L[t][1] = Max(f[t][1][0], f[t][1][1]);
        L[t][0] = Max(L[t][0], 0);
        L[t][1] = Max(L[t][1], 0);
        memcpy(R[t], L[t], sizeof(L[t]));
        return;
    }
    const int mid = l+r >> 1;
    Build(Left[t], l, mid);
    Build(Right[t], mid+1, r);
    Combine(f[t], f[Left[t]], f[Right[t]]);
    CalcL(L[t], f[Left[t]], L[Left[t]], L[Right[t]]);
    CalcR(R[t], f[Right[t]], R[Left[t]], R[Right[t]]);
}

void Modify(const int t, const int l, const int r, const int p, const int k)
{
    if (l == r)
    {
        f[t][0][0] = a[k][0] == '.'   1 : -oo;
        f[t][0][1] = f[t][1][0] = a[k][0] == '.' && a[k][1] == '.'   2 : -oo;
        f[t][1][1] = a[k][1] == '.'   1 : -oo;
        L[t][0] = Max(f[t][0][0], f[t][0][1]);
        L[t][1] = Max(f[t][1][0], f[t][1][1]);
        L[t][0] = Max(L[t][0], 0);
        L[t][1] = Max(L[t][1], 0);
        memcpy(R[t], L[t], sizeof(L[t]));
        return;
    }
    const int mid = l+r >> 1;
    if (p <= mid)
        Modify(Left[t], l, mid, p, k);
    else
        Modify(Right[t], mid+1, r, p, k);
    Combine(f[t], f[Left[t]], f[Right[t]]);
    CalcL(L[t], f[Left[t]], L[Left[t]], L[Right[t]]);
    CalcR(R[t], f[Right[t]], R[Left[t]], R[Right[t]]);
}

void Query(const int t, const int l, const int r, const int x, const int y, int Res[2][2], int rL[2], int rR[2])
{
    if (x <= l && y >= r)
    {
        memcpy(Res, f[t], sizeof(f[t]));
        memcpy(rL, L[t], sizeof(L[t]));
        memcpy(rR, R[t], sizeof(R[t]));
        return;
    }
    const int mid = l+r >> 1;
    int tmp[2][2], tmpL[2], tmpR[2];
    if (x <= mid)
        Query(Left[t], l, mid, x, y, Res, rL, rR);
    if (y > mid)
        Query(Right[t], mid+1, r, x, y, tmp, tmpL, tmpR);
    if (x <= mid && y > mid)
    {
        CalcL(rL, Res, rL, tmpL);
        CalcR(rR, tmp, rR, tmpR);
        Combine(Res, Res, tmp);
    }
    else if (y > mid)
    {
        memcpy(Res, tmp, sizeof(tmp));
        memcpy(rL, tmpL, sizeof(tmpL));
        memcpy(rR, tmpR, sizeof(tmpR));
    }
}

void Prework()
{
    DFS(1);
    for (int i, j = 1, k = (int)log2(Total); j <= k; ++j)
        for (i = 1; i+(1 << j)-1 <= Total; ++i)
            d[i][j] = RMQMin(d[i][j-1], d[i+(1 << j-1)][j-1]);
    Total = 0;
    memset(View, 0, sizeof(View));
    for (int i = 1, j; i <= n; ++i)
        if (! View[i])
        {
            for (j = i; Heavy[j]; j = Heavy[j]);
            ++STTotal;
            for (View[j] = 1; Heavy[Father[j]] == j; View[j = Father[j]] = 1)
                Seq[STPos[j] = ++STSize[STNum[j] = STTotal]] = j;
            Seq[STPos[STTail[STTotal] = j] = ++STSize[STNum[j] = STTotal]] = j;
            Build(Root[STTotal], 1, STSize[STTotal]);
        }
}

void Ask1(int x, const int y, int Res[2][2], int rL[2], int rR[2])
{
    if (STNum[x] == STNum[y])
        Query(Root[STNum[x]], 1, STSize[STNum[x]], STPos[x], STPos[y], Res, rL, rR);
    else
    {
        int tmpL[2], tmpR[2], tmp[2][2];
        Query(Root[STNum[x]], 1, STSize[STNum[x]], STPos[x], STSize[STNum[x]], Res, rL, rR);
        x = Father[STTail[STNum[x]]];
        for (; STNum[x] != STNum[y]; x = Father[STTail[STNum[x]]])
        {
            Query(Root[STNum[x]], 1, STSize[STNum[x]], STPos[x], STSize[STNum[x]], tmp, tmpL, tmpR);
            CalcL(rL, Res, rL, tmpL);
            CalcR(rR, tmp, rR, tmpR);
            Combine(Res, Res, tmp);
        }
        Query(Root[STNum[x]], 1, STSize[STNum[x]], STPos[x], STPos[y], tmp, tmpL, tmpR);
        CalcL(rL, Res, rL, tmpL);
        CalcR(rR, tmp, rR, tmpR);
        Combine(Res, Res, tmp);
    }
}

void Ask2(int x, const int y, int Res[2][2], int rL[2], int rR[2])
{
    if (STNum[x] == STNum[y])
        Query(Root[STNum[x]], 1, STSize[STNum[x]], STPos[x], STPos[y]-1, Res, rL, rR);
    else
    {
        int tmpL[2], tmpR[2], tmp[2][2];
        Query(Root[STNum[x]], 1, STSize[STNum[x]], STPos[x], STSize[STNum[x]], Res, rL, rR);
        x = Father[STTail[STNum[x]]];
        for (; STNum[x] != STNum[y]; x = Father[STTail[STNum[x]]])
        {
            Query(Root[STNum[x]], 1, STSize[STNum[x]], STPos[x], STSize[STNum[x]], tmp, tmpL, tmpR);
            CalcL(rL, Res, rL, tmpL);
            CalcR(rR, tmp, rR, tmpR);
            Combine(Res, Res, tmp);
        }
        if (STPos[y] > STPos[x])
        {
            Query(Root[STNum[x]], 1, STSize[STNum[x]], STPos[x], STPos[y]-1, tmp, tmpL, tmpR);
            CalcL(rL, Res, rL, tmpL);
            CalcR(rR, tmp, rR, tmpR);
            Combine(Res, Res, tmp);
        }
    }
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen(InputFileName, "r", stdin);
    freopen(OutputFileName, "w", stdout);
    #endif
    Init();
    Prework();
    char cmd[2];
    for (int x, y, lca, tmp[2][2], Res[2][2], Ans, rL[2], rR[2], tmpL[2], tmpR[2]; m; --m)
    {
        scanf("%s%d", cmd, &x);
        if (cmd[0] == 'C')
        {
            scanf("%s", a[x]);
            Modify(Root[STNum[x]], 1, STSize[STNum[x]], STPos[x], x);
        }
        else
        {
            scanf("%d", &y);
            lca = LCA(x, y);
            Ask1(x, lca, Res, rL, rR);
            if (y != lca)
            {
                Ask2(y, lca, tmp, tmpR, tmpL);
                swap(tmp[0][1], tmp[1][0]);
                CalcL(rL, Res, rL, tmpL);
                CalcR(rR, tmp, rR, tmpR);
                Combine(Res, Res, tmp);
            }
            Ans = Max(rL[0], rL[1]);
            printf("%d\n", Ans);
        }
    }
    return 0;
}
