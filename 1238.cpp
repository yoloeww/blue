#include <cstring>
#include <iostream>
#include <algorithm>

#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;

const int N = 100010;

int n, d, k;
PII logs[N];
int cnt[N];
bool st[N];  // 记录每个帖子是否是热帖

int main()
{
    scanf("%d%d%d", &n, &d, &k);
    for (int i = 0; i < n; i ++ ) cin >> logs[i].x >> logs[i].y;
    sort(logs, logs + n);

    for (int i = 0,j = 0;i < n; i ++ )
    {
        int id = logs[i].y;
        cnt[id] ++ ;

        while (logs[i].x - logs[j].x >= d)
        {
            cnt[logs[j].y] -- ;
            j ++ ;
        }

        if (cnt[id] >= k)  st[id] = true;
       
    }

    for (int i = 0; i <= 100000; i ++ )
        if (st[i])
            printf("%d\n", i);

    return 0;
}
