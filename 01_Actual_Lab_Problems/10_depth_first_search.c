#include <stdio.h>

int graph[4][4] = {
    {0, 1, 1, 0},
    {1, 0, 0, 1},
    {1, 0, 0, 1},
    {0, 1, 1, 0}
};
int visited[4] = {0};

void dfs(int node) {
    visited[node] = 1;
    printf("%d ", node);

    for (int i = 0; i < 4; i++) {
        if (graph[node][i] == 1 && visited[i] == 0) {
            dfs(i);
        }
    }
}

int main() {
    dfs(0);
    return 0;
}