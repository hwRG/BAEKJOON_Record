#include <iostream>
using namespace std;

int a, b, c;
int table[51][51][51];

int w(int a, int b, int c) {
	if (table[a][b][c] != 0) 
		return table[a][b][c];

	if (a <= 0 || b <= 0 || c <= 0) 
		return 1;

	else if (a > 20 || b > 20 || c > 20)
		return table[20][20][20] = w(20, 20, 20);

	else if (a < b && b < c && a < c)
		return table[a][b][c] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);

	else
		return table[a][b][c] = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	while (true) {
		cin >> a >> b >> c;
		if (a == -1 && b == -1 && c == -1)
			break;
		if (a <= -1 || b <= -1 || c <= -1) {
			cout << "w(" << a << ", " << b << ", " << c  << ") = " << 1 << '\n';
			continue;
		}
		cout << "w(" << a << ", " << b << ", " << c << ") = " << w(a, b, c) << '\n';
	}
}