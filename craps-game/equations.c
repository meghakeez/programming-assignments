/*

	Contains function headers

*/



#include "equations.h"

void print_game_rules(void)
{
	printf("A player rolls two dice. Each die has six faces. These faces contain 1, 2, 3, 4, 5, and 6 spots.\n");
	printf("After the dice have come to rest, the sum of the spots on the two upward faces is calculated.\n");
	printf("If the sum is 7 or 11 on the first throw, the player wins.\n");
	printf("If the sum is 2, 3, or 12 on the first throw (called \"craps\"), the player loses (i.e.the \"house\"wins.\n");
	printf("If the sum is 4, 5, 6, 8, 9, or 10 on the first throw, then the sum becomes the player's \"point\" \n");
	printf(" If the sum is 4, 5, 6, 8, 9, or 10 on the first throw, then the sum becomes the player's \"point\" \n");
	printf("To win, you must continue rolling the dice until you \"make your point\". The player loses by rolling a 7 before making the point.\n");
	printf("\n");

}

double get_bank_balance(void) // prompts player for initial bank balance
{
	double balance;

	printf("What is your initial bank balance: ");
	scanf( "%lf", &balance);

	return balance;

}

double get_wager_amount(void) // prompts the player for a wager on a particular role
{
	double wager;

	printf("What is your wager: ");
	scanf(" %lf", &wager);

	return wager;

}

int check_wager_amount(double wager, double balance)
{

	if (wager > balance)
	{ 
		do {

			printf("Your wager is larger than your bank balance\n");

			printf("Pick a new wager amount: ");
			scanf(" %lf", &wager);

			printf("Your wager: $%.2lf\n", wager);

		} while (wager > balance);

	}	

	if (wager <= 0)
	{
		do {

			printf("Your wager cannot be 0 or below\n");

			printf("Pick a new wager amount: ");
			scanf("%lf", &wager);

			printf("Your wager: $%.2lf\n", wager);

		} while (wager <= 0);

	}	

	
		return wager;


}

int roll_die(void)
{
	int number = 0;
	number = rand() % 6 + 1; // limits numbers from 1 - 6
	return number;

}

int calculate_sum_dice(int die1_value, int die2_value)
{
	int sum = 0;

	sum = die1_value + die2_value;

	return sum;

}

int is_win_loss_or_point(int sum_dice) // determines result of first dice roll
{
	switch (sum_dice)
	{
		case 7:
		case 11:
			return 1;
			break;

		case 2:
		case 3:
		case 12:
			return 0;
			break;

		case 4:
		case 5:
		case 6:
		case 8:
		case 9:
		case 10:
			return -1;
			break;
	}
			

}

int is_point_loss_or_neither(int sum_dice, int point_value) // determines the result of successive dice roll
{
	if (sum_dice == point_value)
	{
		return 1;

	}
	else if (sum_dice == 7)
	{
		return 0;
		
	}
	else
	{
		return -1;
	}

}

double adjust_bank_balance(double bank_balance, double wager_amount, int add_or_subtract)
{
	if (add_or_subtract == 1)
	{
		bank_balance = bank_balance + wager_amount  ;
		return bank_balance;

	}
	else if (add_or_subtract == 0)
	{
		bank_balance = bank_balance - wager_amount;
		return bank_balance;

	}
		return bank_balance;

}


void chatter_messages(int number_rolls, int win_loss_neither, double initial_bank_balance, double current_bank_balance)
{
	if (win_loss_neither == 1)
	{
		printf("YOU WON!!!\n");


	}
	else if (win_loss_neither == 0)
	{
		printf("YOU LOSE!\n");
		printf("The House Wins!\n");
		printf("Better luck next time!!\n");

	}
	else
	{
		
		if (number_rolls == 3)
		{
			printf("You're going steady!\n");
			printf("Keep those dice rolling...\n");


		}
		else if (number_rolls == 5)
		{
			printf("You're on a streak!\n");

		}

	}
	// chatter messages based on bank balance
	if (current_bank_balance > initial_bank_balance)
	{

		printf("The dice were on your side this time!!\n");


	}
	if (current_bank_balance < initial_bank_balance)
	{
		printf("Oof the dice weren't on your side\n");


	}

}

int update_streak(int streak, int outcome)
{
	if (outcome == 1)
	{
		streak++;

	}
	else if (outcome == 0)
	{
		streak = 0;

	}

	return streak;
}

void print_streak_messages(int streak)
{
	switch (streak)
	{
		case 2:
			printf("2 Wins!\n");
			break;

		case 3:
			printf("Damn 3 Wins! You're on fire\n");
			break;

		case 5:
			printf("OMGG 5 Wins! Didn't even know that was possible\n");
			break;

	}


}