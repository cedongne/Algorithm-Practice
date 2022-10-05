#include<vector>
#include<iostream>
#include <queue>
using namespace std;

pair<int, int> direction[4] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

int bfs(vector<vector<int>> maps){
    int rowSize = maps.size();
    int colSize = maps[0].size();
    
    queue<pair<int, int>> q;
    q.push({0, 0});
    
    while(!q.empty()){
        int curRow = q.front().first;
        int curCol = q.front().second;
        q.pop();
        
        if(curRow == rowSize - 1 && curCol == colSize - 1){
            return maps[curRow][curCol];
        }
        
        for(auto dir : direction){
            int nextRow = curRow + dir.first;
            int nextCol = curCol + dir.second;
            
            if(nextRow < 0 || nextRow >= rowSize || nextCol < 0 || nextCol >= colSize || maps[nextRow][nextCol] != 1){
                continue;
            }
            else{
                maps[nextRow][nextCol] = maps[curRow][curCol] + 1;
                q.push({nextRow, nextCol});
            }
        }
    }
    
    return maps[rowSize - 1][colSize - 1];
}

int solution(vector<vector<int> > maps)
{
    int answer = bfs(maps);
    return (answer == 1) ? -1 : answer;

}