#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct 
{
    char name[20];
    int start;
    int finish;
} Element;

int compare(const void *a, const void *b) 
{
    Element *elementA = (Element *)a;
    Element *elementB = (Element *)b;
    return elementB->finish - elementA->finish;
}

int main() 
{
    Element elements[] = 
    {
        {"watch", 9, 10},
        {"shirt", 1, 8},
        {"tie", 2, 5},
        {"jacket", 3, 4},
        {"belt", 6, 7},
        {"pants", 12, 15},
        {"undershorts", 11, 16},
        {"socks", 17, 18},
        {"shoes", 13, 14}
    };
    int n = sizeof(elements) / sizeof(Element);

    qsort(elements, n, sizeof(Element), compare);

    printf("topological sort:\n");
    for (int i = 0; i < n; i++) 
    {
        printf("%s\n", elements[i].name);
    }

    return 0;
}
