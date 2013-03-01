/*
 * Author:  Troy
 * Created Time:  2012/6/24 15:11:39
 * File Name: bbb.cpp
 */
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
#define sf scanf
#define pf printf
#define Maxn 15000
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

typedef struct TREE  
{  
    int key,left,right,num;  
    int k;//附加信息  
}TREE;  
TREE Tree[MAX];  
int keep[MAX],end;//保存闲置空间的栈  
int Root,top;//树根节点 预制空间定位  
void Right_Turn(int &Root)  //右旋  
{  
    int k=Tree[Root].left;  
    Tree[Root].left=Tree[k].right;  
    Tree[k].right=Root;  
    Tree[k].num=Tree[Root].num;//转上去的节点数量为先前此处节点的num  
    Tree[Root].num=Tree[Tree[Root].left].num+Tree[Tree[Root].right].num+1;  
    Root=k;  
}  
void Left_Turn(int &Root) //左旋  
{  
    int k=Tree[Root].right;  
    Tree[Root].right=Tree[k].left;  
    Tree[k].left=Root;  
    Tree[k].num=Tree[Root].num;  
    Tree[Root].num=Tree[Tree[Root].left].num+Tree[Tree[Root].right].num+1;  
    Root=k;  
}  
void Check_Blance(int &Root,bool flag)//平衡函数  
{  
    if (flag==false)//左边被强势插入  
    {  
        if (Tree[Tree[Tree[Root].left].left].num>Tree[Tree[Root].right].num) //左子树的左子树大于右子树  
            Right_Turn(Root);  
        else if (Tree[Tree[Tree[Root].left].right].num>Tree[Tree[Root].right].num)//左子树右子树大于右子树   
        {  
            Left_Turn(Tree[Root].left);  
            Right_Turn(Root);  
        }  
        else return; //平衡  
    }     
    else //右边  
    {  
        if (Tree[Tree[Tree[Root].right].right].num>Tree[Tree[Root].left].num) //同上  
            Left_Turn(Root);  
        else if (Tree[Tree[Tree[Root].right].left].num>Tree[Tree[Root].left].num)  
        {  
            Right_Turn(Tree[Root].right);  
            Left_Turn(Root);  
        }  
        else return;  
    }  
    Check_Blance(Tree[Root].left,false);//检查左子树的左子树平衡  
    Check_Blance(Tree[Root].right,true);//右子树  
    Check_Blance(Root,true);//根节点右子树   
    Check_Blance(Root,false);//左子树  
}  
void Insert(int &Root,int key,int note) //插入  
{  
    if (Root==0) //最底层插入  
    {  
        if (end>0) Root=keep[--end];//如果回收站还有剩余，优先用回收站的  
        else Root=++top;//反之使用预置空间  
        Tree[Root].key=key;  
        Tree[Root].num=1;  
        Tree[Root].right=0;  
        Tree[Root].left=0;  
        Tree[Root].k=note;//附加信息  
    }  
    else  
    {  
        Tree[Root].num++;    
        if (key<Tree[Root].key)  Insert(Tree[Root].left,key,note);  
        if (key>Tree[Root].key)  Insert(Tree[Root].right,key,note);  
        Check_Blance(Root,key>=Tree[Root].key); //每次插入把平衡操作压入栈中   
    }  
}  
 
int Delete(int &Root,int key)//在Root的树中删除关键值为key的元素  
{  
    Tree[Root].num--;//减少数量  
    if (key>Tree[Root].key&&Tree[Root].right) return Delete(Tree[Root].right,key);//先行判断节省时间  
    else if (key<Tree[Root].key&&Tree[Root].left) return Delete(Tree[Root].left,key);  
    else//定点到删除的节点或者没有找到删除的，此时删除最后一个节点  
    {  
        if (!Tree[Root].left||!Tree[Root].right)//左右子树一个为空，若都为空就是叶子直接fuck掉  
        {  
            int temp=Root;//记录节点坐标  
            Root=Tree[Root].left+Tree[Root].right;  
            return temp;//返回删除节点的坐标  
        }  
        else   
        {  
            int temp=Delete(Tree[Root].left,Tree[Root].key+1);//找到左子树最大点删除  
            int change=Tree[Root].key;  
            int useful=Tree[Root].k;//记录节点中有用信息，此处不移动节点，仅仅拷贝数据完成交换（左子树最大的点代替这个点）  
            Tree[Root].key=Tree[temp].key;//手动改变替代节点额的有用信息  
            Tree[Root].k=Tree[temp].k;//存储有用信息  
            Tree[temp].k=useful;  
            Tree[temp].key=change;//手动记录有用信息  
            return temp;//返回删除的节点（temp为左子树最大的节点，但是里面数据时此时删除节点的）  
        }  
    }         
}  
int Find (int Root,int key)//查找关键值key的元素  
{  
    if (key>Tree[Root].key&&Tree[Root].right!=0) return Find(Tree[Root].right,key);  
    else if (key<Tree[Root].key&&Tree[Root].left) return Find(Tree[Root].left,key);  
    else return Root;  
}  
 
int Select(int Root,int Rank)//找到排名第rank的元素  
{  
    if (Rank==Tree[Tree[Root].left].num+1)//此节点为所求  
        return Root;  
    else if (Rank<=Tree[Tree[Root].left].num)   
        return Select(Tree[Root].left,Rank);  
    else return Select(Tree[Root].right,Rank-Tree[Tree[Root].left].num-1);//右子树继续找  
}  

void print(int tot)
{
    if (tot == 0) pf("Empty!\n");//cout <<"Empty!" <<endl;
    else
    {
        if (tot % 2 == 0)
        {
            ll t1 = getKth(tot/2, r);
            ll t2 = getKth(tot/2 + 1, r);
            long long s = t1 + t2;
            if (s % 2 == 0) pf("%lld\n", s/2);
            else pf("%lld.5\n", s/2);
        }
        else
        {
            ll t = getKth((tot+1)/2, r);
            pf("%lld\n", t);
        }
    }
}
int n;
int main() 
{
    srand(time(NULL));
    //ios::sync_with_stdio(false);
    int T, cnt;
    ll x;
    char op[10];
    //string op;
    sf("%d", &T);
    //cin >>T;
    while (T--)
    {
        sf("%d", &n);
        r = NULL;
        cnt = 0;
        //cin >>n;
        while (n--)
        {
            sf("%s", op);
            sf("%lld", &x);
            //cin >>op;
            //cin >>x;
            //if (op == "remove")
            if (op[0] == 'r')
            {
                if (cnt == 0 || !dfs(x, r)) pf("Wrong!\n");//cout <<"Wrong!" <<endl;
                else
                {
                    cnt--;
                    del(x, r);
                    print(cnt);
                }
            }
            else
            {
                insert(x, r);
                cnt++;
                print(cnt);
            }
        }
    }
    
    return 0;
}
