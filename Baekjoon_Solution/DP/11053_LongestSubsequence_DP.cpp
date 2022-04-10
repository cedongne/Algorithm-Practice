#include <iostream>

std::pair<int, int> subSequence[1001];

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    
    int n;

    int temp;
    int max = 0;

    std::cin >> n;

    for(int count = 1; count <= n; count++){
        std::cin >> subSequence[count].first;

        int tmpIdx = 0;

        for(int index = 0; index < count; index++){
            if(subSequence[index].first < subSequence[count].first){
                if(subSequence[tmpIdx].second < subSequence[index].second){
                    tmpIdx = index;
                }
            }
        }
        subSequence[count].second = subSequence[tmpIdx].second + 1;
        if(max < subSequence[count].second){
            max = subSequence[count].second;
        }
    }
    std::cout << max;
}