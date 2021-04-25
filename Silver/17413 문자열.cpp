#include <iostream>
#include <string>
#include <stack>
using namespace std;

void print(stack<char>* stack) {
	while (!stack->empty()) {
		char index = stack->top();
		stack->pop();
		cout << index;
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	stack<int> pack;
	string str;
	getline(cin, str);
	for (unsigned i = 0; i < str.length(); i++) {
		if (str[i] == '<') pack.push(1);
		else if (str[i] == '>') pack.pop();
		if (str[i] == '>' || pack.empty()) {
			if (str[i] != '>') i--;
			else cout << '>';
			stack<char> stack;
			while (i+1 != str.length() && str[i+1] != '<') {
				if (str[i + 1] == ' ') {
					print(&stack);
					cout << ' ';
					i++;
				}
				stack.push(str[i + 1]);
				i++;
			}
			print(&stack);
		}
		else cout << str[i];
	}
}