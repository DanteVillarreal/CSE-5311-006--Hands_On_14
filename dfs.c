#include<stdio.h>

#define MAX 9

void dfs(int i, int adj[][MAX], int visited[], char *names[]) 
{
    int j;
    printf("%s ", names[i]);
    visited[i] = 1;

    for(j = 0; j < MAX; j++) 
    {
        if(!visited[j] && adj[i][j] == 1) 
        {
            dfs(j, adj, visited, names);
        }
    }
}

int main() 
{
    int adj[MAX][MAX] = 
    {
        {0, 0, 0, 0, 0, 0, 0, 0, 0}, // watch
        {0, 0, 1, 1, 0, 0, 0, 0, 0}, // shirt
        {0, 0, 0, 0, 0, 0, 0, 0, 1}, // tie
        {0, 0, 0, 0, 0, 0, 0, 0, 1}, // belt
        {0, 0, 0, 1, 0, 0, 0, 0, 0}, // pants
        {0, 0, 0, 0, 1, 0, 0, 1, 0}, // undershorts
        {0, 0, 0, 0, 0, 0, 0, 1, 0}, // socks
        {0, 0, 0, 0, 0, 0, 0, 0, 0},  // shoes
        {0, 0, 0, 0, 0, 0, 0, 0, 0}  // jacket
    };
    int visited[MAX] = {0};
    char *names[MAX] = {"watch", "shirt", "tie", "belt", "pants", "undershorts", "socks", "shoes", "jacket"};
    int i;

    printf("DFS traversal of the graph is: ");
    for(i = 0; i < MAX; i++) 
    {
        if(!visited[i]) 
        {
            dfs(i, adj, visited, names);
        }
    }

    return 0;
}
