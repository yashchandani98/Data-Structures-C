#include<stdio.h>
#include<conio.h>
int main(){
    int arr[]={10,2,3,12,5,8,12,11,7,4};
    int temp,j;
    int i,k=0;
    for(i=1;i<10;i++){
        temp = arr[i];
        j=i-1;
        while (j >= 0 && temp<=arr[j]){
            arr[j+1]=arr[j];
            j=j-1;
        }
        arr[j+1] = temp;
    }
    for (k = 0; k < 10; k++){
        printf("%d\n",arr[k]);
    }
}