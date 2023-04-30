//FIFO Page Replacement Policy
#include <stdio.h>
int main()
{
    int n, frames, i, j = 0, k, page_faults = 0, hit = 0;
    printf("Enter the number of page requests: ");
    scanf("%d", &n);
    int pages[n];
    printf("Enter the page requests: ");
    for (i = 0; i < n; i++) 
        scanf("%d", &pages[i]);
    printf("Enter the number of frames: ");
    scanf("%d", &frames);
    int frames_arr[frames];
    for (i = 0; i < frames; i++) 
        frames_arr[i] = -1;
    printf("\nPage Requests\tPage Frames\n");
    for (i = 0; i < n; i++) 
    {
        printf("%d\t\t", pages[i]);
        int flag = 0;
        for (k = 0; k < frames; k++) 
        {
            if (frames_arr[k] == pages[i]) 
            {
                hit++;
                flag = 1;
                break;
            }
        }
        if (flag == 0) 
        {
            frames_arr[j] = pages[i];
            j = (j + 1) % frames;
            page_faults++;
            for (k = 0; k < frames; k++) 
            {
                if (frames_arr[k] != -1) 
                    printf("%d ", frames_arr[k]);
            }
        } 
        else 
        {
            for (k = 0; k < frames; k++) 
            {
                if (frames_arr[k] != -1) 
                    printf("%d ", frames_arr[k]);
            }
        }
        printf("\n");
    }
    float hit_ratio = (float)hit / n;
    float miss_ratio = 1 - hit_ratio;
    printf("\nHit Ratio = %.2f\nMiss Ratio = %.2f\n", hit_ratio, miss_ratio);
    printf("Number of page faults: %d\n", page_faults);
    return 0;
}
