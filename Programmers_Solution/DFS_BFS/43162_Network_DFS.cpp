#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool visit[200] = { 0, };

void dfs(int computer, int n, vector<vector<int>> computers){
    for(int index = 0; index < n; index++){
        if(!visit[index] && computers[computer][index]){
            visit[index] = true;
            dfs(index, n, computers);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int networkCnt = 0;
    
    for(int count = 0; count < n; count++){
        if(!visit[count]){
            visit[count] = true;
            networkCnt++;
            dfs(count, n, computers);
        }
    }
    
    return networkCnt;
}