#include <iostream>
#include <vector>

int n, m;
char nums[18];
bool visit[9];

void permutation(int count){
    if(count == m){
        std::cout << nums <<'\n';
        return;
    }
    for(int index = 1; index <= n; index++){
        if(visit[index] != 1){
            nums[count * 2] = index + '0';
            visit[index] = 1;
            permutation(count + 1);
            visit[index] = 0;
        }
    }
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	std::cin >> n >> m;
    for(int index = 0; index <= m * 2; index++){
        nums[index] = ' ';
    }

    permutation(0);
}