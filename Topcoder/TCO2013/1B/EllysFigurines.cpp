// BEGIN CUT HERE

// END CUT HERE
#line 5 "EllysFigurines.cpp"
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
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;


class EllysFigurines
{
        public:
        int getMoves(vector <string> board, int R, int C)
        {
            int ans = maxint, n = board.size(), m = board[0].size();
            REP(i, 1<<n) {
                vector<string> tmp = board;
                int cnt = 0;
                bool flag;
                for (int j = 0; j < n; j++) {
                    flag = false;
                    if ((i>>j)&1) {
                        for (int x=j; x < min(j+R, n); x++)
                            REP(k, m) tmp[x][k] = '.';
                        cnt++;
                    }
                }
                for (int j = 0; j < m; ) {
                    flag = false;
                    REP(k, n)
                        if (tmp[k][j] == 'X') {
                            cnt++;
                            j += C;
                            flag = true;
                            break;
                        }
                    if (!flag) j++;
                }
                ans = min(ans, cnt);
            }
            return ans;
        }
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {".X.X.",
 "XX..X",
 ".XXX.",
 "...X.",
 ".X.XX"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 2; int Arg3 = 3; verify_case(0, Arg3, getMoves(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arr0[] = {".X.X.",
 "XX..X",
 ".X.X.",
 "...X.",
 ".X.XX"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 2; int Arg3 = 2; verify_case(1, Arg3, getMoves(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arr0[] = {"XXXXXXX"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 3; int Arg3 = 1; verify_case(2, Arg3, getMoves(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arr0[] = {"XXXXX",
 "X....",
 "XXX..",
 "X....",
 "XXXXX"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 1; int Arg3 = 4; verify_case(3, Arg3, getMoves(Arg0, Arg1, Arg2)); }
	void test_case_4() { string Arr0[] = {"XXX..XXX..XXX.",
 ".X..X....X...X",
 ".X..X....X...X",
 ".X..X....X...X",
 ".X...XXX..XXX.",
 "..............",
 "...XX...XXX...",
 "....X......X..",
 "....X....XXX..",
 "....X......X..",
 "...XXX..XXX..."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 2; int Arg3 = 7; verify_case(4, Arg3, getMoves(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
        EllysFigurines ___test;
        ___test.run_test(-1);
        return 0;
}
// END CUT HERE
