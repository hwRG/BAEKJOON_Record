#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N, M, a, b, degree[32001];
vector<int> vec[32001], rvec[32001];

void Topo() {
	queue<int> head;
	int* list = new int[N];
	for (int i = 1; i <= N; i++)
		if (!degree[i]) head.push(i);
	while (!head.empty()) {
		int cur = head.front();
		cout << cur << ' ';
		head.pop();
		for (int i = 0; i < rvec[cur].size(); i++) {
			vec[rvec[cur][i]].pop_back();
			if (!vec[rvec[cur][i]].size())
				head.push(rvec[cur][i]);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		vec[b].push_back(a);
		rvec[a].push_back(b);
	}
	for (int i = 1; i <= N; i++) 
		degree[i] = vec[i].size();
	Topo();
}