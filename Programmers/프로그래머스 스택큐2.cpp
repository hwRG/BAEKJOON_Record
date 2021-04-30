#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	vector<int> prices = { 1,2,3,2,3 };
	vector<int> answer(prices.size());
	stack<int> stack; 
	for (int i = 0; i < prices.size(); i++) {
		while (!stack.empty() && prices[i] < prices[stack.top()]) {
			answer[stack.top()] = i - stack.top();
			stack.pop();
		}
		stack.push(i);
	}
	while (!stack.empty()) {
		answer[stack.top()] = prices.size() - stack.top() - 1;
		stack.pop();
	}
	for (auto a : answer) cout << a;

}