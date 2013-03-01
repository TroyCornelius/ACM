#include <iostream>
#include <cstring>

using namespace std;

int bag[5];
void pr()
{
     for (int i=0; i<5; i++) cout <<bag[i] <<" ";
     cout <<endl;
     }
int main()
{
    int num;
    //freopen("a.txt", "w", stdout);
    for (int i=4; i<=10; i++)
    {
    cin >>num;
        memset(bag, 0, sizeof(bag));
        bag[0] = num; bag[1] = 1;
        bool flag = true;
        while (1)
        {
              
            bag[1]++;
            bag[4] = 0;
            pr();
            while (bag[0])
            {
                while (bag[0]>0 && bag[1]>0)
                {
                    bag[0]--; bag[1]--;
                    bag[2]++; bag[3]++;
                }
                bag[4]++;
                if (bag[0] == 0 && bag[1] == 0)
                {
                    bag[4] += bag[3];
                    flag = false;
                    bag[3] = 0;
                    break;                
                }
                if (!flag)break;
                bag[1] += bag[3]; bag[3] = 0;
                pr();
            }
            if (!flag) break;
            bag[0] += bag[2]; bag[2] = 0;        
        }
    cout <<bag[4] <<" " <<i <<endl;
   system("pause");
    }
    

    return 0;
}
