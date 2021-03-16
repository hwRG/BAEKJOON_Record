#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n, st, en, line, a, b;
vector<int> edge[101];
bool visited[101], flag;

void BFS() {
	int count = 1;
	queue<int> que;
	que.push(st);
	int cur = que.front();
	visited[cur] = true;
	que.pop();
	for (int i = 0; i < edge[cur].size(); i++) {
		que.push(edge[cur][i]);
		visited[edge[cur][i]] = true;
	}
	while (1) {
		if (que.empty()){
			cout << -1;
			break;
		}
		int length = que.size();
		for (int i = 0; i < length; i++) {
			cur = que.front();
			if (cur == en) {
				flag = true;
				cout << count;
				break;
			}
			que.pop();
			for (int j = 0; j < edge[cur].size(); j++) {
				if (!visited[edge[cur][j]]) {
					que.push(edge[cur][j]);
					visited[edge[cur][j]] = true;
				}
			}
		}
		if (flag) break;
		count++;
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n >> st >> en >> line;
	for (int i = 1; i <= line; i++) {
		cin >> a >> b;
		edge[a].push_back(b);
		edge[b].push_back(a);
	}
	BFS();
}