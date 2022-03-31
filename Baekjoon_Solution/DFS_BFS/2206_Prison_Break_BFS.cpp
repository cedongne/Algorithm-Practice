#include <iostream>
#include <queue>
#include <vector>

struct state{
    int x;
    int y;
    int breaking;
};

std::pair<int, int> direction[4] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int rowSize, colSize;
int map[1000][1000];

int visit[1000][1000][2];
std::queue<state> q;

int bfs(){
    while(!q.empty()){
        state cur = q.front();
        q.pop();
        if(cur.x == colSize - 1 && cur.y == rowSize - 1){
            return visit[cur.y][cur.x][cur.breaking];
        }

        for(auto dir : direction){
            int nextX = cur.x + dir.second;
            int nextY = cur.y + dir.first;

            if(nextX < 0 || nextX >= colSize || nextY < 0 || nextY >= rowSize){
                continue;
            }
            if(map[nextY][nextX] == 1 && !cur.breaking){
                q.push({nextX, nextY, 1});
                visit[nextY][nextX][1] = visit[cur.y][cur.x][cur.breaking] + 1;
            }
            else if(map[nextY][nextX] == 0 && !visit[nextY][nextX][cur.breaking]){
                q.push({nextX, nextY, cur.breaking});
                visit[nextY][nextX][cur.breaking] = visit[cur.y][cur.x][cur.breaking] + 1;
            }
        }
    }

    return -1;
}


int main(){
    scanf("%d %d", &rowSize, &colSize);
    for(int row = 0; row < rowSize; row++){
        std::string line;
        std::cin >> line;

        for(int index = 0; index < colSize; index++){
            map[row][index] = line[index] - '0';
        }
    }

    q.push({0, 0, 0});
    visit[0][0][0] = 1;

    printf("%d", bfs());

    printf("\n");
    for(int row = 0; row < rowSize; row++){
        for(int col = 0; col < colSize; col++){
            printf("%d", visit[row][col][0]);
        }
        printf("\n");
    }
    printf("\n");
    for(int row = 0; row < rowSize; row++){
        for(int col = 0; col < colSize; col++){
            printf("%d", visit[row][col][1]);
        }
        printf("\n");
    }

}