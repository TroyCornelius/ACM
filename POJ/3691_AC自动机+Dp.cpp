#include    <iostream>
#include    <cstdio>
#include    <cstring>
#include    <algorithm>
using namespace std;
const int INF = 10000000;
int code(char ch)
{
     if(ch == 'A') return 0;
     if(ch == 'G') return 1;
     if(ch == 'C') return 2;
          if(ch == 'T') return 3;
}
class ACAutoMachine
{
#define    NXT(u, i)     (u)->nxt[i]            /*  */
#define     CC(u, v)     memset(u, v, sizeof(u))        /*  */
public:
    void initialize()
    {
        pp = pool;
        root = newNode();
    }
    void insert(char *str)
    {
        node *now = root;
        while(*str)
        {
            int idx = code(*str);
            if(NXT(now, idx) == NULL)
                NXT(now, idx) = newNode();
            now = NXT(now, idx);
            str++;
        }
        now->c++;
    }
    void build ()
    {
        head = tail = 0;
        q[tail++] = root;
        while(head != tail)
        {
            node *u = q[head++], *p = NULL;
            for(int i = 0;i < KIND;i++)
            {
                if(NXT(u, i) == NULL)
                    continue;
                if(u == root)
                    NXT(u, i)->fail = root;
                else
                {
                    p = u->fail;
                    while(p)
                    {
                        if(NXT(p, i) == NULL)
                        {
                            p = p->fail;
                            continue;
                        }
                        NXT(u, i)->fail = NXT(p, i);
                        //pass the c mark it as a dangrous node because the fail of is dangrous
                        //一般自动机构造fail没有这句话
                        if(NXT(p, i)->c)
                            NXT(u, i)->c++;
                        break;
                    }
                    if(p == NULL)
                        NXT(u, i)->fail = root;
                }
                q[tail++] = NXT(u, i);
            }
        }
    }
    int DP (int n, char *str)
    {
        int m = pp - pool;
        make_tr(m);
        for(int i = 0;i <= n;i++)
            fill(dp[i], dp[i] + m, INF);
         dp[0][0] = 0;
        for(int i = 0;i < n;i++)
        {
           for(int j = 0;j < m;j++)
            {
                if(dp[i][j] == INF || pool[j].c)
                    continue;
                for(int k = 0;k < KIND;k++)
                {
                     if(tr[j][k] != -1)
                        dp[i + 1][tr[j][k]] = min(dp[i + 1][tr[j][k]], dp[i][j] + (code(str[i]) != k));
                }
            }
        }
        int ans = INF;
        for(int i = 0;i < m;i++)
           ans = min(ans, dp[n][i]);
        if(ans == INF) return -1;
        else return ans;
    }
private:
    const static int KIND = 4, MAXNODE = 1001, N = 1001;
    int dp[N][MAXNODE], tr[MAXNODE][KIND];
    struct node
    {
        node *fail, *nxt[KIND];
        int c;
    }pool[MAXNODE], *pp, *root, *q[MAXNODE];
    int head, tail;
    node *newNode()
    {
       pp->fail = NULL;
        pp->c = 0;
        CC(pp->nxt, 0);
        return pp++;
    }
    void make_tr(int m)
    {
        memset(tr, -1, sizeof(tr));
        for(int i = 0;i < m;i++)
        {
            if(pool[i].c)
                continue;
            for(int j = 0;j < KIND;j++)
           {
                node *p = pool + i;
                while(p)
                {
                    if(p->nxt[j] != NULL)
                    {
                        p = p->nxt[j];
                        break;
                    }
                    p = p->fail;
               }
                if(p == NULL)
                {
                    p = root;
                    if(p->nxt[j] != NULL)
                        p = p->nxt[j];
                }
                if(p->c == 0)
                    tr[i][j] = p - pool;
            }
        }
    }
}AC;

char str[1001];
int main()
{
    int n, cases = 1;
    while(scanf("%d", &n) == 1 && n)
    {
        AC.initialize();
        for(int i = 0;i < n;i++)
        {
            scanf("%s", str);
            AC.insert(str);
        }
        scanf("%s", str);
        AC.build();
        printf("Case %d: %d\n", cases++, AC.DP(strlen(str), str));
    }
    return 0;
}
