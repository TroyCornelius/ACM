#include <cstdio>
#include <iostream>
#include <cmath>
#define eps 1e-6
using namespace std;

struct point
{
   double x, y;
};
 
double dis(point p1, point p2)
{
   point p3;
   p3.x = p2.x - p1.x;
   p3.y = p2.y - p1.y;
   return p3.x * p3.x + p3.y * p3.y;
}
 
point find_centre(point p1, point p2)
{
   point p3, mid, centre;
   double b, c, ang;
   p3.x = p2.x - p1.x;
   p3.y = p2.y - p1.y;
   mid.x = (p1.x + p2.x) / 2;
   mid.y = (p1.y + p2.y) / 2;    
   b = dis(p1, mid);
   c = sqrt(1 - b);
   if(fabs(p3.y) < eps)//´¹ÏßµÄÐ±½Ç¶È
   {
      centre.x = mid.x;
      centre.y = mid.y + c;
   }
   else
   {
      ang = atan(-p3.x / p3.y);
      centre.x = mid.x + c * cos(ang);
      centre.y = mid.y + c * sin(ang);
   }
   return centre;  
}
 
int main()
{
    int n, ans, tmpans, i, j, k;
    point p[305], centre;
        double tmp, xx, yy;
        n = 0;
        while (~scanf("%lf%lf", &xx, &yy) && xx>0) p[n].x = xx, p[n++].y = yy;
        cout <<n <<endl;
      ans = 1;
      for(i = 0;i < n;i++)
        for(j = i + 1;j < n;j++)
        {
           if(dis(p[i], p[j]) > 4.0*6.2500000) continue;
           tmpans = 0;
           centre = find_centre(p[i], p[j]);
           cout <<centre.x <<" "<<centre.y <<endl;
           for(k = 0;k < n;k++)
           {
              //if(tmpans + n - k <= ans) break;
              tmp = dis(centre, p[k]);
              //if(tmp < 1.0 || fabs(tmp - 1.0) < eps) tmpans++;
              if(tmp <= 6.250000001) tmpans++;
           }
           if(ans < tmpans) ans = tmpans;
        }
      printf("%d\n", ans);    
    return 0;
}

