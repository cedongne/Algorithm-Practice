#include <iostream>
#define MAX(a, b) ((a > b) ? a : b)
int n;
int stair[400][3];

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    std::cin >> n;
    for(int count = 1; count <= n; count++){
        int num;

        std::cin >> num;
        stair[count][1] += num;
        stair[count][2] += num;
        if(stair[count + 1][2] < stair[count][1]){
            stair[count + 1][2] = stair[count][1];
        }
        if(stair[count + 2][1] < MAX(stair[count][1], stair[count][2])){
            stair[count + 2][1] = MAX(stair[count][1], stair[count][2]);
        }
    }

    std::cout << MAX(stair[n][1], stair[n][2]);
}