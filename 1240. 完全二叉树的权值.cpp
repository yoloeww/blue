#include <iostream>

using namespace std;
const int N = 100000 + 10;

long long q[N];

int main() {
    int n;
    cin >> n;
    for(int i = 1; i <=n; i++) 
        cin >> q[i];
    int max = -1e18;
    /*
    完全二叉树 每层的开头为   2^(n-1) 结尾则是 2^n - 1
    计算每层的数值只需要两个positioner 分别指向开头和结尾
    */
    int depth = 1;
    int res = 1;
    for(int i = 1; i <= n; i *= 2){
        long long s = 0;
        for(int j = i;  j <=  i*2 - 1 && j <= n; j ++) {
            s += q[j];
        }
        if(s > max) {
            max = s;
            res = depth;
        }
        depth++;
    }
    cout << res;
}
