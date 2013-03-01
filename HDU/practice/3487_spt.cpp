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
	int sz[maxn]; //sz[x]-��xΪ����������Ľ������
	int ch[maxn][2];    //ch[x][0]-x�����ӽڵ�;ch[x][1]-x�����ӽڵ�
	int pre[maxn];      //pre[x]-x�ĸ����
	int root , top1 , top2;    //root-�����;top1-δ�ý�����ͷָ��;top2-������ջ��ջ��ָ��
	int ss[maxn] , que[maxn];
    /* Rotate(x,f):f=0-��x������;f=1-��x������ */
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
    /* Splay(x,goal):��x�����չΪgoal�����ӽڵ� */
    inline void Splay(int x, int goal) {
        push_down(x);
        while(pre[x] != goal) {
            if(pre[pre[x]] == goal) {   /* x�ڵ�ĸ����ĸ����Ϊgoal,���е���ת */
                Rotate(x , ch[pre[x]][0] == x);
            } else {
                int y = pre[x] , z = pre[y];
                int f = (ch[z][0] == y);
                if(ch[y][f] == x) {     /* һ������ת */
                    Rotate(x , !f) , Rotate(x , f);
                } else {                /* ֮������ת */
					Rotate(y , f) , Rotate(x , f);
				}
			}
		}
		push_up(x);
		if(goal == 0) root = x;
	}
	inline void RotateTo(int k, int goal) {//�ѵ�kλ����ת��goal�±�
		int x = root;
		push_down(x);   //�·�lazy���
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
	inline void erase(int x) {//����xΪ���Ƚ��ɾ���Ž��ڴ��,�����ڴ�
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
    /*get_end(x, c) c=0����x�ڵ�����ߵĵ㣬c=1����x�ڵ����ұߵĵ�*/
    inline int get_end(int x, int c) {
        push_down(x);
        while (ch[x][c]) {
            x = ch[x][c];
            push_down(x);
        }
        return x;
    }
    /* join(s1, s2)����Ϊs1��s2������spt�ϲ���Ҫ��s1���еĽڵ㶼С��s2���нڵ�
     * ���غϲ���ĸ��ڵ�*/
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
    //erasenNode(x) ��x�ڵ�ɾ�����������������кϲ�
    inline void eraseNode(int x) {
        int ret = join(ch[x][0], ch[x][1]);
        if (pre[x]) {
            int f = (ch[pre[x]][0] == x);
            ch[pre[x]][!f] = ret;
        }
        else root = ret;
        if (ret) pre[ret] = pre[x];
        if (pre[x]) Splay(pre[x], 0);   //�������ĸ��ĸ��ڵ���ת��root
    }
    /*get_near(x, c) c=0����x�ڵ��ǰ���ڵ㣬c=1����x�ڵ�ĺ�̽ڵ� */
    inline int get_near(int x, int c) {
        if (ch[x][c]) return get_end(ch[x][c], 1-c);
        while (pre[x] && ch[pre[x]][c] == x) x = pre[x];
        return pre[x];
    }
    //����x�ڵ��ǰ���ڵ�
    inline int get_succ(int x) {return get_near(x, 1);}
    //����x�ڵ�ĺ�̽ڵ�
    inline int get_prev(int x) {return get_near(x, 0);}
	//����һ�㲻�޸�//////////////////////////////////////////////////////////////////////////////
	void debug() {printf("%d\n",root);Treaval(root);}
	void Treaval(int x) {
		if(x) {
			Treaval(ch[x][0]);
			printf("���%2d:����� %2d �Ҷ��� %2d ����� %2d size = %2d ,val = %2d\n",x,ch[x][0],ch[x][1],pre[x],sz[x],val[x]);
			Treaval(ch[x][1]);
		}
	}
	//����Debug
	//��������Ŀ���ض�����:
	inline void NewNode(int &x, int c) {
		if (top2) x = ss[--top2];//��ջ�ֶ�ѹ���ڴ��
		else x = ++top1;
		ch[x][0] = ch[x][1] = pre[x] = 0;
		sz[x] = 1;
        val[x] = c;     //�Լ��趨��ʼֵ
        _rev[x] = false;
	}
    //��ǽڵ�
    inline void markNode(int x) {
        if (x) {
            _rev[x] = !_rev[x];
            swap(ch[x][0], ch[x][1]);  //�����ڵ�
            //int tmp = ch[x][0];
            //ch[x][0] = ch[x][1], ch[x][1] = tmp;
        }
    }
	//���ӳٱ���Ƶ�����
	inline void push_down(int x) {/*������Ŀ�ض�����*/
        if (_rev[x]) {
            markNode(ch[x][0]);
            markNode(ch[x][1]);
            _rev[x] = false;
        }
    }
    //�Ѻ���״̬��������
    inline void push_up(int x) {
        sz[x] = 1 + sz[ ch[x][0] ] + sz[ ch[x][1] ];
        /*������Ŀ�ض�����*/
    }
    /*��ʼ��*/
    inline void makeTree(int &x,int l,int r,int f) { //x-son��f-father
        if(l > r) return ;
        int mid = (l + r)>>1;
        NewNode(x , mid);		/*num[m]Ȩֵ�ĳ���Ŀ�����*/
        makeTree(ch[x][0] , l , mid - 1 , x);
        makeTree(ch[x][1] , mid + 1 , r , x);
        pre[x] = f;
        push_up(x);
    }
    inline void init(int n) {/*��ʼ������*/
        ch[0][0] = ch[0][1] = pre[0] = sz[0] = 0;
        root = top1 = top2 = 0;
		makeTree(root , 0 , n + 1 , 0);  //ע��������0..n+1,�Ӷ������߸��ڵ㣬��Ȼ��TLE��
		push_up(root);
	}
    //����spt�е�k���ڵ�,�������
    inline int find_kth_node(int k) {
        int x, tmp;
        for (x = root; ;) {
            push_down(x);
            tmp = sz[ch[x][0]];  //�·�lazy mark
            if (k == tmp + 1) break;  //�����ǰ�ڵ�����Լ�����K����ǰ�ڵ�x����Ҫ�ҵĵ�
            if (k <= tmp) x = ch[x][0];  //����������
            else {                       //����������
                k -= tmp + 1;
                x = ch[x][1];
            }
        }
        return x;
    }
    //��Ŀ�ض����ܺ���
    inline void Cut() {
        int a, b, c;
        sf("%d%d%d", &a, &b, &c);
        a = find_kth_node(a);   //��Ϊ������и��߽�㣬����������a������a-1
        Splay(a, 0);
        b = find_kth_node(b+2); //ͬ����߶��˸��߽�㣬������b+2������b+1
        Splay(b, root);         //��ʱkeyTree����������������Ҫ�ҵ�����[a, b]
        int cut = ch[b][0];
        keyTree = 0;        //ɾ������
        a = find_kth_node(c+1);
        Splay(a, 0);
        b = get_succ(a);  //�ҳ�c�ĺ��
        Splay(b, root);
        keyTree = cut;   //��cut�������ϲ���ȥ
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
        markNode(keyTree);  //��ǽڵ�
    }
    inline void outputNode(int x, int n) {  //�������
        if (x) {
            push_down(x);
            outputNode(ch[x][0], n);
            tot++;
            if (tot != 0 && tot != n+1) {   //�߽�㲻���
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
	/*������Ŀ�ض�����*/
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
