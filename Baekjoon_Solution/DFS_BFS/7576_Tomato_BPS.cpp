#include <iostream>
#include <queue>

struct Coordinate{
    int x;
    int y;
    int h;
};
Coordinate direction[6] = {{1, 0, 0}, {-1, 0, 0}, {0, 1, 0}, {0, -1, 0}, {0, 0, 1}, {0, 0, -1}};

std::queue<Coordinate> q;
int box[100][100][100];
int days[100][100][100];

int colSize, rowSize, height;

int maxDays = 0;

void bfs(){
    while(!q.empty()){
        Coordinate cur = q.front();
        q.pop();

        for(auto dir : direction){
            int nextX = cur.x + dir.x;
            int nextY = cur.y + dir.y;
            int nextH = cur.h + dir.h;

            if(nextX < 0 || nextX >= rowSize || nextY < 0 | nextY >= colSize || nextH < 0 || nextH >= height){
                continue;
            }
            if(box[nextH][nextY][nextX] == 0 && days[nextH][nextY][nextX] == 0){
                q.push({nextX, nextY, nextH});
                days[nextH][nextY][nextX] = days[cur.h][cur.y][cur.x] + 1;
                box[nextH][nextY][nextX] = 1;
                if(maxDays < days[nextH][nextY][nextX]){
                    maxDays = days[nextH][nextY][nextX];
                }
            }
        }
    }
}

int main(){
    scanf("%d %d %d", &rowSize, &colSize, &height);

    for(int high = 0; high < height; high++){
        for(int col = 0; col < colSize; col++){
            for(int row = 0; row < rowSize; row++){
                scanf("%d", &box[high][col][row]);
                if(box[high][col][row] == 1){
                    q.push({row, col, high});
                }
            }
        }
    }
    
    bfs();

    for(int high = 0; high < height; high++){
        for(int col = 0; col < colSize; col++){
            for(int row = 0; row < rowSize; row++){
                if(box[high][col][row] == 0){
                    maxDays = -1;
                }
            }
        }
    }
    printf("%d\n", maxDays);
}