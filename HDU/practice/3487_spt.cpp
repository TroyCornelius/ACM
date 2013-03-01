#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <time.h>
#include <cctype>
#include <functional>
#include <deque>
#include <iomanip>
#include <bitset>
#include <assert.h>
#include <numeric>
#include <sstream>
#include <utility>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(a) (a).begin(),(a).end()
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define FORD(i,a,b) for (int i=(a); i>=(b); i--)
#define REP(i,b) FOR(i,0,b)
#define ll long long
#define sf scanf
#define pf printf
#define keyTree (ch[ ch[root][1] ][0])
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;
const int maxn = 300100;
struct SplayTree{
	int sz[maxn]; //sz[x]-以x为根结点子树的结点数量
	int ch[maxn][2];    //ch[x][0]-x的左子节点;ch[x][1]-x的右子节点
	int pre[maxn];      //pre[x]-x的父结点
	int root , top1 , top2;    //root-根结点;top1-未用结点队列头指针;top2-结点回收栈的栈顶指针
	int ss[maxn] , que[maxn];
    /* Rotate(x,f):f=0-将x点左旋;f=1-将x点右旋 */
    inline void Rotate(int x,int f) {
        int y = pre[x];
        push_down(y);
        push_down(x);
        ch[y][!f] = ch[x][f];
        pre[ ch[x][f] ] = y;
        pre[x] = pre[y];
        if(pre[x]) ch[ pre[y] ][ ch[pre[y]][1] == y ] = x;
        ch[x][f] = y;
        pre[y] = x;
        push_up(y);
    }
    /* Splay(x,goal):将x结点伸展为goal结点的子节点 */
    inline void Splay(int x, int goal) {
        push_down(x);
        while(pre[x] != goal) {
            if(pre[pre[x]] == goal) {   /* x节点的父结点的父结点为goal,进行单旋转 */
                Rotate(x , ch[pre[x]][0] == x);
            } else {
                int y = pre[x] , z = pre[y];
                int f = (ch[z][0] == y);
                if(ch[y][f] == x) {     /* 一字形旋转 */
                    Rotate(x , !f) , Rotate(x , f);
                } else {                /* 之字形旋转 */
					Rotate(y , f) , Rotate(x , f);
				}
			}
		}
		push_up(x);
		if(goal == 0) root = x;
	}
	inline void RotateTo(int k, int goal) {//把第k位的数转到goal下边
		int x = root;
		push_down(x);   //下放lazy标记
		while(sz[ ch[x][0] ] != k) {
			if(k < sz[ ch[x][0] ]) {
				x = ch[x][0];
			} else {
				k -= (sz[ ch[x][0] ] + 1);
				x = ch[x][1];
			}
			push_down(x);
		}
		Splay(x,goal);
	}
	inline void erase(int x) {//把以x为祖先结点删掉放进内存池,回收内存
		int father = pre[x];
		int head = 0 , tail = 0;
		for (que[tail++] = x ; head < tail ; head ++) {
			ss[top2 ++] = que[head];
			if(ch[ que[head] ][0]) que[tail++] = ch[ que[head] ][0];
			if(ch[ que[head] ][1]) que[tail++] = ch[ que[head] ][1];
		}
		ch[ father ][ ch[father][1] == x ] = 0;
		push_up(father);
	}
    /*get_end(x, c) c=0返回x节点最左边的点，c=1返回x节点最右边的点*/
    inline int get_end(int x, int c) {
        push_down(x);
        while (ch[x][c]) {
            x = ch[x][c];
            push_down(x);
        }
        return x;
    }
    /* join(s1, s2)将跟为s1和s2的两棵spt合并，要求s1所有的节点都小于s2所有节点
     * 返回合并后的根节点*/
    inline int join(int s1, int s2) {
        if (s1 && s2) {
            int right_end = get_end(s1, 1);
            Splay(right_end, pre[s1]);
            ch[right_end][1] = s2;
            pre[s2] = right_end;
            push_up(right_end);
            return right_end;
        }   
        return s1 ? s1 : (s2 ? s2 : 0);
    }
    //erasenNode(x) 将x节点删除，并将其子树进行合并
    inline void eraseNode(int x) {
        int ret = join(ch[x][0], ch[x][1]);
        if (pre[x]) {
            int f = (ch[pre[x]][0] == x);
            ch[pre[x]][!f] = ret;
        }
        else root = ret;
        if (ret) pre[ret] = pre[x];
        if (pre[x]) Splay(pre[x], 0);   //将新树的根的父节点旋转到root
    }
    /*get_near(x, c) c=0返回x节点的前驱节点，c=1返回x节点的后继节点 */
    inline int get_near(int x, int c) {
        if (ch[x][c]) return get_end(ch[x][c], 1-c);
        while (pre[x] && ch[pre[x]][c] == x) x = pre[x];
        return pre[x];
    }
    //返回x节点的前驱节点
    inline int get_succ(int x) {return get_near(x, 1);}
    //返回x节点的后继节点
    inline int get_prev(int x) {return get_near(x, 0);}
	//以上一般不修改//////////////////////////////////////////////////////////////////////////////
	void debug() {printf("%d\n",root);Treaval(root);}
	void Treaval(int x) {
		if(x) {
			Treaval(ch[x][0]);
			printf("结点%2d:左儿子 %2d 右儿子 %2d 父结点 %2d size = %2d ,val = %2d\n",x,ch[x][0],ch[x][1],pre[x],sz[x],val[x]);
			Treaval(ch[x][1]);
		}
	}
	//以上Debug
	//以下是题目的特定函数:
	inline void NewNode(int &x, int c) {
		if (top2) x = ss[--top2];//用栈手动压的内存池
		else x = ++top1;
		ch[x][0] = ch[x][1] = pre[x] = 0;
		sz[x] = 1;
        val[x] = c;     //自己设定初始值
        _rev[x] = false;
	}
    //标记节点
    inline void markNode(int x) {
        if (x) {
            _rev[x] = !_rev[x];
            swap(ch[x][0], ch[x][1]);  //交换节点
            //int tmp = ch[x][0];
            //ch[x][0] = ch[x][1], ch[x][1] = tmp;
        }
    }
	//把延迟标记推到孩子
	inline void push_down(int x) {/*这是题目特定函数*/
        if (_rev[x]) {
            markNode(ch[x][0]);
            markNode(ch[x][1]);
            _rev[x] = false;
        }
    }
    //把孩子状态更新上来
    inline void push_up(int x) {
        sz[x] = 1 + sz[ ch[x][0] ] + sz[ ch[x][1] ];
        /*这是题目特定函数*/
    }
    /*初始化*/
    inline void makeTree(int &x,int l,int r,int f) { //x-son，f-father
        if(l > r) return ;
        int mid = (l + r)>>1;
        NewNode(x , mid);		/*num[m]权值改成题目所需的*/
        makeTree(ch[x][0] , l , mid - 1 , x);
        makeTree(ch[x][1] , mid + 1 , r , x);
        pre[x] = f;
        push_up(x);
    }
    inline void init(int n) {/*初始化函数*/
        ch[0][0] = ch[0][1] = pre[0] = sz[0] = 0;
        root = top1 = top2 = 0;
		makeTree(root , 0 , n + 1 , 0);  //注意这里是0..n+1,加多两个边个节点，不然会TLE的
		push_up(root);
	}
    //返回spt中第k个节点,中序遍历
    inline int find_kth_node(int k) {
        int x, tmp;
        for (x = root; ;) {
            push_down(x);
            tmp = sz[ch[x][0]];  //下放lazy mark
            if (k == tmp + 1) break;  //如果当前节点加上自己等于K，则当前节点x就是要找的点
            if (k <= tmp) x = ch[x][0];  //往左子树走
            else {                       //往右子树走
                k -= tmp + 1;
                x = ch[x][1];
            }
        }
        return x;
    }
    //题目特定功能函数
    inline void Cut() {
        int a, b, c;
        sf("%d%d%d", &a, &b, &c);
        a = find_kth_node(a);   //因为最左边有个边界点，所以这里是a而不是a-1
        Splay(a, 0);
        b = find_kth_node(b+2); //同理，左边多了个边界点，这里是b+2而不是b+1
        Splay(b, root);         //此时keyTree整棵子树就是我们要找的区间[a, b]
        int cut = ch[b][0];
        keyTree = 0;        //删除区间
        a = find_kth_node(c+1);
        Splay(a, 0);
        b = get_succ(a);  //找出c的后继
        Splay(b, root);
        keyTree = cut;   //把cut的子树合并上去
        pre[cut] = b;
        Splay(b, 0);
    }
    inline void Reverse() {
        int a, b;
        sf("%d%d", &a, &b);
        a = find_kth_node(a);
        Splay(a, 0);
        b = find_kth_node(b+2);
        Splay(b, root);
        markNode(keyTree);  //标记节点
    }
    inline void outputNode(int x, int n) {  //中序遍历
        if (x) {
            push_down(x);
            outputNode(ch[x][0], n);
            tot++;
            if (tot != 0 && tot != n+1) {   //边界点不输出
                if (tot == n) pf("%d\n", val[x]);
                else pf("%d ", val[x]);
            }
            outputNode(ch[x][1], n);
        }
    }
    inline void gao(int n, int m) {
        char op[5];
        while (m--) {
            sf("%s", op);
            if (op[0] == 'C') Cut();
            else Reverse();
        }
        tot = -1;
        outputNode(root, n);
    }
	/*这是题目特定变量*/
	int val[maxn], tot;
    bool _rev[maxn];
}spt;
int main() {
	int n , m;
    while (~scanf("%d%d",&n,&m)) {
        if (n == -1 && m == -1) break;
        spt.init(n);  
        spt.gao(n, m);
    }
    return 0;
}
