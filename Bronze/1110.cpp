#include <iostream>
using namespace std;

int main() {
	int num, result = 0, count = 0, tens;
	cin >> num;
	result = num;
	while (1) {
		tens = (num % 10) *10;
		if (num < 10)
			num *= 10;
		num = num % 10 + num / 10;
		if (num > 9)
			num %= 10;
		num = tens + num;
		count++;
		if (result == num && count != 0)
			break;
	}
	cout << count;
}