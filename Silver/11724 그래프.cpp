#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> edge[1001];
bool visited[1001];
int N, M, u, v;

int BFS() {
	queue<int> que;
	int count = 0, cur;
	for(int i = 1; i <= N; i++){
		if (!visited[i]) {
			que.push(i);
			visited[i] = true;
			count++;
		}
		while (!que.empty()) {
			cur = que.front();
			que.pop();
			for(int i = 0; i < edge[cur].size(); i++){
				if (!visited[edge[cur][i]]) {
					que.push(edge[cur][i]);
					visited[edge[cur][i]] = true;
				}
			}
		}
	}
	return count;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> u >> v;
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	cout << BFS();
}