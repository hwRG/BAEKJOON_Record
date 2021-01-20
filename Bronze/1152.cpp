#include <iostream>
#include <string>
using namespace std;

int main() {
	string line;
	int count = 1;
	getline(cin, line);

	
	for (int i = 0; i < line.length(); i++) 
		if (line[i] == ' ')
			count++;
	if (line[0] == ' ')
		count--;
	if (line[line.length() - 1] == ' ')
		count--;
	cout << count;
	return 0;
}

/*
	for (int i = 0; i < line.length(); i++)
		if (line[i] >= 97 && line[i] <= 122)
			line[i] = line[i] - 32;
*/