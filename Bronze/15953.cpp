#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int T, a, b;
	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> a >> b;
		int balance = 0;
		if (a <= 0) balance += 0;
		else if (a == 1) balance += 5000000;
		else if (a < 4) balance += 3000000;
		else if (a < 7) balance += 2000000;
		else if (a < 11) balance += 500000;
		else if (a < 16) balance += 300000;
		else if (a < 22) balance += 100000;
		else balance += 0;

		if (b <= 0) balance += 0;
		else if (b == 1) balance += 5120000;
		else if (b < 4) balance += 2560000;
		else if (b < 8) balance += 1280000;
		else if (b < 16) balance += 640000;
		else if (b < 32) balance += 320000;
		else balance += 0;

		cout << balance << '\n';
	}
}