#include <iostream>
#include <vector>
using namespace std;

int n, m, result, fr;
vector<int> list[10001];
bool check[10001];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int a, b;
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		cin >> a >> b;
		list[a].push_back(b);
		list[b].push_back(a);
	}

	check[1] = true;
	for (int i = 0; i < list[1].size(); i++) {
		int point = list[1][i];
		if (!check[point])
			result++;
		check[point] = true;
		for (int j = 0; j < list[point].size(); j++) {
			if (!check[list[point][j]]) {
				check[list[point][j]] = true;
				result++;
			}
		}
	}
	cout << result;
}