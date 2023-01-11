#include<iostream>
using namespace std;
int main()
{
    long long a;
    while (cin >> a) {
       long long sum = 0;
        while(a) {
            sum += a % 10;
            a = a / 10;
        }
        cout << sum << endl;
    }
    return 0;
}
