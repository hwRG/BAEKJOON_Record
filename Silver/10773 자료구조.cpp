#include <iostream>
#include <stack>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	stack<int> stack;
	int K, index;
	cin >> K;
	for (int i = 0; i < K; i++) {
		cin >> index;
		if (index == 0) stack.pop();
		else stack.push(index);
	}
	int count = stack.size(), total = 0;
	for (int i = 0; i < count; i++) {
		total += stack.top();
		stack.pop();
	}
	cout << total;
}