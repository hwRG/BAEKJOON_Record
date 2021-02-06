#include <iostream>
using namespace std;
int x[50], y[50], ranks[50];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) 
		cin >> x[i] >> y[i];
	for (int i = 0; i < N; i++) 
		for (int j = 0; j < N; j++) 
			if (x[i] < x[j] && y[i] < y[j])
				ranks[i]++;
	for (int i = 0; i < N; i++) 
		cout << ranks[i] + 1 << ' ';
}