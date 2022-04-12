#include <iostream>

int tiles[31] = {0, };

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int n;

    std::cin >> n;
    tiles[0] = 1;
    tiles[2] = 3;

    for(int index = 4; index <= n; index += 2){
        tiles[index] = tiles[index - 2] * 3;
        for(int temp = 4; temp <= index; temp += 2){
            tiles[index] += tiles[index - temp] * 2;
        }
    }

    std::cout << tiles[n];
}