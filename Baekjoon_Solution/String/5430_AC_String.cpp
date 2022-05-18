#include <iostream>
#include <vector>
#include <string>
#define SWAP(a, b) {int temp = a; a = b; b = a;}

int t, arrSize;
std::string command, arrStr;
std::vector<int> arr;

bool reverse;
bool isError;

int start, end;
void reset() {
	arr.clear();
	reverse = false;
	isError = false;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> t;

	for (int count = 0; count < t; count++) {
		std::cin >> command >> arrSize >> arrStr;

		reset();

		int prevIdx = 1;
		if (arrStr.length() > 2) {
			for (int index = 1; index < arrStr.length(); index++) {
				if (arrStr[index] == ',' || arrStr[index] == ']') {
					arr.push_back(std::stoi(arrStr.substr(prevIdx, index - prevIdx)));
					prevIdx = index + 1;
				}
			}
		}

		start = 0;
		end = arr.size() - 1;

		for (int index = 0; index < command.length(); index++) {
			if (command[index] == 'R') {
				if (reverse) {
					reverse = false;
				}
				else {
					reverse = true;
				}
			}
			else if (command[index] == 'D') {
				if (start > end) {
					isError = true;
					break;
				}
				if (reverse) {
					end--;
				}
				else {
					start++;
				}
			}
		}
		if (isError) {
			std::cout << "error\n";
			continue;
		}
		if (reverse) {
			std::cout << "[";
			for (int index = end; index >= start; index--) {
				std::cout << arr[index];
				if (index > start) {
					std::cout << ",";
				}
			}
			std::cout << "]\n";
		}
		else {
			std::cout << "[";
			for (int index = start; index <= end; index++) {
				std::cout << arr[index];
				if (index < end) {
					std::cout << ",";
				}
			}
			std::cout << "]\n";
		}
	}
}