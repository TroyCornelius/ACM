#include <stdio.h>
const int mo = 10007, maxn    = 10008;
int i, j, bj[maxn], ss[maxn], ny[maxn], tot, n, f[60000];
struct node
{
    int k, b, ks, bs, typec;
    node *ch[2], *f, *fking;
}*g[60000], tree[60000];
int power(int x, int e) {
    int b = x;
    for (--e; e > 0; b = 1LL * b * b % mo, e >>= 1)
        if ((e & 1) == 1) x = 1LL * x * b % mo;
    return x;
}
int getfa(int u) {
    if (f[u] != u) f[u] = getfa(f[u]);
    return f[u];
}
void updata(node *x) {
    if (x->ch[0] != NULL) {
        x->ks = x->k * x->ch[0]->ks % mo;
        x->bs = (x->k * x->ch[0]->bs + x->b) % mo;
    } 
    else x->ks = x->k, x->bs = x->b;
    if (x->ch[1] != NULL)
    {
        x->bs = (x->bs * x->ch[1]->ks + x->ch[1]->bs) % mo;
        x->ks = x->ks * x->ch[1]->ks % mo;
    }
}
void rotate(node *x, int p) {
    node *y = x->f; y->ch[p] = x->ch[!p];
    if (y->ch[p] != NULL) y->ch[p]->f = y, y->ch[p]->typec = p;
    x->f = y->f, x->typec = y->typec;
    if (x->f != NULL && x->typec != 2) x->f->ch[x->typec] = x;
    x->ch[!p] = y, y->f = x;
    y->typec = !p, updata(y);
}
void splay(node *x) {
    for (; x->typec != 2; ) {
        node *y = x->f;
        int p = x->typec, q = y->typec;
        if (p == q) rotate(y, p); else rotate(x, p);
        if (q == 2) break; rotate(x, q);
    }
    updata(x);
}
node *findroot(node *x) {
    node *mid; splay(x);
    for (;x != NULL; mid = x, x = x->ch[0])
    splay(mid); return mid;
}
node *findup(node *x) {
    node *mid;
    for (x = x->ch[0]; x != NULL; mid = x, x = x->ch[1]);
    return mid;
}
node *access(node *x) {
    node *u = NULL;
    for (; x != NULL; x = x->f) {
        splay(x);
        if (x->ch[1] != NULL) x->ch[1]->typec = 2;
        x->ch[1] = u;
        if (u != NULL) u->typec = 1, u->f = x;
        updata(u = x);
    }
    return u;
}
int ask(int a) {
    node *p = findroot(access(g[a]));
    if (p->fking == NULL) return -1;
    splay(p);
    int k = p->ks, b = p->bs;
    node *q = access(p->fking);
    splay(q);
    if (q->ks == 1) return -1;
    int ks = 1 - q->ks, bs = q->bs;
    if (ks <= 0) ks += mo;
    ks = ny[ks] * bs % mo;
    return (k * ks + b) % mo;
}
void change(int a, int k, int p, int b) {
    node *q = findroot(access(g[a]));
    if (q == g[a]) {g[a]->k = k, g[a]->b = b, updata(g[a]);}
    else {
        node *lca = access(q->fking);
        node *xx = access(g[a]);
        splay(g[a]);
        node *r = findup(g[a]);
        splay(r), r->ch[1]->typec = 2;
        r->ch[1] = NULL, updata(r);
        splay(g[a]), g[a]->k = k, g[a]->b = b;
        g[a]->f = NULL, updata(g[a]);
        if (lca == g[a]) {splay(q), q->f = q->fking, q->fking = NULL;}
    }
    if (findroot(access(g[p])) == g[a]) g[a]->fking = g[p], g[a]->f = NULL;
    else g[a]->f = g[p], g[a]->fking = NULL;
    g[a]->typec = 2;
}
int main() {
    for (i = 2, ny[0] = 0, ny[1] = 1; i < mo; ++i) {
        if (!bj[i]) ny[ss[++tot] = i] = power(i, mo - 2);
        for (j = 1; j <= tot && i * ss[j] < mo; ++j) {
            ny[i * ss[j]] = ny[i] * ny[ss[j]] % mo;
            bj[i * ss[j]] = 1;
            if (i % ss[j] == 0) break;
        }    
    } 
    scanf("%d", &n);
    for (i = 1; i <= n; ++i) f[i] = i;
    for (i = 0; i <= n; ++i) g[i] = &tree[i];
    int a, p, k, b, q;
    for (i = 1; i <= n; ++i) {
        scanf("%d%d%d", &g[i]->k, &q, &g[i]->b);
        int f1 = getfa(i), f2 = getfa(q);
        if (f1 == f2) g[i]->fking = g[q]; 
        else {f[f2] = f1, g[i]->f = g[q];}
        g[i]->ks = g[i]->k, g[i]->bs = g[i]->b, g[i]->typec = 2;
    }
    scanf("%d\n", &q);
    for (char ch; q; --q){
        scanf("%c", &ch);
        if (ch == 'A') {
            scanf("%d\n", &a), printf("%d\n", ask(a));
        } else {
            scanf("%d%d%d%d\n", &a, &k, &p, &b), change(a, k, p, b);
        }
    }
    return 0;
}

