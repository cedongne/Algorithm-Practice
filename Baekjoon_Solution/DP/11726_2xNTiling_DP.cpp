#include <iostream>

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int dp[3];
    int n;

    std::cin >> n;

    dp[1] = 1;
    dp[2] = 2;
    for(int count = 3; count <= n; count++){
        dp[0] = dp[1];
        dp[1] = dp[2];
        dp[2] = (dp[0] + dp[1]) % 10007;
    }

    if(n > 1){
        n = 3;
    }
    std::cout << dp[n - 1];
}