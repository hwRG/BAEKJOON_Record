#include <iostream>
using namespace std;
// Union Find

int list[1000001];
// 경로 압축
int find(int x) {
	if (x == list[x]) return x;
	// 애초에 부모노드로 만들어버리기
	else return list[x] = find(list[x]);
}

void union_ele(int x, int y) {
	x = find(x);
	y = find(y);
	list[y] = x;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, m, act, a, b;
	cin >> n >> m;
	for (int i = 0; i <= n; i++) 
		list[i] = i;

	for (int i = 0; i < m; i++) {
		cin >> act >> a >> b;
		if (act == 0) 
			union_ele(a, b);
		else if (act == 1) {
			if (find(a) == find(b)) cout << "YES" << '\n';
			else cout << "NO" << '\n';
		}
	}
}