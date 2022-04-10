#include <iostream>

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int arr[103][10];
    int nums[103] = {0, };

    nums[1] = 9;
    int n;

    std::cin >> n;
    for(int count = 0; count <= n; count++){
        for(int index = 0; index < 10; index++){
            arr[count][index] = 0;
        }
    }

    for(int index = 1; index < 10; index++){
        arr[1][index] = 1;
    }
    
    for(int count = 1; count <= n; count++){
        for(int index = 0; index < 10; index++){
            if(arr[count][index] <= 0){
                continue;
            }
            if(index > 0){
                arr[count + 1][index - 1] = (arr[count + 1][index - 1] + arr[count][index]) % 1000000000;
                nums[count + 1] = (nums[count + 1] + arr[count][index]) % 1000000000;
            }
            if(index < 9){
                arr[count + 1][index + 1] = (arr[count + 1][index + 1] + arr[count][index]) % 1000000000 ;
                nums[count + 1] = (nums[count + 1] + arr[count][index]) % 1000000000;
            }
        }
    }

    std::cout << nums[n];
}