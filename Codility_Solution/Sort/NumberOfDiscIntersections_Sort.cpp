#include <algorithm>

int solution(vector<int> &A) {
    vector<long long> lower;
    vector<long long> upper;

    long long intersect_cnt = 0;
    for(long long index = 0; index < A.size(); index++){
        lower.push_back(index - A[index]);
        upper.push_back(index + A[index]);
    }

    sort(lower.begin(), lower.end());
    sort(upper.begin(), upper.end());

    int upper_idx = 0;
    long long disc_cnt = 0;
    for(auto low : lower){
        while(upper[upper_idx] < low){
            upper_idx++;
            disc_cnt--;
        }
        intersect_cnt += disc_cnt;
        disc_cnt++;

        if(intersect_cnt > 10000000){
            return -1;
        }
    }
    return intersect_cnt;
}