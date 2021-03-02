#include <iostream>
#include <queue>
#include <string>
using namespace std;

int N, direction[4][2] = { {0, -1}, {1, 0}, {0, 1}, {-1, 0} };
char pic[101][101];
char spic[101][101];
bool visited[101][101];

int BFS(char PIC[101][101]) {
	queue<pair<int, int>> que;
	int count = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (!visited[i][j]) {
				que.push({ i,j });
				visited[i][j] = true;
				count++;
			}
			while (!que.empty()) {
				pair<int, int> cur = que.front();
				que.pop();
				for (int k = 0; k < 4; k++) {
					int NY = cur.first + direction[k][0];
					int NX = cur.second + direction[k][1];
					if (NY >= 1 && NY <= N && NX >= 1 && NX <= N && !visited[NY][NX] && PIC[i][j] == PIC[NY][NX]) {
						que.push({ NY, NX });
						visited[NY][NX] = true;
					}
				}
			}
		}
	}
	return count;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	string str;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> str;
		for (int j = 1; j <= N; j++) {
			pic[i][j] = str[j - 1];
			if (str[j - 1] == 'R') spic[i][j] = 'G';
			else spic[i][j] = str[j - 1];
		}
	}
	int norm = BFS(pic);
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			visited[i][j] = false;
	int spec = BFS(spic);
	cout << norm << ' ' << spec;
}