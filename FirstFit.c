//First Fit Memory Allocation Technique
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
void main()
{
    int no_of_processes,no_of_blocks;
    printf("Enter number of processes: ");
    scanf("%d",&no_of_processes);
    printf("Enter number of blocks: ");
    scanf("%d",&no_of_blocks);
    int processes[no_of_processes],blocks[no_of_blocks];
    printf("Enter the sizes of blocks: ");
    for(int i=0;i<no_of_blocks;i++)
    {
        scanf("%d",&blocks[i]);
    }
    printf("Enter sizes of processes: ");
    for(int i=0;i<no_of_processes;i++)
    {
        scanf("%d",&processes[i]);
    }
    for(int i=0;i<no_of_processes;i++)
    {
        int flag = 0;
        for(int j=0;j<no_of_blocks;j++)
        {
            if(processes[i]<blocks[j])
            {
                printf("Process %d is in block %d\n",i+1,j+1);
                blocks[j] = blocks[j] - processes[i];
                flag = 1;
                break;
            }
        }
        if(flag == 0)
        {
            printf("Process %d not allocated\n",i+1);
        }
    }
}