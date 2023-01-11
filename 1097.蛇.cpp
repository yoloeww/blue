#include <iostream>
#include <vector>
 
using namespace std;
 
int main() {
    int N = 0;
    cin >> N;
    vector<vector<int>> matrix(N, vector<int>(N, 0)); // 全0的N*N矩阵
    int count  = 1; // 计数器，一直递增
    for (int i = 0; i < N; ++i) {
        for (int j = i; j >= 0; --j) {
            matrix[j][i - j] = count++; // 生成蛇形矩阵
        }
    }
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N - i; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl; // 未处理每行的最后一个空格
    }
    return 0;
}
