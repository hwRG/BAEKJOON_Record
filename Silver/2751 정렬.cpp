#include <iostream>
using namespace std;

void Merge(int values[], int leftFirst, int leftLast, int rightFirst, int rightLast) {
	int arySize = rightLast - leftFirst + 1;
	int* tempArray = new int[arySize];
	int index = 0;
	int saveFirst = leftFirst;

	while ((leftFirst <= leftLast) && (rightFirst <= rightLast)) {
		if (values[leftFirst] < values[rightFirst]) {
			tempArray[index] = values[leftFirst];
			leftFirst++;
		}
		else {
			tempArray[index] = values[rightFirst];
			rightFirst++;
		}
		index++;
	}
	while (leftFirst <= leftLast) {
		tempArray[index] = values[leftFirst];
		leftFirst++;
		index++;
	}
	while (rightFirst <= rightLast) {
		tempArray[index] = values[rightFirst];
		rightFirst++;
		index++;
	}
	for (index = 0; index <= rightLast - saveFirst; index++)
		values[index + saveFirst] = tempArray[index];
	delete[] tempArray;
}

void MergeSort(int values[], int first, int last)
// Post: The elements in values are sorted by key.
{
	if (first < last)
	{
		int middle = (first + last) / 2;
		MergeSort(values, first, middle);
		MergeSort(values, middle + 1, last);
		Merge(values, first, middle, middle + 1, last);
	}
}


int main() {
	int N;

	cin >> N;
	int* list = new int[N];
	for (int i = 0; i < N; i++)
		cin >> list[i];
	MergeSort(list, 0, N-1);

	for (int i = 0; i < N; i++)
		cout << list[i] << '\n';
}