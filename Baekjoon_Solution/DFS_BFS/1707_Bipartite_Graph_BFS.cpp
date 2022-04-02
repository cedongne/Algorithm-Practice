#include <iostream>
#include <vector>
#include <queue>

int v, e;
std::queue<int> q;
std::vector<int> graph[20001];
int visit[20001];
int group[20001];

bool bfs(){
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(auto adj : graph[cur]){
            if(!visit[adj]){
                q.push(adj);
                visit[adj] = 1;
                group[adj] = group[cur] * -1;
            }
            else if(group[cur] == group[adj]){
                return false;
            }
        }
    }
    return true;
}

void reset(){
    for(int index = 0; index <= v; index++){
        visit[index] = 0;
        group[index] = 0;
        graph[index].clear();
    }
    while(!q.empty()){
        q.pop();
    }
}

int main(){
    int cases;
    scanf("%d", &cases);

    for(int count = 0; count < cases; count++){
        scanf("%d %d", &v, &e);
        int vert1, vert2;
        for(int edgeCount = 0; edgeCount < e; edgeCount++){
            scanf("%d %d", &vert1, &vert2);
            graph[vert1].push_back(vert2);
            graph[vert2].push_back(vert1);
        }

        bool bipartite = true;
        for(int index = 1; index <= v; index++){    // 불완전 그래프를 위한 모든 정점 탐색
            if(!visit[index]){
                q.push(index);
                visit[index] = 1;
                group[index] = 1;
            }
            if(!bfs()){
                bipartite = false;
                break;
            }
        }
        (bipartite) ? printf("YES\n") : printf("NO\n");
        reset();
    }
}