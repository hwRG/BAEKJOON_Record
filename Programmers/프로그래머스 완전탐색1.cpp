#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    vector<int> answers = { 1,3,2,4,2 };
    vector<int> answer;
    vector<int> a = { 1,2,3,4,5 };
    vector<int> b = { 2,1,2,3,2,4,2,5 };
    vector<int> c = { 3,3,1,1,2,2,4,4,5,5 };
    vector<int> count(3);
    int top;
    for (int i = 0; i < answers.size(); i++) {
        if (answers[i] == a[i % 5]) count[0]++;
        if (answers[i] == b[i % 8]) count[1]++;
        if (answers[i] == c[i % 10]) count[2]++;
    }
    top = max({ count[0], count[1], count[2] });
    for (int i = 0; i < 3; i++) 
        if (count[i] == top) 
            answer.push_back(i + 1);
    for (auto i : answer)
        cout << i << ' ';
}