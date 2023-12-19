/*Write a C program that implements MFT memory management scheme in Linux.*/

#include<stdio.h>

int main(){
    int ms, bs, nob, n, ef, tif=0, mp[10];
    printf("Enter the memory size:");
    scanf("%d", &ms);
    printf("Enter the block size:");
    scanf("%d", &bs);
    nob = ms / bs;
    ef = ms - nob * bs;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        printf("Enter the memory required for process %d: ", i + 1);
        scanf("%d", &mp[i]);
    }
    printf("Number of blocks available is %d\n", nob);
    printf("Process \t Memory required \t Allocated or not \t Internal fragmentation\n");
    int p = 0;
    for(int i = 0; i < n && p < nob; i++){
        printf("%d\t\t\t%d\t\t\t", i + 1, mp[i]);
        if(mp[i] > bs){
            printf("NO\t---");
            p++;
        }
        else{
            printf("YES\t\t\t\t%d", bs - mp[i]);
            tif = tif + (bs - mp[i]);
            p++;
        }
        printf("\n");
    }
    printf("Total internal fragmentation is %d\n", tif);
    printf("Total external fragmentation is %d\n", ef);
}
