#include <iostream>
using namespace std;

void Swap(int& a, int& b) {
	int temp;
	temp = a;
	a = b;
	b = temp;
}

int main() {
	int N;

	cin >> N;
	int* list = new int[N];
	for (int i = 0; i < N; i++)
		cin >> list[i];
	for (int i = 0; i < N; i++) 
		for (int j = 0; j < N-1; j++)
			if (list[j] > list[j + 1])
				Swap(list[j], list[j + 1]);

	for (int i = 0; i < N; i++)
		cout << list[i] << '\n';
}