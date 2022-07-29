int solution(int N) {
    // write your code in C++14 (g++ 6.2.0)
    int n_cnt = 0;
    while(N % 2 == 0){
        n_cnt++;
        N /= 2;
    }

    return n_cnt;
}