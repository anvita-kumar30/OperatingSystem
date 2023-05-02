//MFT (Multiprogramming with fixed number of tasks)
#include <stdio.h>
int main() 
{
    int tot, i, n, parsize, m, frag = 0;
    printf("Enter size of memory: ");
    scanf("%d", &tot);
    printf("Enter memory for OS: ");
    scanf("%d", &m);
    tot = tot - m;
    printf("Enter no. of partitions to be divided: ");
    scanf("%d", &n);
    int size[n];
    parsize = tot / n;
    for (i = 0; i < n; i++) 
    {
        printf("Enter process %d size: ", i + 1);
        scanf("%d", &size[i]);
        if (size[i] <= parsize) 
        {
            printf("Allocated page %d\n", i + 1);
            frag = frag + parsize - size[i];
        } else 
        {
            printf("Page %d is blocked as its size is larger than partition size\n", i + 1);
        }
    }
    printf("Internal fragmentation is %d", frag);
    return 0;
}
