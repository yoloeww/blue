#include <iostream>
using namespace std;
const int N = 1e5 + 10, INF = 0x3f3f3f3f;
int n;
int w[N];

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) 
    cin >> w[i];

    int res = 0;
    for (int i = 2; i <= n + 1; ++i) {
        if (w[i] - w[i - 1] > 0) res += w[i] - w[i - 1];
    }
    cout << res;
    return 0;
}


作者：智慧树_4
链接：https://www.acwing.com/activity/content/code/content/5680969/
来源：AcWing
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
