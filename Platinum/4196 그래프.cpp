#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<vector<int>> total;
vector<int> edge[100001];
vector<int> rev[100001];
bool visited[100001];
int scc[100001];
vector<int> list;

int N, M, a, b;

void clear() {
	for (int i = 0; i < 100001; i++) {
		edge[i].clear();
		rev[i].clear();
		scc[i] = 0;
		visited[i] = 0;
	}
	list.clear();
	total.clear();
}

void DFS(int x) {
	visited[x] = true;
	for (auto i : edge[x]) {
		if (visited[i]) continue;
		DFS(i);
	}
	list.push_back(x);
}

void DFS2(int x, int point) {
	scc[x] = point;
	total.back().push_back(x);
	for (auto i : rev[x]) {
		if (scc[i]) continue;
		DFS2(i, point);
	}
}

void getSCC() {
	for (int i = 1; i <= N; i++) 
		if (!visited[i]) DFS(i);
	reverse(list.begin(), list.end());
	int point = 1;
	for (auto i : list) {
		if (scc[i]) continue;
		total.push_back(vector<int>());
		DFS2(i, point);
		point++;
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int T, a, b;
	cin >> T;
	for (int k = 0; k < T; k++) {
		int result = 0;
		clear();
		cin >> N >> M;
		for(int i = 0; i < M; i++){
			cin >> a >> b;
			edge[a].push_back(b);
			rev[b].push_back(a);
		}
		getSCC();
		for (auto& i : total) {
			bool flag = false;
			for (auto& j : i) {
				for (auto& k : rev[j]) {
					if (scc[j] == scc[k]) continue;
					flag = true;
				}
			}
			if (!flag) result++;
		}
		cout << result << '\n';
	}
}