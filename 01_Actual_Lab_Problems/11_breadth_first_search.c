#include <stdio.h>

int graph[4][4] = {
    {0, 1, 1, 0},
    {1, 0, 0, 1},
    {1, 0, 0, 1},
    {0, 1, 1, 0}
};

int visited[4] = {0};
int queue[4];

void bfs(int start) {
    int front = 0, rear = 0, node, i;

    queue[rear++] = start;
    visited[start] = 1;

    while (front < rear) {
        node = queue[front++];
        printf("%d ", node);

        for (i = 0; i < 4; i++) {
            if (graph[node][i] == 1 && visited[i] == 0) {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
    }
}

int main() {
    bfs(0);
    return 0;
}
