#include <iostream>
#include <cmath>
using namespace std;

bool primeCalc(int n) {
	for (int i = 2; i <= sqrt(n); i++)
		if (!(n % i)) return false;
	return true;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T, num, first, second;
	cin >> T;
	for(int i = 0; i < T; i++){
		cin >> num;
		if (num == 0) break;
		for (int i = num / 2; i >= 1; i--) {
			first = i;
			second = num - i;
			if (primeCalc(first) && primeCalc(second)) {
				cout << first << ' ' << second << '\n';
				break;
			}
		}
	}
}