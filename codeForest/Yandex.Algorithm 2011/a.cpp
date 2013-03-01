#include <cstdio>
#include <iostream>
using namespace std;

int n;
string name[5] = {"Sheldon", "Leonard", "Penny", "Rajesh", "Howard"};
int main()
{
    cin >>n;
    int sum=0, tot=1, c=1;
    while (sum + 5*tot < n)
    {
       sum += 5*tot;
       tot*=2;          
       c++;
    }
    int p1 = -1;
    while (sum < n)
    {
       sum += tot;
       p1++;     
    }
    cout <<name[p1] <<endl;

    return 0;
    }
