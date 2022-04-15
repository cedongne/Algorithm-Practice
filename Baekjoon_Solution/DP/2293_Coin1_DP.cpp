#include <iostream>
#include <algorithm>

int coins[100];
int coinCnt[100] = {0, };

long long cases = 0;

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
    int tmpSum = 0;
    for(int coinIdx = 0; coinIdx < n;){
        while(true){
            tmpSum = coins[coinIdx] * (++coinCnt[coinIdx]);
            if(tmpSum == k){
                cases++;
            }
            else if(tmpSum > k){
                tmpSum -= coins[coinIdx++];
            }
        }
    }
}