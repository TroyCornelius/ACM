#include <cstdio>
#include <cstring>

using namespace std;
char str[100];
int main()
{
    gets(str);
    int len = strlen(str), j = 0;
    for (int i = 0; i < len && str[i] != ' '; i++) 
        str[j++] = str[i];
    str[j] = '\0';
    puts(str);
    return 0;    
}

