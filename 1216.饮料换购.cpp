#include<cstdio>
#include<cstring>
#include<iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    for(int i = n; i >=3 ; i = i - 3) {
        if(i != 0) {
            n ++;
            i ++;
        }
    }
    cout << n;
    return 0;
}
