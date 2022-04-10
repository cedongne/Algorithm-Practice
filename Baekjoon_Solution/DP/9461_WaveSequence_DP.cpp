#include <iostream>

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    long long sequence[101] = {0, 1, 1, 1, 2, };

    int t, n;

    std::cin >> t;

    for(int index = 5; index <= 101; index++){
        sequence[index] = sequence[index - 5] + sequence[index - 1];
    }
    for(int cases = 0; cases < t; cases++){
        std::cin >> n;
        std::cout << sequence[n] << "\n";
    }

}