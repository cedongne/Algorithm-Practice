#include <iostream>
#include <vector>
#define MAX 501
int n;
int pole[MAX] = { 0, };

int dp[MAX] = { 0, };
std::vector<int> nums;

int max_len = 0;

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> n;
	int index;
	for (int count = 0; count < n; count++) {
		std::cin >> index;
		std::cin >> pole[index];
	}
	for (index = 0; index <= MAX; index++) {
		dp[index] = 1;
		if (pole[index] > 0) {
			nums.push_back(pole[index]);
		}
	}

	for (int index = 0; index < nums.size(); index++) {
		for (int temp = 0; temp <= index; temp++) {
			if (nums[temp] < nums[index]) {
				if (dp[temp] >= dp[index]) {
					dp[index] = dp[temp] + 1;
					if (dp[index] > max_len) {
						max_len - dp[index];
					}
				}
			}
		}
	}

	std::cout << n - max_len;
}