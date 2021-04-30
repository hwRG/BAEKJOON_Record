#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n = 3, answer = 0;
	vector<vector<int>> computers = { {1,1,0}, {1,1,0}, {0,0,1} };
	bool visited[200];
	for (int i = 0; i < n; i++) 
		visited[i] = true;
	queue<int> que;
	for (int k = 0; k < n; k++) {
		if (que.empty() && visited[k]) {
			que.push(k);
			visited[k] = false;
			answer++;
		}
		while (!que.empty()) {
			int now = que.front();
			que.pop();
			for (int i = 0; i < computers[now].size(); i++) {
				if (computers[now][i] && visited[i]) {
					que.push(i);
					visited[i] = false;
				}
			}
		}
	}
	cout << answer;
}