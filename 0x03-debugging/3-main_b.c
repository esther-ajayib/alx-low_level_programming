#include <stdio.h>
#include "main.h"

int convert_day(int month, int day);
int print_remaining_days(int month, int day, int year);

/**
 * main - test function for print_remaining_days
 *
 * Return: Always 0
 */
int main(void)
{
	int month;
	int day;
	int year;
	int dayOfYear;

	month = 2;
	day = 29;
	year = 2000;

	printf("Date: %02d/%02d/%04d\n", month, day, year);

	if (month == 2 && day > 29) {
		printf("Invalid date: %02d/%02d/%04d\n", month, day, year);
		return 0;
	}

	dayOfYear = convert_day(month, day);

	if (dayOfYear == -1)
	{
		printf("Invalid date: %02d/%02d/%04d\n", month, day, year);
	}
	else
	{
		print_remaining_days(month, dayOfYear, year);
	}

	return (0);
}
