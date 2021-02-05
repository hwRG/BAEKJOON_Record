#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int N, total = 0;
	cin >> N;
	int* line = new int[N];
	for (int i = 0; i < N; i++)
		cin >> line[i];
	sort(line, line + N);
	for (int i = 0; i < N; i++) 
		for (int j = 0; j <= i; j++) 
			total += line[j];
	cout << total;
	delete[] line;
}