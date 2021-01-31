#include <iostream>
using namespace std;

int main() {
	int h, m, afterM;
	cin >> h >> m;
	if (m - 45 < 0) afterM = 15 + m;
	else afterM = m - 45;
	if (m - 45 < 0) {
		if (h == 0)
			h = 23;
		else
			h--;
	}
	cout << h << ' ' << afterM;
}