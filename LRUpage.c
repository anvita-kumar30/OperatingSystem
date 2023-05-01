//LRU Algorithm (Page Replacement Policy)
#include <stdio.h>
// Find the index of the least recently used page in the frames_arr
int findLRU(int time[], int n) 
{
    int i, minimum = time[0], pos = 0;
    for (i = 1; i < n; ++i) 
    {
        if (time[i] < minimum) 
        {
            minimum = time[i];
            pos = i;
        }
    }
    return pos;
}
int main() 
{
    int frames, n, counter = 0, time[10], flag1, flag2, i, j, pos, faults = 0, hit=0;
    printf("Enter number of page requests: ");
    scanf("%d", &n);
    int pages[n];
    printf("Enter the page requests: ");
    for (i = 0; i < n; ++i)
        scanf("%d", &pages[i]);
    printf("Enter the number of frames: ");
    scanf("%d", &frames);
    int frames_arr[frames];
    // Initialize the frames and time arrays
    for (i = 0; i < frames; ++i) 
    {
        frames_arr[i] = -1;
        time[i] = -1;
    }
    // Loop through the pages
    printf("\nPage Requests\tPage Frames\n");
    for (i = 0; i < n; ++i) 
    {
        printf("%d\t\t", pages[i]);
        flag1 = flag2 = 0;
        // Check if the current page is already in a frame
        for (j = 0; j < frames; ++j) 
        {
            if (frames_arr[j] == pages[i]) 
            {
                counter++;
                time[j] = counter;
                flag1 = flag2 = 1;
                break;
            }
        }
        // If the page is not in a frame, find an empty frame or the least recently used page
        if (flag1 == 0) 
        {
            for (j = 0; j < frames; ++j) 
            {
                if (frames_arr[j] == -1) 
                {
                    counter++;
                    faults++;
                    frames_arr[j] = pages[i];
                    time[j] = counter;
                    flag2 = 1;
                    break;
                }
            }
        }
        if (flag2 == 0) 
        {
            pos = findLRU(time, frames);
            counter++;
            faults++;
            frames_arr[pos] = pages[i];
            time[pos] = counter;
        }
        // Print the current state of the frames
        for (j = 0; j < frames; ++j) {
            if (frames_arr[j] == -1)
                printf("  ");
            else
                printf("%d ", frames_arr[j]);
        }
        printf("\n");
    }
    hit = n - faults;
    float hit_ratio=(float)hit/n;
    float miss_ratio= 1 - hit_ratio;
    printf("\nHit ratio: %.2f\n", hit_ratio);
    printf("Miss ratio: %.2f\n", miss_ratio);
    printf("\nTotal Page Faults = %d", faults);
    return 0;
}
