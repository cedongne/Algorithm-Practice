#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>

std::pair<int, int> direction[4] = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};

int estateNum;
int graph[25][25];
int visit[25][25];

int estateCnt = 0;
std::vector<int> estates;
int houseCnt;

std::queue<std::pair<int, int>> q;

void dfs(int x, int y){
    visit[x][y] = 1;
    houseCnt++;
    for(auto dir : direction){
        int nextX = x + dir.first;
        int nextY = y + dir.second;
        if(nextX < 0 || nextX >= estateNum || nextY < 0 || nextY >= estateNum){
            continue;
        }
        else if(graph[nextX][nextY] == 1 && visit[nextX][nextY == 0]){
            dfs(nextX, nextY);
        }
    }
}

void bfs(int x, int y){
    visit[x][y] = 1;
    while(!q.empty()){
        std::pair<int, int> cur = q.front();
        q.pop();
        houseCnt++;

        for(auto dir : direction){
            int nextX = cur.first + dir.first;
            int nextY = cur.second + dir.second;

            if(nextX < 0 || nextX >= estateNum || nextY < 0 || nextY >= estateNum){
                continue;
            }
            if(graph[nextX][nextY] == 1 && visit[nextX][nextY] == 0){
                q.push({nextX, nextY});
                visit[nextX][nextY] = 1;
            }
        }
    }
}

int main(){
    scanf("%d", &estateNum);
    for(int col = 0; col < estateNum; col++){
        std::string tmp;
        std::cin >> tmp;
        for(int index = 0; index < tmp.length(); index++){
            graph[col][index] = tmp[index] - '0';
        }
    }

    for(int col = 0; col < estateNum; col++){
        for(int row = 0; row < estateNum; row++){

            if(graph[col][row] == 1 && visit[col][row] == 0){
//                dfs(col, row);
                q.push({col, row});
                bfs(q.front().first, q.front().second);
                estates.push_back(houseCnt);
                houseCnt = 0;
            }
        }
    }
    printf("%d\n", estates.size());
    std::sort(estates.begin(), estates.end());
    for(int count = 0; count < estates.size(); count++){
        printf("%d\n", estates[count]);
    }
}