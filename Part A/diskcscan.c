#include <stdlib.h>
#include <stdio.h>

#define HIGH 199
#define LOW 0

void main()
{
    int queue[20], q_size, head, i, j, seek = 0, diff, max, temp, queue1[20], queue2[20], temp1 = 0, temp2 = 0;
    printf("Enter the Number of Disk Locations:");
    scanf("%d", &q_size);
    printf("\nEnter the Current Head Position:");
    scanf("%d", &head);
    printf("\nEnter Elements into Disk Queue:");
    for (i = 0; i < q_size; i++)
    {
        scanf("%d", &temp);
        if (temp >= head)
        {
            queue1[temp1] = temp;
            temp1++;
        }
        else
        {
            queue2[temp2] = temp;
            temp2++;
        }
    }
    for (i = 0; i < temp1 - 1; i++)
    {
        for (j = i + 1; j < temp1; j++)
        {
            if (queue1[i] > queue1[j])
            {
                temp = queue1[i];
                queue1[i] = queue1[j];
                queue1[j] = temp;
            }
        }
    }
    for (i = 0; i < temp2 - 1; i++)
    {
        for (j = i + 1; j < temp2; j++)
        {
            if (queue2[i] > queue2[j])
            {
                temp = queue2[i];
                queue2[i] = queue2[j];
                queue2[j] = temp;
            }
        }
    }
    if (abs(head - LOW) >= abs(head - HIGH))
    {
        for (i = 1, j = 0; j < temp1; i++, j++)
        {
            queue[i] = queue1[j];
        }
        queue[i] = HIGH;
        queue[i + 1] = 0;
        for (i = temp1 + 3, j = 0; j < temp2; i++, j++)
        {
            queue[i] = queue2[j];
        }
    }
    else
    {
        for (i = 1, j = temp2 - 1; j >= 0; i++, j--)
        {
            queue[i] = queue2[j];
        }
        queue[i] = LOW;
        queue[i + 1] = HIGH;
        for (i = temp2 + 3, j = temp1 - 1; j >= 0; i++, j--)
        {
            queue[i] = queue1[j];
        }
    }
    queue[0] = head;
    for (j = 0; j <= q_size + 1; j++)
    {
        diff = abs(queue[j + 1] - queue[j]);
        seek += diff;
        printf("\nDisk head moves from %d to %d with seek %d\n", queue[j], queue[j + 1], diff);
    }
    printf("\nTotal number of Cylinder Access=%d", seek);
}
