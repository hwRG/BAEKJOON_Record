#include <iostream>
#include <stack>
using namespace std;

int top[500000];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	stack<pair<int, int>> stack;
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> top[i];
	cout << 0 << ' ';
	stack.push({ top[0], 0 });
	for (int i = 1; i < N; i++){
		bool flag = true;
		while(!stack.empty()){
			if (stack.top().first > top[i]) {
				cout << stack.top().second+1 << ' ';
				stack.push({ top[i], i });
				flag = false;
				break;
			}
			else if (stack.top().first == top[i]) {
				cout << stack.top().second + 1 << ' ';
				stack.pop();
				stack.push({ top[i], i });
				flag = false;
				break;
			}
			else 
				stack.pop();
		}
		if(flag == true){
			stack.push({ top[i], i });
			cout << 0 << ' ';
		}
	}
}