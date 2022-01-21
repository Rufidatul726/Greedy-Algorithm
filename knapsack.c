#include<stdio.h>
#include<string.h>
#include<stdlib.h>


void swap (int * p1, int * p2) {
   int temp = *p1;
  *p1 = *p2;
  *p2 = temp;
}

void fswap (float * p1, float * p2) {
   float temp = *p1;
  *p1 = *p2;
  *p2 = temp;
}

struct knap{
        int item_no[1000];
        int weight[1000];
        int benifit[1000];
        float value[1000];
};

int main(void){
        int i,j,n,a[1000]={0};
        int capacity, items;
        float  sum=0.0000,item_price=0.00000;
        char ch;

        struct knap activity;
        struct knap accept;

        FILE *fp;
        fp = fopen("knapsack1226.txt", "r");

         if (!fp){
            printf("Not Found");
            return 1;
        }

        printf("File Found\n");
        i=0;

        while((ch = fgetc(fp)) != EOF){
            printf("%c",ch);
            if(ch>47 && ch<58){
                a[i]=a[i]*10+ch-48;
            }
            else if(ch!=' ')continue;

            else i++;
        }

        fclose(fp);

        items = a[0];
        capacity = a[1];

        for(i=2;i<items+2;i++){
            activity.weight[i-2]=a[i];
        }

        for(i=items+2;i<2*items+2;i++){
            activity.benifit[i-2-items]=a[i];
        }

        for(i=0;i<items;i++){
            activity.item_no[i]=i+1;
            activity.value[i]=activity.benifit[i]/activity.weight[i];
            //printf("\n%f\t%d\t%d",activity.value[i],activity.benifit[i],activity.weight[i]);
        }

        for(i=0;i<items;i++){
            for(j=i+1;j<items;j++){
                if(activity.value[i]<activity.value[j]){
                    fswap(&activity.value[i], &activity.value[j]);
                    swap(&activity.benifit[i], &activity.benifit[j]);
                    swap(&activity.weight[i], &activity.weight[j]);
                    swap(&activity.item_no[i],&activity.item_no[j]);
                }
            }
        }

        printf("\n--------------------THE ITEMS ARE (BY VALUE)---------------------\n");
        for(i=0;i<items;i++){
            printf("\n%d\t%d\t%d\t%.2f",activity.item_no[i],activity.benifit[i],activity.weight[i],activity.value[i]);
        }

        printf("\nItems those are needed:\n");
        for(i=0;i<items && capacity!=0;i++){
            if(capacity>=activity.weight[i]){
                capacity=capacity-activity.weight[i];
                item_price= item_price+ activity.benifit[i];
                printf("%d no item %d units\n",activity.item_no[i],activity.weight[i]);
            }

            else{
                item_price= item_price+ capacity*activity.value[i];
                printf("%d no item %d units\n",activity.item_no[i],capacity);
                capacity=0;
            }

        }

        printf("\n\nTotal Item Price: %.2f",item_price);
}
