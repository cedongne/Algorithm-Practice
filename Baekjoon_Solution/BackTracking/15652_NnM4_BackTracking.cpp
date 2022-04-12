#include <iostream>

char nums[16];
short n, m;

void permutation(int count){
    if(count == m){
        nums[count * 2 - 1] = '\n';
        std::cout << nums;
    }
    else{
        for(int num = 1; num <= n; num++){
            if(count >= 1){
                if(nums[(count - 1) * 2] > num + '0'){
                    continue;
                }
            }
            nums[count * 2] = num + '0';
            permutation(count + 1);
        }
    }
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    std::cin >> n >> m;

    for(int index = 0; index < m * 2; index++){
        nums[index] = ' ';
    }
    permutation(0);
}