#include <iostream>

int n, m;

int arr[2001] = { 0, };

bool pal[2001][2001] = { 0, };

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> n;

	for (int count = 1; count <= n; count++) {
		std::cin >> arr[count];
		pal[count][1] = true;

		if (arr[count] == arr[count - 1]) {
			pal[count - 1][2] = true;
		}
	}

	for (int start = 1; start < n; start++) {
		int stmp = start - 1;
		int etmp = start + 1;

		for (int etmp = start + 1; stmp >= 1 && etmp <= n; stmp--, etmp++) {
			if (arr[stmp] == arr[etmp] && pal[stmp + 1][etmp - stmp - 1]) {
				pal[stmp][etmp - stmp + 1] = true;
			}
			else {
				break;
			}
		}

		stmp = start - 1;
		for (int etmp2 = start + 2; stmp >= 1 && etmp2 <= n; stmp--, etmp2++) {
			if (arr[stmp] == arr[etmp] && pal[stmp + 1][etmp - stmp - 1]) {
				pal[stmp][etmp - stmp + 1] = true;
			}
			else {
				break;
			}
		}
	}

	std::cin >> m;

	int s, e;
	for (int count = 0; count < m; count++) {
		std::cin >> s >> e;

		std::cout << pal[s][e - s + 1] << "\n";
	}
}