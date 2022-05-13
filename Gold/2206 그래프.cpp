#include <iostream>
#include <string>
#include <queue>
using namespace std;

int direction[4][2] = { {0, -1}, {1, 0}, {0, 1}, {-1, 0} };
int map[1001][1001], visited[1001][1001][2];
int N, M;

void BFS() {
    queue<pair<pair<int, int>, int>> que;
    visited[1][1][1] = 1;
    que.push({{ 1, 1 }, 1});
    int TX, TY, broke;
    while (!que.empty()) {
        pair<pair<int, int>, int> cur = que.front();
        que.pop();
        if (cur.first.first == N && cur.first.second == M) break;
        for (int i = 0; i < 4; i++) {
            TX = cur.first.first + direction[i][0];
            TY = cur.first.second + direction[i][1];
            broke = cur.second;

            if(TX >= 1 && TX <= N && TY >= 1 && TY <= M){
                if (!map[TX][TY] && !visited[TX][TY][broke]) {
                    que.push({ { TX, TY }, broke });
                    visited[TX][TY][broke] = visited[cur.first.first][cur.first.second][broke] + 1;
                }
                else if (map[TX][TY] && broke) {
                    que.push({ { TX, TY }, broke - 1 });
                    visited[TX][TY][broke - 1] = visited[cur.first.first][cur.first.second][broke] + 1;
                }
            }
        }
    }
    if (visited[N][M][1]) visited[N][M][0] = visited[N][M][1];
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> N >> M;
    string str;
    for (int i = 1; i <= N; i++) {
        cin >> str;
        for (int j = 1; j <= M; j++)
            map[i][j] = int(str[j - 1] - 48);
    }
    BFS();
    if (visited[N][M][0] == 0) cout << -1;
    else cout << visited[N][M][0];
}

/*
배열로
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