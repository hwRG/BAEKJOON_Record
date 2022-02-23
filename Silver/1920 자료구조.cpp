#include <iostream>
#include <algorithm>
using namespace std;

int N, M, target;
long long table[100000];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) 
		cin >> table[i];
	sort(table, table + N);

	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> target;
		int mid, min = 0, max = N-1;
		bool flag = false;

		while (max - min >= 0) {
			mid = (min + max) / 2;
			if (table[mid] == target) {
				flag = true;
				break;
			}
			else if (table[mid] > target)
				max = mid - 1;
			else if (table[mid] < target)
				min = mid + 1;
			
		}
		if (flag) 
			cout << 1 << '\n';
		else
			cout << 0 << '\n';
	}
}