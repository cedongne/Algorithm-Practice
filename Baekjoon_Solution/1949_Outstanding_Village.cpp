#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> resident_count;
    int village_num;
    int tmp_resident_num;

    scanf("%d", &village_num);


    for(int count = 0; count < village_num; count++){
        scanf("%d", &tmp_resident_num);
        resident_count.push_back(tmp_resident_num);
        printf("%d ", resident_count[count]);
    }
}