#include <stdio.h>
#include <stdlib.h>

void main()
{
    int queue[100], q_size, head, seek = 0, diff;
    printf("Enter the Size of the Queue:");
    scanf("%d", &q_size);
    printf("\nEnter Queue Elements:");
    for (int i = 1; i <= q_size; i++)
    {
        scanf("%d", &queue[i]);
    }
    printf("\nEnter Current Head Position:");
    scanf("%d", &head);
    queue[0] = head;
    for (int j = 0; j <= q_size - 1; j++)
    {
        diff = abs(queue[j] - queue[j + 1]);
        seek += diff;
        printf("Move from %d to %d with Seek %d\n", queue[j], queue[j + 1], diff);
    }
    printf("\nTotal number of Cylinder Access=%d", seek);
}
