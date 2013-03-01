#include <iostream>
#include <cstring>
#include <algorithm>
#include <functional>
#include <cstdio>
#define sf scanf
using namespace std;
int mat[600][600];
int res;
//Stoer-Wagner算法，加了自己看得懂的备注
//无向图全局最小割，用求prim类似方法o（n^3)，学习了一个下午……
//一开始用枚举源点汇点的最大流求解，复杂度o(n^5) 超时

void Mincut(int n) {
    int node[600], dist[600];
    bool visit[600];
    int i, prev, maxj, j, k;
    for (i = 0; i < n; i++)
        node[i] = i;
    while (n > 1) {
        int maxj = 1;
        for (i = 1; i < n; i++) { //初始化到已圈集合的割大小
            dist[node[i]] = mat[node[0]][node[i]];
            if (dist[node[i]] > dist[node[maxj]])
                maxj = i;
        }
        prev = 0;
        memset(visit, false, sizeof (visit));
        visit[node[0]] = true;
        for (i = 1; i < n; i++) {
            if (i == n - 1) { //只剩最后一个没加入集合的点，更新最小割
                res = min(res, dist[node[maxj]]);
                for (k = 0; k < n; k++) //合并最后一个点以及推出它的集合中的点
                    mat[node[k]][node[prev]] = (mat[node[prev]][node[k]] += mat[node[k]][node[maxj]]);
                node[maxj] = node[--n]; //缩点后的图
            }
            visit[node[maxj]] = true;
            prev = maxj;
            maxj = -1;
            for (j = 1; j < n; j++)
                if (!visit[node[j]]) { //将上次求的maxj加入集合，合并与它相邻的边到割集
                    dist[node[j]] += mat[node[prev]][node[j]];
                    if (maxj == -1 || dist[node[maxj]] < dist[node[j]])
                        maxj = j;
                }
        }

    }
    return;
}

int main() {
    int n, m, a, b, v, T;
    while (~sf("%d", &T), T) {
        while (T--){
        sf("%d%d", &n, &m);
        res = (1 << 29);
        int sum = 0;
        for (int i = 0; i < n ; i++)
            for (int j = 0; j < n; j++)
            {
                sf("%d", &mat[i][j]);
                sum += mat[i][j];
            }
        Mincut(n);
        printf("%d\n", sum - 4 * res);
        }
    }
}

