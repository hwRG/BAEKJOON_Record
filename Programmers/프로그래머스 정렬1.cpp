#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    vector<int> array = { 1,5,2,6,3,7,4 };
    vector<vector<int>> commands = { {2,5,3}, {4,4,1}, {1,7,3} };
    vector<int> answer;
    for(int p = 0; p < commands.size(); p++){
        int i = commands[p][0], j = commands[p][1], k = commands[p][2];
        vector<int> temps;
        for (int q = i-1; q < j; q++) 
            temps.push_back(array[q]);
        sort(temps.begin(), temps.end());
        answer.push_back(temps[k - 1]);
    }
    for (int i = 0; i < answer.size(); i++) 
        cout << answer[i];
}