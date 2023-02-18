#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1010, MOD = 100000007;

int n, s, a, b;
int f[N][N];

int get_mod(int a, int b)
{
    return (a % b + b) % b;
}

int main()
{
    scanf("%d%d%d%d", &n, &s, &a, &b);

    f[0][0] = 1;
    for (int i = 1; i < n; i++)
        for (int j = 0; j < n; j++)
            f[i][j] = (f[i - 1][get_mod(j - (n - i) * a, n)] + f[i - 1][get_mod(j + (n  - i) * b, n)]) % MOD;

    printf("%d", f[n - 1][get_mod(s, n)]);

    return 0;
}
