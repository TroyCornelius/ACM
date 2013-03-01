#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
#include <vector>

using namespace std;

const int MAX_SIZE = 100 + 1;
const int INF = 0x7f7f7f7f;
int N, M;
int L, K;

int Grid[MAX_SIZE][MAX_SIZE];
int Monster[MAX_SIZE][MAX_SIZE];
int D[MAX_SIZE][MAX_SIZE][1 << 6];
int B[10];
int dx[] = {0, 1, -1, 0};
int dy[] = {1, 0, 0, -1};

struct Coord
{
    int x, y, s;
};

struct comp
{
    bool operator () (const Coord &a, const Coord &b)
    {
        return D[a.x][a.y][a.s] > D[b.x][b.y][b.s];
    }
};

void init()
{
    memset(Monster, -1, sizeof(Monster));
    memset(D, 0x7f, sizeof(D));
    memset(B, 0, sizeof(B));
}

void input()
{
    int x, y;
    scanf("%d%d", &N, &M);
    for(int i = 1; i <= N; ++i)
    {
        for(int j = 1; j <= M; ++j)
        {
            scanf("%d", &Grid[i][j]);
        }
    }
    scanf("%d%d", &L, &K);
    for(int i = 1; i <= L; ++i)
    {
        scanf("%d%d%d", &x, &y, &B[i - 1]);
        Monster[x][y] = i - 1;
    }
}
bool isCoordValid(const int &x, const int &y)
{
    if(x >= 1 && x <= N && y >= 1 && y <= M && Grid[x][y] > 0)
        return true;
    return false;
}

int searchPath()
{
    priority_queue<Coord, vector<Coord>, comp> que;
    Coord start;
    start.x = start.y = 1;
    start.s = 0;
    if(Monster[1][1] != -1)
        start.s |= 1 << Monster[1][1];
    D[start.x][start.y][start.s] = 0;
    que.push(start);
    while(!que.empty())
    {
        Coord cur = que.top();
        que.pop();
        if(cur.x == N && cur.y == M)
            return D[cur.x][cur.y][cur.s];
        if(cur.s != 0)
        {
            int sumB = 0;
            for(int i = 0; i < 5; ++i)
            {
                if((cur.s & (1 << i)) != 0)
                    sumB += B[i];
            }
            if(Grid[cur.x][cur.y] > K - sumB)
                continue;
        }
        Coord newNode;
        for(int i = 0; i < 4; ++i)
        {
            newNode.x = cur.x + dx[i];
            newNode.y = cur.y + dy[i];
            newNode.s = cur.s;
            if(isCoordValid(newNode.x, newNode.y))
            {
                if(Monster[newNode.x][newNode.y] != -1)
                    newNode.s |= 1 << Monster[newNode.x][newNode.y];
                if(D[newNode.x][newNode.y][newNode.s] > D[cur.x][cur.y][cur.s] + Grid[cur.x][cur.y])
                {
                    D[newNode.x][newNode.y][newNode.s] = D[cur.x][cur.y][cur.s] + Grid[cur.x][cur.y];
                    que.push(newNode);
                }
            }
        }
    }
    return -1;
}

int main(int argc, char **argv)
{
    /*  
    freopen(argv[1], "r", stdin);
    for(int i = 0; argv[1][i]; ++i)
    {
        if(argv[1][i] == '.')
        {
            argv[1][i + 1] = 'o';
            argv[1][i + 2] = 'u';
            argv[1][i + 3] = 't';
            argv[1][i + 4] = 0;
            break;
        }
    }
    freopen(argv[1], "w", stdout);
    */

    init();
    input();
    int ans = searchPath();
    if(ans == -1)
        printf("Oh~,poor boys and girls!\n");
    else
        printf("%d\n", ans);
    return 0;
}


