#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int N;
	queue<int> que;
	cin >> N;
	for (int i = 1; i <= N; i++) 
		que.push(i);
	while (que.size() > 1) {
		que.pop();
		que.push(que.front());
		que.pop();
	}
	cout << que.front();
}