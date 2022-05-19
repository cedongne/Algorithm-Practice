#include <iostream>
#include <regex>

int t;
std::string str;

std::regex r("(100+1+|01)+");

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> t;
	for (; t > 0; t--) {
		std::cin >> str;

		if (std::regex_match(str, r)) {
			std::cout << "YES\n";
		}
		else {
			std::cout << "NO\n";
		}
	}
}