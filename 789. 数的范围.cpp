#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;

int main() {
    vector<int> a;
    int n;
    cin >> n;
    int q;
    cin >> q;
    a.resize(n);
    for (int i = 0; i < n; i ++){
        cin >> a[i];
    }
    int x;
    int l = 0;
    int r = n - 1;
    while (q--) {
        cin >> x;
        while (l < r) {
           int mid = l + r >> 1;
           if (a[mid] >= x) r = mid;
           else
           l = mid - 1;
        }
        if (a[l] == x) {
          cout << l << " ";
        r = n - 1;
        while (l < r) {
           int mid = l + r + 1>> 1;
           if (a[mid] <= x) l = mid;
           else
           r = mid - 1;
        }
        cout << r << endl;
    }
    else
    cout << "-1 -1" << endl;
    }
    return 0;
}789. 数的范围
