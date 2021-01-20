#include <iostream>
using namespace std;

void Swap(int& first, int& second) {
	int temp;
	temp = first;
	first = second;
	second = temp;
}

int main() {
	int count;
	cin >> count;

	int* divisor = new int[count];
	for (int i = 0; i < count; i++) 
		cin >> divisor[i];
	for (int i = 0; i < count; i++) {
		for (int j = 0; j < count; j++) {
			if (count - 1 == j)
				continue;
			if (divisor[j] > divisor[j + 1])
				Swap(divisor[j], divisor[j + 1]);
		}
	}

	cout << divisor[0] * divisor[count - 1] << endl;
}