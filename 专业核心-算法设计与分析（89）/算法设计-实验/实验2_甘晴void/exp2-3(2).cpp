#include <algorithm>
#include <stdio.h>
using namespace std;

int solve(int f[], int n)
{
    if (n == 1)
        return 1;
    if (f[n] != 0)
        return f[n];
    int sum = 1;
    for (int i = 1; i <= n / 2; i++)
    {
        sum += solve(f, i);
        if ((i > 10) && (2 * (i / 10) <= (i % 10)))
        {
            sum -= f[i / 10];
        }
    }
    f[n] = sum;
    return sum;
}

int main()
{
    int n;
    scanf("%d", &n);
    int f[n + 1];
    for (int i = 1; i <= n; i++)
        f[i] = 0;
    f[1] = 1;
    printf("%d\n", solve(f, n));
}
