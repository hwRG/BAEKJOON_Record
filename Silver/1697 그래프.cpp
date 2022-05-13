#include <iostream>
#include <cmath>
#include <queue>
using namespace std;

int N, K;
bool visited[200001];

int BFS() {
	queue<pair<int, int>> que;
	que.push({ N, 0 });
	while(!que.empty()) {
		pair<int, int> index = que.front();
		if (index.first == K)
			return index.second;
		que.pop();
		if (!visited[index.first - 1] && index.first - 1 <= 100000 && index.first - 1 >= 0) {
			que.push({ index.first - 1, index.second + 1 });
			visited[index.first - 1] = true;
		}
		if (!visited[index.first * 2] && index.first * 2 <= 100000 && index.first * 2 >= 0) {
			que.push({ index.first * 2, index.second + 1 });
			visited[index.first * 2] = true;
		}
		if (!visited[index.first + 1] && index.first + 1 <= 100000 && index.first + 1 >= 0) {
			que.push({ index.first + 1, index.second + 1 });
			visited[index.first + 1] = true;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> N >> K;
	cout << BFS();
}