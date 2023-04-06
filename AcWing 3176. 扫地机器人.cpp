#include <iostream>
#include <algorithm>
using namespace std;
int n, k;
const int N = 100010;
int s[N];
bool check(int m)
{
    int l = 0;
    for (int i = 0; i < k; i++)
    {
        if (s[i] - m <= l)
        {
            if (s[i] <= l)  l = s[i] + m - 1;
            else l += m;
        }
        else
            return false;
    }
    if (l >= n)
        return true;
    else
        return false;
}
int main()
{
    cin >> n >> k;
    for (int i = 0; i < k; i++)
        cin >> s[i];
    sort(s, s + k);
    int l = 1, r = n;
    while (l < r)
    {
        int mid = l + r >> 1;
        if (!check(mid))
            l = mid + 1;
        else
            r = mid;
    }
    cout << 2 * (l - 1);
    return 0;
}


