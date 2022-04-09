#include <iostream>

int arr[10000000];

void dp(int num){
    int index = 1;
    for(; index < num; index++){
        int count = arr[index] + 1;
        if(arr[index + 1] > count){
            arr[index + 1] = count;
        }
        if(arr[index * 2] > count){
            arr[index * 2] = count;
        }
        if(arr[index * 3] > count){
            arr[index * 3] = count;
        }
    }
    std::cout << arr[index];
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int n;

    std::cin >> n;

    for(int index = 1; index <= n; index++){
        arr[index] = n;
    }
    arr[1] = 0;
    dp(n);
}