#include <iostream>

char nums[15] = "              ";
short n, m;

void permutation(int count){
    if(count == m){
        nums[(count * 2) - 1] = '\n';
        std::cout << nums;
    }
    else{
        for(short num = 1; num <= n; num++){
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

    for(int index = 1; index < m * 2; index += 2){
        nums[index] = ' ';
    }

    permutation(0);
}