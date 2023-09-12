#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int main() {
    int h, m, s, n, count;
    count = n = 0;

    int timeDifferences[] = {-10, 5, 4, 2, -10}; // USA, UK, Australia, Dubai, Canada

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    while (count == 0) {
        system("cls");
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
        SetConsoleTextAttribute(hConsole, 7);
        printf("Local Time: %02d:%02d:%02d\n", h, m, s);

        printf("\t\t\t\n\n\n -------------------------- 5 Country Time table --------------------------\n\n");

        for (int i = 0; i < 5; i++) {
            int adjustedHour = h + timeDifferences[i];
            if (adjustedHour < 0) {
                adjustedHour += 24;
            } else if (adjustedHour >= 24) {
                adjustedHour -= 24;
            }
            SetConsoleTextAttribute(hConsole, i == 0 ? 12 : i == 1 ? 10 : i == 2 ? 14 : i == 3 ? 9 : 13);
            printf("%s Time: %02d:%02d:%02d\n",
                i == 0 ? "\t\tUSA" : i == 1 ? "\t\tUK" : i == 2 ? "\t\tAustralia" : i == 3 ? "\t\tDubai" : "\t\tCanada",
                adjustedHour, m, s);
        }

        SetConsoleTextAttribute(hConsole, 7);
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

