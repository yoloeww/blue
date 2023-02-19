#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int res = 0;
    int t = 0;
    for (int i = 1; i <= n; i++) {
        int x = i;
        while (x) {
            t = x % 10;
            x = x / 10;
            if(t == 1 || t == 2 || t == 9 || t == 0) {
                res += i;
                break;
            }
        }
    }
    cout << res << endl;
    return 0;
}
