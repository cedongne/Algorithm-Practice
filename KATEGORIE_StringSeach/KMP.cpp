#include <iostream>
#include <vector>
using namespace std;

vector<int> MakeTable(string pattern) {
	int patternSize = pattern.size();
	vector<int> table(patternSize, 0);

	int start = 0;
	for (int end = 1; end < patternSize; end++) {
		while (start > 0 && pattern[start] != pattern[end]) {
			start = table[start - 1];
		}
		if (pattern[start] == pattern[end]) {
			table[end] = ++start;
		}
	}

	return table;
}

vector<int> KMP(string parent, string pattern) {
	int parentSize = parent.size();
	int patternSize = pattern.size();

	vector<int> table = MakeTable(pattern);

	int patternCount = 0;

	vector<int> found_index;
	for (int parentCount = 0; parentCount < parentSize; parentCount++) {
		while (patternCount > 0 && parent[parentCount] != pattern[patternCount]) {
			patternCount = table[patternCount - 1];
		}
		if (parent[parentCount] == pattern[patternCount]) {
			if (patternCount == patternSize - 1) {
				found_index.push_back(parentCount - patternSize + 2);
				patternCount = table[patternCount];
			}
			else {
				patternCount++;
			}
		}
	}
	return found_index;
}

void PrintPatternIndex(vector<int> found_index) {
	for (int count = 0; count < found_index.size(); count++) {
		printf("%d Found.\n", found_index[count]);
	}
}

int main() {
	string parent = "asdfasdfddasdfasdfasdf";
	string pattern = "asdfasdf";
	vector<int> found_indexes = KMP(parent, pattern);
	PrintPatternIndex(found_indexes);
}