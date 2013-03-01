#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <functional>
#include <vector>
#include <map>
#include <cstring>
#include <string>
#include <list>
#include <set>
#include <bitset>
#include <cctype>
#include <cmath>
#include <ctime>
#include <numeric>
#include <utility>
#include <stack>
#include <queue>
#include <deque>
#include <iomanip>
#include <cassert>
#define pb push_back
#define mp make_pair
#define inf 999999999
#define Maxn 1100

using namespace std;
typedef pair<int, int> pii;
typedef priority_queue<int, vector<int>, less<int> > PQ;
string s;
int n;
int pile[2];
int main()
{
    char op[10];
    int a;
    bool flag = false;
    while (~scanf("%d", &n), n)
    {
        if (flag) printf("\n");
        flag = true;
        pile[0] = pile[1] = 0;
        for(int i = 0; i < n; i++) {
            scanf("%s%d", op, &a);
            if(strcmp(op, "DROP") == 0) {
                printf("DROP 2 %d\n", a);
                pile[1] += a;
            } else {
                if(pile[0] == 0) {
                    swap(pile[0], pile[1]);
                    printf("MOVE 2->1 %d\n", pile[0]);
                }
                if(a <= pile[0]) {
                    printf("TAKE 1 %d\n", a);
                    pile[0] -= a;
                }
                else {
                    printf("TAKE 1 %d\n", pile[0]);
                    a -= pile[0], pile[0] = 0;
                    swap(pile[0], pile[1]);
                    printf("MOVE 2->1 %d\n", pile[0]);
                    printf("TAKE 1 %d\n", a);
                    pile[0] -= a;
                }
            }
        }
    }
    return 0;
}

