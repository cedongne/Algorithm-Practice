#include <iostream>

int n;

int nums[101];
int operators[100];
bool used[100];

int max = -100000000;
int min = 1000000000;

void back_tracking(int num, int cal){
    if(num == n){
        if(cal > max){
            max = cal;
        }
        if(cal < min){
            min = cal;
        }
    }
    else{
        for(int index = 0; index < 4; index++){
            if(operators[index] > 0){
                operators[index]--;
                switch(index){
                    case 0:
                    back_tracking(num + 1, cal + nums[num]);
                    break;
                    case 1:
                    back_tracking(num + 1, cal - nums[num]);
                    break;
                    case 2:
                    back_tracking(num + 1, cal * nums[num]);
                    break;
                    case 3:
                    back_tracking(num + 1, cal / nums[num]);
                    break;
                }
                operators[index]++;
            }
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
    for(int count = 0; count < 4; count++){
        std::cin >> operators[count];
    }

    back_tracking(1, nums[0]);

    std::cout << max << '\n' << min << std::endl;
}