#include <stdio.h>
#include <iostream>
using namespace std;


struct node
{
       int cou ;
       char ch ;
       } a ;

int main()
{
    int one , br ;
    char ch ;
    a.cou = 0 ;
    one = 0 ;
    br = 0 ;
    while( true )
    {
       ch = getchar();
       if( ch == '\n' )
       {
          printf( "\n" ) ;
          continue ;
       }
       a.ch = ch , a.cou = 1 ;
       while( ch = getchar() )
       {
       {
           if( a.ch == ch )
           {
               a.cou ++ ;
               if( a.cou > 9 )
               {
                   if( one )
                   {
                      printf( "1" ) ;
                      one = 0 ;
                   }
                   printf( "9%c" , a.ch ) ;
                   a.cou = 1 ;
               }
           }
           else
           {
              if( a.cou == 1 )
              {
                  if(one==0)
                  {
                    printf( "1" ) ;
                    one = 1 ;
                  }
                  if( a.ch == '1' )
                  {
                     printf( "11" ) ;
                  }
                  else
                    printf( "%c" , a.ch ) ;
                  a.ch = ch , a.cou = 1 ;
              }
              else
              {
                 if(one==1)
                 {
                     printf("1") ;
                     one = 0 ;
                 }
                 printf( "%d%c" , a.cou , a.ch ) ;
                 a.ch = ch , a.cou = 1 ;
              }
            }
            }
             if( ch == '\n' )
             {
                 if(one==1) printf("1") ;
                 printf("\n") ;
                 a.cou = 0 ;
                 one = 0 ;
                 break ;
             }
             if( ch == EOF )
             {
                 br = 1 ;
                 if( one )
                 printf( "1" ) ;
                 break ;
             }
            }
            if( br ) break ;
       }
     return 0 ;
}
