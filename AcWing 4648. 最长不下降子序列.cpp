#include <bits/stdc++.h>
const int N = 1e5 + 10;
int n, m, k, ans;
int a[N];
int b[N];       // 用于离散化的数组
int dp1[N];     // dp1[i]表示从前往后以a[i]结尾的最长不下降子序列的长度
int dp2[N];     // dp2[i]表示从前往后以a[i]开头的最长不下降子序列的长度
int find(int x) //返回整数a[i]在b数组中的下标
{
    int l = 1, r = m;
    while (l < r)
    {
        int mid = l + r >> 1;
        if (b[mid] >= x)
            r = mid;
        else
            l = mid + 1;
    }
    return l;
}
struct
{
    int maxv;
} seg[N * 4];
void pushup(int id)
{
    seg[id].maxv = std::max(seg[id << 1].maxv, seg[id << 1 | 1].maxv);
}
void build(int id, int l, int r)
{
    if (l == r)
        seg[id].maxv = 0;
    else
    {
        int mid = l + r >> 1;
        build(id << 1, l, mid);
        build(id << 1 | 1, mid + 1, r);
        pushup(id);
    }
}
void change(int id, int l, int r, int pos, int val)
{
    if (l == r)
        seg[id].maxv = std::max(seg[id].maxv, val);
    else
    {
        int mid = l + r >> 1;
        if (pos <= mid)
            change(id << 1, l, mid, pos, val);
        else
            change(id << 1 | 1, mid + 1, r, pos, val);
        pushup(id);
    }
}
int query(int id, int l, int r, int ql, int qr)
{
    if (l == ql && r == qr)
        return seg[id].maxv;
    int mid = l + r >> 1;
    if (qr <= mid)
        return query(id << 1, l, mid, ql, qr);
    else if (ql >= mid + 1)
        return query(id << 1 | 1, mid + 1, r, ql, qr);
    else
        return std::max(query(id << 1, l, mid, ql, mid), query(id << 1 | 1, mid + 1, r, mid + 1, qr));
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    std::cin >> n >> k;
    for (int i = 1; i <= n; ++i)
        std::cin >> a[i], b[i] = a[i];
    std::sort(b + 1, b + n + 1); //排序
    if (n == k)
    {
        std::cout << n << '\n';
        return 0;
    } 
    m = 1;
    for (int i = 2; i <= n; i++) //去重
        if (b[i] != b[m])
            b[++m] = b[i];
    for (int i = 1; i <= n; ++i)
        a[i] = find(a[i]);
    build(1, 1, m); //建权值线段树
    for (int i = 1; i <= n - k; ++i)
    {
        dp1[i] = query(1, 1, m, 1, a[i]) + 1;
        change(1, 1, m, a[i], dp1[i]);
    }
    build(1, 1, m); // dp1已经处理完，重新建树处理dp2
    for (int i = n; i >= k + 1; --i)
    {
        ans = std::max(ans, dp1[i - k] + k + query(1, 1, m, a[i - k], m));
        // 第一段为dp1[i-k]，第二段为k，第三段为max(dp2[j]),i+k+1<=j<=n且a[j]>=a[i]
        dp2[i] = query(1, 1, m, a[i], m) + 1;
        change(1, 1, m, a[i], dp2[i]);
    }
    // 特殊情况
    for (int i = 1; i <= n - k; ++i)
        ans = std::max(ans, dp1[i] + k);
    for (int i = n; i >= k + 1; --i)
        ans = std::max(ans, dp2[i] + k);
    std::cout << ans << '\n';
    return 0;
}

