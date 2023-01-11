#include<iostream>
using namespace std;
int main()
{
    int N;
    cin >> N;
    int a,b;
    int i,j;
    while ( N --) {
        cin >> a;
        cin >> b;
        for(int j = 0; j < a; j++){
            if(j == 0 || j == a - 1)
              cout << "X" ;
            else
              cout << " " ;
        }
        cout << "\n";
        while(b --) {//需要重复b次
            for(i = 1;i < a; i++) {
                for(j = 0;j < a; j++) {
                    if ( i == j || i + j == a - 1) {//判断是否在对角线和副对角线上
                        cout << "X" ;
                    } 
                    else {
                        cout << " " ;
                    }
                }
               cout << "\n" ;
            }
        }
        cout << "\n" ;//数据之间空一行
    }
}
