#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n, st, en, line, a, b;
vector<int> edge[101];
bool visited[101];

void BFS() {
	int count = 0;
	queue<int> que;
	que.push(st);
	int cur = que.front();
	visited[cur] = true;
	que.pop();
	for (int i = 0; i < edge[cur].size(); i++) {
		que.push();
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