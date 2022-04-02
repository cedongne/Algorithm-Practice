#include <iostream>
#include <vector>

std::vector<std::string> perms;
char nums[20];
bool visit[20];
int n, m;

void permutation(int count){
    if(count == m){
        std::cout << nums << "\n";
    }
    else {
        for(int num = 1; num <= n; num++){
            if(!visit[num]){
                if(count > 0){
                    if(nums[(count - 1) * 2] > num + '0'){
                        continue;
                    }
                }
                nums[count * 2] = num + '0';
                visit[num] = 1;
                permutation(count + 1);
                visit[num] = 0;
            }
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