#include <iostream>

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int n, k;

    std::cin >> n >> k;

    int valSum[100001] = {0, };
    int max = 0;

    for(int count = 0; count < n; count++){
        int weight, value;
        std::cin >> weight >> value;
        for(int index = k - weight; index >= 0; index--){
            if(valSum[index] != 0){
                if(valSum[index + weight] < valSum[index] + value){
                    valSum[index + weight] = valSum[index] + value;
                }
            }
        }
        if(valSum[weight] < value){
            valSum[weight] = value;
        }
    }
    for(int count = 1; count <= k; count++){
        if(max < valSum[count]){
            max = valSum[count];
        } 
    }
    std::cout << max;
}