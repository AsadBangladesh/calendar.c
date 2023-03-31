#include <stdio.h>

// Function to check if a year is a leap year
int isLeapYear(int year) {
    return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
}

// Function to get the number of days in a month
int getDaysInMonth(int month, int year) {
    int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month == 2 && isLeapYear(year)) {
        return 29;
    }
    return days[month - 1];
}

// Function to get the day of the week for a given date
int getDayOfWeek(int day, int month, int year) {
    int t[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
    if (month < 3) {
        year--;
    }
    return ((year + year/4 - year/100 + year/400 + t[month-1] + day) % 7);
}

// Function to print the calendar for a given month and year
void printCalendar(int month, int year) {
    int i, j, daysInMonth, dayOfWeek;
    char *months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    int monthDays[6][7] = {0};
    daysInMonth = getDaysInMonth(month, year);
    dayOfWeek = getDayOfWeek(1, month, year);

    printf("%s %d\n", months[month - 1], year);
    printf("Sun Mon Tue Wed Thu Fri Sat\n");

    // Fill in the calendar array
    for (i = 0, j = dayOfWeek; i < daysInMonth; i++, j++) {
        monthDays[j/7][j%7] = i + 1;
    }

    // Print the calendar array
    for (i = 0; i < 6; i++) {
        for (j = 0; j < 7; j++) {
            if (monthDays[i][j] != 0) {
                printf("%3d ", monthDays[i][j]);
            } else {
                printf("    ");
            }
        }
        printf("\n");
    }
}

// Main function to get user input and call printCalendar
int main() {
    int month, year, i;

    printf("Enter month (1-12): ");
    scanf("%d", &month);
    if(month>=12)
    {
        for(i=0; month>=12; i++)
        {
            printf("It is wrong answer. Please enter correct answer.\n");
            printf("Enter month (1-12): ");
            scanf("%d", &month);
        }

    }
    //else if(year)
    printf("Enter year: ");
    scanf("%d", &year);

    printCalendar(month, year);


    return 0;
}
