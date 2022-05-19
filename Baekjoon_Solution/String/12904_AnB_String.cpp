#include <iostream>
#include <math.h>
#define SWAP(a, b) {int temp = a; a = b; b = temp;}
std::string str1;
std::string str2;

int start, end;
bool reverse;

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> str1 >> str2;

	start = 0;
	end = str2.length() - 1;
	while (std::abs(start - end) >= str1.length()) {
		if (!reverse) {
			if (str2[end] == 'A') {
				end--;
			}
			else {
				end--;
				SWAP(start, end);
				reverse = true;
			}
		}
		else {
			if (str2[end] == 'A') {
				end++;
			}
			else {
				end++;
				SWAP(start, end);
				reverse = false;
			}
		}
	}
	std::string tmpStr;
	if (!reverse) {
		while (start <= end) {
			tmpStr.push_back(str2[start++]);
		}
	}
	else {
		while (start >= end) {
			tmpStr.push_back(str2[start--]);
		}
	}

	std::cout << (tmpStr == str1);
}