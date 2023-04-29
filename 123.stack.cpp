#include<iostream>
#include<stack>
using namespace std;
stack<int> s;
int f(stack<int> s);
void rev(stack<int> s) {
	if (s.size() == 0) {
		return;
	}
	int i = f(s);
	rev(s);
	s.push(i);
}
int f(stack<int> s) { // 去掉一个数返回

	int res = s.top();
	s.pop();
	if (s.size() == 0) {
		return res;
	} 
	else {
		int last = f(s);
		s.push(res);
		return last; 
	}
}
int main() {
	rev(s);

	s.push(1);
	s.push(2);
	s.push(3);
	return 0;
}
