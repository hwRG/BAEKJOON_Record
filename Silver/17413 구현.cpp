#include <iostream>
#include <string>
using namespace std;

string piece[100000], mids[100000];

int main() {
	int cut = 0, count = 0;
	string str, tempStr;
	getline(cin, str);

	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '<') {
			int repeat = 0;
			while(1){
				if (str[i] == '>')
					repeat++;
				piece[count] += str[i];
				i++;
				if (repeat == 2)
					break;
			}
			cut = i + 2;
			count++;
		}
		else if (str[i + 1] == ' ' || i == str.length() - 1) {
			for (int j = cut; j <= i; j++)
				piece[count] += str[j];
			cut = i + 2;
			count++;
		}
	}
	int pos = 0;
	for (int i = 0; i < count; i++) {	// 나눈 문자열들
		if (piece[i][0] == '<') {
			string first, mid, end;
			for(int j = 0; j < piece[i].length(); j++) {
				if (piece[i][j] == '>') {
					for(int k = 0 ; k <= j; k++)
						first += piece[i][k];
					j++;
					while(1){
						if (piece[i][j] == '<')
							break;
						mid += piece[i][j];
						j++;
					}
					for (int k = j; k < piece[i].length(); k++)
						end += piece[i][k];
					break;
				}
			}
			int midCount = 0;
			cut = 0;
			for (int j = 0; j < mid.length(); j++) {
				if (mid[j + 1] == ' ' || j == mid.length() - 1) {
					for (int k = cut; k <= j; k++)
						mids[midCount] += mid[k];
					midCount++;
					cut = j + 2;
				}
			}
			mid = "";
			for(int t = 0; t < midCount; t++){
				for (int j = 0; j < mids[t].length(); j++)
					tempStr += mids[t][mids[t].length() - j - 1];
				mid += tempStr + ' ';
				tempStr = "";
			}
			piece[i] = first + mid + end;
		}
		else{
			for (int j = 0; j < piece[i].length(); j++)
				tempStr += piece[i][piece[i].length() - j - 1];
			piece[i] = tempStr;
			tempStr = "";
		}
	}

	for(int i = 0; i < count; i++)
		cout << piece[i] << ' ';
}