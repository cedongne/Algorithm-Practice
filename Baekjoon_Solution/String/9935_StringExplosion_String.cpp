#include <iostream>

std::string str;
std::string bombStr;
std::string newStr;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> str >> bombStr;

	int strLength = str.length();
	int bombStrLength = bombStr.length();
	for (int index = 0; index < strLength; index++) {
		newStr += str[index];
		if (str[index] == bombStr[bombStrLength - 1]) {
			int tmpIdx;
			int offset = newStr.length() - bombStrLength;
			for (tmpIdx = 0; tmpIdx < bombStrLength; tmpIdx++) {
				if (bombStr[tmpIdx] != newStr[offset + tmpIdx]) {
					break;
				}
			}
			if (tmpIdx == bombStrLength) {
				for (int count = 0; count < bombStrLength; count++) {
					newStr.pop_back();
				} 
			}
		}
	}
	if (newStr.length() == 0) {
		newStr = "FRULA";
	}
	std::cout << newStr;
}