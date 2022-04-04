#include <iostream>
#include <vector>

int n;
int queenCnt = 0;
int caseCnt = 0;
bool overlapped;
bool col[32];
bool rightDiagonal[32];
bool leftDiagonal[32];

void back_tracking(int line){
    if(queenCnt == n){
        caseCnt++;
    }
    else{
        for(int index = 1; index <= n; index++){
            if(!col[index] && !leftDiagonal[index + line] && !rightDiagonal[index - line]){
                col[index] = true;
                leftDiagonal[index + line] = true;
                rightDiagonal[index - line] = true;
                queenCnt++;

                back_tracking(line + 1);

                col[index] = false;
                leftDiagonal[index + line] = false;
                rightDiagonal[index - line] = false;
                queenCnt--;
            }
        }
    }
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    std::cin >> n;

    back_tracking(1);
    std::cout << caseCnt << '\n';
}