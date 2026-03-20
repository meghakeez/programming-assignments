/*
	Name: Megha Keezhanjil
	Course: CptS 121, Spring 2026 Lab Section 7
	Lab Assignment: Programming Assignment 4
	Date: 2/25/2026
	Description: A Game of Chance "CRAPS"

*/


#include "equations.h"

int main(void)
{
	//initialize random number
	srand((unsigned int)time(NULL));

	int option,
		die1,
		die2,
		sum_dice,
		point_value,
		outcome,
		successive_outcome,
		number_rolls = 0,
		streak = 0;


	double bank_balance,
		   wager,
		   update_bank_balance;

	do{



		do
		{
			printf("Welcome to the CRAPS Game!\n");
			printf("These are your options:\n");
			printf("1. Play the Game\n");
			printf("2. Display the Rules\n");
			printf("3. Exit the Game\n");
			printf("What option do you pick: ");
			scanf(" %d", &option);
		} while (option < 1 || option > 3); // prompts user to pick valid option!


		if (option == 2) // displays the rules of the game
		{

			print_game_rules(); 


		}

		if (option == 1) // plays the game while the player does not choose option 3
		{

			bank_balance = get_bank_balance();

			printf("Initial Balance: $%.2lf\n", bank_balance);

			wager = get_wager_amount();

			printf("Wager amount: $%.2lf\n", wager);

			wager = check_wager_amount(wager, bank_balance); // sets wager to valid amount

			printf("\n"); 

			number_rolls = 1;

			printf("-----Rolling dice now-----\n");
			die1 = roll_die();
			printf("Your die1 number is %d\n", die1);

			die2 = roll_die();
			printf("Your die2 number is %d\n", die2);


			sum_dice = calculate_sum_dice(die1, die2);
			printf("The sum of both dices is %d\n", sum_dice);

			outcome = is_win_loss_or_point(sum_dice);
			streak = update_streak(streak, outcome);

			if (outcome == 1) // result of first dice roll is either 7 or 11
			{
				printf("You rolled %d\n", sum_dice);
				update_bank_balance = adjust_bank_balance(bank_balance, wager, 1);
				chatter_messages(number_rolls, outcome, bank_balance, update_bank_balance);
				print_streak_messages(streak);
				printf("Your wager of %.2lf is added to your account\n", wager);
				printf("Your bank balance is now %.2lf\n", update_bank_balance);
				printf("---------------------------------------------------\n");


			}
			if (outcome == 0) // result of first dice roll is either 2, 3 or 12
			{
				printf("You rolled %d\n", sum_dice);
				update_bank_balance = adjust_bank_balance(bank_balance, wager, 0);
				chatter_messages(number_rolls, outcome, bank_balance, update_bank_balance);
				printf("Your wager of %.2lf is subtracted from your account\n", wager);
				printf("Your bank balance is now %.2lf\n", update_bank_balance);
				printf("----------------------------------------------------\n");


			}
			else if (outcome == -1) // result of first dice roll is either 4, 5, 6, 8, 9 or 10
			{
				point_value = sum_dice;
				successive_outcome = -1; 

				printf("You rolled %d\n", sum_dice);
				printf("You have entered the point phase of CRAPS\n");
				printf("Roll until you get %d again\n", sum_dice);
				printf("If you roll 7, you lose!\n");
				printf("If sum is 4, 5, 6, 8, 9 or 10, bank balance remains the same\n");

				while (successive_outcome == -1)
				{
					number_rolls++;

					printf("-----Rolling dice now-----\n");
					die1 = roll_die();
					printf("Your die1 number is %d\n", die1);

					die2 = roll_die ();
					printf("Your die2 number is %d\n", die2);

					sum_dice = calculate_sum_dice(die1, die2);
					printf("The sum of both dices is %d\n", sum_dice);

					successive_outcome = is_point_loss_or_neither(sum_dice, point_value); // Evaluating this roll
					streak = update_streak(streak, successive_outcome);

				}

				if (successive_outcome == 1) // sum of second dice roll is equal to point value
				{
					update_bank_balance = adjust_bank_balance(bank_balance, wager, 1);
					chatter_messages(number_rolls, outcome, bank_balance, update_bank_balance);
					printf("You rolled %d again\n",point_value);
					printf("YOU WON!!\n");
					print_streak_messages(streak);
					printf("Your bank balance is now %.2lf\n", update_bank_balance);
					printf("--------------------------------------------------\n");


				}
			
				if (successive_outcome == 0) // sum of second dice roll is equal to 7
				{
					update_bank_balance = adjust_bank_balance(bank_balance, wager, 0);
					chatter_messages(number_rolls, outcome, bank_balance, update_bank_balance);
					printf("You rolled a 7!\n");
					printf("YOU LOSE!\n");
					printf("The House Wins!\n");
					printf("Your wager of %.2lf is subtracted from your account\n", wager);
					printf("Your bank balance is now %.2lf\n", update_bank_balance);
					
					printf("--------------------------------------------------\n");

				}


	
			}

		}

	}while (option != 3);

	


	return 0;	
    

}


	
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			














	
	







