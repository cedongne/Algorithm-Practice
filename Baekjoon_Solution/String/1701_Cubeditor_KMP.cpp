#include <iostream>
#include <string>

std::string str;
std::string subStr;

int table[5001] = { 0, };

int maxLen = 0;

void make_table() {
	for (int index = 0; index < subStr.length(); index++) {
		table[index] = 0;
	}
	int start = 0;
	for (int end = 1; end < subStr.length(); end++) {
		while (start > 0 && subStr[start] != subStr[end]) {
			start = table[start - 1];
		}
		if (subStr[start] == subStr[end]) {
			table[end] = ++start;
			if (maxLen < table[end]) {
				maxLen = table[end];
			}
		}
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> str;

	for (int start = 0; start < str.length(); start++) {
		subStr = str.substr(start, str.length() - start);

		make_table();
	}

	std::cout << maxLen;
}