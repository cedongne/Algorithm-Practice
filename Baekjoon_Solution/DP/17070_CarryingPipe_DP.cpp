#include <iostream>
#define RIGHT 0
#define DIAGONAL 1
#define DOWN 2

int map[18][18];
int dp[18][18][3] = { 0, };

int n;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> n;

	for (int row = 0; row < n; row++) {
		for (int col = 0; col < n; col++) {
			std::cin >> map[row][col];
		}
	}
	dp[0][1][RIGHT] = 1;
	for (int row = 0; row < n; row++) {
		int col = 0;
		if (row == 0) {
			col = 1;
		}

		for (; col < n; col++) {
			if (map[row][col + 1] == 0 && map[row + 1][col + 1] == 0 && map[row + 1][col] == 0) {
				dp[row][col + 1][RIGHT] += dp[row][col][DIAGONAL] + dp[row][col][RIGHT];
				dp[row + 1][col + 1][DIAGONAL] += dp[row][col][RIGHT] + dp[row][col][DIAGONAL] + dp[row][col][DOWN];
				dp[row + 1][col][DOWN] += dp[row][col][DIAGONAL] + dp[row][col][DOWN];
				continue;
			}
			if (map[row][col + 1] == 0) {
				dp[row][col + 1][RIGHT] += dp[row][col][DIAGONAL] + dp[row][col][RIGHT];
			}
			if (map[row + 1][col] == 0) {
				dp[row + 1][col][DOWN] += dp[row][col][DIAGONAL] + dp[row][col][DOWN];
			}
		}
	}
	std::cout << dp[n][n][DIAGONAL] + dp[n][n][RIGHT] + dp[n][n][DOWN];
}