//Scan Disk Scheduling Algorithm
#include<stdio.h>
int main() 
{
    int nc,nt,head,track[100],i,j,dist=0,temp,headPos;
    printf("Enter the number of cylinders (0 to n-1): n = ");
    scanf("%d",&nc);
    printf("Enter the number of requested tracks: ");
    scanf("%d",&nt);
    printf("Enter the current location of pointer head: ");
    scanf("%d",&head);
    track[0] = head;
    printf("Enter the requested tracks in FIFO order: \n");
    for(i=1;i<=nt;i++) 
    {
        scanf("%d",&track[i]);
        // check whether the requested track lies in the cylinder range
        if(track[i]>=nc || track[i]<0) 
        {
            printf("INVALID INPUT!!! ABORTING!!");
            return 0;
        }
    }
    nt++;
    track[nt] = nc-1;
    // process the requests according to SCAN algorithm
    // requests are processed first in right direction
    for(i=0;i<=nt;i++) 
    {
        for(j=i;j<=nt;j++) 
        {
            if(track[i]>track[j]) 
            {
                temp = track[i];
                track[i] = track[j];
                track[j] = temp;
            }
        }
    }
    for(i=0;i<=nt;i++)
    {
        if(track[i] == head)
        {
            headPos = i;
            break;
        }
    }
    printf("The requests are processed in the following order: %d -> ",track[headPos]);
    for(i=headPos+1 ;i<=nt;i++) 
    {
        printf("%d -> ",track[i]);
    }
    for(i=headPos-1 ;i>=0;i--) 
    {
        if(i!=0) 
            printf("%d -> ",track[i]);
        else    
            printf("%d \n",track[i]);
    }
    dist = (track[nt]-track[headPos])+(track[nt]-track[0]);
    printf("The total seek distance is: %d \n",dist);
    return 0;
}