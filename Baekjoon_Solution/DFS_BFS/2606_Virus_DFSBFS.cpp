#include <iostream>
#include <queue>

int graph[100][100];
int visit[100];

std::queue<int> q;

int pc_num;
int edge_num;

int linked_count = 0;

void dfs(int startPoint){
    if(visit[startPoint] == 1){
        return;
    }
    visit[startPoint] = 1;
    linked_count++;

    for(int count = 1; count <= pc_num; count++){
        if(graph[startPoint][count] == 1){
            dfs(count);
        }
    }
}

void bfs(int startPoint){
    q.push(startPoint);

    while(!q.empty()){
        int cur = q.front();
        q.pop();
        if(visit[cur] == 1){
            continue;
        }
        visit[cur] = 1;
        linked_count++;

        for(int count = 1; count <= pc_num; count++){
            if(graph[cur][count] == 1){
                q.push(count);
            }
        }
    }
}

void graph_reset(){
    for(int index = 1; index <= pc_num; index++){
        for(int index2 = 1; index <= pc_num; index2++){
            graph[index][index2] = 0;
        }
        visit[index] = 0;
    }
    linked_count = 0;
}

int main(){
    scanf("%d %d", &pc_num, &edge_num);
    for(int count = 0; count < edge_num; count++){
        int first_pc, second_pc;
        scanf("%d %d", &first_pc, &second_pc);
        graph[first_pc][second_pc] = 1;
        graph[second_pc][first_pc] = 1;
    }

    bfs(1);
    printf("%d\n", linked_count - 1);
}