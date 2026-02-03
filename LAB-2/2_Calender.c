#include <stdio.h>
int leap(int y) {
    if ((y%4==0 && y%100!=0) || (y%400==0)){
        return 1;
    }
    return 0;
}
int firstday(int m, int y) {
    int d = 1,k,j,day;
    if (m < 3) {
        m= m+12;
        y--;
    }
    k = y % 100;
    j = y / 100;
    day = (d + (13 * (m + 1)) / 5 + k + (k / 4) + (j / 4) + (5 * j)) % 7;
    return (day + 6) % 7;
}
int main() {
    char *days[] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
    char *months[] = {"Jan", "Feb", "March", "April", "May", "June", "July", "Aug", "Sep", "Oct", "Nov", "Dec"};
    int totalday[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int m, y;
    printf("Enter month: ");
    scanf("%d", &m);
    printf("Enter year: ");
    scanf("%d", &y);
    if (leap(y)) {
        totalday[1] = 29;
    }
    int daystart = firstday(m, y);
    printf("\n   %s %d\n", months[m - 1], y);
    for (int i = 0; i < 7; i++) {
        printf("%s ", days[i]);
    }
    printf("\n");
    for (int i = 0; i < daystart; i++) {
        printf("    ");
    }
    for (int day = 1; day <= totalday[m - 1]; day++) {
        printf("%3d ", day);
        if ((day + daystart) % 7 == 0)
            printf("\n");
    }
}