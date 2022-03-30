#include <iostream>
#include <queue>
#include <vector>

std::pair<int, int> direction[4] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
std::queue<std::pair<int, int>> q;
std::vector<std::pair<int, int>> walls;
std::vector<std::pair<int, int>> visit;
int rowSize, colSize;
int map[1000][1000];
int distance[1000][1000];

int minDistance = 1000000;

void bfs(){
    while(!q.empty()){
        std::pair<int, int> cur = q.front();
        q.pop();

        for(auto dir : direction){
            int nextX = cur.second + dir.second;
            int nextY = cur.first + dir.first;

            if(nextX < 0 || nextX >= colSize || nextY < 0 || nextY >= rowSize){
                continue;
            }
            if(distance[nextY][nextX] == 0){
                if(map[nextY][nextX] == 1)
                q.push({nextY, nextX});
                distance[nextY][nextX] = distance[cur.first][cur.second] + 1;
                visit.push_back({nextY, nextX});
            }
        }
    }
}

void reset(){
    for(auto visited : visit){
        distance[visited.first][visited.second] = 0;
    }
    visit.clear();
}

int main(){
    scanf("%d %d", &rowSize, &colSize);
    for(int row = 0; row < rowSize; row++){
        std::string line;
        std::cin >> line;

        for(int index = 0; index < colSize; index++){
            map[row][index] = line[index] - '0';
            if(line[index] == '1'){
                walls.push_back({row, index});
            }
        }
    }

    for(auto wall : walls){
        map[wall.first][wall.second] = 0;
        q.push({0, 0});
        distance[0][0] = 1;

        bfs();

        map[wall.first][wall.second] = 1;

        if(distance[rowSize - 1][colSize - 1] > 0 && distance[rowSize - 1][colSize - 1] < minDistance){
            minDistance = distance[rowSize - 1][colSize - 1];
        }

        reset();
    }

    if(minDistance == 1000000){
        minDistance = -1;
    }
    printf("%d\n", minDistance);
}