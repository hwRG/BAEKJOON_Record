#include <iostream>
using namespace std;

int main() {
	int count;
	int a, b;
	cin >> count;
	int* listA = new int[count];
	int* listB = new int[count];
	
	for(int i = 0; i < count; i++)
		cin >> listA[i] >> listB[i];
	for (int i = 0; i < count; i++)
		cout << listA[i] + listB[i] << endl;
}