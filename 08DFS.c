#include <stdio.h>
#include <conio.h>


int adj[10][10];  
int visited[15]; 
int i,n;


void DFS(int v)
{
   
    printf("%d ", v);
    
    
    visited[v] = 1;


    for ( i = 0; i < n; i++)
    {

	if (adj[v][i] == 1 && !visited[i])
	{

	    DFS(i);
	}
    }
}

void main()
{

    int edges, v1, v2, start, i, j;


    clrscr();


    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter the number of edges: ");
    scanf("%d", &edges);


    for (i = 0; i < n; i++)
    {
	for (j = 0; j < n; j++)
	{
	    adj[i][j] = 0;
	}
    }


    printf("Enter the edges (format: v1 v2):\n");
    for (i = 0; i < edges; i++)
    {
	scanf("%d %d", &v1, &v2);

	adj[v1][v2] = 1;
	adj[v2][v1] = 1;
    }


    for (i = 0; i < n; i++)
    {
	visited[i] = 0;
    }


    printf("Enter the starting vertex: ");
    scanf("%d", &start);

    printf("DFS traversal: ");
    DFS(start); 


    getch();
}
