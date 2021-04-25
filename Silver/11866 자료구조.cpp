#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int N, K, index, count = 1;
	queue<int> que;
	cin >> N >> K;
	for (int i = 0; i < N; i++)
		que.push(i + 1);
	cout << '<';
	while (!que.empty()) {
		index = que.front();
		que.pop();
		if (count == K) {
			if (que.empty()) cout << index << '>';
			else cout << index << ", ";
			count = 1;
		}
		else {
			que.push(index);
			count++;
		}
	}
}