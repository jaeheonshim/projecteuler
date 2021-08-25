#include <stdio.h>

#define DayOfWeek(day) ((day) % 7)
#define IsLeap(year) (((year) % 4 == 0 && (year) % 100 != 0) || ((year) % 400 == 0))

static int currentDay = 0;
static int currentMonth = 0;
static int currentYear = 1900;

static char daysInMonth[] = {31, 0, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

static enum { MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY, SUNDAY } weekday;

void nextDate();

int main() {
    int count = 0;

    // feed
    for(int i = 0; i < 12; i++) {
        nextDate();
    }

    while(currentYear < 2001) {
        if(DayOfWeek(currentDay) == 6) {
            count++;
        }
        nextDate();
    }

    printf("%d\n", count);
}

void nextDate() {
    if(currentMonth == 1) {
        currentDay += IsLeap(currentMonth) ? 29 : 28;
    } else {
        currentDay += daysInMonth[currentMonth];
    }

    currentMonth += 1;
    if(currentMonth > 11) {
        currentMonth %= 12;
        currentYear++;
    }
}