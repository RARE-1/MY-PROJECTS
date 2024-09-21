#include <stdio.h>
 
unsigned long amount=0, deposit, withdraw;
int choice, pin,k,transfer;
char transaction ='y';
 
void main()
{
	while (pin != 8820)
	{
        printf("\n NEW USER? CLICK 0 TO GENERATE YOUR PASSWORD\n");
        printf("\n \n THIS IS YOUR NEW PASSWORD :\t 8820");
		printf("ENTER YOUR SECRET PIN NUMBER:");
		scanf("%d", &pin);
		if (pin != 8820)
		printf("PLEASE ENTER VALID PASSWORD\n");
	}
	do
	{
		printf("*******Welcome to ATM Service*************\n");
		printf("1. Check Balance\n");
		printf("2. Withdraw Cash\n");
		printf("3. Deposit Cash\n");
		printf("4. Transfer Cash\n");
    printf("5. Quit\n");
		printf("******************?**************************?*\n\n");
		printf("Enter your choice: ");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			printf("\n YOUR BALANCE IN Rs : %lu ", amount);
			break;
		case 2:
			printf("\n ENTER THE AMOUNT TO WITHDRAW: ");
			scanf("%lu", &withdraw);
			if (withdraw % 100 != 0)
			{
				printf("\n PLEASE ENTER THE AMOUNT IN MULTIPLES OF 100");
			}
			else if (withdraw >(amount - 0))
			{
				printf("\n INSUFFICENT BALANCE");
			}
			else
			{
				amount = amount - withdraw;
				printf("\n\n PLEASE COLLECT CASH");
				printf("\n YOUR CURRENT BALANCE IS%lu", amount);
			}
			break;
		case 3:
			printf("\n ENTER THE AMOUNT TO DEPOSIT");
			scanf("%lu", &deposit);
                        amount = amount + deposit;
			printf("YOUR BALANCE IS %lu", amount);
			break;
		case 4:
			printf("\n ENTER THE AMOUNT TO BE TRANSFER");
      scanf("%i", &transfer);
        float balance_after_transfer;
        balance_after_transfer = amount - transfer;
        printf("Net balance after transfer is %i", balance_after_transfer);
			break;
      case 5:
      printf("\n THANK U FOR USING ATM");
			break;
		default:
			printf("\n INVALID CHOICE");
		}
		printf("\n\n\n DO U WISH TO HAVE ANOTHER TRANSCATION?(y/n): \n");
		fflush(stdin);
		scanf("%c", &transaction);
		if (transaction == 'n'|| transaction == 'N')
                    k = 1;
	} while (!k);
	printf("\n\n THANKS FOR USING OUT ATM SERVICE");
}