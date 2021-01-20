#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int count;
	cin >> count;
	int x1, y1, r1, x2, y2, r2;
	for (int i = 0; i < count; i++) {
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
		int length = pow((x2 - x1), 2) + pow((y2 - y1), 2);
		int subR = pow(r2 - r1, 2);
		int sumR = pow(r2 + r1, 2);
		if (length == 0) {
			if (subR == 0)
				cout << -1 << endl;
			else
				cout << 0 << endl;
		}
		else if (length == sumR || length == subR)
			cout << 1 << endl;
		else if (length < sumR && length > subR)
			cout << 2 << endl;
		else
			cout << 0 << endl;
	}

}