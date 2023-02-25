#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long LL;

const int N = 1010, mod = 1e9 + 7, INF = 0x3f3f3f3f;

int n, m;
int a[N]; //原序列
vector<int> nums; //离散化
int tr[N]; //树状数组
int f[N][N]; //设 $f[i][j]$ 表示序列 $a$ 的前 $j$ 个数构成的以 $a[j]$ 为结尾的数列中，长度为 $i$ 的严格递增子序列的数量

int lowbit(int x)
{
    return x & -x;
}

void add(int x, int c) //添加
{
    for(int i = x; i <= n + 1; i += lowbit(i)) tr[i] = (tr[i] + c) % mod;
}

int query(int x) //查询前缀和
{
    int res = 0;
    for(int i = x; i; i -= lowbit(i)) res = (res + tr[i]) % mod;
    return res;
}

int find(int x) //返回每个数离散化后的数
{
    int l = 0, r = nums.size() - 1;
    while(l < r)
    {
        int mid = l + r >> 1;
        if(nums[mid] >= x) r = mid;
        else l = mid + 1;
    }
    return r + 2; //让原序列中所有数值离散化到 [2, N + 1] 之间，因此每个下标应该 + 2
}

int main()
{
    int T;
    scanf("%d", &T);
    for(int cases = 1; cases <= T; cases++)
    {
        scanf("%d%d", &n, &m);

        nums.clear(); //清空容器
        for(int i = 1; i <= n; i++)
        {
            scanf("%d", &a[i]);
            nums.push_back(a[i]);
        }

        //离散化
        sort(nums.begin(), nums.end());
        nums.erase(unique(nums.begin(), nums.end()), nums.end());
        for(int i = 1; i <= n; i++) a[i] = find(a[i]); //将每个数离散化并放回原序列

        //初始化
        memset(f, 0, sizeof f);
        a[0] = 1; //保证 a[0] 离散化后是 1
        f[0][0] = 1;

        //dp
        for(int i = 1; i <= m; i++)
        {
            memset(tr, 0, sizeof tr); //每一层独立计算，每次初始化树状数组
            add(a[0], f[i - 1][0]); //加入边界

            for(int j = 1; j <= n; j++)
            {
                f[i][j] = query(a[j] - 1); //状态转移方程
                add(a[j], f[i - 1][j]); //将当前值放入树状数组
            }
        }

        int res = 0; //记录总方案数
        for(int i = 1; i <= n; i++) res = (res + f[m][i]) % mod;
        printf("Case #%d: %d\n", cases, res);
    }
    return 0;
}
