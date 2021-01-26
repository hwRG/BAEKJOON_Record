#include <iostream>
using namespace std;

int test[100000];

int main() {
	int num, max = 0, count = 0, testCase = 0;
	bool right = true;
	for (int i = 0; i < 100000; i++) {
		cin >> num;
		if (num == 0)
			break;
		test[i] = num;
		if (max < num) max = num;
		testCase++;
	}
	int* total = new int[max+1];
	int* prime = new int[max+1];

	for (int i = 1; i <= max; i++) {
		total[i] = i;

	for (int i = 2; i <= max; i++) {
		if (total[i] == 0)
			continue;
		prime[count] = total[i];
		count++;
		for (int j = i; j <= max; j+=i)
			total[j] = 0;
	}
	int first = 0, end = count;
	for (int i = 0; i < testCase; i++) {
		while (1) {
			if (prime[first] + prime[end] == test[i]) {
				cout << test[i] << " = " << prime[first] << " + " << prime[end];
				break;
			}
			else if (prime[first] + prime[end] == test[i]) {
			
			}
		}
	}
}