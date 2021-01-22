#include <iostream>
#include <algorithm>
using namespace std;



bool ascend()
bool descend()

int main() {
	int N[10] = { 4, 5, 2, 3, 7, 9, 1, 6, 0, 8};
	sort(N, N + 10, compare);
	for (int i = 0; i < 10; i++) {
		cout << N[i] << ' ';
	}
}