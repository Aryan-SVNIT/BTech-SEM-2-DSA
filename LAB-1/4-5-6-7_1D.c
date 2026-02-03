#include<stdio.h>
int main(){
    int n,tamp,total=0, search,flag=0;
    printf("Enter N : ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter Elements of Array\n");
    for(int i=0 ; i<n ; i++){
        scanf("%d",&arr[i]);
    }
    printf("Array is\n");
    for(int i=0 ; i<n ; i++){
        printf("%d\t",arr[i]);
    }
    //---------------Q5----------------------------
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(arr[i]>arr[j])
            {
                tamp=arr[j];
                arr[j]=arr[i];
                arr[i]=tamp;
            }
        }
    }
    printf("\n\nMax = %d",arr[n-1]);
    printf("\nMin = %d",arr[0]);
    //----------------Q6---------------------------
    for (int i=0;i<n;i++){
        total=total+arr[i];
    }
    printf("\n\nAverage = %d",total/n);
    //------------------Q7-------------------------
    printf("\n\nEnter you Searching Element: ");
    scanf("%d",&search);
    for(int i=0 ; i<n ;i++){
        if(arr[i]==search){
            flag=1;
            break;
        }
    }
    if(flag==1){
        printf("\nElement is in Array");
    }
    else{
        printf("\nElement is not in Array");
    }
}
