#include <iostream>

int n;
int days[16];
int profits[16];

int max = 0;

void conserting(int day, int profit){
    for(; day < n; day++){
        int next = day + days[day];
        int totalProfit = profit + profits[day];

        if(next < n){
            conserting(next, totalProfit);
        }
        if(next == n){
            if(max < totalProfit){
                max = totalProfit;
            }
        }
        else{
            if(max < profit){
                max = profit;
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
        std::cin >> days[count] >> profits[count];
    }  
    conserting(0, 0);

    std::cout << max << std::endl;
}