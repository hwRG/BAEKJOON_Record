#include <iostream>
#include <string>
using namespace std;

class QueType {
public:
	void push(int index) {
		list[end++] = index;
	}
	int pop() {
		if (empty() == 1) return -1;
		else return list[first++];
	}
	int size() {
		return end - first;
	}
	bool empty() {
		if (end == first) return 1;
		else return 0;
	}
	int front() {
		if (empty() == 1) return -1;
		else return list[first];
	}
	int back() {
		if (empty() == 1) return -1;
		else return list[end - 1];
	}

private:
	int list[10001];
	int first = 0, end = 0;
};

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int N, index;
	QueType que;
	string command;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> command;
		if (command == "push") {
			cin >> index;
			que.push(index);
		}
		else if (command == "pop")
			cout << que.pop() << '\n';
		else if (command == "size")
			cout << que.size() << '\n';
		else if (command == "empty")
			cout << que.empty() << '\n';
		else if (command == "front")
			cout << que.front() << '\n';
		else if (command == "back")
			cout << que.back() << '\n';
	}
}