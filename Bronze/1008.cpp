#include <iostream>
using namespace std;

int main() {
	double a, b;
	cin >> a >> b;
	if (a > 0 && b < 10 && b > 0) {
		cout.precision(15);
		cout << a / b << endl;
	}
}