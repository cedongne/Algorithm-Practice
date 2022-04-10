#include <iostream>
#define MAX(a, b) ((a > b) ? a : b)

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int n;
    int wine[10001][2];
    int max = 0;
    std::cin >> n;

    int tmp;

    for(int count = 1; count <= n; count++){
        std::cin >> tmp;
        
        wine[count][1] += tmp;
        wine[count][2] += tmp;
        if(max < MAX(wine[count][1], wine[count][2])){
            max = MAX(wine[count][1], wine[count][2]);
        }
        wine[count + 1][2] = wine[count][1];
        if(wine[count + 2][1] < MAX(wine[count][1], wine[count][2])){
            wine[count + 2][1] = MAX(wine[count][1], wine[count][2]);
        }
        wine[count + 3][1] = MAX(wine[count][1], wine[count][2]);
    }

    std::cout << max;
}