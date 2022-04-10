#include <iostream>

int main(){

    int n;

    std::cin >> n;

    int tmp;
    int sum = 0;
    int max = -1001;

    for(int count = 0; count < n; count++){
        std::cin >> tmp;
        if(sum >= 0){
            sum += tmp;
        }
        else{
            if(tmp > sum){
                sum = tmp;
            }
        }
        if(max < sum){
            max = sum;
        }
    }

    std::cout << max;
}