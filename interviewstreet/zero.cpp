#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <set>
#include <map>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pii> vp;
typedef vector<vi> vvi;

const int N = 101000;
const ll M = 1000007;
const int K = 16;
const int LIT = 2500;
const int INF = 1 << 30;
const int dir[][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {0, 0}};
const int lowbit(int x) {return x & -x;}

#define mp make_pair
#define pb push_back
#define fst first
#define snd second

struct TNode 
{
    int left, right;
    int depth;
    TNode *LeftChild, *RightChild;
    void construct(int, int, int);
    int GetRank(int lt, int rt);
}Node[2*N+2];

int SortArray[18][N+2], len, n, q;
int ls, rs, key, res;

//vi v;

void TNode::construct(int l, int r, int dep)
{
    left = l; right = r; depth = dep;
    if(left == right)
    {
        scanf("%d", &SortArray[dep][l]);
        //v.pb(SortArray[dep][l]);
        return;
    }
    int mid = (l + r) / 2;
    LeftChild = &Node[len++];
    LeftChild->construct(l, mid, dep+1);
    RightChild = &Node[len++];
    RightChild->construct(mid+1, right, dep+1);
    int i = left, j = mid + 1, k = left;
    while(i <= mid && j <= r)
    {
        if(SortArray[dep+1][i] < SortArray[dep+1][j])
            SortArray[dep][k++] = SortArray[dep+1][i++];
        else
            SortArray[dep][k++] = SortArray[dep+1][j++];
    }
    while(i <= mid) SortArray[dep][k++] = SortArray[dep+1][i++];
    while(j <= right) SortArray[dep][k++] = SortArray[dep+1][j++];
}

int cal(int dep, int l, int r)
{
    for(int i = K; i >= 0; i--)
    {
        int p = key & (1 << i);
        int lt = l, rt = r + 1;
        while(lt < rt)
        {
            int mid = (lt + rt) >> 1;
            int num = SortArray[dep][mid];
            if(num & (1 << i)) rt = mid;
            else lt = mid + 1;
        }
        
        int x = lt - 1;
        if(x < l || x + 1 > r) ;
        else if(!p) r = x;
        else l = x + 1;
    }
    return key ^ SortArray[dep][l];
}

int TNode::GetRank(int l, int r)
{
    if(l == left && right == r) return cal(depth, left, right);
    int mid = (left + right) / 2, tmp = INF;
    if(l <= LeftChild->right) tmp = min(tmp, LeftChild->GetRank(l, min(mid, r)));
    if(RightChild->left <= r) tmp = min(tmp, RightChild->GetRank(max(l, mid+1), r)); 
    return tmp;
}

void init()
{
    //v.clear();
    memset(Node, 0, sizeof(Node));
    memset(SortArray, 0, sizeof(SortArray));
    len = 1;
    Node[0].construct(0, n-1, 0);
}

int chk(int ttt)
{
    int ret = -1;
    for(int i = ls; i <= rs; i++)
    {
        //int tmp = ttt ^ v[i]; ret = max(tmp, ret);    
    }    
    //cout<<ret<<endl;
    return ret;
}

void solve()
{
    int tmp = (1 << K) - 1;
    while(q--)
    {
        scanf("%d %d %d", &key, &ls, &rs);
        ls--, rs--;
        //int ttt = chk(key);
        key ^= tmp;
        res = -1;
        res = Node[0].GetRank(ls, rs);
        res ^= tmp;
        //if(res != ttt) cout<<"error"<<endl;
        printf("%d\n", res);
    }
}

int main()
{
    //freopen("in2.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    
    int T;
    cin>>T;
    
    while(T-- && cin>>n>>q)
    {
        init();
        solve();
    }
    //cout<<"ok"<<endl;
    //while(1);
}
