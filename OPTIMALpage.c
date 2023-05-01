//Optimal Algorithm (Page Replacement Policy)
#include <stdio.h>
#include <limits.h>
#define MAX_FRAMES 10
int main()
{
    int frames, n, page_faults = 0, i, j, k, max, index, hit=0;
    printf("Enter number of page requests: ");
    scanf("%d", &n);
    int pages[n];
    printf("Enter page requests: ");
    for (i = 0; i < n; i++) 
    {
        scanf("%d", &pages[i]);
    }
    printf("Enter number of frames: ");
    scanf("%d", &frames);
    int frames_arr[frames], next[MAX_FRAMES];
    for (i = 0; i < frames; i++) 
    {
        frames_arr[i] = -1;
        next[i] = INT_MAX;
    }
    printf("\nPage Requests\tPage Frames\n");
    for (i = 0; i < n; i++) 
    {
        printf("%d\t\t", pages[i]);
        int is_hit = 0;
        // Check if page is already in frame
        for (j = 0; j < frames; j++) 
        {
            if (frames_arr[j] == pages[i]) 
            {
                is_hit = 1;
                break;
            }
        }
        if (!is_hit) 
        {
            page_faults++;
            // Find the optimal page to replace
            for (j = 0; j < frames; j++) 
            {
                for (k = i + 1; k < n; k++) 
                {
                    if (frames_arr[j] == pages[k]) 
                    {
                        next[j] = k;
                        break;
                    }
                }
            }
            max = -1;
            index = -1;
            for (j = 0; j < frames; j++) 
            {
                if (next[j] > max) 
                {
                    max = next[j];
                    index = j;
                }
            }
            // Replace the optimal page
            frames_arr[index] = pages[i];
            next[index] = INT_MAX;
        }
        // Print current state of frames
        for (j = 0; j < frames; j++) 
        {
            if (frames_arr[j] == -1) 
                printf("  ");
            else
                printf("%d ", frames_arr[j]);
        }
        printf("\n");
    }
    hit = n - page_faults;
    float hit_ratio=(float)hit/n;
    float miss_ratio= 1 - hit_ratio;
    printf("\nHit ratio: %.2f\n", hit_ratio);
    printf("Miss ratio: %.2f\n", miss_ratio);
    printf("Number of page faults: %d\n", page_faults);
    return 0;
}
