#include <iostream>
#include <vector>
#include <math.h>
std::vector<int> prime_factorization(int num){
    std::vector<int> result;
    while(num > 1){
        for(int div = 2; div <= num; div++){
            printf("num : %d div : %d num / div : %d\n", num, div, num/div);
            if(num % div == 0){
                result.push_back(div);
                num /= div;
                break;
            }
        }
    }
    return result;
}

int main(){
    int input;
    scanf("%d", &input);

    for(auto data : prime_factorization(input)){
        printf("%d\n", data);
    }

}