#include <iostream>
#include <string>
using namespace std;

class StackType {
public:
	void push(int index) {
		list[end++] = index;
	}
	int pop() {
		if (empty() == 1) return -1;
		else return list[end-- - 1];
	}
	int size() {
		return end - front;
	}
	bool empty() {
		if (end == 0) return 1;
		else return 0;
	}
	int top() {
		if (empty() == 1) return -1;
		else return list[end -1];
	}

private:
	int list[10001];
	int front = 0, end = 0;
};

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int N, index;
	StackType stack;
	string command;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> command;
		if (command == "push") {
			cin >> index;
			stack.push(index);
		}
		else if (command == "pop") 
			cout << stack.pop() << '\n';
		else if (command == "size") 
			cout << stack.size() << '\n';
		else if (command == "empty") 
			cout << stack.empty() << '\n';
		else if (command == "top") 
			cout << stack.top() << '\n';
	}
}