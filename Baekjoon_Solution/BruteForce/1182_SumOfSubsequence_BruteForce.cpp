#include <iostream>

int n, sum;
int nums[21];

int caseCnt = 0;

void bruteForce(int numCnt, int curIdx, int subSum){
    if(subSum == sum){ 
        caseCnt++;
    }
    for(int index = curIdx; index < n; index++){
        bruteForce(numCnt + 1, index + 1, subSum + nums[index]);
    }
}

int main(){
    scanf("%d %d", &n, &sum);
    for(int count = 0; count < n; count++){
        scanf("%d", &nums[count]);
    }

    bruteForce(0, 0, 0);
    printf("%d", ((sum == 0) ? caseCnt - 1 : caseCnt));
}