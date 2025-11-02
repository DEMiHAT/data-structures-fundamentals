#include <stdio.h>
#define INF 9999
#define MAX 10

void dijkstra(int graph[MAX][MAX], int n, int start);

void dijkstra(int graph[MAX][MAX], int n, int start) {
    int cost[MAX][MAX], dist[MAX], visited[MAX], count, minDist, nextNode, i, j;

    // Create cost matrix
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            cost[i][j] = (graph[i][j] == 0) ? INF : graph[i][j];

    // Initialize distance and visited arrays
    for (i = 0; i < n; i++) {
        dist[i] = cost[start][i];
        visited[i] = 0;
    }

    dist[start] = 0;
    visited[start] = 1;
    count = 1;

    // Find shortest paths
    while (count < n - 1) {
        minDist = INF;

        // Find the unvisited node with minimum distance
        for (i = 0; i < n; i++)
            if (dist[i] < minDist && !visited[i]) {
                minDist = dist[i];
                nextNode = i;
            }

        visited[nextNode] = 1;

        // Update distances of adjacent nodes
        for (i = 0; i < n; i++)
            if (!visited[i] && minDist + cost[nextNode][i] < dist[i])
                dist[i] = minDist + cost[nextNode][i];

        count++;
    }

    // Display shortest distances
    printf("\nShortest distances from node %d:\n", start + 1);
    for (i = 0; i < n; i++)
        if (dist[i] == INF)
            printf("To node %d = No path\n", i + 1);
        else
            printf("To node %d = %d\n", i + 1, dist[i]);
}

int main() {
    int graph[MAX][MAX], n, start, i, j;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix (0 if no edge):\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    printf("Enter starting node (1 to %d): ", n);
    scanf("%d", &start);

    dijkstra(graph, n, start - 1);

    return 0;
}
