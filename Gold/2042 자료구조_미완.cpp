#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

typedef long long ll;

int N, M, K;
ll tree[1000001];
vector<ll> treeSum;

ll init(int start ,int end, int node) {
	if (start == end) return treeSum[node] = tree[start];

	int mid = (start + end) / 2;
	return treeSum[node] = init(start, mid, node * 2) + init(mid + 1, end, node * 2 + 1);
}

ll result(int start, int end, int node, int left, int right) {
	if (left > end || end < start) return 0;
	if (start >= left && end <= right) return treeSum[node];

	int mid = (start + end) / 2;
	return result(start, mid, node * 2, left, right) + result(mid + 1, end, node * 2 + 1, left, right);
}

void update(int start, int end, int node, int index, ll dif) {
	if (index < start || index > end) return;
	treeSum[node] += dif;
	if (start == end) return;

	int mid = (start + end) / 2;
	update(start, mid, node * 2, index, dif);
	update(mid + 1, end, node * 2 + 1, index, dif);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> N >> M >> K;
	int H = (int)ceil(log2(N) + 1);
	int tr = 1 << H;
	treeSum.resize(tr);

	for (int i = 1; i <= N; i++) 
		cin >> tree[i];
	init(1, N, 1);

	for (int i = 0; i < M + K; i++) {
		int a, b;
		ll c;
		cin >> a >> b >> c;
		if (a == 1){
			tree[b] = c;
			update(1, N, 1, b, c - tree[b]);
		}
		else if (a == 2) 
			cout << result(1, N, 1, b, c) << '\n';
	}
	return 0;
}