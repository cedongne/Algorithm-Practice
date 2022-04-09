#include <iostream>
#include <queue>

std::pair<int, int> direction[4] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

std::queue<std::pair<int, int>> q;

int n;
int map[102][102];
bool zone[102][102];

int maxZoneNum = 0;

void bfs(){
    while(!q.empty()){
        std::pair<int, int> cur = q.front();
        q.pop();
        for(auto dir : direction){
            int nextX = cur.second + dir.second;
            int nextY = cur.first + dir.first;

            if(!zone[nextY][nextX]){
                q.push({nextY, nextX});
                zone[nextY][nextX] = true;
            }
        }
    }
}

void flood(int height){
    for(int y = 1; y <= n; y++){
        for(int x = 1; x <=n; x++){
            if(map[y][x] <= height){
                zone[y][x] = true;
            }
            else{
                zone[y][x] = false;
            }
        }
    }

    int zoneNum = 0;
    for(int y = 1; y <= n; y++){
        for(int x = 1; x <= n; x++){
            if(!zone[y][x]){
                zone[y][x] = true;
                q.push({y, x});
                bfs();
                zoneNum++;
            }
        }
    }
    if(maxZoneNum < zoneNum){
        maxZoneNum = zoneNum;
    }
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    std::cin >> n;

    int maxHeight = 0;

    for(int y = 0; y <= n + 1; y++){
        for(int x = 0; x <= n + 1; x++){
            zone[y][x] = true;
        }
    }

    for(int y = 1; y <= n; y++){
        for(int x = 1; x <= n; x++){
            std::cin >> map[y][x];
            if(maxHeight < map[y][x]){
                maxHeight = map[y][x];
            }
        }
    }
    for(int height = 0; height <= maxHeight; height++){
        flood(height);
    }
    std::cout << maxZoneNum;
}