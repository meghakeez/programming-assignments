/*
	Name: Megha Keezhanjil
	Course: CptS 121, Spring 2026 Lab Section 7
	Lab Assignment: Programming Assignment 5
	Date: 3/11/2026
	Description: The Game of Yahtzee

*/

#include "functions.h"


int main(void)
{

	srand((unsigned int)time(NULL));

	int option,
		die_arr[5] = {0},
		sum_dice = 0,
		combination = 0,
		points = 0,
		roll = 0,
		round = 1,
		current_player = 1,
		done = 0,
		player1_upper = 0,
		player2_upper = 0,
		player1_total = 0,
		player2_total = 0,
	
	    player1_score[14] = {0},
		player2_score[14] = {0},
		player1_used[14] = {0},
		player2_used[14] = {0};


	do 
	{

		
		do {
			
			printf("Welcome to Yahtzee!!\n");
			printf("These are your options:\n");
			printf("1. Print game rules\n");
			printf("2. Start a game of Yahtzee\n");
			printf("3. Exit\n");
			printf("What option do you pick: ");
			scanf(" %d", &option);
			getchar(); 
		} while (option < 1 || option > 3);

		system("cls"); // clears the screen

		if (option == 1) // prints game rules
		{

			print_game_rules();

		}

		if (option == 2) //plays the game 
		{

			for (int round = 1; round <= 13; round++)
			{

				for (int current_player = 1; current_player <= 2; current_player++)
				{	
					
					if (current_player == 1 && round == 1)
					{
						printf("Let's start playing!!\n");
					}
					
					printf("Player %d's turn (Round %d)\n", current_player, round);

					while (getchar() != '\n'); // removes leftover newline character from previous scanf 
					printf("Press Enter to roll the dice\n");
					getchar(); // waits for user to press Enter

					done = 0; // resets done to 0 after each player's turn
					roll = 1;

					//First Roll
					for (int i = 0; i < 5; i++)
					{
						die_arr[i] = roll_die();
					}

					//Rerolling Selective Dice
					while (!done) // loops until done = 1
					{
						for (int i = 0; i < 5; i++)
						{
							printf("Die %d: %d\n", i + 1, die_arr[i]); // add 1 to show die number

						}

						done = handling_of_rolls(die_arr, &roll);

					}


					printf("Pick a scoring combination: \n");
					print_scoring_combinations();

					if (current_player == 1)
					{
						combination = choosen_scoring_combination(player1_used);
						points = scoring_category(die_arr, combination);

						player1_score[combination] = points;

						printf("You score %d points in round %d\n", points, round);


					}
					else
					{
						combination = choosen_scoring_combination(player2_used);
						points = scoring_category(die_arr, combination);

						player2_score[combination] = points;
						
						printf("You score %d points in round %d\n", points, round);

					}

				}


			}
			
			
			player1_upper = totalscore_uppersection(player1_score);
			player2_upper = totalscore_uppersection(player2_score);

			printf("Player 1: Total score for Upper Section: %d\n", player1_upper);
			printf("Player 2: Total score for Upper Section: %d\n", player2_upper);

			player1_total = total_score(player1_score);
			player2_total = total_score(player2_score);

			printf("Player 1: Total score for game: %d\n", player1_total);
			printf("Player 2: Total score for game: %d\n", player2_total);

			if (player1_total > player2_total)
			{
				printf("Congratulations Player 1!! You're a pro\n");

			}

			else if (player2_total > player1_total)
			{
				printf("Congratulations Player 2! You're a pro\n");

			}

			else
			{
				printf("It's a tie! We've got 2 experts in the house\n");
			}


			printf("Let's play again?\n");
		}


    }while (option != 3);

	printf("See you soon!\n");


 return 0;
}
