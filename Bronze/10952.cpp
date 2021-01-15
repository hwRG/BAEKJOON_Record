#include <iostream>
#include <string>
using namespace std;

int main() {
	int count;
	cin >> count;
	string* list = new string[count];
	int* listA = new int[count];
	int* listB = new int[count];

	for (int i = 0; i < count; i++){
		cin >> list[i];
		listA[i] = list[i][0] - 48;
		listB[i] = list[i][2] - 48;
	}
	for (int i = 0; i < count; i++)
		cout << listA[i] + listB[i] << endl;
}