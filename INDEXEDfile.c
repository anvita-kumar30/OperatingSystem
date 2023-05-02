//INDEXED File Allocation Technique
#include <stdio.h>
int main()
{
    int f[50], i, k, j, index[50], n, c, count = 0, p;
    for (i = 0; i < 50; i++)
        f[i] = 0;
x:
    printf("\nEnter index block: ");
    scanf("%d", &p);
    if (f[p] == 0)
    {
        f[p] = 1;
        printf("Enter no of files on index: ");
        scanf("%d", &n);
    }
    else
    {
        printf("Block already allocated");
        goto x;
    }
    printf("\nEnter blocks: ");
    for (i = 0; i < n; i++)
        scanf("%d", &index[i]);
    for (i = 0; i < n; i++)
    {
        if (f[index[i]] == 1)
        {
            printf("Block already allocated");
            f[p] = 0;
            goto x;
        }
    } 
    for (j = 0; j < n; j++)
        f[index[j]] = 1;
    printf("\nAllocated");
    printf("\nFile indexed");
    for (k = 0; k < n; k++)
        printf("\n%d->%d: allocated", p, index[k]);
    printf("\nEnter 1 to enter more files and 0 to exit: ");
    scanf("%d", &c);
    if (c == 1)
        goto x;
    return 0;
}