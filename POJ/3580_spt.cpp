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
using namespace std;
const int inf = 1<<29;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;
#define keyTree (ch[ ch[root][1] ][0])
const int maxn = 222222;
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
    /* splay(x,goal):将x结点伸展为goal结点的子节点 */
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
        if (ch[x][c]) return get_end(ch[x][c], c^1);
        while (pre[x] && ch[pre[x]][c] == x) x = pre[x];
        return pre[x];
    }
    //返回x节点的后继节点
    inline int get_succ(int x) {return get_near(x, 1);}
    //返回x节点的前驱节点
    inline int get_prev(int x) {return get_near(x, 0);}
	//以上一般不修改//////////////////////////////////////////////////////////////////////////////
	void debug() {printf("%d\n",root);Treaval(root);}
	void Treaval(int x) {
		if(x) {
			Treaval(ch[x][0]);
			printf("结点%2d:左儿子 %2d 右儿子 %2d 父结点 %2d size = %2d ,val = %2d , min = %d\n",x,ch[x][0],ch[x][1],pre[x],sz[x],val[x],min_num[x]);
			Treaval(ch[x][1]);
		}
	}
	//以上Debug
	//以下是题目的特定函数:
	inline void NewNode(int &x,int c) {
		if (top2) x = ss[--top2];//用栈手动压的内存池
		else x = ++top1;
		ch[x][0] = ch[x][1] = pre[x] = 0;
		sz[x] = 1;
		val[x] = c;/*这是题目特定函数*/
        min_num[x] = c;
		add[x] = 0;
        _rev[x] = false;
	}
    inline void markNode(int x) {
        if (x) {
            swap(ch[x][0], ch[x][1]);
            _rev[x] ^= 1;
        }
    }
    inline void update_add(int x, int c) {
        if (x) {
            add[x] += c;
            val[x] += c;
            min_num[x] += c;
        }
    }
	//把延迟标记推到孩子
	inline void push_down(int x) {/*这是题目特定函数*/
		if(add[x]) {
            update_add(ch[x][0], add[x]);
            update_add(ch[x][1], add[x]);
			add[x] = 0;
		}
        if (_rev[x]) {
            markNode(ch[x][0]);
            markNode(ch[x][1]);
            _rev[x] = false;
        }
	}
	//把孩子状态更新上来
	inline void push_up(int x) {
		sz[x] = 1 + sz[ ch[x][0] ] + sz[ ch[x][1] ];
        min_num[x] = min(min(min_num[ch[x][0]], min_num[ch[x][1]]), val[x]);
	}
	/*初始化*/
	inline void makeTree(int &x,int l,int r,int f) {
		if(l > r) return ;
		int m = (l + r)>>1;
		NewNode(x , num[m]);		/*num[m]权值改成题目所需的*/
		makeTree(ch[x][0] , l , m - 1 , x);
		makeTree(ch[x][1] , m + 1 , r , x);
		pre[x] = f;
		push_up(x);
	}
	inline void init(int n) {/*这是题目特定函数*/
		ch[0][0] = ch[0][1] = pre[0] = sz[0] = 0;
		add[0] = 0;
		root = top1 = top2 = 0;
		//为了方便处理边界,加两个边界顶点
        min_num[0] = val[0] = inf;
		NewNode(root , inf);
		NewNode(ch[root][1] , inf);
		pre[top1] = root;
		sz[root] = 2;
		for (int i = 0 ; i < n ; i ++) scanf("%d",&num[i]);
		makeTree(keyTree , 0 , n-1 , ch[root][1]);
		push_up(ch[root][1]);
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
	/*更新*/
	inline void add_num() {/*这是题目特定函数*/
		int l , r , c;
		scanf("%d%d%d",&l,&r,&c);
		RotateTo(l-1,0);
		RotateTo(r+1,root);
        update_add(keyTree, c);
        push_up(ch[root][1]);
        push_up(root);
	}
	/*询问*/
	inline void query_min() {/*这是题目特定函数*/
		int l , r;
		scanf("%d%d",&l,&r);
        l = find_kth_node(l);
        Splay(l, 0);
        r = find_kth_node(r+2);
        Splay(r, root);
		printf("%d\n", min_num[keyTree]);
	}
    inline void Reverse() {     //反转[L,R]之间的元素
        int l, r;
        sf("%d%d", &l, &r);
        l = find_kth_node(l);
        Splay(l, 0);
        r = find_kth_node(r+2);
        Splay(r, root);
        markNode(keyTree);
    }
    inline void Revolve() {
        int a, b, ti;
        sf("%d%d%d", &a, &b, &ti);
        ti %= b - a + 1;
        if (!ti) return;
        int x = find_kth_node(b - ti + 1);
        Splay(x, 0);
        int y = find_kth_node(b + 2);
        Splay(y, root);
        int cut = keyTree;
        keyTree = 0;
        x = find_kth_node(a);
        Splay(x, 0);
        y = get_succ(x);
        Splay(y, root);
        keyTree = cut;
        pre[keyTree] = y;
        push_up(ch[root][1]);
        push_up(root);
    }
    inline void Insert() {      //在第a个元素后插入num
        int a, num;
        sf("%d%d", &a, &num);
        a = find_kth_node(a+1);
        Splay(a, 0);
        a = get_succ(a);
        Splay(a, root);
        NewNode(keyTree, num);
        pre[keyTree] = ch[root][1];
        push_up(ch[root][1]);
        push_up(root);
    }
    inline void Delete() {
        int l;
        sf("%d", &l);
        int x = find_kth_node(l);
        Splay(x, 0);
        int y = find_kth_node(l+2);
        Splay(y, root);
        erase(keyTree);
    }
    inline void solve(int m) {
        char op[10];
        while (m--) {
            sf("%s", op);
            if (op[0] == 'A') add_num();
            else if (op[0] == 'M') query_min();
            else if (op[0] == 'R' && op[3] == 'E') Reverse();
            else if (op[0] == 'R') Revolve();
            else if (op[0] == 'I') Insert();
            else if (op[0] == 'D') Delete();
        }
    }
	/*这是题目特定变量*/
	int num[maxn];
	int val[maxn];
	int add[maxn];
    bool _rev[maxn];
    int min_num[maxn];
}spt;
int main() {
	int n , m;
    while (~sf("%d", &n)) {
        spt.init(n);
        sf("%d", &m);
        spt.solve(m);
    }
	return 0;
}
