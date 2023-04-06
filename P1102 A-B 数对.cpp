#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int n,c;
const int N = 1000010;
int a[N];
int search1(int x) {
    int l = 0,r = n + 1;
    while (l + 1 < r) {
        int mid = (l + r) >> 1;
        if (a[mid] < x) 
            l = mid;
        else
            r = mid;
            
    }
    if (a[r] == x)
        return r;
    else
        return -1;
}
int search2(int x) {
    int l = 0,r = n + 1;
    while (l + 1 < r) {
        int mid = (l + r) >> 1;
        if (a[mid] <= x) 
            l = mid;
        else
            r = mid;
            
    }
    if (a[l] == x)
        return l;
    else
        return -1;
}
int main() {
    cin >> n >> c;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1,a + 1 + n);
    long long cnt = 0;
    for (int b = 1; b <= n; b++) {
        int A = a[b]+ c;
        int res1 = search1(A);
        if (res1 == -1) 
            continue;
        else {
        int res2 = search2(A);
        cnt += res2 - res1 + 1;
        }
    }
    cout << cnt << endl;
    return 0;
}
