#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int INF = 1000000000;
vector<pair<int, int>> vec[20001];
int d[20001]; 

void dijkstra(int start) { 
	priority_queue<pair<int, int>> que;
	que.push({ 0, start });
	d[start] = 0;
	while (!que.empty()) {
		int dis = -que.top().first;
		int cur = que.top().second;
		que.pop();
		if (d[cur] < dis) continue;
		for (int i = 0; i < vec[cur].size(); i++) {
			int nextCur = vec[cur][i].first;
			int nextDis = dis + vec[cur][i].second;
			if (nextDis < d[nextCur]) {
				d[nextCur] = nextDis;
				que.push({ -nextDis, nextCur });
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int V, E, K, u, v, w;
	cin >> V >> E >> K;
	for (int i = 1; i <= V; i++) 
		d[i] = INF;
	for (int i = 0; i < E; i++){
		cin >> u >> v >> w;
		vec[u].push_back({ v, w });
	}
	dijkstra(K);
	for (int i = 1; i <= V; i++) {
		if (d[i] == INF) cout << "INF" << '\n';
		else cout << d[i] << '\n';
	}
}

/*
배열 구현
int getSmall() {
	int min = INF;
	int result = 0;
	for (int i = 1; i <= V; i++) {
		if (d[i] < min && !visited[i]) {
			min = d[i];
			result = i;
		}
	}
	return result;
}

void dijkstra(int start) { // 1에 대해서
	for (int i = 1; i <= V; i++)
		d[i] = map[start][i];
	visited[start] = 1;
	for (int i = 1; i <= V - 2; i++) {
		int current = getSmall();
		visited[current] = 1;
		for (int j = 1; j <= V; j++)
			if (!visited[j])
				if (d[current] + map[current][j] < d[j])
					d[j] = d[current] + map[current][j];
	}
}
*/