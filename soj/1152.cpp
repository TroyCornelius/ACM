
#include <iostream>
#include <vector>
#include <memory.h>
#include <algorithm>
 
 
using namespace std;
 
struct point
{
    int x;
    int y;
    int totaltonext;
 
};
 
int board[10][10];
 
int move_x[] = {-1, -1, -2, -2, 1, 1, 2, 2};
int move_y[] = {-2, 2, 1, -1, 2, -2, 1, -1};
 
int path[30];
bool dfs(point, int);
bool isvalue(point );
bool cmp(point , point );
 
int main()
{
    int n;
    point p;
 
 
    //freopen("C:\\Users\\Haojian\\Desktop\\test.txt", "r", stdin);
    while (cin >> n && n != -1)
    {
        bool isfind = false;
        memset(board, 0, 10*10*sizeof(int));
        p.x = (n - 1) / 6 + 1;
        p.y = n - ((p.x-1) * 6);
        //p.num = 1;
        //    path[p.num-1] = n;
        path[0] = n;
        board[p.x][p.y] = 1;
        dfs (p, 1);
 
    }
    return 0;
}
 
 
bool dfs (point p, int current)
{
    point n;
 
 
    if (current == 30)
    {
        for (int i = 0; i < 29; i++)
            cout << path[i] << " ";
        cout << path[29];
        cout << endl;
        return true;
    }
    else
    {
        vector<point> tmp;
        for (int i = 0; i < 8; i++)
        {
            n.x = p.x + move_x[i];
            n.y = p.y + move_y[i];
            n.totaltonext = 0;
 
            if (isvalue(n))
            {
 
                point k;
                for (int j = 0; j < 8; j++)
                {
                    k.x = n.x + move_x[j];
                    k.y = n.y + move_y[j];
                    if (isvalue(k))
                        n.totaltonext++;
                }
                tmp.push_back(n);
            }
        }//计算下一个要找的点的扩展点
 
        sort(tmp.begin(), tmp.end(), cmp);//按扩展点从小到大排序
 
        //从扩展点小的开始搜索
        for (int i = 0; i < tmp.size(); i++)
        {
            board[tmp[i].x][tmp[i].y] = 1;
            path[current] = (tmp[i].x - 1) * 6 + tmp[i].y;
            if (dfs(tmp[i], current+1)) return true;
            board[tmp[i].x][tmp[i].y] = 0;
        }
 
 
 
    }
    return false;
}
 
bool cmp(point a, point b)
{
    return a.totaltonext < b.totaltonext;
}
 
bool isvalue(point n)
{
    return (n.x >= 1 && n.x <= 5 && n.y >= 1 && n.y <= 6 && !board[n.x][n.y]);
}
