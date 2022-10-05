#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    for(auto command : commands){
        vector<int> subArray;
        int start = command[0];
        int end = command[1];
        int pick = command[2];

        for(int index = start - 1; index < end; index++){
            subArray.push_back(array[index]);
        }

        sort(subArray.begin(), subArray.end());
        answer.push_back(subArray[pick - 1]);
    }
    return answer;
}