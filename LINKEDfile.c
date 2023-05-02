// LINKED File Allocation Technique
#include <stdio.h>
int main()
{
    int f[50], p, i, j, k, a, st, len, n, c;
    for (i = 0; i < 50; i++)
        f[i] = 0;
    printf("Enter number of blocks that are already allocated: ");
    scanf("%d", &p);
    printf("Enter the blocks numbers that are already allocated: ");
    for (i = 0; i < p; i++)
    {
        scanf("%d", &a);
        f[a] = 1;
    }
x:
    printf("\nEnter the starting block of the file: ");
    scanf("%d", &st);
    printf("Enter length of the file: ");
    scanf("%d", &len);
    k = len;
    for (j = st; j < (k + st); j++)
    {
        if (f[j] == 0)
        {
            f[j] = 1;
            printf("\n%d->allocated", j);
        }
        else
        {
            printf("\n%d->file is already allocated", j);
            k++;
        }
    }
    printf("\nThe file is allocated to disk");
    printf("\nEnter 1 to enter more files and 0 to exit: ");
    scanf("%d", &c);
    if (c == 1)
        goto x;
    return 0;
}