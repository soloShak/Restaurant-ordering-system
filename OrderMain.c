#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define LINE 36
#define N 20 
#define DISH_VAR 7

void order(int a[N][DISH_VAR], int f[DISH_VAR], int g[DISH_VAR], int j[N]);
void show_bill(int a[N][DISH_VAR], int f[DISH_VAR], int g[DISH_VAR], int j[N]);
void bill_menu(int a[N][DISH_VAR], int f[DISH_VAR], int g[DISH_VAR], int j[N]);
void menu(int a[N][DISH_VAR], int f[DISH_VAR], int g[DISH_VAR], int j[N]);
void end(int j[N]);
void line();

int table = 0;

/*Function: main
* ----------------
* Defines all arrays and variables 
* 
* count - to fill the array tota[]
* bill_pay[][] - to know the amount of money needed for the particular table and for perticular dish
* quant[] - to know how many particular dishes were ordered
* availab[] - to make the software know if dish was ordered or not
* total[] - to calculate total amount of money which needed for particular table 
* 
* return: zero
*/

int main()										            
{
	system("cls");
	int count;
	int bill_pay[N][DISH_VAR];
	int quant[DISH_VAR];
	int availab[DISH_VAR];
	int total[N];

	for (count = 0; count < N; count++)  // Filling array with zeros
		total[count] = 0;

	menu(bill_pay, quant, availab, total); // calls next function

	return 0;
}

/*Function : menu
* --------------------
* Prints main menu in software and makes the user choose the next step
* 
* choice - to chose between 3 options
* count, count2 - to fill the arrays bill_pay[][], availab[] and quant[]
* 
* returns nothing because type is void
*/

void menu(int bill_pay[N][DISH_VAR], int quant[DISH_VAR], int availab[DISH_VAR], int total[N])
{
	system("cls");
	int choice, count, count2;

	printf("*** Welcome to **** restauraunt ***  \n");
	line();
	printf("\n");
	printf("\t System menu \n\n");
	printf("1. Create New Order \n");
	printf("2. Show Bill \n");
	printf("3. Exit \n\n");
	line();
	printf("\n");

	printf("Enter Your Choice: ");
	scanf("%d", &choice);

	if (choice == 1)  // if user typed '1' then table number increases by one, bill_pay[][], availab[] and quant[] are filled with zeros
	{                 // and runs function order()
		table++; 
		for (count = 0; count < N; count++)
			for (count2 = 0; count2 < DISH_VAR; count2++)
				bill_pay[count][count2] = 0;

		for (count = 0; count < DISH_VAR; count++)
		{	
			availab[count] = 0;
			quant[count] = 0;
		}

		order(bill_pay, quant, availab, total);
	}
	else if (choice == 2) // if user typed '2' then it runs bill_menu() function
		bill_menu(bill_pay, quant, availab, total);
	else if (choice == 3) // if user typed '3' software runs end() function
		end(total);
}

/* Function: line
* ------------------
* count for typint '=' LINE times
*/

void line()
{
	int count;

	for (count = 0; count <= LINE; count++)
		printf("=");
}

/*Function: order
* -----------------
* Prints food menu with prices, asks for order and it's quanttity 
* 
* order - to take number of the dish
* action - to take number and gp to the next function
*/

void order(int bill_pay[N][DISH_VAR], int quant[DISH_VAR], int availab[DISH_VAR], int total[N])
{
	system("cls");
	int order, action;

	printf("RESTAURANT MENU \n\n");
	printf("BUNS : \n\n");
	printf("1. Beef Burger:        $20 \n");
	printf("2. Hot Dog:            $15 \n\n");
	printf("CHICKEN : \n\n");
	printf("3. Chicken Breast      $25 \n");
	printf("4. Chicken Wings       $65 \n\n");
	printf("DESSERTS : \n\n");
	printf("5. Ice Cream           $5 \n\n");
	printf("Drinks \n\n");
	printf("6. Coca Cola           $3 \n");
	printf("7. Fanta               $2 \n\n");
	printf("Order: (Enter 0  to finish order) \n\n");

	while (1) // infinite loop 
	{
		printf("Enter Food Number:  ");
		scanf("%d", &order);

		while (order != 0) // loop that repeates till user types '0'
		{
			switch (order) //  checks variable "order"
			{
			case 1:                          // if user types numbers from '1' to '7' software asks for quantity, 
				printf("Enter Quantity: ");  // availab[] for this dish becomes '1' and it calculates both dish money and total money 
				scanf("%d", &quant[0]);
				printf("\n");
				availab[0] = 1;
				bill_pay[table][0] = quant[0] * 20;
				total[table] += bill_pay[table][0];
				break;
			case 2:
				printf("Enter Quantity: ");
				scanf("%d", &quant[1]);
				printf("\n");
				availab[1] = 2;
				bill_pay[table][1] = quant[1] * 15;
				total[table] += bill_pay[table][1];
				break;
			case 3:
				printf("Enter Quantity: ");
				scanf("%d", &quant[2]);
				printf("\n");
				availab[2] = 3;
				bill_pay[table][2] = quant[2] * 25;
				total[table] += bill_pay[table][2];
				break;
			case 4:
				printf("Enter Quantity: ");
				scanf("%d", &quant[3]);
				printf("\n");
				availab[3] = 4;
				bill_pay[table][3] = quant[3] * 65;
				total[table] += bill_pay[table][3];
				break;
			case 5:
				printf("Enter Quantity: ");
				scanf("%d", &quant[4]);
				printf("\n");
				availab[4] = 5;
				bill_pay[table][4] = quant[4] * 5;
				total[table] += bill_pay[table][4];
				break;
			case 6:
				printf("Enter Quantity: ");
				scanf("%d", &quant[5]);
				printf("\n");
				availab[5] = 6;
				bill_pay[table][5] = quant[5] * 3;
				total[table] += bill_pay[table][5];
				break;
			case 7:
				printf("Enter Quantity: ");
				scanf("%d", &quant[6]);
				printf("\n");
				availab[6] = 7;
				bill_pay[table][6] = quant[6] * 2;
				total[table] += bill_pay[table][6];
				break;
			}
			break;
		}
		if (order == 0)  // if user types '0' than software cleans the screen, prints table number and makes user to choose between two options
		{
			system("cls");
			printf("Thanks for your order. We are getting ready the dishes. \n\n");
			printf("Your table number is %d. Use this table order while paying the bill. \n\n", table);
			printf("  Further actions: \n");
			printf("1. Check your bill \n");
			printf("2. Go to main menu \n");

			printf("Enter your choice:  ");
			scanf("%d", &action);

			if (action == 1) // if action is '1' than software goes to show_bill() function
				show_bill(bill_pay, quant, availab, total);
			if (action == 2) // is user typed '2' than software goes back to menu() function
				menu(bill_pay, quant, availab, total);
		}
		continue;
	}
}

/* Function: show_bill
* -----------------------
* Prints the dishes which were ordered, their price and it's total price
* 
* count - used for loop
* action - to go to the next functiion
*/

void show_bill(int bill_pay[N][DISH_VAR], int quant[DISH_VAR], int availab[DISH_VAR], int total[N])
{
	system("cls");
	int count, action;
	printf("Your Bill: \n");
	printf("Item(s)                Quantity                   Price(s) \n\n");

	for (count = 0; count < 7; count++) //  for loop which runs 7 times
	{
		switch (availab[count]) // checks for the value of elements in availab[] array
		{
		case 1:                 // from 1 to 7 prints dish name, it's price 
			printf("1. Beef Burger            %d piece(s)              %d  \n", quant[0], bill_pay[table][0]);
			break;
		case 2:
			printf("2. Hot Dog                %d piece(s)              %d  \n", quant[1], bill_pay[table][1]);
			break;
		case 3:
			printf("3. Chicken Breast         %d piece(s)              %d  \n", quant[2], bill_pay[table][2]);
			break;
		case 4:
			printf("4. Chicken Wings          %d piece(s)              %d  \n", quant[3], bill_pay[table][3]);
			break;
		case 5:
			printf("5. Ice Cream              %d piece(s)              %d  \n", quant[4], bill_pay[table][4]);
			break;
		case 6:
			printf("6. Coca Cola              %d piece(s)              %d  \n", quant[5], bill_pay[table][5]);
			break;
		case 7:
			printf("7. Fanta                  %d piece(s)              %d  \n", quant[6], bill_pay[table][6]);
			break;
		}
	}
	printf("\n\nTotal cost = $%d \n\n", total[table]);
	printf("Further action \n");
	printf("1. Go to main menu \n");

	printf("Enter your choice: ");
	scanf("%d", &action);

	if (action == 1) // if user typed '1' than software goes back to menu() function
		menu(bill_pay, quant, availab, total);
}

/*Function: bill_menu()
* ----------------------
* Receives table number, prints total amount money for this table and asks for money
* 
* num - for table number
* money_pay - for amount of money which user types 
*/


void bill_menu(int bill_pay[N][DISH_VAR], int quant[DISH_VAR], int availab[DISH_VAR], int total[N])
{
	system("cls");

	int num, money_pay;

	while (1) // infinite loop
	{
		printf("Enter table number (Enter -1 to go to main page): ");
		scanf("%d", &num);

		if ((total[num] > 0) && (num < N) && (num != -1)) // if there is money to be paid in total[] array, 'num' which is written by user
		{                                               // is less than number of all tables and not equal to '-1' software asks for money
			printf("Total cost for the table to be paid %d \n", total[num]);
			printf("Please enter required money amount:  ");
			scanf("%d", &money_pay);

			if (money_pay - total[num] == 0)
			{ // if typed money is equal to the total price it prints this
				printf("\nThe order is paid succesfully\n\n");
				total[num] = 0;
				continue;
			}
			else if (money_pay - total[num] > 0)
			{ // if typed money is great than total price it prints this
				printf("\nThe order is paid succesfully and thanks for the tip\n\n");
				total[num] = 0;
				continue;
			}
			else if (total[num] - money_pay > 0)
			{ //  if typed money is less than needed one software prints this 
				printf("\nThe amount of money is less than required \n\n");
				continue;
			}
		}
		if (num > N)
		{ // if user types number which is greater than the number of tables sotware prints this
			printf("Uknown table number \n\n");
			continue;
		}
		if ((total[num] == 0) && (num <= N) && (num != -1))
		{ // if there is no needed money for the table software prints this 
			printf("There is no charge for the table \n\n");
			continue;
		}

		if (num == -1)
		{ // and if user types '-1' software goes back to menu()
			menu(bill_pay, quant, availab, total);
			break;
		}
	}
}

/*Function: end()
* ------------------
* Thanks the user and writes money for unpaid tables if there is one
* 
* count - used in for loop
*/

void end(int total[N])
{
	system("cls");

	int count;

	printf("Thanks for using our system \n\n");

	for (count = 1; count < N; count++)
	{
		if (total[count] > 0)
		{  // if there is unpaid table software prints this
			printf("Here are the unpaid orders: \n");
			printf("The amount money to be paid for table %d : %d \n", count, total[count]);
		}
	}
	exit(0);
}