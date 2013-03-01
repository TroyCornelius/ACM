#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cstring>
#include <stdio.h>

using namespace std;

string s1, s2;
double p;
struct Tnode
{
       double a, b;
       Tnode (double a1=0, double b1=0)
       {
          a = a1; b = b1;     
       }
       };
vector <Tnode> x;
vector <Tnode> y;
vector <double> c;
bool init()
{
     x.clear(); 
     y.clear();
     double tx, ty;
     char ch;
     int tmp;
     while (tmp = scanf("(%lf,%lf)", &tx, &ty) !=EOF)
     {        
        x.push_back(Tnode(tx, ty));
        ch = getchar();
        if (ch == '\n') break;           
     }
     if (tmp == 0) return false;
     while (tmp=scanf("(%lf,%lf)", &tx, &ty))
     {
        y.push_back(Tnode(tx, ty));
        ch = getchar();
        if (ch == '\n') break;           
     }     
     cin >>p;
     getchar();
     if (tmp==0) return false;
     return true;
     }
void calc()
{
     c.clear();
     for (int i=0; i<x.size(); i++)
     {
        c.push_back(sqrt((x[i].a-y[i].a)*(x[i].a-y[i].a) + (x[i].b-y[i].b)*(x[i].b-y[i].b)));         
     }
     
     double ss = 0;
     for (int i=0; i<c.size(); i++) ss += pow(c[i], p);
     printf("%.7lf\n",pow(ss, 1/p));
     }
int main()
{
    while (init())
    {
          calc();
    }
    return 0;
    }
