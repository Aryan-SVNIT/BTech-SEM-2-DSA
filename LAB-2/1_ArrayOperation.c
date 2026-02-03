#include <stdio.h>

void display(int a[], int n) {
    int i;
    printf("Array: ");
    for (i = 0; i < n; i++){
        printf("%d ", a[i]);
    }
    printf("\n");
}

void inBegin(int a[], int *n, int val) {
    for (int i = *n; i > 0; i--){
    a[i] = a[i - 1];
    }
    a[0] = val;
    (*n)++;
}

void inEnd(int a[], int *n, int val) {
    a[*n] = val;
    (*n)++;
}

void inPos(int a[], int *n, int val, int pos) {
    for (int i = *n; i >= pos; i--){
    a[i] = a[i - 1];
    }
    a[pos - 1] = val;
    (*n)++;
}
void delBegin(int a[], int *n) {
    for (int i = 0; i < *n - 1; i++){
        a[i] = a[i + 1];
    }
        (*n)--;
    }

    void delEnd(int a[], int *n) {
        (*n)--;
    }
    
    void delPos(int a[], int *n, int pos) {
        for (int i = pos - 1; i < *n - 1; i++){
            a[i] = a[i + 1];
        }
        (*n)--;
    }
    

void reverse(int a[], int n) {
    int i, temp;
    for (i = 0; i < n / 2; i++) {
        temp = a[i];
        a[i] = a[n - i - 1];
        a[n - i - 1] = temp;
    }
}

void copyArray(int src[], int sn, int dest[], int *dn) {
    int i;
    for (i = 0; i < sn; i++){
        dest[(*dn)++] = src[i];
    }
}

int sumArray(int a[], int n) {
    int i, s = 0;
    for (i = 0; i < n; i++){
        s += a[i];
    }
    return s;
}

int search(int a[], int n, int key) {
    int i;
    for (i = 0; i < n; i++){
        if (a[i] == key)
            return i + 1;
        }
    return -1;
}

int main() {
    int SubArray1[10], SubArray2[10], MainArray[20];
    int n1, n2, nm;
    int ch = -1, val, key, pos;
    printf("Enter number of elements in SubArray1: ");
    scanf("%d", &n1);
    for (int i = 0; i < n1; i++){
        scanf("%d", &SubArray1[i]);
    }

    printf("Enter number of elements in SubArray2: ");
    scanf("%d", &n2);
    for (int i = 0; i < n2; i++){
        scanf("%d", &SubArray2[i]);
    }
    printf("Enter number of elements in MainArray: ");
    scanf("%d", &nm);
    for (int i = 0; i < nm; i++){
        scanf("%d", &MainArray[i]);
    }
    while (ch != 0) {
        printf("\n1.Insert Menu");
        printf("\n2.Delete Menu");
        printf("\n3.Reverse MainArray");
        printf("\n4.Copy SubArray to MainArray");
        printf("\n5.Sum of MainArray");
        printf("\n6.Search element");
        printf("\n7.Display MainArray");
        printf("\n0.Exit");
        printf("\nEnter choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter value of insert element: ");
            scanf("%d", &val);
            printf("1.Begin\n 2.End\n 3.Position\n ");         
            scanf("%d", &pos);
            if (pos == 1)
                inBegin(MainArray, &nm, val);
            else if (pos == 2)
                inEnd(MainArray, &nm, val);
            else {
                printf("Enter position: ");
                scanf("%d", &pos);                
                inPos(MainArray, &nm, val, pos);
            }
            display(MainArray, nm);
            break;

            case 2:
                printf("1.Begin\n 2.End\n 3.Position\n ");
            scanf("%d", &pos);
            if (pos == 1)
                delBegin(MainArray, &nm);
            else if (pos == 2)
                delEnd(MainArray, &nm);
            else {
                printf("Enter position: ");
                scanf("%d", &pos);
                delPos(MainArray, &nm, pos);
            }
            display(MainArray, nm);
            break;

            case 3:
                reverse(MainArray, nm);
                break;

            case 4:
                printf("Copy from: 1.SubArray1  2.SubArray2 : ");
                scanf("%d", &pos);
                if (pos == 1)
                    copyArray(SubArray1, n1, MainArray, &nm);
                else
                    copyArray(SubArray2, n2, MainArray, &nm);
                break;

            case 5:
                printf("Sum = %d\n", sumArray(MainArray, nm));
                break;

            case 6:
                printf("Enter key: ");
                scanf("%d", &key);
                pos = search(MainArray, nm, key);
                if (pos != -1)
                    printf("Found at position %d\n", pos);
                else
                    printf("Not Found\n");
                break;

            case 7:
                display(MainArray, nm);
                break;
        }
    }
    return 0;
}
