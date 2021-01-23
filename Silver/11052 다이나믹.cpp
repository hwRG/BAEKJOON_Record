#include <iostream>
using namespace std;

int main() {

	int N, price;
	cin >> N;
	int card[10000][2];

	for (int i = 0; i < N; i++) {
		cin >> price;
		card[i][0] = i + 1;
		card[i][1] = price;
	}
}