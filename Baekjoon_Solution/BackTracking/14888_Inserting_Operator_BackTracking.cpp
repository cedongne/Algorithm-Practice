#include <iostream>

int n;

int nums[101];
int operators[100];
bool used[100];

int max = 0;
int min = 1000000;

void back_tracking(int num, int prev){
    if(num == n - 1){
        if(prev > max){
            max = prev;
        }
        if(prev < min){
            min = prev;
        }
    }
    else{
        for(int index = 0; index < n - 1; index++){
            if(used[index]){
                continue;
            }
//            printf("[%d] %d ", num, prev);
            int cal = prev;
            switch(operators[index]){
                case 0:
                cal += nums[num + 1];
                break;
                case 1:
                cal -= nums[num + 1];
                break;
                case 2:
                cal *= nums[num + 1];
                break;
                case 3:
                cal /= nums[num + 1];
                break;
            } 
//            printf("%d %d = %d\n", operators[index], nums[num + 1], cal);
            used[index] = true;
            back_tracking(num + 1, cal);
            used[index] = false;
        }
    }
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    std::cin >> n;
    for(int count = 0; count < n; count++){
        std::cin >> nums[count];
    }
    int operatorNum;
    int operatorCnt = 0;
    for(int count = 0; count < 4; count++){
        std::cin >> operatorNum;
        for(int count2 = 0; count2 < operatorNum; count2++){
            operators[operatorCnt + count2] = count;
        }
        operatorCnt += operatorNum;
    }

    back_tracking(0, nums[0]);

    std::cout << max << '\n' << min << std::endl;
}