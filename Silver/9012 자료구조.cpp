#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	string str;
	int T;
	cin >> T;
	for (int k = 0; k < T; k++) {
		stack<int> stack;
		bool flag = true;
		cin >> str;
		for (int i = 0; i < str.length(); i++) {
			if (str[i] == '(')
				stack.push(1);
			else {
				if (stack.empty()) {
					flag = false;
					break;
				}
				else stack.pop();
			}
		}
		if (!flag) cout << "NO" << '\n';
		else {
			if (!stack.empty()) cout << "NO" << '\n';
			else cout << "YES" << '\n';
		}
	}
}