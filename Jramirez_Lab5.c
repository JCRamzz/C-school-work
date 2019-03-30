/*
Program Name: Bank Application (Now with 120% More Functions!)
Author: Juan C. Ramirez

Description: Same lab as lab 4, except this time I have added a few more functions
to make the code cleaner and more readable.
*/

#include <stdio.h>
#include <unistd.h>
#include <ctype.h>
#include <stdlib.h>


//function prototypes
void print();
void main2();
void preMenu();
void viewBalance(float balance);
double quickDeposit();
double quickWithdraw(double balance);

// main function definition. Execution begins here.

int main(void)
{
	float balance = 1000.00;
	char choice;
	
	preMenu();
	do
	{
			print();
			printf("Enter your choice:");
			choice = getchar();
			fflush(stdin);//getchar();
			choice = toupper(choice);
			 // Making the character capitalized so validation is easier

		if (choice == 'A')
		{
			viewBalance(balance);
		}
		else if (choice == 'B')
		{
			balance += quickDeposit();
			viewBalance(balance);
		}
		else if (choice == 'C')
		{
			balance -= quickWithdraw(balance);
			viewBalance(balance);
			
		}
		else if (choice == 'D')
		{
			int index;
			printf("Thank you, until next time! \n");
			printf("Exiting program");

			for (index = 0; index < 6; index++)
			{
				printf(".");
				sleep(1);
				index++;
			}

			exit(0);
		}
		else if (choice == 'F')
		{
			preMenu();
		}
		else
		{
			printf("Error!\n");
		}
		
	} while (choice != 'D');


	return 0;
}

void preMenu()
{ //"developer mode" to let user access the two variations this program is written in. 
  // they should offer the same results, just a different coding structure
	char choice;

	do
	{
		printf("!!!!!!! Developer mode !!!!!!!\n");
		printf("!                            !\n");
		printf("!    A) Else/if statements   !\n");
		printf("!    B) Switch statements    !\n");
		printf("!    C) Exit Program         !\n");
		printf("!                            !\n");
		printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");

		printf("Enter your choice: ");
		choice = getchar();
		fflush(stdin);
		//while((choice = getchar()) != EOF && choice != '\n') // This will eat up all other characters
    	;	//getchar(); // Ensures it will only process one character
		choice = toupper(choice);

		if (choice == 'A')
		{
			return;
		}
		else if (choice == 'B')
		{
			main2();
		}
		else if (choice == 'C')
		{
			int index;
			printf("Exiting program");

			for (index = 0; index < 3; index++)
			{
				printf(".");
				sleep(1);
			}
			
			exit(0);
			
		}
		else
		{
			printf("Error, please select a valid choice.");
		}
	} while (choice != 'C' && choice != 'D' && choice != 'F'); //validation


}
void print()
{

	printf(" | ~~ Account Managenent Menu ~~ |\n");
	printf(" |                               |\n");
	printf(" |  A) Check Account Balance     |\n");
	printf(" |  B) Deposit Funds             |\n");
	printf(" |  C) Withdraw Funds            |\n");
	printf(" |  D) Exit Program              |\n");
	printf(" |  F) Back to developer mode    |\n");
	printf(" |                               |\n");
	printf(" |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n");

}

void main2() // switch statement program
{
	float balance = 1000.00;
	char choice;
	float withdrawal;

	do
	{
		print();
		printf("Enter your choice:");
		choice = getchar();
		//getchar();
		choice = toupper(choice);
		switch (choice)
		{
		case 'A': 
			printf("Your current balance is: %.2f\n"), balance;
			break;
		case 'B':
			balance += quickDeposit();
			viewBalance(balance);
			break;
		case 'C':
			balance -= quickWithdraw(balance);
			viewBalance(balance);
			break;
		case 'D':
			//int index = 0;
			printf("Thank you, until next time! \n");
			printf("Exiting program");

			for (int index = 0; index < 3; index++)
			{
				printf(".");
				sleep(1);
			}

			exit(0);
			break;
		case 'F':
			return;
			break;

		default: 
			printf("Error!\n");
			break;
		}
	}while (choice != 'D');	
}

void viewBalance(float balance)
{
    printf ("Success! your new balance is: %.2f\n", balance);
}
double quickDeposit()
{
	float deposit = 0.0;

	printf("Enter amount you would like to deposit: ");
	scanf("%f", &deposit);
	printf("Depositing %.2f in your account", deposit);

			for (int index = 0; index < 3; index++)
			{
				printf(".");
				sleep(1);
			}

	return deposit;

}
double quickWithdraw(double balance)
{
	float withdrawal = 0.0;
	printf("Enter amount you would like to withdraw: ");
	scanf("%f", &withdrawal);
	printf("Withdrawing %.2f from your account", withdrawal);

			for (int index = 0; index < 3; index++)
			{
				printf(".");
				sleep(1);
			}
	
	do
		{
			if (withdrawal > balance)
			{
			printf("Error: You do not have sufficient funds to withdraw that amount\n");
			printf("Current balance is: %.2f", balance);
			printf("\nPlease select another amount:"); // use do/while to let user try another ammount if it exceeds the current balance
			scanf("%f", &withdrawal);
			}
		} while (withdrawal > balance);
	
	return withdrawal;
}