#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

queue<pair<int, int>> q;

bool changable_test(string str, string target){
    int diffCnt = 0;
    for(int index = 0; index < str.length(); index++){
        if(str[index] != target[index]){
            diffCnt++;
        }
    }
    
    return (diffCnt == 1) ? true : false;
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    vector<int> changeArr(words.size(), 1000);
    int len = begin.length();
    
    for(int index = 0; index < words.size(); index++){
        bool change = changable_test(begin, words[index]);
        if(change){
            q.push({index, 1});
            changeArr[index] = change;
        }
    }
    
    while(!q.empty()){
        int wordIdx = q.front().first;
        int changeCnt = q.front().second;
        q.pop();
        
        for(int index = 0; index < words.size(); index++){
            if(changable_test(words[wordIdx], words[index]) && changeArr[index] > changeCnt + 1){
                changeArr[index] = changeCnt + 1;
                q.push({index, changeArr[index]});
            }
        }
    }
    
    for(int index = 0; index < words.size(); index++){
        if(target == words[index]){
            answer = changeArr[index];
        }
    }
    
    return answer;
}