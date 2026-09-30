#include <stdio.h>

int main(void)
{
	int price, quantity;
	int total, discount, payment, change;
	int money;


	printf("product price (won): ");
	scanf_s("%d", &price);

	printf("quantity: "); 
	scanf_s("%d", &quantity);

	total = price * quantity;
	discount = (int)(total * 0.1);
	payment = total - discount;

	printf("total price: %dwon\n", total);
	printf("discount (10%%): -%dwon\n", discount);
	printf("payment amount: %dwon\n", payment);

	printf("money received: ");
	scanf_s("%d", &money);
	
	change = money - payment; 

	printf ("change: %dwon\n", change);

	printf( "50000won bills:%d\n", change / 50000);
	change %= 50000;

	printf( "10000won bills:%d\n", change / 10000);
	change %= 10000;

	printf("1000won bills:%d\n", change / 1000);
	change %= 1000;

	printf("500won coins:%d\n", change / 500);
	change %= 500;

	printf("100won coins:%d\n", change / 100);
	change %= 100;

	printf("50won coins:%d\n", change / 50);
	change %= 50;

	printf( "10won coins:%d\n", change / 10);
	change %= 10;

	printf("1won coins:%d\n", change);
	change %= 1;

	return 0;
}