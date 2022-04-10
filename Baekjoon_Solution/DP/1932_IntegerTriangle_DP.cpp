#include <iostream>
#define MAX(a, b) ((a > b) ? a : b)
int n;

int triangle[501][501];
int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    std::cin >> n;

    for(int height = 1; height <= n; height++){
        for(int width = 1; width <= height; width++){
            std::cin >> triangle[height][width];
            triangle[height][width] += MAX(triangle[height - 1][width - 1], triangle[height - 1][width]);
        }
    }

    int max = 0;
    for(int width = 1; width <= n; width++){
        if(max < triangle[n][width]){
            max = triangle[n][width];
        }
    }

    std::cout << max << std::endl;
}