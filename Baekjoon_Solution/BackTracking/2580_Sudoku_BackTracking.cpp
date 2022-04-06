#include <iostream>
#include <vector>
#define MAX_SIZE 9

struct holeCoor{
    int x;
    int y;
    int squareNum;
};

int sudoku[MAX_SIZE + 1][MAX_SIZE + 1];

bool row[MAX_SIZE + 1][MAX_SIZE + 1];
bool col[MAX_SIZE + 1][MAX_SIZE + 1];
bool square[MAX_SIZE + 1][MAX_SIZE + 1];

int holeNum = 0;
holeCoor hole[81];

int get_square_number(int x, int y){
    return ((x - 1)/ 3) + (((y - 1)/ 3) * 3) + 1;
}

bool back_tracking(int index){
    if(index == holeNum){
        for(int y = 1; y <= MAX_SIZE; y++){
            for(int x = 1; x <= MAX_SIZE; x++){
                std::cout << sudoku[y][x] << " ";
            }
            std::cout << "\n";
        }
        return true;
    }
    else{
        for(int num = 1; num <= MAX_SIZE; num++){
            int x = hole[index].x;
            int y = hole[index].y;
            int squareNum = hole[index].squareNum;

            if(!row[y][num] && !col[x][num] && !square[squareNum][num]){
                sudoku[y][x] = num;
                row[y][num] = true;
                col[x][num] = true;
                square[squareNum][num] = true;

                if(back_tracking(index + 1)){
                    return true;
                }

                sudoku[y][x] = 0;
                row[y][num] = false;
                col[x][num] = false;
                square[squareNum][num] = false;
            }
        }
    }
    return false;
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    for(int y = 1; y <= MAX_SIZE; y++){
        for(int x = 1; x <= MAX_SIZE; x++){
            std::cin >> sudoku[y][x];
            int squareNum = get_square_number(x, y);

            row[y][sudoku[y][x]] = true;
            col[x][sudoku[y][x]] = true;
            square[squareNum][sudoku[y][x]] = true;
            if(sudoku[y][x] == 0){
                hole[holeNum++] = {x, y, squareNum};
            }
        }
    }
    printf("\n");
    back_tracking(0);
}