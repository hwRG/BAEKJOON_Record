#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int A[50], B[50];

bool compare(int a, int b) {
	return a > b;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int N, index, result = 0;
	vector<int> a, b;

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> index;
		a.push_back(index);
	}
	for (int i = 0; i < N; i++){
		cin >> index;
		b.push_back(index);
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end(), compare);
	for (int i = 0; i < N; i++) 
		result += a[i] * b[i];
	cout << result;
}