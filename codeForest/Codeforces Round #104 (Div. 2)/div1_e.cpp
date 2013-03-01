#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define all(a) (a).begin(),(a).end()
#define Maxn 4010000
#define FOR(i,a,b) for (int i(a); i<(b); i++)
#define REP(i, b) FOR(i,0,b)
using namespace std;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
const int inf = 1<<29;
const long long MOD = 1000000007LL;
typedef pair<int,int> pii;
typedef vector<int>::iterator vit;

int n, m;
string s;
int cnt4[Maxn], cnt7[Maxn];
int cnt47[Maxn], cnt74[Maxn];
bool flag[Maxn];
void updata(int root)
{
    cnt4[root] = cnt4[root<<1] + cnt4[root<<1|1];
    cnt7[root] = cnt7[root<<1] + cnt7[root<<1|1];
    
    cnt47[root] = max(cnt47[root<<1]+cnt7[root<<1|1], cnt4[root<<1]+cnt47[root<<1|1]);
    cnt74[root] = max(cnt74[root<<1]+cnt4[root<<1|1], cnt7[root<<1]+cnt74[root<<1|1]);
}

void build(int root, int le, int ri)
{
    flag[root] = false;
    if (le == ri)
    {
        if (s[le-1]=='4') cnt4[root] = 1, cnt7[root] = 0;
        else cnt4[root] = 0, cnt7[root] = 1;
        cnt47[root] = cnt74[root] = 1;
        return;
    }
    int mid = (le + ri) >>1;
    build(root<<1, le, mid);
    build(root<<1|1, mid+1, ri);
    updata(root);
}

void rev(int root)
{
    flag[root] = !flag[root];
    swap(cnt4[root], cnt7[root]);
    swap(cnt47[root], cnt74[root]);    
}

void push_down(int root)
{
    if (!flag[root]) return;
    rev(root<<1);
    rev(root<<1|1);
    flag[root] = false;
}

void cover(int root, int le, int ri, int left, int right)
{
    if (left <= le && ri <= right)
    {
        rev(root);
        return;    
    }
    push_down(root);
    int mid = (le + ri) >>1;
    if (left <= mid) cover(root<<1, le, mid, left, right);
    if (right > mid) cover(root<<1|1, mid+1, ri, left, right);
    updata(root);
}
int main()
{
    //while (1){
    ios::sync_with_stdio(false);
    cin >>n >>m;
    cin >>s;
    build(1, 1, n);
    string op;
    int a, b;
    while (m--)
    {
        cin >>op;
        if (op == "count") cout <<cnt47[1] <<endl;
        else 
        {
            cin >>a >>b;
            cover(1, 1, n, a, b);        
        }
    
    }    
//}
    return 0;
}
