#include <iostream>
#include <vector>
#define MAX_SIZE 9

struct coordinate{
    int x;
    int y;
    int squareNum;
};

bool row[MAX_SIZE + 1][MAX_SIZE + 1];
bool col[MAX_SIZE + 1][MAX_SIZE + 1];
bool square[MAX_SIZE + 1][MAX_SIZE + 1];

std::vector<coordinate> coor;

int holeNum;
void back_tracking(int holeCnt){
    coordinate cur = coor[holeCnt];
    for(int count = 1; count <= MAX_SIZE; count++){
        if(!row[cur.y][count] && !col[cur.x][count] && !square[cur.squareNum][count]){
            row[cur.y][count] = true;
            col[cur.x][count] = true;
            square[cur.squareNum][count] = true;

            back_tracking(holeCnt + 1);
            
            row[cur.y][count] = false;
            col[cur.x][count] = false;
            square[cur.squareNum][count] = false;
        }
    }

}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int num;
    for(int count1 = 1; count1 < MAX_SIZE + 1; count1++){
        for(int count2 = 1; count2 < MAX_SIZE + 1; count2++){
            std::cin >> num;
            row[count1][num] = true;
            col[count2][num] = true;
            int squareNum = (count2 / 3) + ((count1 / 3) * 3);
            square[squareNum][num] = true;
            if(num == 0){
                coor.push_back({count2, count1, squareNum});
            }
        }
    }

    holeNum = coor.size();
    back_tracking(0);
}