#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 100

typedef struct {
    int n; 
    bool matrix[MAX_VERTICES][MAX_VERTICES]; 
} Graph;

void init_graph(Graph *g, int n) {
    g->n = n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            g->matrix[i][j] = 0;
        }
    }
}

void add_edge(Graph *g, int u, int v) {
    g->matrix[u][v] = 1;
    g->matrix[v][u] = 1;
}

void bfs(Graph *g, int start) {
    int visited[MAX_VERTICES] = {0};
    int queue[MAX_VERTICES];
    int front = 0, rear = 0;

    visited[start] = 1;
    queue[rear++] = start;

    while (front != rear) {
        int cur = queue[front++];
        printf("%d ", cur);

        for (int i = 0; i < g->n; i++) {
            if (g->matrix[cur][i] == 1 && !visited[i]) {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
}

int main() {
    Graph g;
    init_graph(&g, 4);

    add_edge(&g, 0, 1);
    add_edge(&g, 1, 2);
    add_edge(&g, 1,3);

    bfs(&g, 0);

    return 0;
}