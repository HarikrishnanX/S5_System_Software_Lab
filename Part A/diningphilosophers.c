#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool all_philosophers_finished_eating(bool phils[], int n)
{
    for (int i = 0; i < n; i++)
        if (!phils[i])
            return false;
    return true;
}

void clear_chopsticks(bool chops[], int n)
{
    for (int i = 0; i < n; i++)
        chops[i] = true;
}

int main()
{
    int n;
    bool chops[n], philosophers_finished_eating[n], flag = true;
    printf("Enter the Number of Philosophers:");
    scanf("%d", &n);
    clear_chopsticks(chops, n);
    while (flag)
    {
        printf("\nNew Loop:");
        clear_chopsticks(chops, n);
        flag = false;
        for (int i = 0; i < n; i++)
        {
            if (!philosophers_finished_eating[i])
            {
                if (chops[i] && chops[(i + 1) % 5])
                {
                    chops[i] = false;
                    chops[(i + 1) % 5] = false;
                    printf("\nPhilosopher %d is Eating.", i);
                    philosophers_finished_eating[i] = true;
                    flag = true;
                }
                else
                    printf("\nPhilosopher %d is Thinking.", i);
            }
            else
                printf("\nPhilosopher %d has Finished Eating.", i);
        }
        if (all_philosophers_finished_eating(philosophers_finished_eating, n))
        {
            printf("\nProgram Completed Successfully.");
            exit(0);
        }
    }
    printf("\nDeadlock is Present!!");
}