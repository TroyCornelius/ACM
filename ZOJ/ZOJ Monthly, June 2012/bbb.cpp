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
    int k;//������Ϣ  
}TREE;  
TREE Tree[MAX];  
int keep[MAX],end;//�������ÿռ��ջ  
int Root,top;//�����ڵ� Ԥ�ƿռ䶨λ  
void Right_Turn(int &Root)  //����  
{  
    int k=Tree[Root].left;  
    Tree[Root].left=Tree[k].right;  
    Tree[k].right=Root;  
    Tree[k].num=Tree[Root].num;//ת��ȥ�Ľڵ�����Ϊ��ǰ�˴��ڵ��num  
    Tree[Root].num=Tree[Tree[Root].left].num+Tree[Tree[Root].right].num+1;  
    Root=k;  
}  
void Left_Turn(int &Root) //����  
{  
    int k=Tree[Root].right;  
    Tree[Root].right=Tree[k].left;  
    Tree[k].left=Root;  
    Tree[k].num=Tree[Root].num;  
    Tree[Root].num=Tree[Tree[Root].left].num+Tree[Tree[Root].right].num+1;  
    Root=k;  
}  
void Check_Blance(int &Root,bool flag)//ƽ�⺯��  
{  
    if (flag==false)//��߱�ǿ�Ʋ���  
    {  
        if (Tree[Tree[Tree[Root].left].left].num>Tree[Tree[Root].right].num) //������������������������  
            Right_Turn(Root);  
        else if (Tree[Tree[Tree[Root].left].right].num>Tree[Tree[Root].right].num)//����������������������   
        {  
            Left_Turn(Tree[Root].left);  
            Right_Turn(Root);  
        }  
        else return; //ƽ��  
    }     
    else //�ұ�  
    {  
        if (Tree[Tree[Tree[Root].right].right].num>Tree[Tree[Root].left].num) //ͬ��  
            Left_Turn(Root);  
        else if (Tree[Tree[Tree[Root].right].left].num>Tree[Tree[Root].left].num)  
        {  
            Right_Turn(Tree[Root].right);  
            Left_Turn(Root);  
        }  
        else return;  
    }  
    Check_Blance(Tree[Root].left,false);//�����������������ƽ��  
    Check_Blance(Tree[Root].right,true);//������  
    Check_Blance(Root,true);//���ڵ�������   
    Check_Blance(Root,false);//������  
}  
void Insert(int &Root,int key,int note) //����  
{  
    if (Root==0) //��ײ����  
    {  
        if (end>0) Root=keep[--end];//�������վ����ʣ�࣬�����û���վ��  
        else Root=++top;//��֮ʹ��Ԥ�ÿռ�  
        Tree[Root].key=key;  
        Tree[Root].num=1;  
        Tree[Root].right=0;  
        Tree[Root].left=0;  
        Tree[Root].k=note;//������Ϣ  
    }  
    else  
    {  
        Tree[Root].num++;    
        if (key<Tree[Root].key)  Insert(Tree[Root].left,key,note);  
        if (key>Tree[Root].key)  Insert(Tree[Root].right,key,note);  
        Check_Blance(Root,key>=Tree[Root].key); //ÿ�β����ƽ�����ѹ��ջ��   
    }  
}  
 
int Delete(int &Root,int key)//��Root������ɾ���ؼ�ֵΪkey��Ԫ��  
{  
    Tree[Root].num--;//��������  
    if (key>Tree[Root].key&&Tree[Root].right) return Delete(Tree[Root].right,key);//�����жϽ�ʡʱ��  
    else if (key<Tree[Root].key&&Tree[Root].left) return Delete(Tree[Root].left,key);  
    else//���㵽ɾ���Ľڵ����û���ҵ�ɾ���ģ���ʱɾ�����һ���ڵ�  
    {  
        if (!Tree[Root].left||!Tree[Root].right)//��������һ��Ϊ�գ�����Ϊ�վ���Ҷ��ֱ��fuck��  
        {  
            int temp=Root;//��¼�ڵ�����  
            Root=Tree[Root].left+Tree[Root].right;  
            return temp;//����ɾ���ڵ������  
        }  
        else   
        {  
            int temp=Delete(Tree[Root].left,Tree[Root].key+1);//�ҵ�����������ɾ��  
            int change=Tree[Root].key;  
            int useful=Tree[Root].k;//��¼�ڵ���������Ϣ���˴����ƶ��ڵ㣬��������������ɽ��������������ĵ��������㣩  
            Tree[Root].key=Tree[temp].key;//�ֶ��ı�����ڵ���������Ϣ  
            Tree[Root].k=Tree[temp].k;//�洢������Ϣ  
            Tree[temp].k=useful;  
            Tree[temp].key=change;//�ֶ���¼������Ϣ  
            return temp;//����ɾ���Ľڵ㣨tempΪ���������Ľڵ㣬������������ʱ��ʱɾ���ڵ�ģ�  
        }  
    }         
}  
int Find (int Root,int key)//���ҹؼ�ֵkey��Ԫ��  
{  
    if (key>Tree[Root].key&&Tree[Root].right!=0) return Find(Tree[Root].right,key);  
    else if (key<Tree[Root].key&&Tree[Root].left) return Find(Tree[Root].left,key);  
    else return Root;  
}  
 
int Select(int Root,int Rank)//�ҵ�������rank��Ԫ��  
{  
    if (Rank==Tree[Tree[Root].left].num+1)//�˽ڵ�Ϊ����  
        return Root;  
    else if (Rank<=Tree[Tree[Root].left].num)   
        return Select(Tree[Root].left,Rank);  
    else return Select(Tree[Root].right,Rank-Tree[Tree[Root].left].num-1);//������������  
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
