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



