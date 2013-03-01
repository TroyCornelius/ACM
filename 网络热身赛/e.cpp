#include <iostream>
#include <string>
#include <cstdio>
using namespace std;
const int maxlen = 5000;
struct bignum
{      int len;
       int data[ maxlen ];
       bignum(){
            len = 0;
            memset( data, 0, sizeof(data) );
       }       
       
       void add( bignum a, bignum b ){
            len = max( a.len, b.len ) + 5;
            for ( int i = 0; i < len; i++ ){
                data[i] += a.data[i] + b.data[i];
                data[ i + 1 ] = data[i] / 10;
                data[i] %= 10;
            }
            while ( len > 1 && data[ len - 1 ] == 0 ) len--;
       }
       void print(){
            for ( int i = len - 1; i >= 0; i-- )
            cout << data[i];
            cout << endl;
       }
       };
//bignum A, B;
string a, b;
int T;
int main()
{
    cin >>T;
    for (int t=1; t<=T; t++)
    {
    bignum ans,A,B;
    cin >> a;
    cin >> b;
    A.len = a.size();
    for ( int i = int(a.size())-1, j=0; i >=0; i--, j++ )
    A.data[j] = a[i] - '0';
    B.len = b.size();
    for (int i = int(b.size())-1, j=0; i >=0; i--, j++ )
    B.data[j] = b[i] - '0';
  
    ans.add(A, B);
 
    printf("Case %d:\n", t);
    cout <<a<<" + "<<b<<" = ";
    ans.print();
    if (t != T) printf("\n");
    }
    system("pause");
    return 0;
    }
