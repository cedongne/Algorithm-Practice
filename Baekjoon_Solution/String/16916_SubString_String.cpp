#include <iostream>
#define MAX_LEN 1000000

std::string str1;
std::string str2;

int table[MAX_LEN] = { 0, };

bool correct = false;

void make_table() {
	int start = 0;
	for (int end = 1; end < str2.length(); end++) {
		while (start > 0 && str2[start] != str2[end]) {
			start = table[start - 1];
		}
		if (str2[start] == str2[end]) {
			table[end] = ++start;
		}
	}
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> str1 >> str2;
	
	make_table();

	int tmpIdx = 0;
	for (int index = 0; index < str1.length(); index++) {
		if (str1[index] != str2[tmpIdx]) {
			tmpIdx = table[tmpIdx - 1];
			correct = false;
		}
		if (str1[index] == str2[tmpIdx]) {
			if (++tmpIdx == str2.length()) {
				correct = true;
				break;
			}
		}
	}

	std::cout << correct;
}