#include <stdio.h>
#include <stdlib.h>

#define MAX 30

typedef struct edge 
{
    int u, v, w;
} edge;

typedef struct edgelist 
{
    edge data[MAX];
    int n;
} edgelist;

edgelist elist;

int G[MAX][MAX] = 
{
    {0, 4, 0, 0, 0, 0, 0, 8, 0},
    {4, 0, 8, 0, 0, 0, 0, 11, 0},
    {0, 8, 0, 7, 0, 4, 0, 0, 2},
    {0, 0, 7, 0, 9, 14, 0, 0, 0},
    {0, 0, 0, 9, 0, 10, 0, 0, 0},
    {0, 0, 4, 14, 10, 0, 2, 0, 0},
    {0, 0, 0, 0, 0, 2, 0, 1, 6},
    {8, 0, 0, 0, 0, 0, 1, 0, 7},
    {0, 0, 2, 0, 0, 0, 6, 7, 0}
};

int n = 9;
int parent[MAX];
char vertices[MAX] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i'};

void kruskal();
int find(int);
void union1(int, int);
void sort();
void print();

void kruskal() {
    int i, j, u, v;
    elist.n = 0;

    for (i = 0; i < n; i++) 
    {
        for (j = 0; j < n; j++) 
        {
            if (G[i][j] != 0) 
            {
                elist.data[elist.n].u = i;
                elist.data[elist.n].v = j;
                elist.data[elist.n].w = G[i][j];
                elist.n++;
            }
        }
    }

    sort();

    for (i = 0; i < n; i++)
    {
        parent[i] = i;
    }

    printf("\nEdges of Minimum Cost Spanning Tree are\n");
    for (i = 0; i < elist.n; i++) 
    {
        u = find(elist.data[i].u);
        v = find(elist.data[i].v);

        if (u != v) 
        {
            union1(u, v);
            printf("\n%c -> %c = %d", vertices[elist.data[i].u], vertices[elist.data[i].v], elist.data[i].w);
        }
    }
}

int find(int i) 
{
    while (parent[i] != i)
    {
        i = parent[i];
    }
    return i;
}

void union1(int i, int j) 
{
    parent[i] = j;
}

void sort() 
{
    int i, j;
    edge temp;

    for (i = 1; i < elist.n; i++)
    {
        for (j = 0; j < elist.n - 1; j++) 
        {
            if (elist.data[j].w > elist.data[j + 1].w) 
            {
                temp = elist.data[j];
                elist.data[j] = elist.data[j + 1];
                elist.data[j + 1] = temp;
            }
        }
    }
}

void main() {
    kruskal();
}
