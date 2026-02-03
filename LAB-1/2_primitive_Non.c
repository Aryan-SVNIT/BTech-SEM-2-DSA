#include<stdio.h>
int main(){
    int Int=5;
    float Float=3.14;
    char Char='a';
    double Double=32.432456;
    int arr[5]={34,53,43,32,65};
    char str[100]="Hello SVNIT";
    printf("For Primitive Data type-\n");
    printf("\nValues :\n");
    printf("type: int\tvalue: %d\tAddress: %d\t size: %d bytes\n",Int,&Int, sizeof(Int));
    printf("type: float\tvalue: %f\tAddress: %d\t size: %d bytes\n",Float,&Float, sizeof(Float));
    printf("type: char\tvalue: %c\tAddress: %d\t size: %d bytes\n",Char,&Char, sizeof(Char));
    printf("type: double\tvalue: %lf\tAddress: %d\t size: %d bytes\n",Double,&Double, sizeof(Double));
    printf("\n\nFor Non-Primitive Data type-\n\n");
    printf("type: Array\tvalue: %d\tAddress: %d\t size: %d bytes\n",arr[0],&arr, sizeof(arr));
    printf("type: String\tvalue: %s\tAddress: %d\t size: %d bytes\n",str,&str, sizeof(str));
}