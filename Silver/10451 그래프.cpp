#include <iostream>
using namespace std;

int list[1001];
bool visited[1001];

void BFS() {
	int N, index, count = 0;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> index;
		list[i] = index;
	}

	for (int i = 1; i <= N; i++) {
		if (visited[i])
			continue;
		visited[i] == true;
		int now = list[i];
		while (!visited[now]) {
			visited[now] = true;
			now = list[now];
		}
		count += 1;
	}
	cout << count << '\n';
	for (int i = 1; i <= N; i++)
		visited[i] = false;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int T;
	cin >> T;

	for (int t = 0; t < T; t++) 
		BFS();
}