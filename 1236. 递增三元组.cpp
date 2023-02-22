#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
#define N 10010
int main() {
	int a[N];
	int b[N];
	int c[N];
	int n;
	int res = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++)
		cin >> b[i];
	for (int i = 0; i < n; i++)
		cin >> c[i];
	for (int i = 0; i < n; i++)
		for (int j = 0 ; j < n; j++)
			for (int k = 0; k < n; k++)
				if (c[k] > b[j] && b[j] > a[i])
					res++;
	cout << res << endl;
	return 0;
}
