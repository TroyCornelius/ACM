/*
 * Author:  Troy
 * Created Time:  2012/6/24 12:02:44
 * File Name: b.cpp
 */
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <string>

#include <time.h>
#include <cctype>
#include <functional>


#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define aint(a) (a).begin(),(a).end()
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define FORD(i,a,b) for (int i=(a); i>=(b); i--)
#define REP(i,b) FOR(i,0,b)
#define sf scanf
#define pf printf
//#define int int
using namespace std;
//typedef long long int;
struct node {
    int key;
    int fix, sum, rep;
    node *lf, *rg;
} *r;
void update(node *&r) {
    if (!r)return;
    r->sum = r->rep;
    if (r->lf)r->sum += r->lf->sum;
    if (r->rg)r->sum += r->rg->sum;
    return;
}
void rotrg(node *&r) {//�������������� 
    node *tmp = r->lf;
    r->lf = tmp->rg;
    tmp->rg = r;
    update(r);
    r = tmp;
    update(r);
    return;
}
void rotlf(node *&r) {//����������Ҷ��� 
    node *tmp = r->rg;
    r->rg = tmp->lf;
    tmp->lf = r;
    update(r);
    r = tmp;
    update(r);
    return;
}
void insert(int num, node *&r) {//����ڵ� 
    if (!r) {//��ǰ��Ϊ�գ������½ڵ� 
        r = new node;
        r->lf = r->rg = NULL;
        r->key = num;
        r->sum = 0;
        r->rep = 1;
        r->fix = rand();//����������ȼ� 
    } else if (r->key == num)r->rep++;//�����ֵ�Ѿ����� 
    else {
        if (num < r->key) {
            insert(num, r->lf);
            if (r->lf->fix > r->fix)rotrg(r);//���������ӵ� ���ȼ��ȸ��׽��Ĵ���������� 
        } else {
            insert(num, r->rg);
            if (r->rg->fix < r->fix)rotlf(r);//������Ҷ��ӵ� ���ȼ��ȸ��׽��Ĵ���������� 
        }
    }
    update(r);//����treap���������� 
    return;
}
bool dfs(int num, node *&r)
{
    if (!r) return false;
    if (r->key == num) return true;
    else
    {
        if (num < r->key) return dfs(num, r->lf);
        else return dfs(num, r->rg);
    }
}
void del(int num, node *&r)   //ɾ����ֵΪnum�Ľڵ�
 {
    if (!r)return;
    if (num < r->key)del(num, r->lf);
    else if (num > r->key)del(num, r->rg);
    else {
        if (r->rep > 1)r->rep--;
        else if (r->lf == NULL && r->rg == NULL) {//���Ҷ��Ӿ�Ϊ�� 
            delete r;
            r = NULL;
        } else if (r->lf == NULL) {//�����Ϊ�� 
            node *tmp = r;
            r = r->rg;
            delete tmp;
        } else if (r->rg == NULL) {//�Ҷ���Ϊ�� 
            node * tmp = r;
            r = r->lf;
            delete tmp;
        } else {//�������Ҷ��� 
            if (r->lf->fix < r->rg->fix) {//����ӵ����ȼ����Ҷ��ӵ�С 
                rotlf(r);//���Ҷ�����ߣ���Ϊ�µĸ� 
                del(num, r->lf);//�ݹ�ɾ�������� 
            } else {
                rotrg(r);
                del(num, r->rg);
            }
        }
    }
    update(r);
    return;
}
int getKth(int k, node *&r)    //��ѯ���е�KСԪ��
{
    if (k <= 0 || k > r->sum || !r)return 0;
    int tmp = 0;
    if (r->lf)tmp = r->lf->sum;
    if (k > tmp + r->rep)return getKth(k - tmp - r->rep, r->rg);
    else if (k <= tmp)return getKth(k, r->lf);
    else return r->key;
}


void print(int tot)
{
    if (tot == 0) pf("Empty!\n");//cout <<"Empty!" <<endl;
    else
    {
        if (tot % 2 == 0)
        {
            int t1 = getKth(tot/2, r);
            int t2 = getKth(tot/2 + 1, r);
            long long s = ((long long)t1) + ((long long)t2);
            cout <<t1 <<" "<<t2 <<" "<<s <<endl;
            if (s % 2 == 0) pf("%d\n", (int)(s/2));
            else 
            {
                pf("%d.5", (int)(s/2));
                //pf(".5\n");
                //cout <<s/2 <<".5" <<endl;
            }
          /*  double ans = 0.5*t1 + 0.5*t2;
            bool f1 = t1%2, f2 = t2%2;
            if (f1 != f2) pf("%.1f\n", ans);
            else pf("%.0f\n", ans);*/
        }
        else
        {
            int t = getKth((tot+1)/2, r);
            //pf("%I64d\n", t);
            //cout <<t <<endl;
            pf("%d\n", t);
        }
    }
}
int n;
int main() 
{
    //freopen("b.in", "r", stdin);
    //freopen("mb.out", "w", stdout);
    srand(12345);
    //ios::sync_with_stdio(false);
    int T, cnt;
    int x;
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
            sf("%d", &x);
            //cin >>op;
            //cin >>x;
            //if (op == "remove")
            if (op[0] == 'r')
            {
                if (!dfs(x, r)) pf("Wrong!\n");//cout <<"Wrong!" <<endl;
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

