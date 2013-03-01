/*
 * Author:  Troy
 * Created Time:  2012/8/26 13:32:46
 * File Name: k.cpp
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
#define Maxn 512100
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

//string a, b;
char a[300], b[Maxn];
int fa[Maxn];
const int kind = 26+26;//儿子结点个数
const int maxn = 512000*2;//总结点数
int root, tot;
int que[maxn];//构造自动机的队列
int w[256];//字符对应表
struct Node {
    int child[kind], fail, id;
    void init() {
        memset(child, 0, sizeof (child));
        fail = id = 0;
    }
} T[maxn];
void init() {
    root = tot = 0;
    T[root].init();
}
void insert(char *s) {//插入单词
    int p = root, index;
    while (*s) {
        index = w[*s];
        if (!T[p].child[index]) {
            T[++tot].init();
            T[p].child[index] = tot;
        }
        p = T[p].child[index];
        s++;
    }
    //T[p].id = id;//根据题目需要
}
void build_ac_auto() {
    int head = 0, tail = 0;
    que[tail++] = root;
    while (head < tail) {
        int u = que[head++];
        for (int i = 0; i < kind; i++) {
            if (T[u].child[i]) {
                int son = T[u].child[i];
                int p = T[u].fail;
                if(u) {
                    T[son].fail = T[p].child[i];
                    T[son].id += T[T[p].child[i]].id;
                }
                que[tail++] = son;
            } else {//trie图，设定虚拟节点
                int p = T[u].fail;
                T[u].child[i] = T[p].child[i];
            }
        }
    }
}

int main() 
{
    for (char ch = 'a'; ch <= 'z'; ch++) w[ch] = ch - 'a';
    for (char ch = 'A'; ch <= 'Z'; ch++) w[ch] = ch - 'A' + 26;
    while (~sf("%s%s", a, b)) {
        init();
        insert(a);
        build_ac_auto();
        
        
    }
    return 0;
}

