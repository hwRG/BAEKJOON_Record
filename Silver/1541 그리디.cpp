#include <iostream>
#include <string>
using namespace std;

int list[1000];

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	string str, temp;
	int count = 0, word = 0;
	cin >> str;

	while(word < str.length()) {
		temp = str[word];
		word++;
		while (str[word] != '-' && str[word] != '+' && str[word] != '\0') {
			temp += str[word];
			word++;
		}
		list[count] = atoi(temp.c_str());
		count++;
	}

	int total = 0, index = 0;
	while (index < count) {
		int piece = 0;
		if (list[index] < 0) {
			piece += abs(list[index]);
			if (list[index + 1] > 0) {
				index++;
				while (list[index] > 0) {
					piece += list[index];
					index++;
				}
			}
			else index++;
			piece -= piece*2;
		}
		else {
			piece = list[index];
			index++;
		}
		total += piece;
	}
	cout << total;
}