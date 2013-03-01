#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
using namespace std;

const double pi = 3.141592653;
const double eps = 1e-8;

struct Point
{
       double x, y;
       };
struct Line
{
       Point a, b;
       }vec1, vec2;
int main()
{
    while (scanf("(%lf,%lf) (%lf,%lf) (%lf,%lf) (%lf,%lf)", &vec1.a.x, &vec1.a.y, &vec1.b.x, &vec1.b.y,&vec2.a.x, &vec2.a.y, &vec2.b.x, &vec2.b.y)!=EOF)
    {
          cout <<vec1.a.x<<" "<<vec1.a.y <<endl;          
    } 
    
    return 0;
    }
