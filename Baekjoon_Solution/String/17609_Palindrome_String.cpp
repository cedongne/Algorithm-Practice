#include <iostream>
#include <string>

int n;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    std::cin >> n;
    std::string str;
    for (int count = 0; count < n; count++) {
        std::cin >> str;

        int start = 0;
        int end = str.length() - 1;

        int answer = 0;
        for (; start < end; start++, end--) {
            if (str[start] != str[end]) {

                int s = start + 1;
                int e = end;
                while (s < e) {
                    if (str[s] != str[e]) {
                        answer++;
                        break;
                    }
                    s++;
                    e--;
                }
                s = start;
                e = end - 1;
                while (s < e) {
                    if (str[s] != str[e]) {
                        answer++;
                        break;
                    }
                    s++;
                    e--;
                }
                if (answer > 1) {
                    answer = 2;
                    break;
                }
                if (answer == 0) {
                    answer = 1;
                }
                break;
            }
        }

        std::cout << answer << "\n";
    }
}
