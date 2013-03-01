/*
 给你一些箱子，大小可任意边，有mov x y和query x，这两类指令，对于前者把合法情况下的移动完成，
就是把x放到y中，后者询问包含x的最外层的箱子号
解法：动态树，简单的 link-cut tree
 */
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
#define REP_1(i, n) for (int i=1;i<=int(n);++i)
#define DO_C(n) int n____ = n; while(n____--)
template<class T> inline void RD(T &x){char c; for (c = getchar(); c < '0'; c = getchar()); x = c - '0'; for (c = getchar(); c >= '0'; c = getchar()) x = x * 10 + c - '0';}
inline int RD(){ int x; RD(x); return x;}
inline void RS(char *s){scanf("%s", s);}
template<class T> inline void RST(T &A){memset(A, 0, sizeof(A));}
template<class T0, class T1, class T2> inline void RST(T0 &A0, T1 &A1, T2 &A2){RST(A0), RST(A1), RST(A2);}
template<class T> inline void OT(const T &x){printf("%d\n", x);}

/* .................................................................................................................................. */

const int N = 50009;
int l[N], r[N], p[N]; bool rt[N];
int n;
#define lx l[x]
#define rx r[x]
inline void Set(int l[], int y, int x)
{
    l[y] = x, p[x] = y;
}
inline void Rotate(int x)
{
    int y = p[x], z = p[y];

    if (!rt[y]) Set(y == l[z] ? l : r, z, x);
    else p[x] = z;

    if (x == l[y]) Set(l, y, rx), Set(r, x, y);
    else Set(r, y, lx), Set(l, x, y);

    if (rt[y]) rt[y] = false, rt[x] = true;
}
inline void Splay(int x)
{
    while (!rt[x]) Rotate(x), cout <<rt[x] <<endl;
}
int Access(int x)
{
    int y = 0; do{
        Splay(x);
        rt[rx] = true, rt[rx = y] = false;
        x = p[y = x];
    } while (x);
    return y;
}
inline int Root(int x)
{
    for (x = Access(x); lx ; x = lx);
    return x;
}
inline int Lca(int x, int y)
{
    int lca; Access(y); y = 0; do{
        cout <<x <<" !!" <<endl;
        Splay(x); if (!p[x]) lca = x;
        rt[rx] = true, rt[rx = y] = false;
        x = p[y = x];
    } while (x);
    return lca;
}
// Public :
void Link(int y, int x)
{
cout <<y <<" "<<x <<endl;
    if (y && (x == y || Root(x) == Root(y) && Lca(x, y) == x)) return;
    cout <<x <<"fuck" <<endl;
    Access(x), Splay(x), rt[lx] = true;
    lx = p[lx] = 0, p[x] = y;
    Access(x);
}
inline void getint(int&a)
{
    int b; a=0;
    while ((b=getchar())<'0'||b>'9'); a=b-'0';
    while ((b=getchar())>='0'&&b<='9') a=a*10+b-'0';
}
int main()
{
    bool first_blood = true;
    while (scanf("%d", &n) != EOF)
    {
        if (first_blood) first_blood = false; else puts("");
        REP_1(i, n) rt[i] = true, RD(p[i]);
        char cmd[9];
        DO_C(RD())  //RD() read an int data
        {
            RS(cmd); if (cmd[0] == 'Q') OT(Root(RD())); //OT(x) <=> print
            else Link(RD(), RD());
        for (int i = 1; i <= n; i++) cout <<rt[i] <<" ";
        cout <<endl;
        for (int i = 1; i <= n; i++) cout <<l[i] <<" ";
        cout <<endl;
        for (int i = 1; i <= n; i++) cout <<r[i] <<" ";
        cout <<endl;
        for (int i = 1; i <= n; i++) cout <<p[i] <<" ";
        cout <<endl;
        }
        RST(p, l, r);
    }
}

