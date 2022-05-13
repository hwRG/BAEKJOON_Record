#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

bool quad[26][26], visited[26][26];
int direction[4][2] = { {0, -1}, {1, 0}, {0, 1}, {-1, 0} };

int BFS(int i, int j) {
	queue<pair<int, int>> que;
	int count = 1;
	que.push({ i,j });
	visited[i][j] = true;
	while (!que.empty()) {
		pair<int, int> cur = que.front();
		que.pop();
		for (int i = 0; i < 4; i++) {
			int NI = cur.first + direction[i][0];
			int NJ = cur.second + direction[i][1];
			if (quad[NI][NJ] && !visited[NI][NJ]) {
				que.push({ NI, NJ });
				visited[NI][NJ] = true;
				count++;
			}
		}
	}
	return count;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int N, list[1000], count = 0;
	string str;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> str;
		for (int j = 1; j <= N; j++)
			quad[i][j] = str[j - 1] - 48;
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (quad[i][j] && !visited[i][j]) {
				list[count] = BFS(i, j);
				count++;
			}
		}
	}
	sort(list, list + count);
	cout << count << '\n';
	for (int i = 0; i < count; i++) 
		cout << list[i] << '\n';
}