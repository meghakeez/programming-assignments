/*

	Contains function headers

*/


#include "functions.h"

void print_game_rules()
{	
	printf("-----------------------------------------------------------------------------------------------------------------------\n");
	printf("The scorecard used for Yahtzee is composed of two sections. A upper section and a lower section\n");
	printf("A total of thirteen boxes or thirteen scoring combinations are divided amongst the sections\n");
	printf("The upper section consists of boxes that are scored by summing the value of the dice matching the faces of the box\n");
	printf("Once a player has chosen to score a box, it may not be changed and the combination is no longer in play for future rounds\n");
	printf("If the sum of the scores in the upper section is >= 63, then a bonus of 35 points are added to the overall score\n");
	printf("The combinations consists of:\n");
	printf("1.Sum of 1's\n");
	printf("2.Sum of 2's\n");
	printf("3.Sum of 3's\n");
	printf("4.Sum of 4's\n");
	printf("5.Sum of 5's\n");
	printf("6.Sum of 6's\n");
	printf("7.Three-of-a-kind\n");
	printf("8.Four-of-a-kind\n");
	printf("9.Full house\n");
	printf("10.Small straight\n");
	printf("11.Large straight\n");
	printf("12.Yahtzee!\n");
	printf("13.Chance\n");
	printf("-----------------------------------------------------------------------------------------------------------------------\n");

}

int roll_die(void)
{
	int number = 0;
	number = rand() % 6 + 1; // limits numbers from 1 - 6
	return number;

}

int handling_of_rolls(int die_arr[], int *roll) 
{
	char option = '\0';

	if (*roll < 3)
	{
		printf("Do you want to use the current roll for one of the game combinations (Y/N): ");
		scanf(" %c", &option);

		if (option == 'Y' || option == 'y')
		{
			return 1;

		}

		if (option == 'N' || option == 'n')
		{
			int choice = 0;

			printf("Which dice do you want to reroll (1-5)? Enter 0 to keep all the dice: ");
			scanf(" %d", &choice);

			while (choice != 0)
			{
				if (choice >= 1 && choice <= 5)
				{
					die_arr[choice - 1] = roll_die();

				}
				else
				{
					printf("You have entered an invalid choice\n");
					

				}
				printf("Enter another dice to reroll (1-5) or 0 to stop: ");
				scanf(" %d", &choice);


			}

			(*roll)++;
			return 0;
		}
	}
}

void print_scoring_combinations()
{
	printf("-------------------------------\n");
	printf("1.Sum of 1's\n");
	printf("2.Sum of 2's\n");
	printf("3.Sum of 3's\n");
	printf("4.Sum of 4's\n");
	printf("5.Sum of 5's\n");
	printf("6.Sum of 6's\n");
	printf("7.Three-of-a-kind\n");
	printf("8.Four-of-a-kind\n");
	printf("9.Full House\n");
	printf("10.Small straight\n");
	printf("11.Large straight\n");
	printf("12.Yahtzee!\n");
	printf("13.Chance\n");
	printf("-------------------------------\n");


}

int choosen_scoring_combination(int used[]) 
{
	int combination = 0;

	do {

		printf("What combination do you pick (1-13): ");
		scanf("%d", &combination);

		if (combination < 1 || combination > 13)
		{
			printf("Invalid choice pick again\n");

		}

		if (combination != 12 && used[combination] == 1)
		{
			printf("That combination has already been used. Choose another combination\n");
			combination = 0;

		}

	} while (combination < 1 || combination > 13);

	if (combination != 12)
	{

		used[combination] = 1;
		printf("%d has been choosen\n", combination);
	}

	return combination;

}


int scoring_category(int dice[], int combination) 
{
	int freq[7] = {0}; // 6-sided dice and we ignore index 0
	int total = 0;

	for (int i = 0; i < 5; i++) // index 4 because we have exactly 5 dice
	{
		freq[dice[i]]++; // counting frequency of each dice value (1-6)
		total += dice[i]; // adds up sum of all dice


	}
				
	int points = 0;

	switch (combination)
	{
		case 1: // Sum of 1's
		case 2: // Sum of 2's
		case 3: // Sum of 3's
		case 4: // Sum of 4's
		case 5: // Sum of 5's
		case 6: // Sum of 6's
			points = freq[combination] * combination; // multiplies frequency of combination into the combination to determine points
			break;

		case 7: // Three-of-a-Kind
		{
			for(int i = 1; i <= 6; i++)
				if (freq[i] >= 3)
					points = total;

			break;
		}

		case 8: // Four-of-a-Kind
		{
			for(int i = 1; i <=6; i++)
				if(freq[i] >= 4)
					points = total;

			break;

		}


		case 9: // Full House (pair + three-of-a-kind)
		{
			
			int two_dice = 0, three_dice = 0;
			for (int i = 1; i <= 6; i++)
			{
				if (freq[i] == 2) 
					two_dice = 1;
				if (freq[i] == 3)
					three_dice = 1;

			}
			
			if (two_dice && three_dice)
				points = 25;
		
			break;

		}

		case 10: // Small Straight (sequnce of 4 dice)
		{
			if((freq [1] && freq[2] && freq[3] && freq[4] ||
				freq [2] && freq[3] && freq[4] && freq[5] ||
				freq [3] && freq[4] && freq[5] && freq[6]))
				points = 30;
			
			break;	

		}

		case 11: // Large Straight (sequence of 5 dice)
		{
			if ((freq[1] && freq[2] && freq[3] && freq[4] && freq[5] ||
				freq[2] && freq[3] && freq[4] && freq[5] && freq[6]))
				points = 40;

			break;

		}

		
		case 12: // Yahtzee (five dice with same face)
		{

			for(int i = 1; i <= 6; i++)
				if (freq[i] == 5)
					points = 50;

			break;
		}

		case 13: // Chance (any sequence of dice)
		{
			points = total;

			break;

		}	

	}

	return points;
	

}

int totalscore_uppersection(int score[]) 
{
	int total = 0;

	for (int i = 1; i <= 6; i++)
	{
		total += score[i]; //sums the first 6 scoring categories

	}

	if (total >= 63)
	{
		total += 35;
	}


	return total;
}

int total_score(int score[]) 

{
	
	int total = 0;

	for (int i = 1; i <= 13; i++)
	{
		total += score[i]; //sums the score from all combinations


	}

	return total;


}













	

