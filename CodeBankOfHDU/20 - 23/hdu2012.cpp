#include <stdio.h>

int main(void)
{
    int m, n;
    int x[] = 
    {
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 0, 0, 1, 1, 0, 1, 1, 1, 1, 0, 1
    };

    while (scanf("%d%d", &m, &n), m || n)
    {
        for (m += 39, n += 39; x[m] && m <= n ; m++);
            puts(m > n ? "OK" : "Sorry");
    }
    
    return 0;
}