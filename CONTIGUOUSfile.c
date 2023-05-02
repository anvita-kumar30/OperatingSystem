//CONTIGUOUS File Allocation Technique
#include <stdio.h>
int main()
{
    int f[50], i, st, j, len, c, k;
    for (i = 0; i < 50; i++)
        f[i] = 0;
x:
    printf("\nEnter the starting block of the file: ");
    scanf("%d", &st);
    printf("Enter length of the file: ");
    scanf("%d", &len);
    for (j = st; j < (st + len); j++)
    {
        if (f[j] == 0)
        {
            f[j] = 1;
            printf("\n%d->allocated", j);
        }
        else
        {
            printf("\nBlock already allocated");
            break;
        }
    }
    if (j == (st + len))
        printf("\nThe file is allocated to disk");
    printf("\nEnter 1 to enter more files and 0 to exit: ");
    scanf("%d", &c);
    if (c == 1)
        goto x;
    return 0;
}