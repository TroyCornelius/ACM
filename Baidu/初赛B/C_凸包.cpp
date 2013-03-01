#include <stdio.h>

#define MAX_N 100032

int S[MAX_N], stack[MAX_N], N, F, sp;

__inline int turn_right(int a, int b, int c)
{
    int x1, y1, x2, y2;

    x1 = b - a;
    y1 = S[b] - S[a];
    x2 = c - b;
    y2 = S[c] - S[b];

    return x1*y2 - x2*y1 <= 0;
}

__inline double calc_k(int a, int b)
{
    return (double)(S[b] - S[a]) / (double)(b - a);
}

int main()
{
    int i, j;
    double max_val, val;

    freopen("e:\\test\\in.txt", "r", stdin);

    scanf("%d%d", &N, &F);
    for (i = 1; i <= N; i++) {
        scanf("%d", &j);
        S[i] = S[i - 1] + j;
    }
    
    max_val = 0;
    for (i = 0; i <= N - F; i++) {
        while (sp >= 2 && turn_right(stack[sp - 2], stack[sp - 1], i))
            sp--;
        stack[sp++] = i;
        for (j = sp; 
             j >= 2 && turn_right(stack[j - 2], stack[j - 1], i + F);
             j--
             );
        val = calc_k(stack[j - 1], i + F);
        if (val > max_val)
            max_val = val;
    }
    printf("%d\n", (int)(max_val * 1000));

    return 0;
}
