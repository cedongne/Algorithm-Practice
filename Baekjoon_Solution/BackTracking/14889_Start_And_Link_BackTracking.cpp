#include <iostream>
#include <math.h>
int n;
int ability[20][20];

bool joined[20];
int min = 1000000000;

void member_list_up(int memberNum, int pos){
    if(memberNum == n / 2){
        int start = 0, link = 0;
        for(int mem1 = 0; mem1 < n; mem1++){
            for(int mem2 = 0; mem2 < n; mem2++){
                if(joined[mem1] && joined[mem2]){
                    start += ability[mem1][mem2];
                }
                if(!joined[mem1] && !joined[mem2]){
                    link += ability[mem1][mem2];
                }
            }
        }
        int result = std::abs(start - link);
        if(result < min){
            min = result;
        }
    }
    else{
        for(int count = pos; count < n; count++){
            joined[count] = true;

            member_list_up(memberNum + 1, count + 1);

            joined[count] = false;
        }
    }
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    std::cin >> n;

    for(int row = 0; row < n; row++){
        for(int col = 0; col < n; col++){
            std::cin >> ability[row][col];
        }
    }

    member_list_up(0, 0);
    std::cout << min;
}