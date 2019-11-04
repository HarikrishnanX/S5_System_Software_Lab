#include <stdio.h>
#include <stdlib.h>

#define LOW 0
#define HIGH 199

void main()
{
    int queue[20], head, max, q_size, temp, sum, dloc;
    printf("Enter the Number of Disk Locations:");
    scanf("%d", &q_size);
    printf("\nEnter the Current Head Position:");
    scanf("%d", &head);
    printf("\nEnter the Elements into Disk Queue:");
    for (int i = 0; i < q_size; i++)
    {
        scanf("%d", &queue[i]);
    }
    queue[q_size] = head;
    q_size++;
    for (int i = 0; i < q_size; i++)
    {
        for (int j = i; j < q_size; j++)
        {
            if (queue[i] > queue[j])
            {
                temp = queue[i];
                queue[i] = queue[j];
                queue[j] = temp;
            }
        }
    }
    max = queue[q_size - 1];
    for (int i = 0; i < q_size; i++)
    {
        if (head == queue[i])
        {
            dloc = i;
            break;
        }
    }
    if (abs(head - LOW) <= abs(head - HIGH))
    {
        for (int j = dloc; j >= 0; j--)
        {
            printf("%d->", queue[j]);
        }
        for (int j = dloc + 1; j < q_size; j++)
        {
            printf("%d->", queue[j]);
        }
    }
    else
    {
        for (int j = dloc + 1; j < q_size; j++)
        {
            printf("%d->", queue[j]);
        }
        for (int j = dloc; j >= 0; j--)
        {
            printf("%d->", queue[j]);
        }
    }
    sum = head + max;
    printf("\nTotal number of Cylinder Access=%d", sum);
}
