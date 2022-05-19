#include <iostream>

int dp[4001][4001] = { 0, };
std::string str1;
std::string str2;

int max = 0;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> str1 >> str2;

	for (int idx1 = 0; idx1 < str1.length(); idx1++) {
		for (int idx2 = 0; idx2 < str2.length(); idx2++) {
			if (str1[idx1] == str2[idx2]) {
				dp[idx1 + 1][idx2 + 1] = dp[idx1][idx2] + 1;
				if (max < dp[idx1 + 1][idx2 + 1]) {
					max = dp[idx1 + 1][idx2 + 1];
				}
			}
		}
	}

	std::cout << max;
}