#include <iostream>
#include <algorithm>

int coins[100];
long long cases[10001] = {0, };

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);


    int n, k;
    std::cin >> n >> k;

    for(int count = 0; count < n; count++){
        std::cin >> coins[count];
    }
    std::sort(coins + n, coins);

    for(int coin = 0; coin < n; coin++){
        for(int value = 0; value <= k - coins[coin]; value++){
            cases[value]
        }
    }
}