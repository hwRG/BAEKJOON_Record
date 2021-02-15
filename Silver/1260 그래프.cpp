#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

bool visitedD[1001];
bool visitedB[1001];
vector<int> edge[10001];

void DFS(int start) {
	cout << start << ' ';
	visitedD[start] = true;
	for (int i = 0; i < edge[start].size(); i++) {
		int vertex = edge[start][i];
		if (!visitedD[vertex])
			DFS(vertex);
	}
}

void BFS(int start) {
	queue<int> que;
	que.push(start);
	visitedB[start] = true;
	while (!que.empty()){
		int vertex = que.front();
		que.pop();
		cout << vertex << ' ';
		for(int i = 0; i < edge[vertex].size(); i++) {
			if (!visitedB[edge[vertex][i]]) {
				que.push(edge[vertex][i]);
				visitedB[edge[vertex][i]] = true;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int N, M, V, a, b;
	cin >> N >> M >> V;
	for (int i = 1; i <= M; i++) {
		cin >> a >> b;
		edge[a].push_back(b);
		edge[b].push_back(a);
	}
	for (int i = 1; i <= M; i++) 
		sort(edge[i].begin(), edge[i].end());
	DFS(V);
	cout << '\n';
	BFS(V);
}