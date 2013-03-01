#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>
using namespace std;

int ans;
void SUNDAY(char *text, char *patt)
{ 
    size_t  temp[256]; 
    size_t  *shift = temp; 
    size_t  i, patt_size = strlen(patt), text_size = strlen(text); 
    for( i=0; i < 256; i++ ) *(shift+i) = patt_size+1; 
    for( i=0; i < patt_size; i++ )  
        *(shift+(unsigned char)(*(patt+i))) = patt_size-i;
    //shift['s']=6 步,shitf['e']=5 以此类推 
    size_t  limit = text_size-patt_size+1; 
    for( i=0; i < limit; i += shift[ text[i+patt_size] ] )
        if( text[i] == *patt )
        { 
            char *match_text = text+i+1; 
            size_t  match_size = 1; 
            do
            {// 输出所有匹配的位置 
                if( match_size == patt_size ) ans++;//cout << "the NO. is " << i << endl; 
                if (match_size >= patt_size) break;
            }while((*match_text++) == patt[match_size++] ); 
        } 
} 
char text[10010], patt[1000100];
int main()
{ 
    int T;
    scanf("%d", &T);
    while (T--)
    {
        ans = 0;
        scanf("%s", patt);
        scanf("%s", text);
        SUNDAY(text, patt); 
        printf("%d\n", ans);
    }
    return 0; 
} 

