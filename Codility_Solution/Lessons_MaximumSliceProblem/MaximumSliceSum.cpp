int solution(vector<int> &A) {
    long long local_max = -1000000;
    long long global_max = -1000000;

    for(auto ele : A){
        local_max = (local_max + ele > ele) ? local_max + ele : ele;
        global_max = (local_max > global_max) ? local_max : global_max;
    }
    return global_max;
}
