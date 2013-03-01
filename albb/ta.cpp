#include <stdio.h>
#include <iostream>
using namespace std;


struct node
{// 数据结构，保存连续字符的个数和值
       int cou ;// 保存个数
       char ch ;// 保存该字符
       } a ;

int main()
{
    int one , br ;
    char ch ;// 暂存当前输入的字符
    a.cou = 0 ;// 初始化为0
    one = 0 ;// 初始化为0
    br = 0 ;// 初始化为0
    while( 1 )
    {
       ch = getchar( ) ;// 输入字符
       if( ch == '\n' )// 当第一个输入的字符为'\n'时即为输入空行，则输出空行
       {
          printf( "\n" ) ;
          continue ;
       }
       a.ch = ch , a.cou = 1 ;// 保存当前输入的第一个字符到a结构中
       while( ch = getchar () )// 继续输入字符
       {
       {// 对于ch，结构a中保存的字符即为前一个输入的字符
           if( a.ch == ch )// 若与前一个输入的字符相同，则进行累加
           {
               a.cou ++ ;
               if( a.cou > 9 )// 若累加达到了10个则需先输出前9个
               {
                   if( one )// 若前面存在未输出的全为当字符串时的‘1’结束的标志，先输出‘1’
                   {
                      printf( "1" ) ;
                      one = 0 ;// 把单字符串的标志清楚
                   }
                   printf( "9%c" , a.ch ) ;// 输出9个连续相同的编码
                   a.cou = 1 ;// 把相同的字符个数置为 1
               }
           }
           else// 当前输入的字符与前一个输入的字符不相同
           {
              if( a.cou == 1 )// 当前一个字符的个数只是一个时
              {
                  if( !one )// 判断前面是不是一个未终止的单字符串，
                  {
                    printf( "1" ) ;
                    one = 1 ;// 单字符串的标志置为1
                  }
                  if( a.ch == '1' )// 若前一个字符为‘1’则输出‘11’，否则输出前一个字符
                  {
                     printf( "11" ) ;
                  }
                  else
                    printf( "%c" , a.ch ) ;
                  
                  a.ch = ch , a.cou = 1 ;// 保存当前字符到a中
              }
              else
              {
                 if( one )//若前面是单字符串，即单字符串标志one为1
                 {
                     printf( "1" ) ;
                     one = 0 ;
                 }
                 printf( "%d%c" , a.cou , a.ch ) ;// 输出a的编码情况
                 a.ch = ch , a.cou = 1 ;// 保存当前字符到a中
              }
            }
            }
             if( ch == '\n' )// 若当前的字符是'\n'，则一行的输入结束，
             {
                 if( one )// 若单字符串标志one为1，则结束单字符串
                    printf( "1" ) ;
                 printf( "\n" ) ;// 输出换行
                 a.cou = 0 ;// 初始置为0
                 one = 0 ;
                 break ;
             }
             if( ch == EOF )// 若当前输入的字符是EOF，这整个程序的输入结束
             {
                 br = 1 ;// 设置标志，以便退出整个程序
                 if( one )// 若单字符串标志one为1，则结束单字符串
                 printf( "1" ) ;
                 printf( "\n" ) ;
                 break ;
             }
            }
            if( br ) break ;// 退出循环，以退出程序
       }
return 0 ;
}
