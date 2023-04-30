//Best Fit Memory Allocation Technique
#include <stdio.h>
int main() 
{
    int block_sizes[10], process_sizes[10], m, n, allocation[10], i, j;
    printf("Enter the number of memory blocks: ");
    scanf("%d", &m);
    printf("Enter the sizes of the memory blocks:\n");
    for (i = 0; i < m; i++) 
        scanf("%d", &block_sizes[i]);
    printf("\nEnter the number of processes: ");
    scanf("%d", &n);
    printf("Enter the sizes of the processes:\n");
    for (i = 0; i < n; i++) 
        scanf("%d", &process_sizes[i]);
    for (i = 0; i < n; i++) 
    {
        allocation[i] = -1;
        for (j = 0; j < m; j++) 
        {
            if (block_sizes[j] >= process_sizes[i]) 
            {
                if (allocation[i] == -1) 
                    allocation[i] = j;
                else if (block_sizes[j] < block_sizes[allocation[i]]) 
                    allocation[i] = j;
            }
        }
        if (allocation[i] != -1) 
            block_sizes[allocation[i]] -= process_sizes[i];
    }
    printf("\nProcess No.\tProcess Size\tBlock no.\n");
    for (i = 0; i < n; i++) 
    {
        printf("%d\t\t%d\t\t", i+1, process_sizes[i]);
        if (allocation[i] != -1) 
             printf("%d\n", allocation[i]+1);
        else 
            printf("Not allocated\n");
    }
    return 0;
}