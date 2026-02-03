#include<stdio.h>
int main()
{
    int arr[3][3];
    for(int i=0 ; i<3 ; i++)
    {
        for(int j=0 ; j<3 ; j++)
        {
            scanf("%d",&arr[i][j]);
        }
    }
    for(int i=0 ; i<3 ; i++)
    {
        for(int j=0 ; j<3 ; j++)
        {
            printf("Value arr[%d][%d]: %d\t",i,j,arr[i][j]);
            printf("Address: %d\n",&arr[i][j]);
        }
    }
}