#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> s;
int main(){
    int N;
    cin >> N;
    //5 6 8
    int x;
    while(cin >> x)
    s.push_back(x);
    int res1;
    int res2;
    sort(s.begin(), s.end());
    for (int i = 0; i < s.size() - 1; i++) {
        if(s[i] == s[i + 1] )
        res1 = s[i];
        if(s[i] != s[i + 1] && s[i + 1] - s[i] == 2)
        res2 = s[i] + 1;
    }
    cout << res2 <<" " << res1;
    return 0;
    
}
