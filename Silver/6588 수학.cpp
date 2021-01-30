#include <iostream>
using namespace std;

int prime[1000001], total[1000001], before, primeCount;

void primeCalc() {
	for (int i = 2; i <= 1000000; i++)
		total[i] = i;
	for (int i = 2; i <= 1000000; i++) { 
		if (total[i] == 0)
			continue;
		prime[primeCount] = total[i];
		primeCount++;
		for (int j = i; j <= 1000000; j += i)
			total[j] = 0;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	primeCalc();

	for (int t = 0; t < 1000000; t++) {
		int num, count = 0;
		cin >> num;
		if (num == 0) break;

		int min = 0, current = primeCount/2, max = primeCount;
		while (1) {
			if (prime[current] < num){
				current = (max + current) / 2;
				min = current;
			}
			else if (prime[current] > num){
				current = (min + max) / 2;
				max = current;
			}
		}

		bool right = false;
		for (int i = current - 1; i >= 0; i--) {
			if (right == true)
				break;
			for (int j = 0; j < i; j++) {
				if (prime[i] + prime[j] == num) {
					cout << num << " = " << prime[i] << " + " << prime[j] << '\n';
					right = true;
					break;
				}
				else if (prime[i] + prime[j] > num)
					break;
			}
		}
	}
}