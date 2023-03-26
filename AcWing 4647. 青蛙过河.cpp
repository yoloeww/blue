#include <bits/stdc++.h>
typedef long long LL;
const int N = 1e5 + 10;
const int INF = 1e9 + 10;
int h[N];
LL s[N];
int n, x;
bool check(int jump)
{
    for (int i = 1; i + jump - 1 <= n - 1; ++i)
        if (s[i + jump - 1] - s[i - 1] < x)
            return false;
    return true;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    std::cin >> n >> x;
    x <<= 1;
    for (int i = 1; i <= n - 1; ++i)
    {
        std::cin >> h[i];
        s[i] = s[i - 1] + h[i];
    }
    int l = 1, r = n;
    while (l < r)
    {
        int mid = l + r >> 1;
        if (check(mid))
            r = mid;
        else
            l = mid + 1;
    }
    std::cout << l << '\n';
    return 0;
}

