// 9941. GRE Words
// Problem code: GRE
#include <ctime>
#include <iostream>
#include <map>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 300000;

int n, w[N], len[N], begin[N],
    trieCnt, fail[N], queue[N],
    firstEdge[N], nextEdge[N],
    dfsCnt, pos[N], size[N],
    delta[N << 2], dp[N];
char str[N];
map <char, int> childs[N];

void dfs (int u) {
    pos[u] = dfsCnt ++;
    size[u] = 1;
    for (int iter = firstEdge[u]; iter != -1; iter = nextEdge[iter]) {
        dfs(iter);
        size[u] += size[iter];
    }
}

void updateMax (int &x, int a) {
    x = max(x, a);
}

void cover (int t, int l, int r, int a, int b, int v) {
    if (b < l || r < a) {
        return;
    }
    if (a <= l && r <= b) {
        updateMax(delta[t], v);
    } else {
        int m = (l + r) >> 1;
        cover(t + t, l, m, a, b, v);
        cover(t + t + 1, m + 1, r, a, b, v);
    }
}

int query (int t, int l, int r, int a) {
    if (a < l || r < a) {
        return 0;
    }
    if (l == a && a == r) {
        return delta[t];
    }
    int m = (l + r) >> 1;
    return max(delta[t],
            max(query(t + t, l, m, a), query(t + t + 1, m + 1, r, a)));
}

int main () {
    int testCnt;
    scanf("%d", &testCnt);
    for (int t = 1; t <= testCnt; ++ t) {
        scanf("%d", &n);
        begin[0] = 0;
        for (int i = 0; i < n; ++ i) {
            scanf("%s", str + begin[i]);
            // w[i] = 1
            scanf("%d", w + i);
            len[i] = strlen(str + begin[i]);
            begin[i + 1] = begin[i] + len[i];
        }
        trieCnt = 1;
        for (int i = 0; i < n; ++ i) {
            int cur = 0;
            for (int j = begin[i]; j < begin[i] + len[i]; ++ j) {
                if (not childs[cur].count(str[j])) {
                    childs[trieCnt].clear();
                    childs[cur][str[j]] = trieCnt ++;
                }
                cur = childs[cur][str[j]];
            }
        }
        int head = 0, tail = 0;
        for (map <char, int> :: iterator iter = childs[0].begin();
                iter != childs[0].end(); ++ iter) {
            fail[iter->second] = 0;
            queue[tail ++] = iter->second;
        }
        while (head != tail) {
            for (map <char, int> :: iterator iter = childs[queue[head]].begin();
                    iter != childs[queue[head]].end(); ++ iter) {
                fail[iter->second] = 0;
                int tmp = queue[head];
                while (tmp != 0) {
                    tmp = fail[tmp];
                    if (childs[tmp].count(iter->first)) {
                        fail[iter->second] = childs[tmp][iter->first];
                        break;
                    }
                }
                queue[tail ++] = iter->second;
            }
            head += 1;
        }
        memset(firstEdge, -1, sizeof(firstEdge));
        for (int i = 1; i < trieCnt; ++ i) {
            nextEdge[i] = firstEdge[fail[i]];
            firstEdge[fail[i]] = i;
            //cout <<fail[i] <<" "<<i <<endl;
        }
        dfsCnt = 0;
        dfs(0);
        memset(delta, 0, sizeof(delta));
        int result = 0;
        for (int i = 0; i < n; ++ i) {
            dp[i] = 0;
            int cur = 0;
            for (int j = begin[i]; j < begin[i] + len[i]; ++ j) {
                cur = childs[cur][str[j]];
            //cout <<cur <<" ";
                //cout <<pos[cur] <<endl;
                updateMax(dp[i],
                        query(1, 0, trieCnt - 1, pos[cur]));
            }
            dp[i] += w[i];
            //cout <<cur <<endl;
            //cout <<pos[cur]+1 <<" "<<pos[cur] + size[cur]  <<endl;
            cover(1, 0, trieCnt - 1, pos[cur], pos[cur] + size[cur] - 1, dp[i]);
            updateMax(result, dp[i]);
        }
        printf("Case #%d: %d\n", t, result);
        for (int i = 0; i < N; i++)
            childs[i].clear();
    }
    return 0;
}

