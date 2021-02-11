#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> edge[101];
int visited[101];
int cnt, N, M;

void BFS(int start) {
	queue<int> que;
	que.push(start);
	visited[start] = true;
	while (!que.empty()) {
		int vertex = que.front();
		que.pop();
		for (int i = 0; i < edge[vertex].size(); i++) {
			if (!visited[edge[vertex][i]] && edge[vertex][i] <= N && edge[vertex][i] > 0) {
				que.push(edge[vertex][i]);
				visited[edge[vertex][i]] = true;
				cnt++;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int a, b;
	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		edge[a].push_back(b);
		edge[b].push_back(a);
	}
	BFS(1);
	cout << cnt;
}