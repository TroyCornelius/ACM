#include <iostream>
#include <cstring>
#include <algorithm>
#include <functional>
#include <cstdio>
#define sf scanf
using namespace std;
int mat[600][600];
int res;
//Stoer-Wagner�㷨�������Լ����ö��ı�ע
//����ͼȫ����С�����prim���Ʒ���o��n^3)��ѧϰ��һ�����硭��
//һ��ʼ��ö��Դ������������⣬���Ӷ�o(n^5) ��ʱ

void Mincut(int n) {
    int node[600], dist[600];
    bool visit[600];
    int i, prev, maxj, j, k;
    for (i = 0; i < n; i++)
        node[i] = i;
    while (n > 1) {
        int maxj = 1;
        for (i = 1; i < n; i++) { //��ʼ������Ȧ���ϵĸ��С
            dist[node[i]] = mat[node[0]][node[i]];
            if (dist[node[i]] > dist[node[maxj]])
                maxj = i;
        }
        prev = 0;
        memset(visit, false, sizeof (visit));
        visit[node[0]] = true;
        for (i = 1; i < n; i++) {
            if (i == n - 1) { //ֻʣ���һ��û���뼯�ϵĵ㣬������С��
                res = min(res, dist[node[maxj]]);
                for (k = 0; k < n; k++) //�ϲ����һ�����Լ��Ƴ����ļ����еĵ�
                    mat[node[k]][node[prev]] = (mat[node[prev]][node[k]] += mat[node[k]][node[maxj]]);
                node[maxj] = node[--n]; //������ͼ
            }
            visit[node[maxj]] = true;
            prev = maxj;
            maxj = -1;
            for (j = 1; j < n; j++)
                if (!visit[node[j]]) { //���ϴ����maxj���뼯�ϣ��ϲ��������ڵıߵ��
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

