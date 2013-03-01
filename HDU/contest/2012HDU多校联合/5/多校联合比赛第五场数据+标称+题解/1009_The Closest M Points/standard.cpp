#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <cmath>
#include <queue>
#include <ctime>
#include <stack>
#define eps 1e-8
#define For(i,a,b) for(int i=(a);i<(b);i++)
#define Me (a,v) memset(a,(v),sizeof(a))
#define M 6
#define inf 1<<30
#define N 50005
using namespace std;

struct Point {
    int x[M];
    int lx[M], mx[M];
    int k;

    Point() {

        For(i, 0, M) {
            mx[i] = inf;
            lx[i] = -inf;
        }
    }

    Point(const Point & p) {

        For(i, 0, p.k) {
            x[i] = p.x[i];
            lx[i] = p.lx[i];
            mx[i] = p.mx[i];
        }
        k = p.k;
    }

    double dis(Point t) {
        double ans = 0;
        For(i, 0, t.k)
        ans += (x[i] - t.x[i])*(x[i] - t.x[i]);
        return sqrt(ans);
    }
} p[N];

typedef struct Node {
    Point p;
    Node *left, *right;
    int num;
    bool flag;

    Node(const Point & p) {
        this->p = p;
        this->left = NULL;
        this->right = NULL;
        this->num = 1;
        this->flag = false;
    }

    Node() {
        flag = false;
        left = right = NULL;
    }
} *node;
Node *root;

int K;

struct Com {
    node v;
    double r;

    friend bool operator<(Com a, Com b) {
        return a.r < b.r;
    }
};
node cur;

priority_queue<Com>pq;

void print(Node *t) {
    if (t == NULL) {
        printf("NULL\n");
        return;
    }
    printf("%d", t->p.x[0]);

    For(i, 1, K) {
        printf(" %d", t->p.x[i]);
    }
    printf("\n");

}

void QuickSort(int ii, int first, int end) {
    int i = first, j = end;
    Point tmp = p[first];
    while (i < j) {
        while (i < j && p[j].x[ii] >= tmp.x[ii])
            j--;
        p[i] = p[j];
        while (i < j && p[i].x[ii] <= tmp.x[ii])
            i++;
        p[j] = p[i];
    }
    p[i] = tmp;
    if (first < i - 1)
        QuickSort(ii, first, i - 1);
    if (end > i + 1)
        QuickSort(ii, i + 1, end);
}

Node *buildkdtree(int f, int t, int depth) {
    if ((t - f) == 0) {
        return NULL;
    } else if ((t - f) == 1) {
        return new Node(p[f]);
    }
    int mid = (f + t - 1) >> 1;
    QuickSort(depth, f, t - 1);
    Node *v = new Node(p[mid]);
    v->left = buildkdtree(f, mid, (depth + 1) % K);
    v->right = buildkdtree(mid + 1, t, (depth + 1) % K);
    return v;
}

int BuildSqr(Node *v, int depth) {
    if (v == NULL)
        return 0;
    if (v->left) {

        For(i, 0, K) {
            v->left->p.mx[i] = v->p.mx[i];
            v->left->p.lx[i] = v->p.lx[i];
        }
        v->left->p.mx[depth] = v->p.x[depth];
    }
    if (v->right) {

        For(i, 0, K) {
            v->right->p.mx[i] = v->p.mx[i];
            v->right->p.lx[i] = v->p.lx[i];
        }
        v->right->p.lx[depth] = v->p.x[depth];
    }
    int na = BuildSqr(v->left, (depth + 1) % K);
    int nb = BuildSqr(v->right, (depth + 1) % K);
    v->num = na + nb + 1;
    return na + nb + 1;
}

node SearchKNode(node v, Point t, int k, int dp) {
    if (v == NULL)
        return NULL;
    if (v->num < k)
        return NULL;
    if ((v->left == NULL || v->left->num < k) && (v->right == NULL || v->right->num < k)) {
        v->flag = 1;
        cur = v;
        return v;
    }
    if (t.x[dp] < v->p.x[dp] && v->left && v->left->num >= k) {
        return SearchKNode(v->left, t, k, (dp + 1) % K);
    } else if (t.x[dp] >= v->p.x[dp] && v->right && v->right->num >= k) {
        return SearchKNode(v->right, t, k, (dp + 1) % K);
    } else {
        v->flag = 1;
        cur = v;
        return v;
    }
}

void SearchMinr(node v, Point t) {
    if (v == NULL)
        return;
    Com tmp;
    tmp.r = v->p.dis(t);
    tmp.v = v;
    pq.push(tmp);
    SearchMinr(v->left, t);
    SearchMinr(v->right, t);
}

double searchKR(Point t, int k) {
    node v = SearchKNode(root, t, k, 0);
    if (v == NULL)
        return -1.0;
    SearchMinr(v, t);
    while (pq.size() > k) {
        pq.pop();
    }
    if (pq.size() == 0)
        return 0.0;
    else
        return pq.top().r;
}

bool check(Node *v, Point t, double r) {
    Point now;

    For(i, 0, K) {
        if (v->p.lx[i] <= t.x[i] && t.x[i] <= v->p.mx[i]) {
            now.x[i] = t.x[i];
        } else if (t.x[i] > v->p.mx[i]) {
            now.x[i] = v->p.mx[i];
        } else
            now.x[i] = v->p.lx[i];
    }
    now.k = K;
    if (now.dis(t) < eps + r)
        return 1;
    return 0;
}

void KFind(int k, Point t, double &r, node v) {
    if (v->flag)
        return;
    double dd = v->p.dis(t);
    if (dd + eps < r) {
        Com tmp;
        tmp.r = dd;
        tmp.v = v;
        pq.push(tmp);
        pq.pop();
        r = pq.top().r;
    }
    if (v->left) {
        if (check(v->left, t, r)) {
            KFind(k, t, r, v->left);
        }
    }
    if (v->right) {
        if (check(v->right, t, r)) {
            KFind(k, t, r, v->right);
        }
    }
}

void KNN(Point t, int k) {
    while (!pq.empty())
        pq.pop();
    double r = searchKR(t, k);
    KFind(k, t, r, root);
    cur->flag = 0;
    printf("the closest %d points are:\n", k);
    stack<node>sta;
    while (!sta.empty())
        sta.pop();
    while (!pq.empty())
        sta.push(pq.top().v), pq.pop();
    while (!sta.empty())
        print(sta.top()), sta.pop();

}

int main() {
//    freopen("data.in","r",stdin);
//    freopen("data.out","w",stdout);
    int n, k;
    while (scanf("%d%d", &n, &k) == 2) {
        K = k;

        For(i, 0, n) {

            For(j, 0, k) {
                scanf("%d", &p[i].x[j]);
                p[i].mx[j] = inf;
                p[i].lx[j] = -inf;
            }

            p[i].k = k;
        }
        root = buildkdtree(0, n, 0);
        BuildSqr(root, 0);
        Point aim;
        int T;
        scanf("%d", &T);
        while (T--) {

            For(i, 0, k) {
                scanf("%d", &aim.x[i]);
            }
            aim.k = k;
            int mm;
            scanf("%d", &mm);
            KNN(aim, mm);
        }
    }

    return 0;
}