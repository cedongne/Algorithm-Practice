#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool comp(string str1, string str2){
    return str1 + str2 > str2 + str1;
}

string solution(vector<int> numbers) {
    vector<string> strNums;
    for(auto num : numbers){
        strNums.push_back(to_string(num));
    }
    
    sort(strNums.begin(), strNums.end(), comp);
    
    string answer = "";
    for(auto num : strNums){
        answer += num;
    }
    
    if(answer[0] == '0'){
        answer = "0";
    }
    return answer;
}
