#include <iostream>
#include <algorithm>
using namespace std;

typedef struct meeting {
	int start, end;
}meeting;

bool startSort(meeting* a, meeting* b) {
	return a->start < b->start;
}
bool endSort(meeting* a, meeting* b) {
	return a->end < b->end;
}

int main() {
	meeting* meet[100000];
	int total, count = 0;
	cin >> total;
	for (int i = 0; i < total; i++) {
		int start, end;
		cin >> start >> end;
		meet[i] = (meeting*)malloc(sizeof(meeting));
		meet[i]->start = start;
		meet[i]->end = end;
	}
	sort(meet, meet + total, endSort);
	int now = 0;
	for (int i = 0; i < total; i++) {
		if (now <= meet[i]->start) {
			int j = i + 1;
			if (j < total && meet[i]->end == meet[j]->end)
				j++;
			sort(meet + i, meet + j, startSort);
			now = meet[i]->end;
			count++;
		}
	}
	cout << count;
}