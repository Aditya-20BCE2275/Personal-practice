#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

void process1();
void process2();
void delay(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while (goal > clock())
        ;
}
int p[10], pr[10], n, i, j, count = 0, ran_pr, temp, max_lmt, min_lmt;

int main()
{
    printf("Enter the no. of processses \n");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        p[i] = i + 1;
    do
    {
        ran_pr = rand() % n;
    } while (ran_pr != 0);
    ran_pr = 3;
    printf("Control process is P%d \n", ran_pr);
    printf("Enter the priority of processes \n");
    for (i = 0; i < n; i++)
    {
        printf("Priority of process P%d : \n", p[i]);
        scanf("%d", &pr[i]);
    }
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (pr[i] > pr[j])
            {
                temp = pr[i];
                pr[i] = pr[j];
                pr[j] = temp;

                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
    for (i = 0; i < n - 1; i++)
    {
        if (p[i] < ran_pr)
        {
            max_lmt = ran_pr;
            process1();
        }
        else
        {
            min_lmt = ran_pr + 1;
            process2();
        }
    }

    getch();
}

void process1()
{
    for (j = 0; j < ran_pr; j++)
    {
        if (i != j)
            printf("Process P%d is sending request to P%d \n", p[i], p[j]);
        else
            continue;
    }
    printf("\n");
    for (j = 0; j < ran_pr; j++)
    {
        if (i != j)
        {
            printf("Process P%d is acknowledging P%d \n", p[j], p[i]);
            count++;
        }
        else
            continue;
    }
    printf("\n");
    if (count == (ran_pr - 1))
    {
        printf("Process P%d is entering CS \n", p[i]);
        // delay(10000);
    }
    printf("\n");
    for (j = 0; j < ran_pr; j++)
    {
        if (i != j)
            printf("Process P%d is sending reply to P%d \n", p[i], p[j]);
        else
            continue;
    }
}

void process2()
{
    for (j = ran_pr + 1; j < n; j++)
    {
        if (i != j)
            printf("Process P%d is sending request to P%d \n", p[i], p[j]);
        else
            continue;
    }
    printf("\n");
    for (j = ran_pr + 1; j < n; j++)
    {
        if (i != j)
        {
            printf("Process P%d is acknowledging P%d \n", p[j], p[i]);
            count++;
        }
        else
            continue;
    }
    printf("\n");

    if (count == (n - ran_pr - 1))
    {
        printf("Process P%d is entering CS \n", p[i]);
        // delay(10000);
    }
    printf("\n");
    for (j = ran_pr + 1; j < n; j++)
    {
        if (i != j)
            printf("Process P%d is sending reply to P%d \n", p[i], p[j]);
        else
            continue;
    }
}

// OUTPUT:
// Enter the no. of processses 5
// Control process is P3
// Enter the priority of processes
// Priority of process P1 :2
// Priority of proce