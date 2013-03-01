/*
 * Author:  Teletubbies
 * Created Time:  2012年10月03日 星期三 14时19分36秒
 * File Name: d.cpp
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
using namespace std;
const int maxint = -1u>>1;
const double pi = 3.14159265358979323;
const double eps = 1e-8;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vit;

int n, m, b, c, d;
int x, y, dir;
char now[5];
int le[10], ri[10], forward[10], back[10];
int w[256];
int poslmr, posfmb;
string ansstr;
void initDir() {
    le[1] = 1, ri[1] = 1, forward[1] = 4, back[1] = 2;
    le[2] = 5, ri[2] = 6, forward[2] = 1, back[2] = 3;
    le[3] = 3, ri[3] = 3, forward[3] = 2, back[3] = 4;
    le[4] = 4, ri[4] = 4, forward[4] = 3, back[4] = 1;
    le[5] = 4, ri[5] = 2, forward[5] = 5, back[5] = 5;
    le[6] = 2, ri[6] = 4, forward[6] = 6, back[6] = 6;
    w['T'] = 2, w['L'] = 5, w['R'] = 6, w['F'] = 1, w['B'] = 3;
}
void goForward(int &x, int &y, int &dir) {
    x++;
    dir = forward[dir];
}
void goBack(int &x, int &y, int &dir) {
    x--;
    dir = back[dir];
}
void goLeft(int &x, int &y, int &dir) {
    y--;
    dir = le[dir];
}
void goRight(int &x, int &y, int &dir) {
    y++;
    dir = ri[dir];
}
void goForwardFromLeft(int &x, int &y) {
    ansstr += "LFR";
    x++;
}
void goForwardFromRight(int &x, int &y) {
    ansstr += "RFL";
    x++;
}
void goBackFromLeft(int &x, int &y) {
    ansstr += "LBR";
    x--;
}
void goBackFromRight(int &x, int &y) {
    ansstr += "RBL";
    x--;
}
void goLeftFromForward(int &x, int &y) {
    ansstr += "FLB";
    y--;
}
void goLeftFromBack(int &x, int &y) {
    ansstr += "BLF";
    y--;
}
void goRightFromForward(int &x, int &y) {
    ansstr += "FRB";
    y++;
}
void goRightFromBack(int &x, int &y) {
    ansstr += "BRF";
    y++;
}
bool work() {
    x = 1, y = b, dir = w[now[0]];
    poslmr = d > y ? -1 : (d < y);
    if(y == d) {
        if(dir == 6 || dir == 5) {
            for(int i = 1; i < c; i++)
                ansstr += 'F';
            return true;
        }
    }
    if(x == c) {
        if(dir == 1 || dir == 3) {
            if(y < d) {
                for(int i = y; i < d; i++) {
                    ansstr += 'R';
                }
            } else {
                for(int i = d; i < y; i++) {
                    ansstr += 'L';
                }
            }
            return true;
        }
    }
    //cout << poslmr << endl;
    if(n == 1 || m == 1) {
        if(n == 1) {
            if(dir == 1 || dir == 3) {
                if(y < d) {
                    for(int i = y; i < d; i++) {
                        ansstr += 'R';
                    }
                } else {
                    for(int i = d; i < y; i++) {
                        ansstr += 'L';
                    }
                }
                return true;
            }
            if(poslmr == 1) {
                int tmp = abs(y - d);
                if(tmp == 1) {
                    ansstr = "L";
                    return true;
                } else if(tmp == 2 && dir == 6) {
                    ansstr = "LL";
                    return true;
                } else return false;
            } else {
                int tmp = abs(y - d);
                if(tmp == 1) {
                    ansstr = "R";
                    return true;
                } else if(tmp == 2 && dir == 5) {
                    ansstr = "RR";
                    return true;
                } else return false;
            }
        } else {
            if(dir == 5 || dir == 6) {
                for(int i = 1; i < c; i++)
                    ansstr += 'F';
                return true;
            } else {
                int tmp = abs(x - c);
                if(tmp == 1) {
                    ansstr = "F";
                    return true;
                } else if(tmp == 2 && dir == 3) {
                    ansstr = "FF";
                    return true;
                } else return false;
            }
        }
    }
    if(dir == 5) goRight(x, y, dir), ansstr += 'R';
    else if(dir == 6) goLeft(x, y, dir), ansstr += 'L';
    else if(dir == 3) goForward(x, y, dir), ansstr += 'F';
    
    if(x == c && y == d) return true;
    if(x < c) {
        int tmp = abs(x - c);
        for(int i = 1; i <= tmp; i++)
            if(y < m) goForwardFromRight(x, y);
            else goForwardFromLeft(x, y);
    }
    if(x == c && y == d) return true;
    if(y > d) {
        int tmp = abs(y - d);
        for(int i = 1; i <= tmp; i++)
            if(x < n) goLeftFromForward(x, y);
            else goLeftFromBack(x, y);
        return true;
    } else if(y < d) {
        int tmp = abs(y - d);
        for(int i = 1; i <= tmp ; i++)
            if(x < n) goRightFromForward(x, y);
            else goRightFromBack(x, y);
        return true;
    }
    return false;
}
int main() {
    //freopen("d.in", "r", stdin);
    //freopen("d.out", "w", stdout);
    initDir();
    while (cin >> n >> m >> b >> c >> d) {
        cin >> now;
        cout <<n <<" "<<m <<" "<<b <<" " <<c <<" "<<d <<endl;
        cout <<now <<endl;
        if(1 == c && b == d) {
            puts("");
            continue;
        }
        if(now[0] == 'F' && c > 1) {
            puts("IMPOSSIBLE");
            continue;
        }
        if(b == 1 && now[0] == 'R' && d > 1) {
            puts("IMPOSSIBLE");
            continue;
        }
        if(b == m && now[0] == 'L' && d < m) {
            puts("IMPOSSIBLE");
            continue;
        }
        ansstr = "";
        int cnt=0;
        if(!work()) puts("IMPOSSIBLE");
        else {
            int xx = 1, yy = b;
            for(int i = 0; i < ansstr.size(); i++) {
                cnt++;
                if(ansstr[i] == 'F') xx++;
                else if(ansstr[i] == 'B') xx--;
                else if(ansstr[i] == 'L') yy--;
                else yy++;
                if (xx<1 || xx>n || yy<1 || yy>m) while (1);
                putchar(ansstr[i]);
                if(xx == c && yy == d) break;
            }
            if (cnt>4*(n+m)) while(1);
            //cout << cnt << endl;
            puts("");
        }
    }
    return 0;
}

