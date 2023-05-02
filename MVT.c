//MVT (Multiprogramming with variable number of tasks)
#include <stdio.h>
int main()
{
    int i, m, n, tot;
    printf("Enter total memory size: ");
    scanf("%d", &tot);
    printf("Enter memory required for OS: ");
    scanf("%d", &m);
    tot = tot - m;
    printf("Enter number of pages: ");
    scanf("%d", &n);
    int size[n];
    for (i = 0; i < n; i++)
    {
        printf("Enter size of page %d: ", i + 1);
        scanf("%d", &size[i]);
    }
    for (i = 0; i < n; i++)
    {
        if (tot >= size[i])
        {
            printf("Allocated page %d\n", i + 1);
            tot = tot - size[i];
        }
        else
            printf("Page %d is blocked as its size is larger than remaining memory size\n",i+1);
    }
    printf("\nExternal Fragmentation is %d", tot);
    return 0;
}