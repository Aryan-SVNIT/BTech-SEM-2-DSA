#include <stdio.h>
int main(){
    int m,n;
    printf("Enter No. of Rows and Column: ");
    scanf("%d%d",&m,&n);
    int arr[m][n];
    printf("Enter data");
    for(int i=0 ; i<m ; i++){
        for(int  j=0 ; j<n ; j++){
            scanf("%d",&arr[i][j]);
        }
    }
    printf("\nPrint : ");
    for(int i=0 ; i<m ; i++){
        for(int  j=0 ; j<n ; j++){
            printf("%d\t",arr[i][j]);
        }
    }
}