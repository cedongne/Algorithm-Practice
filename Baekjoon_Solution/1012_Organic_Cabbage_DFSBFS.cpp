#include <iostream>
#include <queue>

std::pair<int, int> direction[4] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
std::queue<std::pair<int, int>> q;

int graph[50][50];
int visit[50][50];

int warmNum = 0;

int caseNum;
int cabbageNum;
int colSize;
int rowSize;

void bfs(int col, int row){
    while(!q.empty()){
        std::pair<int, int> cur = q.front();
        q.pop();

        for(auto dir : direction){
            int nextX = cur.second + dir.second;
            int nextY = cur.first + dir.first;

            if(nextX < 0 || nextX >= rowSize || nextY < 0 || nextY >= colSize){
                continue;
            }
            if(graph[nextY][nextX] && visit[nextY][nextX] == 0){
                q.push({nextY, nextX});
                visit[nextY][nextX] = 1;
            }
        }
    }
}

void reset(){
    for(int col = 0; col < colSize; col++){
        for(int row = 0; row < rowSize; row++){
            graph[col][row] = 0;
            visit[col][row] = 0;
        }
    }
    warmNum = 0;
}

int main(){
    scanf("%d", &caseNum);
    for(int cases = 0; cases < caseNum; cases++){
        reset();
        
        scanf("%d %d %d", &rowSize, &colSize, &cabbageNum);

        for(int count = 0; count < cabbageNum; count++){
            int tmpX, tmpY;
            scanf("%d %d", &tmpX, &tmpY);

            graph[tmpY][tmpX] = 1;
        }

        for(int col = 0; col < colSize; col++){
            for(int row = 0; row < rowSize; row++){
                if(graph[col][row] && !visit[col][row]){
                    q.push({col, row});
                    visit[col][row] = 1;
                    bfs(col, row);
                    warmNum++;
                }
            }
        }
        printf("%d\n", warmNum);
    }

}