#include <iostream>
using namespace std;

int main() {
	int round = 1;
	while (1) {
		int L, P, V, count = 0;
		cin >> L >> P >> V;
		if (L == 0 && P == 0 && V == 0) break;
		count = V / P;
		int about = V % P > L ? L : V % P;
		cout << "Case " << round++ << ": " << count * L + about << '\n';
	}
}