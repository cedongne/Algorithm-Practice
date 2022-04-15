#include <iostream>

int dp[10001] = { 0, };
int coins[101];

int n, k;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    std::cin >> n >> k;

    dp[0] = 1;

    for (int coinIdx = 1; coinIdx <= n; coinIdx++) {
        std::cin >> coins[coinIdx];

        for (int dpCnt = coins[coinIdx]; dpCnt <= k; dpCnt++) {
            dp[dpCnt] += dp[dpCnt - coins[coinIdx]];
        }
    }

    std::cout << dp[k];
}