#include <iostream>
#include <vector>
using namespace std;

int N, a, b, list[100001];
vector<int> edge[100001];
bool visited[100001];

void DFS(int start) {
	visited[start] = true;
	for (int i = 0; i < edge[start].size(); i++) {
		if (visited[edge[start][i]]) continue;
		list[edge[start][i]] = start;
		DFS(edge[start][i]);
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> N;
	for (int i = 0; i < N - 1; i++) {
		cin >> a >> b;
		edge[a].push_back(b);
		edge[b].push_back(a);
	}
	DFS(1);
	for (int i = 2; i <= N; i++) cout << list[i] << '\n';
}