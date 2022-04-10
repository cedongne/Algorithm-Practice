#include <iostream>
#define MAX(a, b) ((a > b) ? a : b)

int LCS[1001][1001] = {0, };

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    std::string str1, str2;
    std::cin >> str1 >> str2;
    

    for(int row = 0; row < str1.length(); row++){
        for(int col = 0; col < str2.length(); col++){
            if(str1[row] == str2[col]){
                LCS[row + 1][col + 1] = LCS[row][col] + 1;
            }
            else{
                LCS[row + 1][col + 1] = MAX(LCS[row][col + 1], LCS[row + 1][col]);
            }
        }
    }

    std::cout << LCS[str1.length()][str2.length()];
}