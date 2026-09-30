#include <stdio.h>

int main(void)
{
	int total, hour, minute, second;

	printf("enter the total time in seconds: ");
	scanf_s("%d", &total);

	hour = total / 3600;
	minute = (total % 3600) / 60;
	second = total % 60;

	printf("%d seconds is %d hours %d minutes %d seconds.\n", total, hour, minute, second);
	printf("digital format: %02d:%02d:%02d\n", hour, minute, second);

	return 0;
}