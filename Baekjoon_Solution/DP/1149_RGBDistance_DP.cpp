#include <iostream>
#define MIN(a, b) ((a < b) ? a : b)
int colors[1001][3];
int sum = 0;


int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int n;
    std::cin >> n;

    for(int count = 1; count <= n; count++){
        std::cin >> colors[count][0] >> colors[count][1] >> colors[count][2];
        colors[count][0] += MIN(colors[count - 1][1], colors[count - 1][2]);
        colors[count][1] += MIN(colors[count - 1][0], colors[count - 1][2]);
        colors[count][2] += MIN(colors[count - 1][0], colors[count - 1][1]);
    }
    
    std::cout << MIN(MIN(colors[n][0], colors[n][1]), colors[n][2]);
}