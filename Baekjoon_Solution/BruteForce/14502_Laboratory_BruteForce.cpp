#include <iostream>

int n, m;
int map[10][10];
int tempMap[10][10];

std::pair<int, int> ways[64];
std::pair<int, int> viruses[64];

int virusNum = 0;
int tempVirusNum = 0;
int waysNum = 0;

int maxSafeZone = 0;

void bfs(){
    for(int firstWall = 0; firstWall < waysNum - 2; firstWall++){
        for(int secondWall = firstWall + 1; secondWall < waysNum - 1; secondWall++){
            for(int thirdWall = secondWall + 1; thirdWall < waysNum; thirdWall++){

                for(int y = 1; y <= n; y++){
                    for(int x = 1; x <= m; x++){
                        tempMap[y][x] = map[y][x];
                    }
                }

                tempMap[ways[firstWall].first][ways[firstWall].second] = 1;
                tempMap[ways[secondWall].first][ways[secondWall].second] = 1;
                tempMap[ways[thirdWall].first][ways[thirdWall].second] = 1;

                tempVirusNum = virusNum;

                for(int spreadCnt = 0; spreadCnt < tempVirusNum; spreadCnt++){
                    if(tempMap[viruses[spreadCnt].first + 1][viruses[spreadCnt].second] == 0){
                        tempMap[viruses[spreadCnt].first + 1][viruses[spreadCnt].second] = 2;
                        viruses[tempVirusNum++] = {viruses[spreadCnt].first + 1, viruses[spreadCnt].second};
                    }
                    if(tempMap[viruses[spreadCnt].first - 1][viruses[spreadCnt].second] == 0){
                        tempMap[viruses[spreadCnt].first - 1][viruses[spreadCnt].second] = 2;
                        viruses[tempVirusNum++] = {viruses[spreadCnt].first - 1, viruses[spreadCnt].second};
                    }
                    if(tempMap[viruses[spreadCnt].first][viruses[spreadCnt].second + 1] == 0){
                        tempMap[viruses[spreadCnt].first][viruses[spreadCnt].second + 1] = 2;
                        viruses[tempVirusNum++] = {viruses[spreadCnt].first, viruses[spreadCnt].second + 1};
                    }
                    if(tempMap[viruses[spreadCnt].first][viruses[spreadCnt].second - 1] == 0){
                        tempMap[viruses[spreadCnt].first][viruses[spreadCnt].second - 1] = 2;
                        viruses[tempVirusNum++] = {viruses[spreadCnt].first, viruses[spreadCnt].second - 1};
                    }
                }

                int safeZone = waysNum - 3 - tempVirusNum + virusNum;
                if(maxSafeZone < safeZone){
                    maxSafeZone = safeZone;
                }
            }
        }
    }
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    std::cin >> n >> m;
    for(int y = 1; y <= n; y++){
        for(int x = 1; x <= m; x++){
            std::cin >> map[y][x];
            if(map[y][x] == 2){
                viruses[virusNum++] = {y, x};
            }
            else if(map[y][x] == 0){
                ways[waysNum++] = {y, x};
            }
        }
    }

    for(int y = 0; y < 10; y++){
        for(int x = 0; x < 10; x++){
            tempMap[y][x] = -1;
        }
    }
    bfs();
    std::cout << maxSafeZone;
}