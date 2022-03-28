#include <iostream>
#include <queue>
#include <stack>
#include <string>

std::pair<int, int> direction[4] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
std::pair<int, int> goal;
int colSize, rowSize;

int maze[100][100];
int visit[100][100] = {0, };
std::queue<std::pair<int ,int>> q;
std::stack<std::pair<int, int>> route;
std::stack<std::pair<int, int>> cross;

int wayCnt = 0;

void bfs(std::pair<int, int> startPoint){
    while(!q.empty()){
        std::pair<int, int> cur = q.front();
        route.push(cur);
        q.pop();
        
        if(cur == goal){
            return;
        }

        wayCnt = 0;

        for(auto dir : direction){
            int nextX = cur.second + dir.second;
            int nextY = cur.first + dir.first;

            if(nextX < 0 || nextX >= rowSize || nextY < 0 || nextY >= colSize){
                continue;
            }
            if(maze[nextY][nextX] && !visit[nextY][nextX]){
                wayCnt++;
                q.push({nextY, nextX});
                visit[nextY][nextX] = 1;
            }
        }
        printf("cur : %d %d, wayCnt : %d\n", cur.second, cur.first, wayCnt);
        if(wayCnt >= 2){
            cross.push(cur);
        }
        else if(wayCnt == 0){
            printf("route : %d %d, cross : %d %d\n", route.top().second, route.top().first, cross.top().second, cross.top().first);
            while(route.top() != cross.top()){
                route.pop();
            }
        }
    }
}

void dfs(int curY, int curX){
    for(auto dir : direction){
        int nextY = curY + dir.first;
        int nextX = curX + dir.second;

        if(nextX < 0 || nextX >= rowSize || nextY < 0 || nextY >= colSize){
            continue;
        }
        if(maze[nextY][nextX] && !visit[nextY][nextX]){
            dfs(nextY, nextX);
            visit[nextY][nextX] = 1;
        }
    }
}

int main(){
    scanf("%d %d", &colSize, &rowSize);
    goal = {colSize - 1, rowSize - 1};

    for(int col = 0; col < colSize; col++){
        std::string mazeRow;
        std::cin >> mazeRow;

        for(int row = 0; row < rowSize; row++){
            maze[col][row] = mazeRow[row] - '0';
        }
    }

    q.push({0, 0});
    visit[0][0] = 1;
    bfs({0, 0});

    printf("%d\n", route.size());
}