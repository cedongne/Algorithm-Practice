#include <string>
#include <vector>

using namespace std;

int dfs(vector<int> numbers, int target, int index, int result){
    int count = 0;
    if(index == numbers.size()){
        if(result == target){
            return 1;
        }
        else{
            return 0;
        }
    }
    else{  
        count += dfs(numbers, target, index + 1, result + numbers[index]);
        count += dfs(numbers, target, index + 1, result - numbers[index]);
    }
    return count;
}

int solution(vector<int> numbers, int target) {
    return dfs(numbers, target, 0, 0);
}