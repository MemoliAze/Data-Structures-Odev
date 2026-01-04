#include <stdio.h>
#include <stdlib.h>

#define MAX 20

int adj[MAX][MAX]; 
int visited[MAX];  
int n;             

int queue[MAX];
int front, rear;

void enqueue(int v) {
    if (rear == MAX - 1) return;
    if (front == -1) front = 0;
    queue[++rear] = v;
}

int dequeue() {
    if (front == -1 || front > rear) return -1;
    return queue[front++];
}

void BFS(int startNode) {
    int i;
    // Kuyruk indislerini fonksiyon başında sıfırla
    front = -1;
    rear = -1;
    for (i = 0; i < n; i++) visited[i] = 0; 

    enqueue(startNode);
    visited[startNode] = 1;

    printf("BFS Gezintisi: ");
    while (front != -1 && front <= rear) {
        int current = dequeue();
        printf("%d ", current);

        for (i = 0; i < n; i++) {
            if (adj[current][i] == 1 && !visited[i]) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}

void DFS(int v) {
    visited[v] = 1;
    printf("%d ", v);

    for (int i = 0; i < n; i++) {
        if (adj[v][i] == 1 && !visited[i]) {
            DFS(i);
        }
    }
}

int main() {
    int i, j, start;

    printf("Dugum sayisini girin: ");
    scanf("%d", &n);

    if(n > MAX) {
        printf("Hata: Maksimum %d dugum girebilirsiniz.\n", MAX);
        return 1;
    }

    printf("Komsuluk matrisini girin (Her satir arasi Enter'a basin):\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    printf("Baslangic dugumunu girin (0 ile %d arasi): ", n - 1);
    scanf("%d", &start);

    BFS(start);

    for (i = 0; i < n; i++) visited[i] = 0; 
    printf("DFS Gezintisi: ");
    DFS(start);
    printf("\n");

    return 0;
}