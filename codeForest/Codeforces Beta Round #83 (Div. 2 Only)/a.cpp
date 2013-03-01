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
#define Maxn 5000
#define inf 999999999
#define pb push_back
using namespace std;

int hh, mm;
int main()
{
    scanf("%d:%d", &hh, &mm);
    int ti = hh*60+mm;
    if (ti>=0 && ti<= 70) printf("01:10\n");              
    else
    if (hh*60+mm>=70 && hh*60+mm<140) printf("02:20\n");
    else
    if (ti>=140 && ti<210) printf("03:30\n");
    else
    if (ti>=210 && ti<280) printf("04:40\n");
    else
    if (ti>=280 && ti<350) printf("05:50\n");
    else
    if (ti>=350 && ti<601) printf("10:01\n");
    else
    if (ti>=601 && ti<671) printf("11:11\n");
    else
    if (ti>=671 && ti<741) printf("12:21\n");
    else
    if (ti>=741 && ti<811) printf("13:31\n");
    else
    if (ti>=811 && ti<881) printf("14:41\n");
    else
    if (ti>=881 && ti<951) printf("15:51\n");
    else
    if (ti>=951 && ti<1202) printf("20:02\n");
    else
    if (ti>=1202 && ti<1272) printf("21:12\n");
    else
    if (ti>=1272 && ti<1342) printf("22:22\n");
    else
    if (ti>=1342 && ti<1412) printf("23:32\n");
    else printf("00:00\n"); 
    return 0;
    }
