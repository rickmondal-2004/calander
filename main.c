#include <stdio.h>

int main() {
    int year, month, days_in_month, day_of_week;

    printf("Enter the year: ");
    scanf("%d", &year);

    printf("Enter the month (1-12): ");
    scanf("%d", &month);

    // Calculate the number of days in the month
    if (month == 2) {
        // Check if it's a leap year
        if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
            days_in_month = 29;
        } else {
            days_in_month = 28;
        }
    } else if (month == 4 || month == 6 || month == 9 || month == 11) {
        days_in_month = 30;
    } else {
        days_in_month = 31;
    }
    /*
    This is multiline comment
    */
    // Calculate the day of the week for the first day of the month
    day_of_week = (year - 1) * 365 + (year - 1) / 4 - (year - 1) / 100 + (year - 1) / 400;
    for (int i = 1; i < month; i++) {
        if (i == 2) {
            // Check if it's a leap year
            if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
                day_of_week += 29;
            } else {
                day_of_week += 28;
            }
        } else if (i == 4 || i == 6 || i == 9 || i == 11) {
            day_of_week += 30;
        } else {
            day_of_week += 31;
        }
    }
    day_of_week = (day_of_week + 1) % 7; // Convert to day of week (0 = Sunday, 1 = Monday, etc.)

    // Print the calendar header
    printf("  S  M  T  W  T  F  S\n");

    // Print the days of the month
    for (int i = 0; i < day_of_week; i++) {
        printf("   ");
    }
    for (int i = 1; i <= days_in_month; i++) {
        printf("%2d ", i);
        if ((i + day_of_week) % 7 == 0) {
            printf("\n");
        }
    }
    printf("\n");

    return 0;
}
