#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> residentCount;
    vector<int, int> villageLink;
    int village_num;
    int tmp_resident_num;

    scanf("%d", &village_num);


    for(int count = 0; count < village_num; count++){
        scanf("%d", &tmp_resident_num);
        residentCount.push_back(tmp_resident_num);
        printf("%d ", residentCount[count]);
    }
    
}