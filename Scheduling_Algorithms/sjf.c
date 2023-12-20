/*Write a C program to implement SJF Scheduling on a set of processes.*/


#include <stdio.h>

#define max 30

int main() {
    int n, p[max], b[max], tat[max], wt[max], pos, temp, t;
    float awt = 0, atat = 0;

    printf("enter the number of processes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("enter the burst time of process %d: ", i + 1);
        scanf("%d", &b[i]);
    }

    for (int i = 0; i < n; i++) {
        pos = i;
        for (int j = 0; j < n-1-i; j++) {
            if (b[j] > b[j+1]) {
               temp = b[j];
               b[j] = b[j+1];
               b[j+1] = temp; 
             
               t=p[j];
               p[j]=p[j+1];
               p[j+1]=temp;              

            }
        }

    }

    wt[0] = 0;
    printf("process\tburst\twait\ttat\n");

    for (int i = 0; i < n; i++) {
        wt[i] = 0;
        tat[i] = 0;
        for (int j = 0; j < i; j++) {
            wt[i] = wt[i] + b[j];
        }
        tat[i] = wt[i] + b[i];
        awt = awt + wt[i];
        atat = atat + tat[i];
        printf("%d\t%d\t%d\t%d\n", p[i], b[i], wt[i], tat[i]);
    }

    atat = atat / n;
    awt = awt / n;

    printf("average wt: %.2f\n", awt);
    printf("average tat: %.2f\n", atat);

    return 0;
}
