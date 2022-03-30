#include <iostream>
#include <queue>

int nextPoint[3] = {1, -1, 0};
std::queue<std::pair<int, int>> q;
int visit[100001];

int n, k;

int bfs(){
    while(true){
        std::pair<int, int> cur = q.front();
        q.pop();
        if(cur.first == k){
            return cur.second;
        }
        nextPoint[2] = cur.first;
        for(auto move : nextPoint){
            int next = cur.first + move;
            
            if(next < 0 || next > 100000){
                continue;
            }
            if(!visit[next]){
                q.push({next, cur.second + 1});
                visit[next] = 1;
            }
        }
    }

    return -1;
}

int main(){
    scanf("%d %d", &n, &k);

    visit[n] = 1;

    q.push({n, 0});
    printf("%d\n", bfs());
}