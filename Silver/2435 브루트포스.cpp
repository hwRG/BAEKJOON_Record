#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int N, K, MAX = -100000, list[100];
	cin >> N >> K;
	for (int i = 0; i < N; i++)
		cin >> list[i];
	for (int i = 0; i < N - K + 1; i++) {
		int temp = 0;
		for (int j = i; j < i + K; j++) temp += list[j];
		if (temp > MAX) MAX = temp;
	}
	cout << MAX;
}