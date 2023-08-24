#include <stdio.h>
#include <windows.h>

int main() {
    int h, m, s, n, count;
    count = n = 0;
    while (count == 0) {
        printf("Enter hour : \n");
        scanf("%d", &h);
        printf("Enter minutes : \n");
        scanf("%d", &m);
        printf("Enter seconds : \n");
        scanf("%d", &s);
        if (h < 24 && m < 60 && s < 60) {
            count++;
        } else {
            system("cls");
        }
    }
    while (n == 0) {
        system("cls");
        printf("%d: %d: %d\n", h, m, s);
        Sleep(1000);
        s++;
        if (s > 59) {
            s = 0;
            m++;
        }
        if (m > 59) {
            m = 0;
            h++;
        }
        if (h > 23) {
            h = 0;
        }
    }
    return 0;
}

