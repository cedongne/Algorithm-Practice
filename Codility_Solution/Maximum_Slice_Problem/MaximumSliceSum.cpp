int solution(vector<int> &A) {
    int end = 0;

    long long sum = 0;
    long long max = -1000000;

    while(end < A.size()){
        if(A[end] + sum < 0){
            sum = A[end++];
            if(max < sum){
                max = sum;
            }
            sum = 0;
            continue;
        }
        sum += A[end++];
        if(max < sum){
            max = sum;
        }
    }
    return max;
}