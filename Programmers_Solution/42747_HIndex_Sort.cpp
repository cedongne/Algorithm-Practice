#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> citations) {
    sort(citations.begin(), citations.end());
    
    int answer = 0;
    
    for(int count = citations.size(); count > 0; count--){
        if(citations[citations.size() - count] >= count && citations[citations.size() - count - 1] <= count){
            answer = count;
            break;
        }
    }
    return answer;
}