#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct activities{
        int start[100];
        int end[100];
        int length[100];
    };

void swap(int *x, int *y){
    int t;
    t=*x;
    *x=*y;
    *y=t;
}

int main(void){
    int n,i,x,j,a[100]={0};
    char ch;

    struct activities activity;
    struct activities Final;
    i=0;
    j=0;

    printf("press 1 for enter input through file.\npress 2 for enter input through compiler.\n");
    scanf("%d",&x);

    if(x==1){

        FILE *fp;
        fp= fopen("G1226.txt", "r");

        if (!fp){
            printf("Not Found");
            return 1;
        }

        printf("File Found\n");
        while((ch = fgetc(fp)) != EOF){
            printf("%c",ch);
            if(ch>47 && ch<58){
                a[i]=a[i]*10+ch-48;
            }
            else if(ch!=' ')continue;

            else i++;
        }
        fclose(fp);

        n=a[0];
        i=0;
        for(j=1;j<=n;j++){
            activity.start[i]=a[j];
            i++;
        }
        i=0;
        for(j=n+1;j<=2*n;j++){
            activity.end[i]=a[j];
            i++;
        }

    }
    else if(x==2){
        printf("\nActivity number:\n");
        scanf("%d",&n);

        for(i=0;i<n;i++){
            printf("\nStarting time no. %d activity:\t",i+1);
            scanf("%d", &activity.start[i]);
            printf("Ending time no. %d activity:\t",i+1);
            scanf("%d", &activity.end[i]);
        }
    }

    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if(activity.end[i]>activity.end[j]){
                swap(&activity.start[i], &activity.start[j]);
                swap(&activity.end[i], &activity.end[j]);
            }
        }
    }
    printf("\n-------------After sorting-------------------------\n");
   for(i=0;i<n;i++){
        //printf("Starting time no. %d activity:\t",i+1);
        printf("%d\t", activity.start[i]);
       // printf("Ending time no. %d activity:\t",i+1);
        printf("%d\n",activity.end[i]);
    }

    Final.start[0] = activity.start[0];
    Final.end[0] = activity.end[0];

    int k=1;

    for(i=0;i<n;i=j){
        for(j=i+1;j<n;j++){
            if(activity.end[i]<=activity.start[j]){
                Final.start[k] = activity.start[j];
                Final.end[k] = activity.end[j];
                k++;
                break;
            }
        }
    }

    printf("\n-------------After Implementing Algorithm-------------------------\n");
     for(i=0;i<k;i++){
        printf("Starting time no. %d activity:\t",i+1);
        printf("%d\n", Final.start[i]);
        printf("Ending time no. %d activity:\t",i+1);
        printf("%d\n\n",Final.end[i]);
    }


}



