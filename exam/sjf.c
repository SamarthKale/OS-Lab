#include <stdio.h>

int main(){
    int n,i,time=0,completed=0;
    int at[10],bt[10],wt[10],tat[10],done[10]={0},order[10];

    printf("Enter n: ");
    scanf("%d",&n);

    for(i=0;i<n;i++){
        printf("\nP%d\n",i+1);
        printf("AT: "); scanf("%d",&at[i]);
        printf("BT: "); scanf("%d",&bt[i]);
    }

    while(completed<n){
        int idx=-1,min=9999;

        for(i=0;i<n;i++){
            if(at[i]<=time && !done[i] && bt[i]<min){
                min=bt[i];
                idx=i;
            }
        }

        if(idx==-1) time++;
        else{
            wt[idx]=time-at[idx];
            time+=bt[idx];
            tat[idx]=wt[idx]+bt[idx];
            done[idx]=1;
            order[completed++]=idx;
        }
    }

    printf("\nProcess AT BT WT TAT\n");
    for(i=0;i<n;i++){
        int k=order[i];
        printf("P%d\t%d %d %d %d\n",k+1,at[k],bt[k],wt[k],tat[k]);
    }

    printf("\nGantt Chart:\n|");
    for(i=0;i<n;i++) printf(" P%d |",order[i]+1);

    printf("\n0");
    time=0;

    for(i=0;i<n;i++){
        if(time<at[order[i]]) time=at[order[i]];
        time+=bt[order[i]];
        printf("   %d",time);
    }
}
