#include<stdio.h>
#include<stdlib.h>
#include<conio.h>


int queue[10], front = -1, rear = -1;
int visited[10];


void enqueue(int value)
{
    
    queue[++rear] = value;
}


int dequeue()
{

    return queue[++front];
}


void BFS(int graph[10][10], int vertices, int startvertex)
{
    int i, currentvertex;

    
    for(i = 0; i < vertices; i++)
        visited[i] = 0;

    
    enqueue(startvertex);
    visited[startvertex] = 1;

    printf("\nBFS Traversal: ");

    while(front < rear)
    {
        currentvertex = dequeue();
        printf("%d ", currentvertex);

        
        for(i = 0; i < vertices; i++)
        {
            if(graph[currentvertex][i] == 1 && !visited[i])
            {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}


void main()
{
    int vertices, edges, startvertex;
    int graph[10][10] = {0};
    int u, v, i;

    clrscr(); 

    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    printf("Enter the edges (u v) using 0-based indexing:\n");
    for(i = 0; i < edges; i++)
    {
        scanf("%d%d", &u, &v);

        graph[v][u] = 1;
        graph[u][v] = 1;
    }

    printf("Enter the starting vertex: ");
    scanf("%d", &startvertex);

    BFS(graph, vertices, startvertex);

    getch(); 
}
