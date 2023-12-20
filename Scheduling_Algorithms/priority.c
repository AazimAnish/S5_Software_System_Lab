/*Write a C program to implement Priority Scheduling on a set of processes.*/

#include<stdio.h>

#define max 30

int main(){
    int n,p[max],b[max],tat[max],wt[max],pos,awt=0,atat=0,temp;
    printf("Enter the number of process: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("Enter the burst time of the %d process: ",i+1);
        scanf("%d",&b[i]);
    }
     for(int i=0;i<n;i++){
        printf("Enter the priority of the %d process: ",i+1);
        scanf("%d",&p[i]);
    }
    
    for(int i=0;i<n;i++){
        pos=i;
        for(int j=i+1;j<n;j++){
            if(p[j]<p[pos]){
                pos=j;
            }
        }
            temp=p[i];
            p[i]=p[pos];
            p[pos]=temp;
            
            temp=b[i];
            b[i]=b[pos];
            b[pos]=temp;
    }
    
    wt[0]=0;
    printf("Process\tBurst\tPriority\tWait\tTAT\n");
    for(int i=0;i<n;i++){
        wt[i]=0;
        tat[i]=0;
        for(int j=0;j<i;j++){
            wt[i]=wt[i]+b[j];
        }
        tat[i]=wt[i]+b[i];
        awt=awt+wt[i];
        atat=atat+tat[i];
       printf("%d\t%d\t%d\t%d\t%d\n", i + 1, b[i], p[i], wt[i], tat[i]);

    }
    atat=atat/n;
    awt=awt/n;
    
    printf("Average WT : %d\n",awt);
    printf("Average TAT: %d\n",atat);
    return 0;
}