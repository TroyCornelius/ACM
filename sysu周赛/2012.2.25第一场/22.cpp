#include <iostream>
 
#include <cmath>

#define N 8096

#define M 2024

using namespace std;
int n;
double R;
const double pi( acos(-1.0));
struct point
 18
 19{
 20
 21    int x, y;
 22
 23}p[M];
 24
 25struct seg
 26
 27{
 28
 29    double apha;
 30
 31    int flag;
 32
 33}s[N];
 34
 35bool cmp(seg a, seg b)
 36
 37{
 38
 39    return a.apha < b.apha;
 40
 41}
 42
 43int main()
 44
 45{
 46
 47    while (scanf("%d %lf", &n, &R) == 2 )
 48
 49    {
 50
 51        if(n == 0 && R == 0) break;
 52
 53        for (int i(0); i < n; i++)
 54
 55            scanf("%d %d", &p[i].x, &p[i].y);
 56
 57        R = R + 0.001;
 58
 59        int cnt = 0;
 60
 61        int ans = 0, sum = 0;
 62
 63        point tp;
 64
 65        double dist, a1, a2;
 66
 67        for (int i(0); i < n; i++)
 68
 69        {
 70
 71            cnt = 0;
 72
 73            for (int j(0); j < n; j++)
 74
 75            {
 76
 77                if (i == j)
 78
 79                    continue;
 80
 81                tp.x = p[i].x - p[j].x;
 82
 83                tp.y = p[i].y - p[j].y;
 84
 85                dist = sqrt(tp.x * tp.x + tp.y * tp.y);
 86
 87 
 88
 89                if(dist <= 2 * R)
 90
 91                {
 92
 93                    double ang = atan2(p[j].y - p[i].y, p[j].x - p[i].x);
 94
 95                    if(ang < 0) ang += 2 * pi;
 96
 97                    double tpa = acos(dist / (2 * R));
 98
 99                    a1 = ang + tpa + 2 * pi;
100
101                    a2 = ang - tpa + 2 * pi;
102
103                    s[cnt].apha = a2, s[cnt].flag = 1;
104
105                    cnt++;
106
107                    s[cnt].apha = a1, s[cnt].flag = 0;
108
109                    cnt++;
110
111                }
112
113            }
114
115            if (ans >= cnt / 2)
116
117                continue;
118
119            sort(s, s + cnt, cmp);
120
121            sum = 0;
122
123            for (int j(0); j < cnt; j++)
124
125            {
126
127                if (s[j].flag) sum ++;
128
129                else sum --;
130
131                if(sum > ans) ans = sum;
132
133            }
134
135        }
136
137        printf("It is possible to cover %d points.\n", ans + 1);
138
139    }
140
141    return 0;
142
143}