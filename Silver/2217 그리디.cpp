#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int N, list[100000], MAX = 0;
	cin >> N;
	for (int i = 0; i < N; i++) 
		cin >> list[i];
	sort(list, list + N);
	for (int i = N-1; i >= 0; i--) 
		if (list[i] * (N - i) > MAX) MAX = list[i] * (N - i);
	cout << MAX;
}