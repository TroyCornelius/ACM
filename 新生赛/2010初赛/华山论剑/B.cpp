#include <iostream>
#include <string>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int n, year, month, day;
double num1;
string op, user;
bool pd;
const double mon_days[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
struct client
{
       string name;
       double balance;
       int last_mon, last_day;
       int status; //0 is active 1 is manual quit 2 is force quit 4 is already quit
       
       client (string s, double a, int b, int mon, int dd)
         {
            name = s; balance = a; status = b;        
            last_mon = mon; last_day = dd;      
         }
       };
bool cmp(const client &a, const client &b)
{
      if (a.status != b.status) return a.status < b.status;
      else return a.name < b.name;                           
      }
class Tsystem
{
      private:
              vector <client> d;
      public:
             void add_user(string s, double val, int b, int mon, int dd)
               {
                 d.push_back(client(s, val, b, mon, dd));                                  
               }
             void out_user(string s)
               {
                  for (int i=0; i<d.size(); i++)
                    if (d[i].status!=2 && d[i].name == s) {d[i].status = 1; break;}                                 
               }

             void debit(int which_mon)
               {
                 sort(d.begin(), d.end(), cmp);
                 for (int i=0; i<d.size(); i++)
                   if (d[i].status ==0)
                     {
                        double tt;
                        if (d[i].last_day == 27) tt = 30;
                        else
                          {
                             if (d[i].last_mon == which_mon) 
                               tt = (double(27 - d[i].last_day))/mon_days[which_mon] * 30.0;
                             else
                               {
                                  double tmp = mon_days[d[i].last_mon] - d[i].last_day + 27;
                                  tt = (tmp)/mon_days[which_mon/*d[i].last_mon*/] * 30.0;        
                               }  
                          }
                        cout <<d[i].name<<" ";
                        if (d[i].balance - tt < 0)
                          {
                            printf("%.2lf\n", d[i].balance);
                            d[i].balance -= tt;
                            d[i].status = 2;        
                            pd = true;                                 
                          }
                        else
                          {
                            printf("%.2lf\n", tt);
                            d[i].balance -= tt;            
                            pd = true;                            
                          }
                        d[i].last_mon = which_mon; d[i].last_day = 27; 
                     }    
                    else break;                     
               }
             void acct(int which_mon, int which_day)
               {
                  sort(d.begin(), d.end(), cmp);
                  for (int i=0; i<d.size(); i++)
                    if (d[i].status == 1)
                      {
                         cout<<d[i].name <<" ";
                         double tt;
                         if (which_day > 27)
                           {
                              if (which_mon == d[i].last_mon)
                                {
                                   tt = (which_day-d[i].last_day) / mon_days[which_mon] * 30;
                                }
                              else
                                {
                                   double tmp = (mon_days[d[i].last_mon] - d[i].last_day) + 27;
                                   tt = tmp / mon_days[d[i].last_mon];
                                   tt += (which_day - 27) / mon_days[which_mon];                                      
                                }
                                       
                           }
                         else
                         {
                         if (d[i].last_mon == which_mon) 
                           tt = double((which_day - d[i].last_day))/mon_days[which_mon] * 30;
                         else
                           {
                              double tmp = mon_days[d[i].last_mon] - d[i].last_day + which_day;
                              tt = (tmp)/mon_days[d[i].last_mon] * 30;        
                           }   
                         }           
                         if (d[i].balance - tt < 0) 
                           {
                              d[i].balance -= tt;
                              printf("%.2lf\n", d[i].balance);
                              d[i].status = 2;            
                              pd = true;                              
                           }           
                         else
                           {
                              d[i].balance -= tt;
                              printf("%.2lf\n", tt);
                              d[i].status = 3;          
                              pd = true;                             
                           }                                    
                      }
                    else
                    if (d[i].status >2) break;        
               }
             void query(string s)
               {
                 for (int i=0; i<d.size(); i++)
                   if (d[i].name == s)
                     {
                        if (d[i].status == 0) 
                          {
                            cout <<d[i].name <<" is Active, the balance is ";
                            printf("%.2lf\n", d[i].balance);                                        
                          } 
                        else
                        if (d[i].status == 1 || d[i].status == 3)
                          cout <<d[i].name <<" has perform Manual Quit." <<endl;
                        else
                        if (d[i].status == 2)
                          cout <<d[i].name <<" has been performed Force Quit." <<endl;
                        pd = true;
                        break;                                 
                     }    
               }
      };
Tsystem orz;

int main()
{
    cin >>n;
    for (int i=0; i<n; i++)
      {
          scanf("%d %d %d ", &year, &month, &day);   
          cin >>op;
          pd = false;
          if (op=="IN" || op=="OUT" || op=="Query") 
            {
               cin >>user;
               if (op=="IN")
                 {
                    scanf("%lf", &num1);
                    orz.add_user(user, num1, 0, month, day);       
                 }
               else
               if (op == "OUT")
                 {
                    orz.out_user(user);                      
                 }
               else
                 {
                    orz.query(user);                                                             
                 }                       
            }
          else
          if (op=="ACCT")
            {
               orz.acct(month, day);                         
            }
          else
          if (op=="DEBIT")
            {
              orz.debit(month);                          
            }
          
          if (pd) cout<<endl;
      }
    system("pause");
    return 0;
    }
