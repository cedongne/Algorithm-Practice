#include <iostream>

int n, k;
long long dp[201][201] = { 0, };

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> n >> k;

	for (int count = 0; count <= n; count++) {
		dp[count][1] += 1;
		for (int numCnt = 1; numCnt < k; numCnt++) {
			for (int temp = 0; temp <= count; temp++) {
				if (dp[count - temp][numCnt] > 0) {
					dp[count][numCnt + 1] = (dp[count][numCnt + 1] + dp[count - temp][numCnt]) % 1000000000;
				}
			}
		}
	}

	std::cout << dp[n][k];
}