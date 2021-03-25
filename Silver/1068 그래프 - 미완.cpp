#include <iostream>
using namespace std;

int vec[50], N, del, result;

void DFS(int start) {
	vec[start] = -1;
	if (start == 0) vec[start] = -2;
	for (int i = start + 1; i < N; i++) 
		if (vec[i] == start) DFS(i);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) cin >> vec[i];
	cin >> del;
	DFS(del);
	for (int i = N-1; i >= 0; i--) {
		if (vec[i] != -1 && vec[i] != -2) {
			vec[(i-1) / 2] = -1;
			result++;
		}
	}
	if (!result && vec[0] == -1) result++;
	cout << result;
}