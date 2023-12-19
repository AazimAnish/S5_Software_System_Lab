/*Write a C program that implements MVT memory management scheme in Linux.*/

#include<stdio.h>

int main() {
    int ms,mp[10],i, temp,n=0;
    char ch = 'y';
    printf("\nEnter the total memory available (in Bytes): ");
    if(scanf("%d",&ms) != 1) {
        printf("Invalid input\n");
        return 1;
    }
    temp=ms;
    for(i=0;ch=='y' && i<10;i++,n++)
    {
        printf("\nEnter memory required for process %d (in Bytes): ",i+1);
        if(scanf("%d",&mp[i]) != 1) {
            printf("Invalid input\n");
            return 1;
        }
        if(mp[i] <= 0) {
            printf("Memory requirement must be greater than 0\n");
            return 1;
        }
        if(mp[i]<=temp)
        {   
            printf("\nMemory is allocated for Process %d ",i+1);
            temp = temp - mp[i];
        }
        else
        {
            printf("\nMemory is Full");
            break;
        }
        printf("\nDo you want to continue(y/n): ");
        scanf(" %c", &ch);
    }
    printf("\n\nTotal Memory Available: %d", ms);
    printf("\n\n\tPROCESS\t\t MEMORY ALLOCATED ");
    for(i=0;i<n;i++)
        printf("\n \t%d\t\t%d",i+1,mp[i]);
    printf("\n\nTotal Memory Allocated is %d\n",ms-temp);
    printf("\nTotal External Fragmentation is %d\n",temp);
    return 0;
}