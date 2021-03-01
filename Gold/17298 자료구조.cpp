#include <iostream>
#include <stack>
using namespace std;

int list[1000001];
int result[1000001];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	stack<int> stack;
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> list[i];

	stack.push(list[N]);
	for (int i = N - 1; i >= 1; i--) {
		while(!stack.empty()){
			if (list[i] < stack.top()) {
				result[i] = stack.top();
				break;
			}
			else 
				stack.pop();
		}
		stack.push(list[i]);
	}
	for (int i = 1; i <= N; i++){
		if (!result[i]) result[i] = -1;
		cout << result[i] << ' ';
	}
}