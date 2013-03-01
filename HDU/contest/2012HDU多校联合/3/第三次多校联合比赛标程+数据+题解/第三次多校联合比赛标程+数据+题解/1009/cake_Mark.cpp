
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <stack>
#define inf -100000000

using namespace std;

int n, m, num[1010], f[1010];
char mmap[1010][1010];

struct Node {
    int ls, rs;
    int val, cv;
};
struct Node node[1010 * 4];

int t, ans[2010];

struct Que {
    int id, val;
};
//stack<Que> que;

void build(int u, int a, int b) {
    node[u].ls = a, node[u].rs = b;
    node[u].val = inf;
    node[u].cv = 0;

    if(b > a) {
        int mid = (a + b) / 2;
        build(2 * u, a, mid);
        build(2 * u + 1, mid + 1, b);
    }
}

void set(int u, int id, int val) {
    if(node[u].ls == node[u].rs) {
        node[u].val = val;
        node[u].cv = 0;
        return ;
    }

    if(node[u].cv > 0) {
        node[u<<1].cv += node[u].cv;
        node[(u<<1)|1].cv += node[u].cv;
        node[u<<1].val += node[u].cv;
        node[(u<<1)|1].val += node[u].cv;
        node[u].cv = 0;
    }

    int mid = (node[u].ls + node[u].rs) >> 1;
    if(id <= mid)   set(u << 1, id, val);
    else            set((u << 1) | 1, id, val);

    node[u].val = max(node[u<<1].val, node[(u<<1)|1].val);
}

void add(int u, int a, int b, int val) {
    if(a  > b)  return ;

    if(node[u].ls == a && node[u].rs == b) {
        node[u].val += val;
        node[u].cv += val;
        return ;
    }

    int mid = (node[u].ls + node[u].rs) >> 1;
    if(b <= mid)        add(u << 1, a, b, val);
    else if(a > mid)    add((u << 1) | 1, a , b, val);
    else {
        add(u << 1, a, mid, val);
        add((u << 1) | 1, mid + 1, b, val);
    }

    node[u].val = node[u].cv + max(node[u<<1].val, node[(u<<1)|1].val);
}

int find(int u, int a, int b) {
    if(node[u].ls == a && node[u].rs == b)
        return node[u].val;

    int mid = (node[u].ls + node[u].rs) / 2;
    int base = node[u].cv;
    if(b <= mid)        return base + find(2 * u, a, b);
    else if(a > mid)    return base + find(2 * u + 1, a, b);
    else {
        int ret = find(2 * u, a, mid);
        ret = max(ret, find(2 * u + 1, mid + 1, b));
        return base + ret;
    }
}

struct Que que[2010];
int p;
void dp(int n, int *num) {
    //while(que.size())
    //que.pop();
    p = 0;

    build(1, 1, n);

    int pre = 1;

    for(int i = 1; i <= n; i++) {

        set(1 , i , -i + num[i]);
        int ed = i, val = num[i];

        if(num[i] == 0) {
            f[i] = 0;
            pre = i + 1;
            p = 0;
            continue;
        }
        while(p > 0 && que[p].val >= val) {
            int st;

            if(p == 1) {
                st = 1;
            } else {
                st = que[p-1].id + 1;
            }

            add(1 , st , ed - 1, val - que[p].val);
            ed = st;
            p--;
        }

        p ++;
        que[p].id = i;
        que[p].val = num[i];

        if(num[i] == 0) {
            pre = i + 1;
            f[i] = 0;
        } else {
            //f[i] = i;
            f[i] = i + 1 + find(1 , pre , i);
        }
    }

    for(int i = 1; i <= n; i++)
        ans[f[i]] ++;

}

int find_rec()
{
    memset(ans, 0, sizeof(ans));
    memset(num, 0, sizeof(num));

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++)
            if(mmap[i][j] == 'R')   num[j] = 0;
            else                    num[j]++;
        dp(m, num);
    }

    for( int i = 2 * max(n , m) ; i >= 1 ; i-- )
        if(ans[i] > 0)
            return i * 2;

}

int g[1010][1010];

int find_square()
{
    memset( g , 0 , sizeof(g) );

    for(int i = 1 ; i <= n ; i ++)
        g[i][1] = 1;
    for(int j = 1 ; j <= m ; j ++)
        g[1][j] = 1;

    int ans = 1;
    for(int i = 2 ; i <= n ; i ++)for(int j = 2 ; j <= m ; j ++)
        {
            g[i][j] = 1;
            if( mmap[i][j-1] != mmap[i][j] && mmap[i-1][j] == mmap[i][j-1] )
            {
                int u = min( g[i][j-1] , g[i-1][j] );
                if( mmap[i][j] == mmap[i-u][j-u] )
                    g[i][j] = u + 1;
                else
                    g[i][j] = u;
            }
            ans = max( ans , g[i][j] );
        }

    return 4 * ans;
}
int main() {
    freopen("input.txt" , "r" , stdin);
    freopen("output.txt" , "w" , stdout);

    int t, cas = 1;
    scanf("%d", &t);
    while( t-- ) {
        scanf("%d %d", &n, &m);
        for(int i = 1; i <= n; i++)
            scanf("%s", mmap[i] + 1);

        int val = 4;

        val = max( val , find_rec());
        //printf("1 %d\n" , find_rec());

        for(int i = 1 ; i <= n ; i ++)
            for(int j = 1 ; j <= m ; j ++)
                if(mmap[i][j] == 'R')   mmap[i][j] = 'B';
                else                    mmap[i][j] = 'R';

        val = max( val , find_rec() );
        //printf("2 %d\n" , find_rec());
        val = max( val , find_square() );
        //printf("3 %d\n" , find_square());
        printf("Case #%d: %d\n" , cas++, val);

    }
    return 0;
}
