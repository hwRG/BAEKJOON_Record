#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int N, K, count = 1;
	queue<int> que;
	cin >> N >> K;
	for (int i = 1; i <= N; i++) 
		que.push(i);
	cout << "<";
	while (1) {
		int cur = que.front();
		que.pop();
		if (que.empty()) {
			cout << cur << ">";
			break;
		}
		if (count != K)
			que.push(cur);
		else{
			count = 0;
			cout << cur << ", ";
		}
		count++;
	}
}