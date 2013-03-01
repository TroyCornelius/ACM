#include <iostream>
#include <string>
#include <fstream>
using namespace std;
ofstream fout("b.in");
//ofstream fout2("b.out");
string num2[10]={"-----",".----","..---","...--","....-",".....","-....","--...","---..","----."};
string num80[10]={"-----","-- ---.","-- ---..","-- ---...","-- ---....","-- ---.....","-....","--...","---..","----."};
int n, p;
void tran2(long long k)
{
     if (k==0) return;
     else
        {
           tran2(k/10);
           fout<<num2[k%10];               
        }     
     }
/*void tran22(long long k)
{
     if (k==0) return;
     else
        {
           tran2(k/10);
          fout2<<num2[k%10];               
        }     
     }*/ 
void tran80(long long k)
{
     if (k==0) return;
     else
        {
           tran80(k/10);
           fout<<num80[k%10];               
        }     
     }
/*void tran81(long long k)
{
     if (k==0) return;
     else
        {
           tran80(k/10);
           fout2<<num80[k%10];               
        }     
     }*/
int main()
{
    
    
    srand(time(NULL));
    n = rand()%20 + 1;
    fout<<n<<endl;
    for (int i=0; i<n; i++)
      {
         p = rand()%2;
         
         if (p==1) 
           {
              fout <<"2"<<endl;
              long long num1 = rand()%1000000; 
              long long num2 = rand()%1000000;
             // num1 = 29961;
           //   num2 = 22709;
              tran2(num1);
              fout<<endl;
              tran2(num2);
              fout<<endl;  
             tran2(num1+num2);
              fout<<endl;
              fout <<num1 <<"    "<<num2 <<"      "<< num1+num2 <<endl ;
                          
           }
         else 
          {
              fout<<"80"<<endl;
             long long num1 = rand()%1000000, num2 = rand()%1000000;
                      //     num1 = 29961;
            //  num2 = 22709;
              tran80(num1);
              fout<<endl;
              tran80(num2);
              fout<<endl;    
             tran80(num1+num2);
             fout<<endl;        
                           fout <<num1 <<"    "<<num2 <<"      "<< num1+num2 <<endl ;   
          }
      }
    
   // system("pause");
    
    return 0;
    }
