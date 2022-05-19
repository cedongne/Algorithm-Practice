#include <iostream>
#include <unordered_map>

int t, n;
std::string str[10001];
std::unordered_map<std::string, int> hashMap;

bool isExist;

bool find_prefix() {
	for (int count = 0; count < n; count++) {
		for (int index = 1; index < str[count].length(); index++) {
			auto item = hashMap.find(str[count].substr(0, index));
			if (item != hashMap.end()) {
				return true;
			}
		}
	}
	return false;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> t;
	for (; t > 0; t--) {
		hashMap.clear();

		std::cin >> n;

		for (int count = 0; count < n; count++) {
			std::cin >> str[count];
			hashMap[str[count]] = 1;
		}

		if (find_prefix()) {
			std::cout << "NO\n";
		}
		else {
			std::cout << "YES\n";
		}
	}
}