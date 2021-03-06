#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> edge[101];
bool result[101][101];
int N, a;

void BFS() {
	queue<int> que;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < edge[i].size(); j++) {
			que.push(edge[i][j]);
			result[i][edge[i][j]] = 1;
		}
		while (!que.empty()) {
			int cur = que.front();
			que.pop();
			for (int j = 0; j < edge[cur].size(); j++) {
				if(!result[i][edge[cur][j]]){
					que.push(edge[cur][j]);
					result[i][edge[cur][j]] = 1;
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> a;
			if (a) edge[i].push_back(j);
		}
	}
	BFS();
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) 
			cout << result[i][j] << ' ';
		cout << '\n';
	}
}