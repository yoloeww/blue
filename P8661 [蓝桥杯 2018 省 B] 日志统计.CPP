#include<iostream>
#include<bits/stdc++.h>
using namespace std;

const int N = 1000010;
int cnt[N];
typedef pair<int,int> PII;
PII logs[N];
bool st[N];
int main() {
    int n,d,k;
    cin >> n >> d >> k;
    for (int i = 0; i < n; i ++) {
        cin >> logs[i].first >> logs[i].second;
    }
    sort(logs,logs + n);
    for (int i = 0,j = 0; i < n; i++) {
        int id = logs[i].second;
	        cnt[id] ++;
        while (logs[i].first - logs[j].first >= d) {
            cnt[logs[j].second] --;
            j ++;
        }
        if (cnt[id] >= k) st[id] = true;
    }
    	for (int i = 0; i < N; i ++) {
	    if (st[i] == true)
	        cout << i << endl;
	}
    return 0;
}
